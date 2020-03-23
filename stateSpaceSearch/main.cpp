#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "globals.h"
#include "searchAlgo.h"

#include  "search_Random.h"
#include "search_BreadthFirst.h"
#include "search_DeepFirst.h"
#include "search_Greedy.h"
#include "search_Dijkstr.h"
#include "search_aStar.h"

// #define FILE        "0.txt"
#define FILE        "36.txt"
// #define FILE        "72.txt"

// #define FILE        "00_11_11_1550177690.txt"



///////////////////////////////////////////////////////
int main(void)
{
    std::cout << "ApStart.........................\n";

    srand (time(NULL));

    if (!readFile(FILEPATH + std::string(FILE))) {
        std::cout << "Failed to open file\n";
        return 1;
    }

    printf("Point_start: %d, %d\n", point_start.x, point_start.y);
    printf("Point_end: %d, %d\n", point_end.x, point_end.y);

    SHOW

    dataSet[point_start.x][point_start.y] = fs_point_start;
    dataSet[point_end.x][point_end.y] = fs_point_end;

    SHOW

    ctr_iterations = 0;


    // search_Random obj;
    // search_BreadthFirst obj;
    // search_DeepFirst obj;
    // search_Greedy obj;
    // search_Dijkstr obj;
    search_aStar obj;


    obj.start();


    std::cout << "Iterations: " << ctr_iterations << "\n";

    std::cout << "ApEnd...........................\n";
    return 0;
}

///////////////////////////////////////////////////////