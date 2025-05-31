#pragma once
#include <vector>

#include "Disc.cpp"
#include "DirectionEnum.h"

class Field
{
    public:
        Field() = default;

        int getLength();
        int getHeight();
        std::vector<Disc> &getDiscs();
        std::vector<Disc> &getRedDiscs();
        std::vector<Disc> &getYellowDiscs();

        void addDiscToList(const Disc &disc);
        void addRedDiscToList(const Disc &disc);
        void addYellowDiscToList(const Disc &disc);

        void showField();
        void checkFourRow();
        bool getFourRowExists();

    private:
        const int m_length = 7;
        const int m_height = 6;
        bool m_fourRowExists = false;

        std::vector<Disc> m_discs;
        std::vector<Disc> m_redDiscs;
        std::vector<Disc> m_yellowDiscs;
        
        bool checkRedDiscPresent(const Position &position, bool discPresent);
        bool checkYellowDiscPresent(const Position &position, bool discPresent);
        Direction checkNeighborDirection(Disc &disc, Disc &otherDisc);
        void checkCurrentDirection(const Position &position, const Direction &direction, std::vector<Disc> &discs);
        void checkFourRow(const Position &position, const Position &displacement, std::vector< Disc> &discs);
};