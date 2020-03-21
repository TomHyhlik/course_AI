#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <memory>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>    

#define SHOW     dataSet_print(); std::cin.get();
// #define SHOW     dataSet_print();


struct point
{
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

#define FILE        "./dataset/36.txt"
// #define FILE        "./dataset/72.txt"


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
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
class searchAlgo 
{

protected:

    virtual void start() = 0;

};
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
class RandomSearch : public searchAlgo
{
    std::vector <point> frontFocusPoints;


    bool checkNeighbours(point pCenter) 
    {
        point pointsToCheck[] = {
            {pCenter.x - 1, pCenter.y},
            {pCenter.x, pCenter.y - 1},
            {pCenter.x, pCenter.y + 1},
            {pCenter.x + 1, pCenter.y},
        };

        for (int i = 0; i < 4; i++) {
            if (checkPoint(pointsToCheck[i])) return true;

        }

        return false;
    }

    bool checkPoint(point p) 
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

    point getFocusPoint_random()
    {
        // int indexOfSelectedPoint = 73 % frontFocusPoints.size();
        int indexOfSelectedPoint = rand() % frontFocusPoints.size();


        point p = frontFocusPoints.at(indexOfSelectedPoint);
        frontFocusPoints.erase(frontFocusPoints.begin()+indexOfSelectedPoint);

        return p;
    }


public:

    void start()
    {
        srand (time(NULL));

        point point_focus = point_start;
        while (true) 
        {
            if (checkNeighbours(point_focus)) break;

            SHOW

            point_focus = getFocusPoint_random();
            dataSet[point_focus.x][point_focus.y] = fs_focus;

            SHOW

        }
        std::cout << "Finish!\n\n";
    }
};
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
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

    RandomSearch obj;
    obj.start();


    std::cout << "ApEnd...........................\n";
    return 0;
}

///////////////////////////////////////////////////////