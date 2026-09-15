# Fiche de révision : Architecture C++, Mémoire & Robotique

---

## 1. Conteneurs STL : Complexités, Localisation Mémoire & Usages

La pile (*stack*) héberge les variables locales et les en-têtes d'objets ; le tas (*heap*) héberge les données dynamiques allouées via l'allocateur système.

| Conteneur | Accès | Insertion / Suppression | Emplacement Pile (*Stack*) | Emplacement Tas (*Heap*) | Usage & Arbitrage Robotique |
| --- | --- | --- | --- | --- | --- |
| **`std::array<T, N>`** | $\mathcal{O}(1)$ | Impossible (taille fixe) | **100 % des données** | **Rien** (0 allocation) | **Idéal temps-réel.** Zéro allocation, déterministe, cache CPU optimal. Commandes d'actionneurs, matrices de rotation. |
| **`std::vector<T>`** | $\mathcal{O}(1)$ | Fin : $\mathcal{O}(1)$ amorti<br>

<br>Milieu : $\mathcal{O}(n)$ | En-tête (24 o : `data`, `size`, `capacity`) | **Tous les éléments `T**` | **Choix par défaut.** Contigu en mémoire (cache-friendly). Nuages de points, buffers de capteurs. Réserver hors boucle avec `reserve()`. |
| **`std::deque<T>`** | $\mathcal{O}(1)$ | Début / Fin : $\mathcal{O}(1)$ | Tableau de pointeurs de blocs | Blocs de données alloués au fil de l'eau | Ring-buffers, fenêtres glissantes de commandes. Évite le realloc massif du vector, mais multiplie les allocations tas. |
| **`std::list<T>`** | $\mathcal{O}(n)$ | Itérateur connu : $\mathcal{O}(1)$ | En-tête (pointeurs tête/queue) | **Chaque nœud** (`prev`, `next`, valeur) | **À proscrire en robotique.** Une allocation par insertion, éparpille la mémoire et provoque des *cache misses* permanents. |
| **`std::unordered_map`** | $\mathcal{O}(1)$ moy.<br>

<br>$\mathcal{O}(n)$ pire | $\mathcal{O}(1)$ moyen | En-tête (gestionnaire) | Table de hachage + seaux + nœuds de collision | Lookups par identifiant texte ou ID global hors boucle critique. Pour $N < 50$, un `vector` linéaire est souvent plus rapide. |
| **`std::map`** | $\mathcal{O}(\log n)$ | $\mathcal{O}(\log n)$ | En-tête (racine) | **Chaque nœud** de l'arbre rouge-noir | Données devant rester triées en continu (horodatages de logs, séries temporelles). |
| **`std::priority_queue`** | Top : $\mathcal{O}(1)$ | Push / Pop : $\mathcal{O}(\log n)$ | En-tête du conteneur sous-jacent | Éléments dans un `vector` sous-jacent | Planification de trajectoire (tas-min de Dijkstra, A*). |

---

## 2. Le match architectural : Localité spatiale du Cache

Les processeurs modernes chargent les données de la RAM par lignes de cache de 64 octets (*cache lines*).

```
[ std::vector en mémoire ]  --> | Elem 0 | Elem 1 | Elem 2 | Elem 3 |  (1 seul chargement de cache)
[ std::list en mémoire ]    --> [ Nœud A ] ...RAM... [ Nœud B ] ...RAM...  (N accès RAM lents, cache miss)

```

```
DÉCOUPAGE MÉMOIRE D'UN VECTOR :
PILE (Stack) - Accès instantané           TAS (Heap) - Dynamique, fragmentable
┌────────────────────────┐                ┌───────────────────────────────┐
| vector v;              |                | [0] | [1] | [2] | ... | [N-1] |
| - ptr_data     ────────┼───────────────>|                               |
| - size (ex: 3)         |                └───────────────────────────────┘
| - capacity (ex: 4)     |
└────────────────────────┘

```

* **`std::vector`** garantit la contiguïté mémoire : le matériel précharge automatiquement les éléments suivants (*hardware prefetcher*).
* **`std::list`** stocke des nœuds chaînés dispersés sur le tas : chaque saut de pointeur force une attente de lecture en mémoire centrale.

---

## 3. Mémoire & Contraintes Temps-Réel (*Hard Real-Time*)

Dans une boucle de contrôle (ex. PID à 1 kHz = budget strict de 1 ms) :

* **Règle absolue : zéro allocation dynamique sur le tas (`new`, `malloc`, `push_back` non réservé) dans la boucle critique.**
* L'allocateur d'OS n'est pas déterministe (temps de recherche imprévisible en cas de fragmentation).
* Risque de blocage du thread via un défaut de page (*page fault*) ou un verrou interne à l'allocateur.


* **Bonnes pratiques :**
* **Pile pure (`std::array`) :** taille fixe connue à la compilation, allocation à coût nul.
* **Pré-allocation :** appeler `reserve()` ou `resize()` durant la phase d'initialisation du nœud/robot.
* **Zero-copy :** passer les structures volumineuses par référence constante (`const T&`) ou par déplacement (`std::move`).



```cpp
// ❌ INTERDIT EN TEMPS-RÉEL : allocation dynamique à 1000 Hz
void controlLoopCallback() {
    std::vector<double> commands; // Alloue sur le tas si dépassement
    commands.push_back(computeEffort()); 
}

// ✅ VALIDE TEMPS-RÉEL : 100 % sur la pile, déterministe en temps O(1)
class Controller {
    std::array<double, 6> joint_efforts_; // Sur la pile, zéro indirection
public:
    void controlLoopCallback() {
        joint_efforts_[0] = computeEffort();
    }
};

```

---

## 4. Pointeurs intelligents : Modèle mémoire & Coûts

* **`std::unique_ptr<T>` (Usage par défaut)**
* **Stack :** 1 pointeur brut (8 octets).
* **Heap :** l'objet pointé `T`.
* **Propriété exclusive.** Coût nul par rapport à un pointeur nu (*zero-overhead*). Libération automatique en fin de portée (RAII).


* **`std::shared_ptr<T>` (Usage restreint)**
* **Stack :** 2 pointeurs (16 octets : pointeur vers l'objet + pointeur vers le bloc de contrôle).
* **Heap :** l'objet `T` + le bloc de contrôle (compteur de références atomique). Préférer `std::make_shared` pour fusionner ces deux blocs en une seule allocation.
* **Propriété partagée.** Coût CPU à chaque copie (incrément/décrément atomique). Utile pour transmettre un nuage de points lourd à plusieurs nœuds asynchrones.


* **`std::weak_ptr<T>`**
* Observe un `shared_ptr` sans incrémenter son compteur. Brise les références cycliques sur le tas pour éviter les fuites mémoire.



---

## 5. Concurrence & Partage de données

Modèle classique : un thread lit un capteur à 1 kHz, un thread calcule la commande à 100 Hz.

```
[ Thread Capteur (1 kHz) ] ────> Écriture ───┐
                                              ├──> [ Ressource partagée ]
[ Thread Contrôle (100 Hz) ] ───> Lecture ────┘

```

* **`std::mutex` + `std::lock_guard` :** garantit l'exclusion mutuelle via RAII. Risque en robotique : l'**inversion de priorité** (un thread critique attend qu'un thread secondaire libère le mutex).
* **Alternatives temps-réel sans verrou (*lock-free*) :**
* Variables atomiques primitives : `std::atomic<bool>`, `std::atomic<double>`.
* File circulaire sans verrou (*Single-Producer Single-Consumer lock-free ring buffer*) pour échanger des flux de commandes/mesures sans suspendre la boucle de commande.