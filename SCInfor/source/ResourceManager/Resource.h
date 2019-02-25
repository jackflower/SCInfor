//  _________________________________________________________
// | Resource.h - definicja abstrakcyjnego interfejsu        |
// | Jack Flower - September 2012                            |
// |_________________________________________________________|
//

#ifndef H_IRESOURCE_JACK
#define H_IRESOURCE_JACK

#include <string>
#include <map>
#include "../RTTI/RTTI.h"

namespace resource
{
	typedef unsigned long long ResourceHandle; //uchwyt zasobu - bardzo duża liczba
	#define InvalidResourceHandle 0	//definicja - makro (zamiast pisać 0)

	///
	///Klasa reprezentuje abstrakcyjny interfejs
	///
	class Resource
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		Resource();

		///
		///Destruktor wirtualny
		///
		virtual ~Resource();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Wirtualna metoda ładująca zasób - implementacje w klasach pochodnych
		///
		///@param file_name - stała referencja na nazwę pliku
		///
		virtual bool load(const std::string & file_name) = 0;

		///
		///Wirtualna metoda zwalniająca zasób - implementacje w klasach pochodnych
		///
		virtual void drop() = 0;

	};
}//namespace resource
#endif //H_IRESOURCE_JACK
