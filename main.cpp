/***************************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
/***************************************************************************/
using namespace std;
/***************************************************************************/
int main()
{
    int row = 0, col = 0, num_of_rows = 0, num_of_cols = 0, bits;
    ifstream infile("temp2.pgm");
    stringstream ss;
    string inputLine = "";  
    /***************************************************************************/
    getline(infile, inputLine);      // read the first line : P2
    if (inputLine.compare("P2") != 0) 
        cerr << "Version error" << endl;
    cout << "Version : " << inputLine << endl;

    ss << infile.rdbuf();   /* read width and height */
    ss >> num_of_cols >> num_of_rows;
    cout << num_of_cols << " columns and " << num_of_rows << " rows" << endl;
    
    int max_val;  
    ss >> max_val;
    cout << "Max value is " << max_val << endl;
    //ss.ignore();
    /***************************************************************************/
    /***************************************************************************/
    /***************************************************************************/
    int pixel;
    int** pixel_value;

    pixel_value = new int* [num_of_rows];
    for (int i = 0; i < num_of_rows;i++)
        pixel_value[i] = new int[num_of_cols];

    for (row = 0; row < num_of_rows; row++)
    {    
        /* record the pixel values */
        for (col = 0; col < num_of_cols; col++)
        {
            ss >> pixel;
            pixel_value[row][col] = pixel;
            //cout << " " << pixel;
        }
        //cout << endl ;
    }
    cout << endl;


    /* output the the pixels to the pgm file */
    ofstream output1("output.pgm");  
    for (int k = 0; k < num_of_rows; k++)
    {
        for (int r = 0; r < num_of_cols; r++)
        {
            output1 << pixel_value[k][r] << " ";
        }
        output1 << endl;
    }


    infile.close();
    return 0;
}