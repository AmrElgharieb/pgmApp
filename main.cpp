/* ************************************************************************** */
/* ************************ HEADER FILES INCLUDES **************************  */
/* ************************************************************************** */
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <dirent.h>
#include <vector>
#include "pgm.h"
/***************************************************************************/
bool endsWith(std::string const& str, std::string const& suffix);
std::vector<std::string> readDirectory(const char* path, const char* suffix);
/***************************************************************************/
int main(int argc, char** argv)
{ 
	pgm resultPgm;
	pgm tempPgm;
	std::string filePath;
	const char* dirPath =  argv[1];

	/* reading the input files that ends with .pgm extension */
	std::vector<std::string> fileList = readDirectory(dirPath, ".pgm");

	/* check if files were found */
	if (fileList.size() > 0)
	{
		filePath = std::string(dirPath) + "/" + fileList[0];
		/* read the first pgm file */
		resultPgm.readPgm(filePath);

		for (unsigned int i = 1; i < fileList.size(); i++)
		{
			filePath = std::string(dirPath) + "/" + fileList[i];
			/* read the pgm file */
			tempPgm.readPgm(filePath);
			/* add the pgm file pixels to the result object */
			resultPgm.addPgm(&tempPgm);
		}

		/* calculate the average */
		resultPgm.pgmDivide(fileList.size());
		filePath = std::string(dirPath) + "/" + "average.pgm";
		
		/* save the average pgm file */
		resultPgm.writePgm(filePath);
	}
	else
	{
		std::cout << "No pgm files are found in the directory" << std::endl;
	}
	std::cout << "Finished!" << std::endl;
	return 0;
}
/******************************************************************************/
/* !Description : This function is used to check if a string ends with        */
/*				   another suffix string                                      */
/* !Input       : str -> the string shat shall be checked                     */
/* !Input       : suffix -> the suffix string                                 */
/* !Output      : bool									                      */
/******************************************************************************/
bool endsWith(std::string const& str, std::string const& suffix)
{
	if (str.length() < suffix.length())
	{
		return false;
	}
	return str.compare(str.length() - suffix.length(), suffix.length(), suffix) == 0;
}
/******************************************************************************/
/* !Description : This function shall read the files in a given folder        */
/* !Input       : path -> string that represents the full path                */
/*						  for the input files                                 */
/* !Output      : vector containing a list of  the name of the input files    */
/******************************************************************************/
std::vector<std::string> readDirectory(const char* path, const char* suffix)
{
	struct dirent* dir;
	DIR* directory = opendir(path);
	std::vector<std::string> v;

	if (directory)
	{
		while ((dir = readdir(directory)) != NULL)
		{
			std::string name(dir->d_name);

			if (endsWith(name, (std::string)suffix) && (name != "average.pgm"))
			{
				v.push_back(name);
			}
		}
		closedir(directory);
	}
	else
	{
		std::cerr << "The Directory does not exist " << path << std::endl;
	}
	return v;
}
/***************************************************************************/