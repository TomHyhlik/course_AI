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
            // std::cout << "Found the End!\n";
            return true;
        }
        return false;
    }

    virtual point getNextFocusPoint() { return {0,0}; }

    bool pointsEqual(point p1, point p2) {
        return (p1.x == p2.x && p1.y == p2.y);
    }

    void setPointVal(point p, char val) {
        dataSet[p.x][p.y] = val;
    }

    void pasteRoute(std::vector <point> r) {
        for (const point& p : r) {
            setPointVal(p, fs_resultPath);
        }
    }

    int getIndexOf(point p_searched, std::vector <point> r) 
    {
        for (int i = 0; i < r.size();  i++) {
            if (pointsEqual(r.at(i), p_searched)) {
                return i;
            }
        }
        return -1;
    }

    float getDistanceToEnd(point p) {
        int dist_x = p.x - point_end.x;
        int dist_y = p.y - point_end.y;

        float d = sqrt((dist_x*dist_x) + (dist_y*dist_y));

        printf("P_dist(%d, %d) = %f\n", p.x, p.y, d);

        return d;
    }



public:

    virtual void start()
    {
        point point_focus = point_start;
        while (!pointsEqual(point_focus, point_end)) 
        {
            ctr_iterations++;

            if (checkNeighbours(point_focus)) break;

            SHOW

            point_focus = getNextFocusPoint();
            dataSet[point_focus.x][point_focus.y] = fs_focus;

            SHOW

        }
    }

};



#endif