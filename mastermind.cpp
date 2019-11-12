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

    int solution [4];

    firstPeg = rand() % 6;
    secondPeg = rand() % 6;
    thirdPeg = rand() % 6;
    fourthPeg = rand() % 6;

   // firstPeg = 1;
    //secondPeg = 1;
    //thirdPeg = 3;
    //fourthPeg = 2;

    solution[0] = firstPeg;
    solution[1] = secondPeg;
    solution[2] = thirdPeg;
    solution[3] = fourthPeg;

    system("CLS");

    cout << "---MASTERMIND---" << endl << "0 = Vermelho" << endl << "1 = Verde" << endl << "2 = Azul"
    << endl << "3 = Laranja" << endl << "4 = Roxo" << endl << "5 = Amarelo" << endl << "---------------------";

    cout << firstPeg << secondPeg << thirdPeg << fourthPeg << endl;

    cout << endl <<  "Senha definida! Faca sua primeira jogada!" << endl;

    while(tentativas < 8)
    {
        
        cin >> firstGuess >> secondGuess >> thirdGuess >> fourthGuess;
        
        int guesses[4];

        guesses[0] = firstGuess;
        guesses[1] = secondGuess;
        guesses[2] = thirdGuess;
        guesses[3] = fourthGuess;

        array<int,4> feedbackIndex {0,1,2,3};

        unsigned seed = chrono::system_clock::now().time_since_epoch().count();

        shuffle (feedbackIndex.begin(), feedbackIndex.end(), default_random_engine(seed));

        string feedback[4];

        int whiteMarker[4] {0,0,0,0};
        
        for (int i = 0; i < 4; i++)
        {
            if (solution[i] == guesses[i])
            {
                feedback[feedbackIndex[i]] = "PRETO";
                guesses[i] = -1;
                whiteMarker[i] = 1;
                //break;
            }
        }

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (guesses[i] == solution[j] && whiteMarker[j] == 0 && i != j)
                {
                    feedback[feedbackIndex[i]] = "BRANCO";
                    whiteMarker[j] = 1;
                   // break;
                }
            }
            
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
            cout << "Parabens! Voce acertou a sequencia!" << endl;
            break;
        }
        
        for (int i = 0; i < 4; i++)
        {
            cout << feedback[i] << " ";
        }
        cout << endl;
        tentativas++;
    }
}