//  _________________________________
// | RTTI.h - class definition       |
// | Jack Flower October 2012        |
// |_________________________________|
//


#include <string>

#ifndef H_RTTI_JACK
#define H_RTTI_JACK

///
///Klasa reprezentuje funkjonalność zwracającą typ klasy
///
class RTTI 
{

public:

	///
	///Konstruktor
	///
	///@param class_name - stała referencja na nazwę klasy
	///
	RTTI(const std::string & class_name);

	///
	///Konstruktor
	///
	///@param class_name - stała referencja na nazwę klasy
	///
	///@param - baseRTTI - stała referencja na klasę bazową
	///
	RTTI(const std::string & class_name, const RTTI & baseRTTI);

	///
	///Metoda zwraca nazwę klasy
	///
    const std::string & getNameClass() const { return m_class_name; }
    
	///
	///Metoda zwraca flagę
	///
	///@param rtti - stała referencja na obietk klasy RTTI
	///
	bool isExactly(const RTTI & rtti) const { return (this == & rtti); }

	///
	///Metoda zwraca flagę, czy obiekt ma klasę bazową
	///
	///@param rtti - stała referencja na obietk klasy RTTI
	///
	bool derivesFrom (const RTTI & rtti) const;

	///
	///
	///
	const RTTI *getBaseRTTI() const { return p_base_RTTI; }
  
private:
	
	RTTI(const RTTI & obj); //Konstruktor kopiujący prywatny - zabezpiecza przed kopiowaniem
	RTTI & operator = (const RTTI & obj); //operator
	const std::string m_class_name; //nazwa klasy
	const RTTI *p_base_RTTI; //wskaźnik na klasę bazową
};

//Makro
#define RTTI_DECL \
    public: \
        virtual const RTTI & GetRTTI() { return rtti; } \
        static const RTTI rtti;
//Makro
#define RTTI_IMPL_NOPARENT(name) \
    const RTTI name::rtti(#name);

//Makro
#define RTTI_IMPL(name,parent) \
    const RTTI name::rtti(#name, parent::rtti);

#endif //H_RTTI_JACK
