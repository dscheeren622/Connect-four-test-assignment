#pragma once

#include "ColorEnum.h"
#include "Position.h"

class Disc
{
    public:
        explicit Disc(const Position &position);
        virtual ~Disc() = default;
        
        Position &getPosition();

    private:
        Position m_position;
};