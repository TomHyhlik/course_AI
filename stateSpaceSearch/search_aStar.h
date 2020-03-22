#ifndef SEARCH_ASTAR_H_
#define SEARCH_ASTAR_H_


#include "globals.h"
#include "searchAlgo.h"



class search_aStar : public searchAlgo
{
    std::vector <std::vector <point>> frontFocusRoutes;
    int currentRouteIndex;

    bool checkRoute(std::vector <point> r)
    {
        point pCenter = r.back();

        std::vector <point> pointsToCheck = {
            {pCenter.x - 1, pCenter.y},
            {pCenter.x, pCenter.y - 1},
            {pCenter.x, pCenter.y + 1},
            {pCenter.x + 1, pCenter.y},
        };

        while (!pointsToCheck.empty()) {
            int indexOfSelectedPoint = rand() % pointsToCheck.size();
            bool foundEnd = checkPoint(pointsToCheck.at(indexOfSelectedPoint));
            if (foundEnd) return true;

            pointsToCheck.erase(pointsToCheck.begin()+indexOfSelectedPoint);
        }
        return false;
    }

    bool checkPoint(point p) override
    {
        switch (dataSet[p.x][p.y])
        {
        case fs_space:
        {
            setPointVal(p, fs_beenHere);
            
            std::vector <point> r = frontFocusRoutes.front();
            r.push_back(p);

            frontFocusRoutes.push_back(r);

            break;
        }
        case fs_point_end:
            std::cout << "Found the End!\n";
            return true;
        }
        return false;
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


public:
    virtual void start() override
    {
        frontFocusRoutes.push_back({point_start});
        currentRouteIndex = 0;
                
        while (!pointsEqual(frontFocusRoutes.front().back(), point_end)) 
        {
            if (checkRoute(frontFocusRoutes.at(currentRouteIndex))) break;

            SHOW

            frontFocusRoutes.erase(frontFocusRoutes.begin() + currentRouteIndex);






            
            setPointVal(frontFocusRoutes.front().back(),fs_focus);

            SHOW
        }

        frontFocusRoutes.at(currentRouteIndex).erase(frontFocusRoutes.at(currentRouteIndex).begin());
        pasteRoute(frontFocusRoutes.at(currentRouteIndex));

        SHOW

        std::cout << "Finish!\n\n";
    }

};

#endif