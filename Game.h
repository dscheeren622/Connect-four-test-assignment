#pragma once

#include "ColorEnum.h"
#include "Field.cpp"

class Game
{
    public:
        Game() = default;

        void playGame(Field &field);
        void takeTurn(int columnNumber, const Color &color, Field& field);

    private:   
        int m_round = 1;
        int m_maxRounds;
        bool m_gameOver = false;
        
        int checkValidNumber(int number);
        void playRound(Field &field);
        void redPlayerTurn(int number, Field &field);
        void yellowPlayerTurn(Field &field);
        void checkGameOver(bool fourRowPresent);    
        void gameIsOver(Field &field);
};

