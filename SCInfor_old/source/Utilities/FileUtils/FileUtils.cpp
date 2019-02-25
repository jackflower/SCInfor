/*
 __________________________________________________
| FileUtils.cpp - modu³ funkcji do obs³ugi plików. |
| Jack Flower September 2012.                      |
|__________________________________________________|

*/

#include "FileUtils.h"
#include <fstream>
#include <stdio.h>
#include <sys/stat.h>

using namespace fileutils;

//Funkcja zwraca rozmiar pliku
size_t fileutils::GetFileSize(const char* filename)
{
    FILE * pFile;
    long size;

    pFile = fopen(filename,"rb");
    if (!pFile)
		return 0;
  
    fseek(pFile, 0, SEEK_END);
    size = ftell(pFile);
    fclose(pFile);
  
    return size;
}

//Funkcja zwraca rozmiar pliku
size_t fileutils::GetFileSize(const std::string & filename)
{
	return GetFileSize(filename.c_str());
}

//Funkcja zwraca rozmiar pliku
bool fileutils::FileExists(const char* filename)
{
	struct stat stFileInfo; 
	return (0 == stat(filename, &stFileInfo)); 
}

//Funkcja sprawdza, czy plik o podanej nazwie istnieje
bool fileutils::FileExists(const std::string & filename)
{
    return FileExists(filename.c_str());
}

//Funkcja odczytuje dane z pliku
std::string fileutils::ReadFromFile(const std::string & filename)
{
	FILE *file = fopen(filename.c_str(), "rb");
	if (!file) return "";

	fseek(file, 0, SEEK_END);
	size_t size = ftell(file);
	fseek(file, 0, SEEK_SET);
	char* buf = new char[size + 1];
	buf[size] = '\0';
	if (fread(buf, 1, size, file) != size)
		printf("Error while reading %s file\n", filename.c_str());
		//fprintf(stderr, "Error while reading %s file\n", filename.c_str());
	fclose(file);

	std::string str(buf);
	delete[] buf;
	return str;
}

//Funkcja zapisuje dane do pliku
bool fileutils::WriteToFile(const std::string & filename, const std::string & contents)
{
	FILE *file = fopen(filename.c_str(), "wb");
	if (!file) return false;
	if (fwrite(contents.c_str(), 1, contents.size(), file) != contents.size())
	{
		printf("Error while writing to %s file\n", filename.c_str());
		//fprintf(stderr, "Error while writing to %s file\n", filename.c_str());
		fclose(file);
		return false;
	}
	fclose(file);
	return true;
}

//Metoda tworzy katalog
void fileutils::CreateDir(const std::string & filename)
{
	return CreateDir(filename.c_str());
}

//Metoda tworzy katalog
void fileutils::CreateDir(const char* filename)
{
	//linker krzycza³...
}