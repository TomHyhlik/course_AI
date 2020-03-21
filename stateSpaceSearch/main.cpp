#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <memory>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define SHOW     dataSet_print(); std::cin.get();


struct point 
{
    int x, y;

    point(int val1, int val2) : x(val1), y(val2) {}
    point() { x = y = 0; }

};

#define SIZE_MAXROWS            100
#define SIZE_MAXCOLUMNS         100

char dataSet[SIZE_MAXROWS][SIZE_MAXCOLUMNS];

point point_start;
point point_end;

///////////////////////////////////////////////////////
#define fs_space        ' '
#define fs_wall         'X'
#define fs_point_start  'S'
#define fs_point_end    'E'
#define fs_beenHere     '.'
#define fs_focus        '0'

///////////////////////////////////////////////////////
void readFile()
{
   std::ifstream file("./dataset/4.txt", std::ios::binary);
   std::streambuf* raw_buffer = file.rdbuf();
   char* block = new char[1024];
   raw_buffer->sgetn(block, 1024);

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
            sscanf(pch, "start %d, %d", &point_start.x, &point_start.y);
            sscanf(pch, "end %d, %d", &point_end.x, &point_end.y);
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
///////////////////////////////////////////////////////
void do_RandomSearch()
{
    point point_focus = point_start;

    while ( point_focus.x != point_end.x &&
            point_focus.y != point_end.y) {

        


        SHOW
    }
}

///////////////////////////////////////////////////////
int main(void)
{
    std::cout << "ApStart.........................\n";

    readFile();

    printf("Point_start: %d, %d\n", point_start.x, point_start.y);
    printf("Point_end: %d, %d\n", point_end.x, point_end.y);

    SHOW

    dataSet[point_start.x][point_start.y] = fs_point_start;
    dataSet[point_end.x][point_end.y] = fs_point_end;

    SHOW

    do_RandomSearch();



    std::cout << "ApEnd...........................\n";
    return 0;
}

///////////////////////////////////////////////////////