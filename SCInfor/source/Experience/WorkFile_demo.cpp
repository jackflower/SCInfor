#include <iostream>
#include <fstream>
#include <string>
#include<vector>

int main()
{

	std::fstream plik_out;
	plik_out.open("data_out.txt", std::ios::out);
	plik_out << "Jacek" << std::endl;
	plik_out.close();
	

	std::string name;
	std::string kod;
	int first = 0;
	int secound = 0;

	class Dimnention//klasa trzyma rozmiar obiektu
	{
	public:
		int first = 0;
		int secound = 0;
	};

	const int pairs = 2;
	
	class MyData
	{
	public:
		std::string name;
		std::string kod;
		Dimnention dimention[pairs] = { 0 };
		void zerowanie()
		{
			name = "";
			kod = "";
			for(int i = 0; i< pairs; i++)
			{
				dimention[i].first = 0;
				dimention[i].secound = 0;
			}
		}
	};


	MyData dane;
	std::vector< MyData> myData;

	std::fstream plik_in; // odczyt pliku
	plik_in.open("data_in.txt", std::ios::in);

	while (plik_in)
	{
		dane.zerowanie();

		plik_in >> name;
		plik_in >> kod;
		dane.name = name;
		dane.kod = kod;

		for (int i = 0; i< pairs; i++)
		{
			plik_in >> first;
			plik_in >> secound;
			dane.dimention[i].first = first;
			dane.dimention[i].secound = secound;
		}

		if (!plik_in) break;

		myData.push_back(dane);
	}
	plik_in.close();

	int warta = 0;


	getchar();
	return 0;
}