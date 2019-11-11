#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <set> 
#include <string>
#include <array>
#include <algorithm>    // std::shuffle
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock
using namespace std;

enum
{
    VERMELHO,
    VERDE,
    AZUL,
    LARANJA,
    ROXO,
    AMARELO,
};


int main()
{
    int firstPeg, secondPeg, thirdPeg, fourthPeg, firstGuess, secondGuess, thirdGuess, fourthGuess,
    indexOne, indexTwo, indexThree, indexFour, tentativas = 0;

    bool win = false;

    srand (time(NULL));

    set <int> solution;

    firstPeg = rand() % 8;
    secondPeg = rand() % 8;
    thirdPeg = rand() % 8;
    fourthPeg = rand() % 8;

    solution.insert(firstPeg);
    solution.insert(secondPeg);
    solution.insert(thirdPeg);
    solution.insert(fourthPeg);

    cout << "---MASTERMIND---" << endl << "0 = Vermelho" << endl << "1 = Verde" << endl << "2 = Azul"
    << endl << "3 = Laranja" << endl << "4 = Roxo" << endl << "5 = Amarelo" << endl << "---------------------";

    cout << firstPeg << secondPeg << thirdPeg << fourthPeg;

    cout << "Senha definida! Faça sua primeira jogada!";

    while(tentativas < 8)
    {
        cin >> firstGuess >> secondGuess >> thirdGuess >> fourthGuess;

        array<int,4> feedbackIndex {0,1,2,3};

        unsigned seed = chrono::system_clock::now().time_since_epoch().count();

        shuffle (feedbackIndex.begin(), feedbackIndex.end(), default_random_engine(seed));

        string feedback[4];

        if(firstPeg == firstGuess)
        {        
            feedback[feedbackIndex[0]] = "PRETO";
        }
        else if(solution.count(firstGuess) == 1)
        {
            feedback[feedbackIndex[0]] = "BRANCO";
        }
        else
        {
            feedback[feedbackIndex[0]] = "NADA";
        }

        if(secondPeg == secondGuess)
        {        
            feedback[feedbackIndex[1]] = "PRETO";
        }
        else if(solution.count(secondGuess) == 1)
        {
            feedback[feedbackIndex[1]] = "BRANCO";
        }
        else
        {
            feedback[feedbackIndex[1]] = "NADA";
        }

        if(thirdPeg == thirdGuess)
        {        
            feedback[feedbackIndex[2]] = "PRETO";
        }
        else if(solution.count(thirdGuess) == 1)
        {
            feedback[feedbackIndex[2]] = "BRANCO";
        }
        else
        {
            feedback[feedbackIndex[2]] = "NADA";
        }

        if(fourthPeg == fourthGuess)
        {        
            feedback[feedbackIndex[3]] = "PRETO";
        }
        else if(solution.count(fourthGuess) == 1)
        {
            feedback[feedbackIndex[3]] = "BRANCO";
        }
        else
        {
            feedback[feedbackIndex[3]] = "NADA";
        }

        win = true;
        for (int i = 0; i < 4; i++)
        {
            if(feedback[i] != "PRETO")
            {
                win = false;
                break;
            }
        }

        if(win)
        {
            cout << "Parabéns! Você acertou a sequência!" << endl;
            break;
        }else{
            cout << feedback;
            tentativas++;
        }

    }


}