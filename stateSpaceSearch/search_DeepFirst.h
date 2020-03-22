#ifndef SEARCH_DEEPFIRST_H_
#define SEARCH_DEEPFIRST_H_


#include "globals.h"
#include "searchAlgo.h"


class search_DeepFirst : public searchAlgo
{
    point getNextFocusPoint() override
    {
        point p = frontFocusPoints.back();
        frontFocusPoints.pop_back();

        return p;
    }
};



#endif