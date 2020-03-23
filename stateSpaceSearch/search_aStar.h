#ifndef SEARCH_ASTAR_H_
#define SEARCH_ASTAR_H_


#include "globals.h"
#include "search_Dijkstr.h"



class search_aStar : public search_Dijkstr
{

    int getNextRouteIndex() override
    {
        float shortestDist_final = 0x8FFFFFFF;
        int r_index = 0;

        /* get the closest point to */
        for (int i = 0; i < frontFocusRoutes.size(); i++) {
            float d = getDistanceToEnd(frontFocusRoutes.at(i).back());
            if (d < shortestDist_final) {
                shortestDist_final = d;
                r_index = i;
            }
        }
        return r_index;
    }
};

#endif