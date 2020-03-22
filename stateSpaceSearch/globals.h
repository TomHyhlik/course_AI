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

// #define FASTMODE


#ifdef FASTMODE
    #define SHOW     dataSet_print();
#else
    #define SHOW     dataSet_print(); std::cin.get();
#endif




struct point {
    int x, y;
};

#define SIZE_MAXROWS            1000
#define SIZE_MAXCOLUMNS         1000

#define SIZE_FILEMAX            16384

char dataSet[SIZE_MAXROWS][SIZE_MAXCOLUMNS];

point point_start;
point point_end;

///////////////////////////////////////////////////////
#define fs_space        ' '
#define fs_wall         'X'
#define fs_point_start  'S'
#define fs_point_end    'E'
#define fs_beenHere     '#'
#define fs_focus        '0'
#define fs_resultPath   '.'



// #define FILE        "./dataset/0.txt"
#define FILE        "./dataset/36.txt"
// #define FILE        "./dataset/72.txt"

// #define FILE        "./dataset/00_11_11_1550177690.txt"





///////////////////////////////////////////////////////
void readFile()
{
   std::ifstream file(FILE, std::ios::binary);
   std::streambuf* raw_buffer = file.rdbuf();
   char* block = new char[16384];
   raw_buffer->sgetn(block, 16384);

    // std::cout << block;

    memset(&dataSet, 0, SIZE_MAXROWS * SIZE_MAXCOLUMNS);

    int currentRow = 0;
    
    char *pch;
    pch = strtok (block,"\n");
    while (pch != NULL)
    {
        if (*pch == fs_wall) {
            memcpy(dataSet[currentRow], pch, strlen(pch));
            currentRow++;

        } else {
            sscanf(pch, "start %d, %d", &point_start.y, &point_start.x);
            sscanf(pch, "end %d, %d", &point_end.y, &point_end.x);
        }

        // printf ("%s\n",pch);
        pch = strtok (NULL, "\n");
    }

   delete[] block;
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