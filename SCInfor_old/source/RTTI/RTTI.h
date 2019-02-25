//  _________________________________
// | RTTI.h - class definition       |
// | Jack Flower October 2012        |
// |_________________________________|
//


#include <string>

#ifndef H_RTTI_JACK
#define H_RTTI_JACK

///
///Klasa reprezentuje funkjonalnoœæ zwracaj¹c¹ typ klasy
///
class RTTI 
{

public:

	///
	///Konstruktor
	///
	///@param &class_name - sta³a referencja na nazwê klasy
	///
	RTTI(const std::string& class_name);

	///
	///Konstruktor
	///
	///@param &class_name - sta³a referencja na nazwê klasy
	///
	///@param - &baseRTTI - sta³a referencja na klasê bazow¹
	///
	RTTI(const std::string & class_name, const RTTI& baseRTTI);

	///
	///Metoda zwraca nazwê klasy
	///
    const std::string& GetNameClass() const { return m_class_name; }
    
	///
	///Metoda zwraca flagê
	///
	///@param &rtti - sta³a referencja na obietk klasy RTTI
	///
	bool IsExactly(const RTTI& rtti) const { return (this == &rtti); }

	///
	///Metoda zwraca flagê, czy obiekt ma klasê bazow¹
	///
	///@param &rtti - sta³a referencja na obietk klasy RTTI
	///
	bool DerivesFrom (const RTTI& rtti) const;

	///
	///
	///
	const RTTI* GetBaseRTTI() const { return p_base_RTTI; }
  
private:
	
	RTTI(const RTTI & obj);					//Konstruktor kopiuj¹cy prywatny - zabezpiecza przed kopiowaniem
	RTTI & operator = (const RTTI & obj);	//operator
	const std::string	m_class_name;		//nazwa klasy
	const RTTI *		p_base_RTTI;		//wskaŸnik na klasê bazow¹
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
