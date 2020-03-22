#ifndef SEARCH_DIJKSTR_H_
#define SEARCH_DIJKSTR_H_


#include "globals.h"
#include "searchAlgo.h"



class search_Dijkstr : public searchAlgo
{
    std::vector <std::vector <point>> routes;


    // bool checkNeighbours(point pCenter) override
    // {
    //     std::vector <point> pointsToCheck = {
    //         {pCenter.x - 1, pCenter.y},
    //         {pCenter.x, pCenter.y - 1},
    //         {pCenter.x, pCenter.y + 1},
    //         {pCenter.x + 1, pCenter.y},
    //     };

    //     while (!pointsToCheck.empty()) {
    //         int indexOfSelectedPoint = rand() % pointsToCheck.size();
    //         bool foundEnd = checkPoint(pointsToCheck.at(indexOfSelectedPoint));
    //         if (foundEnd) return true;

    //         pointsToCheck.erase(pointsToCheck.begin()+indexOfSelectedPoint);
    //     }
    //     return false;
    // }

    int getIndexOf(point p_searched, std::vector <point> r) 
    {
        int index = -1;
        for (int i = 0; i < r.size();  i++) {
            if (pointsEqual(r.at(i), p_searched)) {
                index = i;
                break;
            }
        }
        return index;
    }


    void checkShortestRoute(point p)
    {
       for (int i = 0; i < routes.size(); i++) 
        {
            int dist = getIndexOf(p, routes.at(i));
            if (dist != -1) 
            {

            }


        }
    }



    virtual bool checkPoint(point p) override
    {
        switch (dataSet[p.x][p.y])
        {
        case fs_space:
        {
            dataSet[p.x][p.y] = fs_beenHere;

            int n = routes.size();
            routes.reserve(n + 1);
            routes.at(n).push_back(p);

            break;
        }
        case fs_focus:
        // case fs_beenHere:
            // checkShortestRoute(p);
            break;
        case fs_point_end:
            // checkShortestRoute(p);

            std::cout << "Found the End!\n";
            return true;
        }
        return false;
    }


    point getNextFocusPoint() override
    {
        // point p = frontFocusPoints.front();
        point p = routes.front().back();

        // frontFocusPoints.erase(frontFocusPoints.begin());
        routes.front().erase(routes.front().begin());
        return p;
    }

public:
    virtual void start() override
    {
        point point_focus = point_start;
        while (pointsEqual(point_focus, point_end)) 
        {
            if (checkNeighbours(point_focus)) break;

            SHOW

            point_focus = getNextFocusPoint();
            dataSet[point_focus.x][point_focus.y] = fs_focus;

            SHOW

        }
        std::cout << "Finish!\n\n";
    }
};




#endif