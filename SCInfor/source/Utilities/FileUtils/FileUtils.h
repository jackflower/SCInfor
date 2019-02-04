/*
 __________________________________________________
| FileUtils.h - modu� funkcji do obs�ugi plik�w.   |
| Jack Flower September 2012.                      |
|__________________________________________________|

*/

#ifndef _H_FILE_UTILS_JACK
#define _H_FILE_UTILS_JACK

#include <string>
#include <fstream>

namespace fileutils
{
	///
	///Funkcja zwraca rozmiar pliku
	///
	///@param *filename - wska�nik na nazw� pliku
	///
	size_t GetFileSize(const char* filename);
	
	///
	///Funkcja zwraca rozmiar pliku
	///
	///@param &filename - sta�a referencja na obiekt std::string
	///
	size_t GetFileSize(const std::string & filename);

	///
	///Funkcja sprawdza, czy plik o podanej nazwie istnieje
	///
	///@param *filename - wska�nik na nazw� pliku
	///
	bool FileExists(const char* filename);

	///
	///Funkcja sprawdza, czy plik o podanej nazwie istnieje
	///
	///@param &filename - sta�a referencja na obiekt std::string
	///
	bool FileExists(const std::string & filename);

	///
	///Funkcja odczytuje dane z pliku
	///
	///@param &filename - sta�a referencja na obiekt std::string
	///
	std::string ReadFromFile(const std::string & filename);

	///
	///Funkcja zapisuje dane do pliku
	///
	///@param &filename - sta�a referencja na obiekt std::string
	///
	///@param &contents - sta�a referencja na obiekt std::string
	///
	bool WriteToFile(const std::string & filename, const std::string & contents);

	///
	///Funkcja zwraca katalog u�ytkownika - zale�nie od platformy
    ///   ~/.GameName				pod linuksem
	///   %APPDATA%/GameName		pod windowsem
	///   ~/Library/GameName		pod macOSem
	///
    const std::string &GetUserDir();//brak implementacji

	// nie moze byc CreateDirectory bo sie gryzie z windows.h

	///
	///Metoda tworzy katalog
	///
	///@param *filename - wska�nik na nazw� pliku
	///
	void CreateDir(const char* filename);
	
	///
	///Metoda tworzy katalog
	///
	///@param &filename - sta�a referencja na obiekt std::string
	///
	void CreateDir(const std::string & filename);

}//namespace fileutils

#endif//_H_FILE_UTILS_JACK

