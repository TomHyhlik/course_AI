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


///////////////////////////////////////////////////////
int main(void)
{
    std::cout << "ApStart.........................\n";

    srand (time(NULL));

    readFile();

    printf("Point_start: %d, %d\n", point_start.x, point_start.y);
    printf("Point_end: %d, %d\n", point_end.x, point_end.y);

    SHOW

    dataSet[point_start.x][point_start.y] = fs_point_start;
    dataSet[point_end.x][point_end.y] = fs_point_end;

    SHOW

    // search_Random obj;
    // search_BreadthFirst obj;
    // search_DeepFirst obj;
    // search_Greedy obj;
    search_aStar obj;


    obj.start();

    std::cout << "ApEnd...........................\n";
    return 0;
}

///////////////////////////////////////////////////////