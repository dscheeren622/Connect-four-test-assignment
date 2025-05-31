#pragma once
#include <iostream>
#include "Field.h"

std::vector<Disc> &Field::getDiscs()
{
    return m_discs;
}

std::vector<Disc> &Field::getRedDiscs()
{
    return m_redDiscs;
}

std::vector<Disc> &Field::getYellowDiscs()
{
    return m_yellowDiscs;
}

void Field::addDiscToList(const Disc &disc)
{
    m_discs.push_back(disc);
}

void Field::addRedDiscToList(const Disc &disc)
{
    m_redDiscs.push_back(disc);
}

void Field::addYellowDiscToList(const Disc &disc)
{
    m_yellowDiscs.push_back(disc);
}

void Field::showField()
{
    for (int i = m_height - 1; i >= 0; --i) // in reverse since the table needs to build from the bottom up
    {
        for (int j = 0; j < m_length; ++j)
        {
            Position position = {i,j};
            bool discPresent = false;
            discPresent = checkRedDiscPresent(position, discPresent); // an "R" will be added to the table
            discPresent = checkYellowDiscPresent(position, discPresent); // a "Y" will be added to the table

            if (!discPresent)
            {
                std::cout << "  O  ";
            }
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }
}

bool Field::checkRedDiscPresent(const Position &position, bool discPresent)
{
    for (int k = 0; k < m_redDiscs.size(); ++k)
    {
        if (m_redDiscs[k].getPosition().m_x == position.m_y && m_redDiscs[k].getPosition().m_y == position.m_x)
        {
            std::cout << "  R  ";
            discPresent = true;
            break;      
        }
    }
    return discPresent;
}

bool Field::checkYellowDiscPresent(const Position &position, bool discPresent)
{
    for (int k = 0; k < m_yellowDiscs.size(); ++k)
    {
        if (m_yellowDiscs[k].getPosition().m_x == position.m_y && m_yellowDiscs[k].getPosition().m_y == position.m_x)
        {
            std::cout << "  Y  ";
            discPresent = true;
            break;      
        }
    }
    return discPresent;
}

int Field::getHeight()
{
    return m_height;
}

int Field::getLength()
{
    return m_length;
}

void Field::checkFourRow()
{
    // red player
    for (int i = 0; i < m_redDiscs.size(); ++i)
    {
        Disc redDisc = m_redDiscs[i];

        for (int j = 0; j < m_redDiscs.size(); ++j)
        {
            Direction direction = checkNeighborDirection(redDisc, m_redDiscs[j]);
            if (direction != Direction::NoDirection)
            {
                checkCurrentDirection(redDisc.getPosition(), direction, m_redDiscs);
            }
        }
    }

    // yellow player
    for (int i = 0; i < m_yellowDiscs.size(); ++i)
    {
        Disc yellowDisc = m_yellowDiscs[i];

        for (int j = 0; j < m_yellowDiscs.size(); ++j)
        {
            Direction direction = checkNeighborDirection(yellowDisc, m_yellowDiscs[j]);
            if (direction != Direction::NoDirection)
            {
                checkCurrentDirection(yellowDisc.getPosition(), direction, m_yellowDiscs);
            }
        }
    }
}

Direction Field::checkNeighborDirection(Disc &disc, Disc &otherDisc)
{
    if (disc.getPosition().m_x + 1 == otherDisc.getPosition().m_x && disc.getPosition().m_y == otherDisc.getPosition().m_y)
    {
        return Direction::Right; 
    }
    else if (disc.getPosition().m_x == otherDisc.getPosition().m_x && disc.getPosition().m_y + 1 == otherDisc.getPosition().m_y)
    {
        return Direction::Up;
    }
    else if (disc.getPosition().m_x - 1 == otherDisc.getPosition().m_x && disc.getPosition().m_y == otherDisc.getPosition().m_y)
    {
        return Direction::Left;
    }
        else if (disc.getPosition().m_x == otherDisc.getPosition().m_x && disc.getPosition().m_y - 1 == otherDisc.getPosition().m_y)
    {
        return Direction::Down;
    }
        else if (disc.getPosition().m_x + 1 == otherDisc.getPosition().m_x && disc.getPosition().m_y + 1 == otherDisc.getPosition().m_y)
    {
        return Direction::UpRight;
    }
        else if (disc.getPosition().m_x - 1 == otherDisc.getPosition().m_x && disc.getPosition().m_y + 1 == otherDisc.getPosition().m_y)
    {
        return Direction::UpLeft;
    }
        else if (disc.getPosition().m_x + 1 == otherDisc.getPosition().m_x && disc.getPosition().m_y - 1 == otherDisc.getPosition().m_y)
    {
        return Direction::DownRight;
    }
        else if (disc.getPosition().m_x - 1 == otherDisc.getPosition().m_x && disc.getPosition().m_y - 1 == otherDisc.getPosition().m_y)
    {
        return Direction::DownLeft;
    }

    return Direction::NoDirection; // if the other disc is not a neighbor of current disc
}

void Field::checkCurrentDirection(const Position &position, const Direction &direction, std::vector<Disc> &discs)
{
    Position displacement;
    switch (direction){
        case Direction::Up:
            displacement = {0, 1};
            checkFourRow(position, displacement, discs);
            break;
        case Direction::Down:
            displacement = {0, -1};
            checkFourRow(position, displacement, discs);
            break;
        case Direction::Right:
            displacement = {1, 0};
            checkFourRow(position, displacement, discs);
            break;
        case Direction::Left:
            displacement = {-1, 0};
            checkFourRow(position, displacement, discs);
            break;
        case Direction::UpRight:
            displacement = {1, 1};
            checkFourRow(position, displacement, discs);
            break;
        case Direction::UpLeft:
            displacement = {-1, 1};
            checkFourRow(position, displacement, discs);
            break;
        case Direction::DownRight:
            displacement = {1, -1};
            checkFourRow(position, displacement, discs);
            break;
        case Direction::DownLeft:
            displacement = {-1, -1};
            checkFourRow(position, displacement, discs);
            break;
        default:
            return;
    }
}

void Field::checkFourRow(const Position &position, const Position &displacement, std::vector<Disc> &discs)
{
    int counter = 1;
    for (int i = 0; i < discs.size(); ++i)
    {
        if ( discs[i].getPosition().m_x == position.m_x + displacement.m_x && discs[i].getPosition().m_y == position.m_y + displacement.m_y )
        {
            ++counter;
        }
        if ( discs[i].getPosition().m_x == position.m_x + 2 * displacement.m_x && discs[i].getPosition().m_y == position.m_y + 2 * displacement.m_y )
        {
            ++counter;
        }        
        if ( discs[i].getPosition().m_x == position.m_x + 3 * displacement.m_x && discs[i].getPosition().m_y  == position.m_y + 3 * displacement.m_y)
        {
            ++counter;
        }

        if (counter == 4)
        {
            m_fourRowExists = true;
            break;
        }
    }
}

bool Field::getFourRowExists()
{
    return m_fourRowExists;
}


