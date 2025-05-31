#pragma once
#include "Disc.h"

Disc::Disc(const Position &position)
:
m_position(position)
{}

Position &Disc::getPosition()
{
    return m_position;
}


