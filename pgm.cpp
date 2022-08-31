/* ************************************************************************** */
/* ************************ HEADER FILES INCLUDES **************************  */
/* ************************************************************************** */
#include "pgm.h"
/******************************************************************************/
/* !Description : This function shall updates all the object data given a path*/
/*				  to an onput pgm file                                       */
/* !Input       : fileName -> The path to the input pgm file                  */
/* !Output      : void									                      */
/******************************************************************************/
 void pgm::readPgm(std::string fileName)
{
	unsigned int rows, cols, MaxVal;
	unsigned int rowIndex, colIndex, pixel;
	std::stringstream ss;
	std::string PgmMagicNum = "";
	std::ifstream infile(fileName);

	/* read the pgm file version */
	getline(infile, PgmMagicNum);
	/* read width and height */
	ss << infile.rdbuf();   
	ss >> cols >> rows;
	/* read the max gray value */
	ss >> MaxVal;

	/* updating the pgm properties */
	this->height = rows;
	this->width = cols;
	this->maxValue = MaxVal;
	this->magicNum = PgmMagicNum;

	/* Allocating data for the pixels */
	/* check if no space is allocated (the space might be previously allocated)*/
	if (this->dataPtr == NULL)
	{
		this->dataPtr = new unsigned int* [rows];
		for (rowIndex = 0; rowIndex < rows; rowIndex++)
			dataPtr[rowIndex] = new unsigned int[cols];
	}

	/* updating the pgm pixels */
	for (rowIndex = 0; rowIndex < (this->height); rowIndex++)
	{
		for (colIndex = 0; colIndex < (this->width); colIndex++)
		{
			ss >> pixel;
			this->dataPtr[rowIndex][colIndex] = pixel;
		}
	}
	/* close the pgm file */
	infile.close();
}
 /******************************************************************************/
/* !Description : This function shall save the pgm file to a certain path     */
/* !Input       : fileName -> full path to the output file                    */
/* !Output      : void									                      */
/******************************************************************************/
 void pgm::writePgm(std::string fileName)
 {
	 unsigned int row, col;
	 std::ofstream outfile(fileName);

	 outfile << magicNum << std::endl;
	 outfile << width << " " << height << std::endl;
	 outfile << maxValue << std::endl;

	 for (row = 0; row < height; row++)
	 {
		 for (col = 0; col < width; col++)
		 {
			 outfile << dataPtr[row][col] << " ";
		 }
		 outfile << std::endl;
	 }
	 outfile.close();
 };
 /******************************************************************************/
/* !Description : This shall add another object's data to this object         */
/* !Input       : inputPgm -> the input pgm object                            */
/* !Output      : void									                      */
/******************************************************************************/
 void pgm::addPgm(pgm* inputPgm)
 {
	 unsigned int rowIndex, colIndex;

	 /* updating the pgm pixels */
	 for (rowIndex = 0; rowIndex < height; rowIndex++)
	 {
		 for (colIndex = 0; colIndex < width; colIndex++)
		 {
			 dataPtr[rowIndex][colIndex] += inputPgm->dataPtr[rowIndex][colIndex];
		 }
	 }
 }
 /******************************************************************************/
 /* !Description : constructor for the pgm class to inititalize the class      */
  /*               parameters and allocate the needed memory for the data      */

 /* !Input       : height -> the number of rows of the input image			   */
 /*              : width  -> the number of columns of the input image          */
 /* !Output      : None									                       */
 /******************************************************************************/
 pgm::pgm(unsigned int height, unsigned int width)
 {
	 unsigned int rowIndex;
	 /* read width and height */
	 this->height = height;
	 this->width = width;
	 this->maxValue = 0;
	 this->magicNum = "";
	 this->dataPtr = NULL;

	 /* Allocating data for the pixels */
	 this->dataPtr = new unsigned int* [height];
	 for (rowIndex = 0; rowIndex < height;rowIndex++)
	 {
		 dataPtr[rowIndex] = new unsigned int[width];
	 }
 }
 /******************************************************************************/
 /* !Description : This function is used to add 2 pgm files data using         */
  /*                operator overloading                                       */
 /* !Input       : InputImage -> the input pgm object                          */
 /* !Output      : void									                       */
 /******************************************************************************/
 pgm pgm::operator+(pgm const& inputImage)
 {
	 unsigned int row, col;
	 pgm result(height, width);
	 result.setMaxValue(maxValue);
	 result.setMagicNum(magicNum);

	 /* adding the pixels of the 2 objects */
	 for (row = 0; row < height; row++)
	 {
		 for (col = 0; col < width; col++)
		 {
			 result.dataPtr[row][col] = dataPtr[row][col] + inputImage.dataPtr[row][col];
		 }
	 }
	 return result;
 }
  /******************************************************************************/
 /* !Description : This function shall divide all the pixels by a given number  */
 /* !Input       : divisor -> divisor for the image pixels                      */
 /* !Output      : void									                        */
 /******************************************************************************/
 void pgm::pgmDivide(const unsigned int divisor)
 {
	 unsigned int row, col;

	 for (row = 0; row < height; row++)
	 {
		 for (col = 0; col < width; col++)
		 {
			 dataPtr[row][col] = round((float)dataPtr[row][col]/divisor);
		 }
	 }
 }
 /******************************************************************************/
/* !Description : destructor to free the allocated memory                      */
/* !Iutput      : void									                       */
/* !Output      : void									                       */
/******************************************************************************/
 pgm::~pgm()
 {
	unsigned int rowIndex;
	 if (dataPtr != NULL)
	 {
		 for (rowIndex = 0; rowIndex < height; rowIndex++)
			 if (dataPtr[rowIndex] != NULL)
				delete[] dataPtr[rowIndex];
		 delete [] dataPtr;
	 }
 }
 /******************************************************************************/
/* !Description : default constructor to initialize the class parameters       */
/* !Input       : void									                       */
/* !Output      : void									                       */
/******************************************************************************/
 pgm::pgm()
 {
	 width = 0;
	 height = 0;
	 maxValue = 0;
	 magicNum = "";
	 dataPtr = NULL;
 }
 /******************************************************************************/
 /* !Description : setter for the witdth of the pgm file                       */
 /* !Input       : width -> the width of the input pgm file                    */
 /* !Output      : void									                       */
 /******************************************************************************/
void pgm::setWidth(unsigned int width)
{
	this->width = width;
};
/******************************************************************************/
/* !Description : setter for the height of the pgm file                       */
/* !Input       : height -> the height of the input pgm file                  */
/* !Output      : void									                      */
/******************************************************************************/
void pgm::setHeight(unsigned int height)
{
	this->height = height;
};
/******************************************************************************/
/* !Description : setter for the maxValue of the pgm file                     */
/* !Input       : maxValue -> the maxValue of the input pgm file              */
/* !Output      : void									                      */
/******************************************************************************/
void pgm::setMaxValue(unsigned int maxValue)
{
	this->maxValue = maxValue;
}
/******************************************************************************/
/* !Description : setter for the magicNum of the pgm file                     */
/* !Input       : magicNum -> the magicNum of the input pgm file              */
/* !Output      : void									                      */
/******************************************************************************/
void pgm::setMagicNum(std::string magicNum)
{
	this->magicNum = magicNum;
};
/******************************************************************************/
/******************************************************************************/
/* !Description : getter for the width of the pgm file                        */
/* !Iutput      : void									                      */
/* !Outnput     : the width of the input pgm file                             */
/******************************************************************************/
unsigned int pgm::getWidth(void)
{
	return this->width;
};
/******************************************************************************/
/* !Description : getter for the height of the pgm file                       */
/* !Iutput      : void									                      */
/* !Outnput     : the height of the input pgm file                            */
/******************************************************************************/
unsigned int pgm::getHeight(void)
{
	return this->height;
};
/******************************************************************************/
/* !Description : getter for the maxValue of the pgm file                     */
/* !Iutput      : void									                      */
/* !Outnput     : the maxValue of the input pgm file                          */
/******************************************************************************/
unsigned int pgm::getMaxValue(void)
{
	return this->maxValue;
};
/******************************************************************************/
/* !Description : getter for the magicNum of the pgm file                     */
/* !Iutput      : void									                      */
/* !Outnput     : the magicNum of the input pgm file                          */
/******************************************************************************/
std::string pgm::getMagicNum(void)
{
	return this->magicNum;
};
/******************************************************************************/
