#pragma once
#include "Disc.h"

Disc::Disc(Position &position)
:
m_position(position)
{}

Position Disc::getPosition()
{
    return m_position;
}


