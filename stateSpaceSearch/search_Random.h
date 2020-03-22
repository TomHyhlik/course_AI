#ifndef SEARCH_RANDOM_H_
#define SEARCH_RANDOM_H_


#include "globals.h"
#include "searchAlgo.h"


class search_Random : public searchAlgo
{
    point getNextFocusPoint() override
    {
        // int indexOfSelectedPoint = 73 % frontFocusPoints.size();
        int indexOfSelectedPoint = rand() % frontFocusPoints.size();

        point p = frontFocusPoints.at(indexOfSelectedPoint);
        frontFocusPoints.erase(frontFocusPoints.begin()+indexOfSelectedPoint);

        return p;
    }
};





#endif