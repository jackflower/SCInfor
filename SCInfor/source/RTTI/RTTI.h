//  _________________________________
// | RTTI.h - class definition       |
// | Jack Flower October 2012        |
// |_________________________________|
//


#include <string>

#ifndef H_RTTI_JACK
#define H_RTTI_JACK

///
///Klasa reprezentuje funkjonalno�� zwracaj�c� typ klasy
///
class RTTI 
{

public:

	///
	///Konstruktor
	///
	///@param &class_name - sta�a referencja na nazw� klasy
	///
	RTTI(const std::string& class_name);

	///
	///Konstruktor
	///
	///@param &class_name - sta�a referencja na nazw� klasy
	///
	///@param - &baseRTTI - sta�a referencja na klas� bazow�
	///
	RTTI(const std::string & class_name, const RTTI& baseRTTI);

	///
	///Metoda zwraca nazw� klasy
	///
    const std::string& GetNameClass() const { return m_class_name; }
    
	///
	///Metoda zwraca flag�
	///
	///@param &rtti - sta�a referencja na obietk klasy RTTI
	///
	bool IsExactly(const RTTI& rtti) const { return (this == &rtti); }

	///
	///Metoda zwraca flag�, czy obiekt ma klas� bazow�
	///
	///@param &rtti - sta�a referencja na obietk klasy RTTI
	///
	bool DerivesFrom (const RTTI& rtti) const;

	///
	///
	///
	const RTTI* GetBaseRTTI() const { return p_base_RTTI; }
  
private:
	
	RTTI(const RTTI & obj);					//Konstruktor kopiuj�cy prywatny - zabezpiecza przed kopiowaniem
	RTTI & operator = (const RTTI & obj);	//operator
	const std::string	m_class_name;		//nazwa klasy
	const RTTI *		p_base_RTTI;		//wska�nik na klas� bazow�
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
