#pragma once

#include "Position.h"
#include "ColorEnum.h"
#include "Field.cpp"

class DiscFactory
{
    public:
        DiscFactory() = default;
        static void makeRedDisc(int columnNumber, Field &field);
        static void makeYellowDisc(int columnNumber, Field &field);

    private:
};