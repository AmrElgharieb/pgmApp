#include <fstream>
#include <sstream>
#include <iostream>  // to be removed

#pragma once
class pgm
{
	private:
		int Width;
		int Height;
		int MaxValue;
		std::string MagicNum;
		int** DataPtr;
	public:
		pgm(std::string FileName);
		pgm(int height, int width);

		void WritePgm(std::string FileName);

		pgm operator + (pgm const& obj);
		~pgm();

		void SetWidth(int Width);
		void SetHeight(int Height);
		void SetMaxValue(int MaxValue);
		void SetMagicNum(std::string MagicNum);

		int GetWidth(void);
		int GetHeight(void);
		int GetMaxValue(void);
		std::string GetMagicNum(void);
};