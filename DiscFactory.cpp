#pragma once
#include "DiscFactory.h"

#include "RedDisc.cpp"
#include "YellowDisc.cpp"

void DiscFactory::makeRedDisc(int columnNumber, Field &field)
{
    int counter = 0;

    //check at which height to put the disc
    std::vector<Disc> discs = field.getDiscs();
    for (int i = 0; i < discs.size(); ++i)
    {
        Disc disc = discs[i];
        if (disc.getPosition().m_x == columnNumber)
        {
            ++counter;
        }
    }

    Position discPosition = {columnNumber, counter};
    RedDisc newDisc = RedDisc(discPosition);
    field.addRedDiscToList(newDisc);
    field.addDiscToList(newDisc);
}

void DiscFactory::makeYellowDisc(int columnNumber, Field &field)
{
    int counter = 0;

    //check at which height to put the disc
    std::vector<Disc> discs = field.getDiscs();
    for (int i = 0; i < discs.size(); ++i)
    {
        Disc disc = discs[i];
        if (disc.getPosition().m_x == columnNumber)
        {
            ++counter;
        }
    }

    Position discPosition = {columnNumber, counter};
    RedDisc newDisc = RedDisc(discPosition);
    field.addYellowDiscToList(newDisc);
    field.addDiscToList(newDisc);
}


