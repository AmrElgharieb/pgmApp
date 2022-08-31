/***************************************************************************/
#include "pgm.h"
/***************************************************************************/
using namespace std;
/***************************************************************************/
 pgm::pgm(std::string FileName)
{
	int rows, cols;
	int rowIndex, colIndex, pixel;

	stringstream ss;
	string inputLine = "";
	ifstream infile(FileName);

	getline(infile, inputLine);      /* read the first line : P2 */
	if (inputLine.compare("P2") != 0)
		cerr << "Version error" << endl;
	cout << "Version : " << inputLine << endl;

	ss << infile.rdbuf();   /* read width and height */
	ss >> cols >> rows;
	cout << cols << " columns and " << rows << " rows" << endl;

	int MaxVal;
	ss >> MaxVal;
	cout << "Max value is " << MaxVal << endl;
	//ss.ignore();


	/* updating the pgm properties */
	this->Height = rows;
	this->Width = cols;
	this->MaxValue = MaxVal;
	this->DataPtr = new int* [rows];
	for (int i = 0; i < rows;i++)
		DataPtr[i] = new int[cols];

	/* updating the pgm pixels */
	for (rowIndex = 0; rowIndex < (this->Height); rowIndex++)
	{
		for (colIndex = 0; colIndex < (this->Width); colIndex++)
		{
			ss >> pixel;
			this->DataPtr[rowIndex][colIndex] = pixel;
			std::cout << " " << pixel;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	infile.close();
}
/***************************************************************************/
 pgm::pgm(int height = 0, int width = 0)
 {
	 this->Height = height;
	 this->Width = width;

	 this->DataPtr = new int* [height];
	 for (int i = 0; i < height;i++)
	 {
		 DataPtr[i] = new int[width];
	 }
 };
 /***************************************************************************/
 void pgm::WritePgm(std::string FileName)
 {
	 int row, col;
	 std::ofstream outfile(FileName);

	 outfile << this->MagicNum << endl;
	 outfile << this->Width << " " << this->Height << endl;
	 outfile << this->MaxValue << endl;

	 for (row = 0; row < (this->Height); row++)
	 {
		 for (col = 0; col < (this->Width); col++)
		 {
			 outfile << this->DataPtr[row][col] << " ";   // check if endl is needed
		 }
		 outfile << std::endl;
	 }
	 outfile.close();
 };
/***************************************************************************/
 pgm pgm::operator+(pgm const& InputImage)
 {
	 int row, col;
	 pgm result(this->Height, this->Width);

	 for (int row = 0; row < this->Height; row++)
	 {
		 for (int col = 0; col < this->Width; col++)
		 {
			 result.DataPtr[row][col] = this->DataPtr[row][col] + InputImage.DataPtr[row][col];
		 }
		 result.SetMaxValue(this->MaxValue);
		 result.SetMagicNum("P2");
	 }
	 return result;
 }
 /***************************************************************************/
 pgm::~pgm()
 {
	 int row;
	 if (DataPtr != NULL)
	 {
		 //for (row = 0; row < (this->Height); row++)
			// delete DataPtr[row];
	 }
 }
/***************************************************************************/
void pgm::SetWidth(int Width)
{
	this->Width = Width;
};
/***************************************************************************/
void pgm::SetHeight(int Height)
{
	this->Height = Height;
};
/***************************************************************************/
void pgm::SetMaxValue(int MaxValue)
{
	this->MaxValue = MaxValue;
}
/***************************************************************************/
void pgm::SetMagicNum(std::string MagicNum)
{
	this->MagicNum = MagicNum;
};
/***************************************************************************/
/***************************************************************************/
int pgm::GetWidth(void)
{
	return this->Width;
};
/***************************************************************************/
int pgm::GetHeight(void)
{
	return this->Height;
};
/***************************************************************************/
int pgm::GetMaxValue(void)
{
	return this->MaxValue;
};
/***************************************************************************/
std::string pgm::GetMagicNum(void)
{
	return this->MagicNum;
};
/***************************************************************************/
/***************************************************************************/
