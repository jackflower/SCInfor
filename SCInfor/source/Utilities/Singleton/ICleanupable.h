/*
 _____________________________________________________________
| ICleanupable.h - definicja klasy abstrakcyjnej - interface. |
| Jack Flower - April 2012.                                   |
|_____________________________________________________________|

*/

#ifndef H_ICLEANUPABLE_JACK
#define H_ICLEANUPABLE_JACK

///
///Klasa abstrakcyjna reprezentuje interfejs zarz¹dzaj¹cy obiektami klas typu Singleton
///
class ICleanupable
{
	///
	///Friendship declaration
	///
	friend class CSingletonCleaner;

protected:

	///
	///Wirtualny interfejs
	///
	virtual void cleanup() {};

	///
	///Destruktor Wirtualny
	///
	virtual ~ICleanupable(){};
};
#endif //H_ICLEANUPABLE_JACK