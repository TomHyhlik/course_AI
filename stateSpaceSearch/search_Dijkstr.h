#ifndef SEARCH_DIJKSTR_H_
#define SEARCH_DIJKSTR_H_


#include "globals.h"
#include "searchAlgo.h"



class search_Dijkstr : public searchAlgo
{
    std::vector <std::vector <point>> frontFocusRoutes;


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


public:
    virtual void start() override
    {
        frontFocusRoutes.push_back({point_start});
                
        while (!pointsEqual(frontFocusRoutes.front().back(), point_end)) 
        {
            if (checkRoute(frontFocusRoutes.front())) break;

            SHOW

            frontFocusRoutes.erase(frontFocusRoutes.begin());
            setPointVal(frontFocusRoutes.front().back(),fs_focus);

            SHOW
        }

        frontFocusRoutes.front().erase(frontFocusRoutes.front().begin());
        pasteRoute(frontFocusRoutes.front());

        SHOW

        std::cout << "Finish!\n\n";
    }

};

#endif