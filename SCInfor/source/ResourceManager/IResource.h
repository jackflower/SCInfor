//  __________________________________________________________
// | IResource.h - definicja abstrakcyjnego interfejsu        |
// | Jack Flower - September 2012                             |
// |__________________________________________________________|
//

#ifndef H_IRESOURCE_JACK
#define H_IRESOURCE_JACK

#include <string>
#include <map>
#include "../RTTI/RTTI.h"

namespace resource
{
	typedef unsigned long long	ResourceHandle;			//uchwyt zasobu - bardzo du¿a liczba
	#define						InvalidResourceHandle 0	//definicja - makro (zamiast pisaæ 0)

	///
	///Klasa reprezentuje abstrakcyjny interfejs
	///
	class IResource
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		IResource();

		///
		///Destruktor wirtualny
		///
		virtual ~IResource();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Wirtualna metoda ³aduj¹ca zasób - implementacje w klasach pochodnych
		///
		///@param &file_name - sta³a referencja na nazwê pliku
		///
		virtual bool Load(const std::string &file_name) = 0;

		///
		///Wirtualna metoda zwalniaj¹ca zasób - implementacje w klasach pochodnych
		///
		virtual void Drop() = 0;

	};
}//namespace resource
#endif //H_IRESOURCE_JACK
