#ifndef SEARCHALGO_H_
#define SEARCHALGO_H_

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


class searchAlgo 
{
protected:
    std::vector <point> frontFocusPoints;


    virtual bool checkNeighbours(point pCenter) 
    {
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

    virtual bool checkPoint(point p) 
    {
        switch (dataSet[p.x][p.y])
        {
        case fs_space:
            dataSet[p.x][p.y] = fs_beenHere;
            frontFocusPoints.push_back(p);
            break;
        case fs_point_end:
            std::cout << "Found the End!\n";
            return true;
        }
        return false;
    }

    virtual point getNextFocusPoint() = 0;

    bool pointsEqual(point p1, point p2) {
        return (p1.x != p2.x || p1.y != p2.y);
    }

public:

    virtual void start()
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