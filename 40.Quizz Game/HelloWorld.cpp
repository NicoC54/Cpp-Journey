#include <iostream>

int main() {

std::string questions []= {"1.What year was C++ created?: ",
                           "2.Who invented C++?: ",
                           "3.What is the predecessor of C++?: ",
                           "4.Is the Earth flat ?: "};

std::string options [][4]=
    {{"A.1969", "B.1972","C.1985" ,"D.2015"},
     {"A.Mark", "B.Elon","C.Antoine" ,"D.Nicolas"},
     {"A.C", "B.C--","C.C##" ,"D.C#"},
     {"A.yes", "B.no","C.sometimes" ,"D.THE MOOOON"}};


char answerKey[] = {'C','B','A','B'};
int size = sizeof(questions)/sizeof(questions[0]);
char guess;
int score = 0;

for (int i = 0; i< size; i++){
    std::cout << "***********************";
    std::cout << questions[i] << '\n';
    std::cout << "***********************";

    for (int j=0; j<sizeof(options[i])/sizeof(options[i][0]); j++){
        std::cout << options[i][j] << std::endl;
    }
    std::cin >> guess;

    if (guess == answerKey[i]){
        score++;
    }
}

std::cout << score;

return 0;
}


