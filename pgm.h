/* ************************************************************************** */
/* ************************ HEADER FILES INCLUDES **************************  */
/* ************************************************************************** */
#include <fstream>
#include <sstream>
#include <cmath>
/***************************************************************************/
#pragma once
class pgm
{
	private:
		unsigned int width;
		unsigned int height;
		unsigned int maxValue;
		unsigned int** dataPtr;
		std::string magicNum;
	public:
		void setWidth(unsigned int width);
		void setHeight(unsigned int height);
		void setMaxValue(unsigned int maxValue);
		void setMagicNum(std::string magicNum);
		unsigned int getWidth(void);
		unsigned int getHeight(void);
		unsigned int getMaxValue(void);
		std::string getMagicNum(void);

		pgm();
		pgm(unsigned int height, unsigned int width);

		void addPgm(pgm* inputPgm);

		void readPgm(std::string fileName);
		void writePgm(std::string fileName);

		pgm operator + (pgm const& obj);
		void pgmDivide(const unsigned int divisor);

		~pgm();
};
/***************************************************************************/