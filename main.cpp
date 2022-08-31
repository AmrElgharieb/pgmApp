/***************************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "pgm.h"
/***************************************************************************/
using namespace std;
/***************************************************************************/
int main()
{
    int fileNum = 3;
    string fileName[3] = {"temp.pgm", "temp.pgm", "temp.pgm"};
    pgm image1(fileName[0]);
    pgm image2(fileName[1]);


    pgm Newimage = image1 + image2;

    for(int i = 2; i < fileNum; i++)
    {
        pgm image(fileName[i]);
        Newimage = Newimage + image;
    }


    Newimage.WritePgm("OUT.pgm");

    return 0;
}
/***************************************************************************/