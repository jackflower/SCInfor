//  _______________________________________________________
// | ICleanupable.h - abstract class definition - inteface |
// | Jack Flower - December 2012                           |
// |_______________________________________________________|
//

#ifndef H_ICLEANUPABLE_JACK
#define H_ICLEANUPABLE_JACK

///
///Klasa abstrakcyjna reprezentuje interfejs zarządzający obiektami klas typu CSingleton
///
class ICleanupable
{
	///
	///Friendship declaration
	///
	friend class SingletonCleaner;

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