#ifndef SEARCH_GREEDY_H_
#define SEARCH_GREEDY_H_

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <memory>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>    
#include <math.h>

#include "globals.h"
#include "searchAlgo.h"



class search_Greedy : public searchAlgo
{

    float getDistanceToEnd(point p) {
        int dist_x = p.x - point_end.x;
        int dist_y = p.y - point_end.y;

        float d = sqrt((dist_x*dist_x) + (dist_y*dist_y));

        printf("P_dist(%d, %d) = %f\n", p.x, p.y, d);

        return d;
    }

    point getNextFocusPoint() override
    {
        float shortestDist_final = 0x8FFFFFFF;
        int p_index = 0;

        /* get the closest point to */
        for (int i = 0; i < frontFocusPoints.size(); i++) {
            float d = getDistanceToEnd(frontFocusPoints.at(i));
            if (d < shortestDist_final) {
                shortestDist_final = d;
                p_index = i;
            }
        }
        point p_closestToEnd = frontFocusPoints.at(p_index);
        frontFocusPoints.erase(frontFocusPoints.begin() + p_index);

        // printf("Choosed point (%d, %d) = %f\n", p_closestToEnd.x, p_closestToEnd.y, shortestDist_final);


        return p_closestToEnd;
    }
};


#endif