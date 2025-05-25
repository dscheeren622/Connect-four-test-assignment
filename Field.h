#pragma once
#include <vector>

#include "Disc.cpp"
#include "DirectionEnum.h"

class Field
{
    public:
        Field() = default;

        std::vector<Disc> getDiscs();
        std::vector<Disc> getRedDiscs();
        std::vector<Disc> getYellowDiscs();
        void addDiscToList(Disc &disc);
        void addRedDiscToList(Disc &disc);
        void addYellowDiscToList(Disc &disc);
        void showField();
        int getLength();
        int getHeight();
        bool getFourRowExists();
        void checkFourRow();

    private:
        int m_length = 7;
        int m_height = 6;
        bool m_fourRowExists = false;

        std::vector<Disc> m_discs;
        std::vector<Disc> m_redDiscs;
        std::vector<Disc> m_yellowDiscs;
        bool checkRedDiscPresent(Position &position, bool discPresent);
        bool checkYellowDiscPresent(Position &position, bool discPresent);
        Direction checkNeighborDirection(Disc &disc, Disc &otherDisc);
        void checkCurrentDirection(Position position, Direction direction, std::vector<Disc> &discs);
        void checkFourRow(Position position, Position displacement, std::vector<Disc> &discs);
};