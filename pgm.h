#include <sstream>
#include <sstream>

#pragma once
class pgm
{
	private:
		int Width;
		int Height;
		int MaxValue;
		int MagicNum;
		int* DataPtr;
	public:
		pgm(int width, int height);
		void ReadPgm(std::stringstream ss);

		void SetWidth(int Width);
		void SetHeight(int Height);
		void SetMaxValue(int MaxValue);
		void SetMagicNum(int MagicNum);

		int GetWidth(void);
		int GetHeight(void);
		int GetMaxValue(void);
		int GetMagicNum(void);
};