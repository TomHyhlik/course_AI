#ifndef SEARCH_BREADTHFIRST
#define SEARCH_BREADTHFIRST


#include "globals.h"
#include "searchAlgo.h"


class search_BreadthFirst : public searchAlgo
{
    point getNextFocusPoint() override
    {
        point p = frontFocusPoints.front();
        frontFocusPoints.erase(frontFocusPoints.begin());

        return p;
    }
};


#endif