#include <iostream>
#include <fstream>
#include "bitmap.h"
#include <cstdlib>
#include <vector>
using namespace std;

int main()
{
    Bitmap image;
    vector <vector <Pixel> > toPixelMatrix();
    vector <vector<Pixel> > bmp;
    Pixel rgb;
    string filesave;
    int rows;
    int cols;
    int loop;
    loop = 0;
    char yesno;

    //declares string to be used as input for bmp file
    string Pic;
    //Gathers user input for the name of the .bmp file they wish to convert
    while (loop == 0)
    {
        cout << "Please enter the name of the bmp file you wish to convert to grayscale." << endl;
        cin >> Pic;

        image.open(Pic);
        bool validBmp;
        validBmp = image.isImage();

        if ( validBmp == true )
        {
            bmp = image.toPixelMatrix();
            for ( rows = 0 ; rows < bmp.size() ; rows++ )
            {
                for ( cols = 0 ; cols < bmp[rows].size() ; cols++)
                {
                    rgb = bmp[rows][cols];
                    rgb.red = (rgb.red + rgb.green + rgb.blue)/3;
                    rgb.green = (rgb.red + rgb.green + rgb.blue)/3;
                    rgb.blue = (rgb.red + rgb.green +rgb.blue)/3;
                    bmp[rows][cols] = rgb;
                }
            }
            cout << "Changes complete, would you like to save the grayscale image? (Y/N)" << endl;
            cin >> yesno;
            if (yesno == 'Y' || yesno == 'y')
            {
                cout << "Enter a name to save the file" << endl;
                cin >> filesave;
                image.fromPixelMatrix(bmp);
                image.save(filesave);
            }
            else if (yesno == 'N' || yesno == 'n')
            {

            }

            loop++;
        }
        else if (validBmp == false)
        {
            cout << "Invalid File." << endl;
            loop = 0;
        }

}

  // get the photo and turn the pixels into a matrix
  //loop that goes through every row in the matrix with a loop inside of it that goes through every column in the row
  //average out the red, blue, and green for each input in row 0 within the row loop
  //create a rgb with the average number as all 3 inputs before moving on to the next loop
  //when cols hits its max, ++ rows and redo the loop
  //continue until matrix completes and loops end
  //allow user to save the greyscale photo

  return 0;
}
