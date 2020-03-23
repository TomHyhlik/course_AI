#ifndef SEARCH_DIJKSTR_H_
#define SEARCH_DIJKSTR_H_


#include "globals.h"
#include "searchAlgo.h"



class search_Dijkstr : public searchAlgo
{
protected:
    std::vector <std::vector <point>> frontFocusRoutes;
    int route_focus_index;


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
            
            std::vector <point> r = frontFocusRoutes.at(route_focus_index);
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

    virtual int getNextRouteIndex()
    {

        return 0;
    }

public:
    virtual void start() override
    {
        frontFocusRoutes.push_back({point_start});

        route_focus_index = 0;
                
        while (!pointsEqual(frontFocusRoutes.at(route_focus_index).back(), point_end)) 
        {
            ctr_iterations++;

            if (checkRoute(frontFocusRoutes.at(route_focus_index))) break;

            SHOW

            frontFocusRoutes.erase(frontFocusRoutes.begin() + route_focus_index);
            route_focus_index = getNextRouteIndex();
            setPointVal(frontFocusRoutes.at(route_focus_index).back(),fs_focus);

            SHOW
        }

        frontFocusRoutes.at(route_focus_index)
            .erase(frontFocusRoutes.at(route_focus_index).begin());
        pasteRoute(frontFocusRoutes.at(route_focus_index));

        SHOW

    }

};

#endif