#pragma once
#include <random>
#include "Game.h"

#include "DiscFactory.cpp"

// random generator for int between 1 and 7
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> dist(1, 7);

void Game::playGame(Field &field)
{
    m_maxRounds = field.getHeight() * field.getLength();
    
    std::cout << "You are going to play connect-four:" << std::endl << std::endl;
    std::cout << "O means empty, R means a red disc and Y means a yellow disc" << std::endl << std::endl;
    
    std::cout << "Round " << m_round << std::endl;
    field.showField(); // show empty field at beginning of the game

    while (!m_gameOver)
    {
        playRound(field);
    }
}

void Game::playRound(Field &field)
{
    int number;
    std::cout << "Put in an integer between 1 and 7.." << std::endl; 
    std::cin >> number;
    number = checkValidNumber(number);
    std::cout << std::endl;
    std::cout << std::endl;

    redPlayerTurn(number, field);
    yellowPlayerTurn(field);
}

void Game::redPlayerTurn(int number, Field &field)
{
    //Red player
    takeTurn(number, Color::Red, field);
    checkGameOver(field.getFourRowExists());
    if(m_gameOver)
    {
        gameIsOver(field);
    }
    ++m_round;
    std::cout << "Round " << m_round << std::endl;
    field.showField();
}

void Game::yellowPlayerTurn(Field &field)
{
    int number = dist(gen); // cpu plays a random row
    takeTurn(number, Color::Yellow, field);
    checkGameOver(field.getFourRowExists());
    if(m_gameOver)
    {
        gameIsOver(field);
    }
    ++m_round;
    std::cout << "Round " << m_round << std::endl;
    field.showField();
}

void Game::takeTurn(int columnNumber, Color color, Field& field)
{   
    if (color == Color::Red)
    {
        DiscFactory::makeRedDisc(columnNumber - 1, field);
    }
    else 
    {
        DiscFactory::makeYellowDisc(columnNumber - 1, field);
    }
    field.checkFourRow();
}

void Game::checkGameOver(bool fourRowPresent)
{
    if (m_round >= m_maxRounds || fourRowPresent)
    {
        m_gameOver = true;
    }
}

void Game::gameIsOver(Field &field)
{
    field.showField(); //field at the end of the game
    std::cout << "Game over!" << std::endl;        
    return;
}

int Game::checkValidNumber(int number)
{
    if (number <= 7 && number >= 1)
    {
        return number;
    }
    else
    {
        std::cout << "Invalid input, using a random number.." << std::endl;
        number = dist(gen); // cpu plays a random row
        return number;
    }
}

