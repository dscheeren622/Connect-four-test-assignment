#pragma once

#include "ColorEnum.h"
#include "Position.h"

class Disc
{
    public:
        Disc(Position &position);
        virtual ~Disc() = default;
        
        Position getPosition();
        Color getColor();

    private:
        Position m_position;
};