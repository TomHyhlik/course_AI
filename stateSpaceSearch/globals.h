#ifndef GLOBALS_H_
#define GLOBALS_H_

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <memory>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>   

#define FASTMODE


#ifdef FASTMODE
    #define SHOW     dataSet_print();
#else
    #define SHOW     dataSet_print(); std::cin.get();
#endif


int ctr_iterations;

struct point {
    int x, y;
};

#define SIZE_MAXROWS            1000
#define SIZE_MAXCOLUMNS         1000

#define SIZE_FILEMAX            16384

char dataSet[SIZE_MAXROWS][SIZE_MAXCOLUMNS];

point point_start;
point point_end;

#define FILEPATH    "./dataset/"

///////////////////////////////////////////////////////
#define fs_space        ' '
#define fs_wall         'X'
#define fs_point_start  'S'
#define fs_point_end    'E'
#define fs_beenHere     '#'
#define fs_focus        'o'
#define fs_resultPath   '.'




///////////////////////////////////////////////////////
bool readFile(std::string fileName)
{
    std::string line;
    std::ifstream myfile (fileName);
    if (myfile.is_open())
    {
        memset(&dataSet, 0, SIZE_MAXROWS * SIZE_MAXCOLUMNS);
        int currentRow = 0;
        while ( std::getline (myfile,line))
        {
            // std::cout << line << '\n';

            if (line.at(0) == fs_wall) {
                memcpy(dataSet[currentRow], line.c_str(), strlen(line.c_str()));
                currentRow++;

            } else {
                sscanf(line.c_str(), "start %d, %d", &point_start.y, &point_start.x);
                sscanf(line.c_str(), "end %d, %d", &point_end.y, &point_end.x);
            }
        }
        myfile.close(); 
        return true;
    }
    else return false;
}

///////////////////////////////////////////////////////
void dataSet_print()
{
    std::cout << "__________________________________\n";

    int currentRow = 0;
    while (*dataSet[currentRow] != 0) {
        printf("%s\n", dataSet[currentRow]);
        currentRow++;
    }

}








#endif