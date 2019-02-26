//  ________________________________
// | Xml.h - class definition       |
// | Jack Flower -  September 2012  | 
// |________________________________|
//

#ifndef H_XML_JACK
#define H_XML_JACK

#include "RapidXML/rapidxml.hpp"
#include "RapidXML/rapidxml_utils.hpp"
#include <string>

using namespace std;
using namespace rapidxml;

namespace xml
{
	///
	///Klasa reprezentuje opadkowanie parsera RapidXML
	///
	class Xml
	{
	public:
		
		///
		///Konstruktor domyślny
		///
		///@param filename - nazwa pliku
		///
		///@param root - nazwa węzła głównego root
		///
		Xml(std::string filename, std::string root);
		
		///
		///Destruktor
		///
		~Xml();

		///
		///Metoda zwraca wskaźnik na węzeł root dokumentu
		///
		xml_node<> *getRootNode();

		///
		///Metoda zwraca nazwę pliku
		///
		const std::string & getFilename() const;

		///
		///Metoda zwraca wskaźnik na węzeł dziecka
		///
		///@param parent  - wskaźnik na węzeł
		///
		///@param node_name - nazwa pobieranego węzła
		///
		xml_node<> *getChild(xml_node<> *parent, const std::string & node_name);

		///
		///Metoda zwraca wskaźnik na węzeł rodzeństwa
		///
		///@param *sibling - wskaźnik na węzeł
		///
		///@param node_name - nazwa węzła
		///
		xml_node<> *getSibling(xml_node<> *sibling, const std::string & node_name);    

		///
		///Metoda zwraca atrybut wskazanego typu
		///
		///@param *parent - wskaźnik na węzeł dokumentu xml
		///
		///@param attrib_name - stała referencja na nazwę atrybutu dokumentu xml
		///
		///@param default_value - wartość default (false)
		///
		bool getBool(xml_node<> *parent, const std::string & attrib_name = "", bool default_value = false);

		///
		///Metoda zwraca atrybut wskazanego typu
		///
		///@param node_name - stała referencja na nazwę węzła
		///
		///@param attrib_name - stała referencja na nazwę atrybutu dokumentu xml
		///
		///@param default_value - wartość default (false)
		///
		bool getBool(const std::string & node_name, const std::string & attrib_name = "", bool default_value = false);

		///
		///Metoda zwraca atrybut wskazanego typu
		///
		///@param *parent - wskaźnik na węzeł dokumentu xml
		///
		///@param attrib_name - stała referencja na nazwę atrybutu dokumentu xml
		///
		///@param default_value - wartość default (false)
		///
		int getInt(xml_node<> *parent, const std::string & attrib_name = "", int default_value = 0);

		///
		///Metoda zwraca atrybut wskazanego typu
		///
		///@param node_name - stała referencja na nazwę węzła
		///
		///@param attrib_name - stała referencja na nazwę atrybutu dokumentu xml
		///
		///@param default_value - wartość default (false)
		///
		int	getInt(const std::string & ode_name, const std::string & attrib_name = "", int default_value = 0);

		///
		///Metoda zwraca atrybut wskazanego typu
		///
		///@param *parent - wskaźnik na węzeł dokumentu xml
		///
		///@param attrib_name - stała referencja na nazwę atrybutu dokumentu xml
		///
		///@param default_value - wartość default (false)
		///
		float getFloat(xml_node<> *parent, const std::string &attrib_name = "", float default_value = 0.0f);

		///
		///Metoda zwraca atrybut wskazanego typu
		///
		///@param node_name - stała referencja na nazwę węzła
		///
		///@param attrib_name - stała referencja na nazwę atrybutu dokumentu xml
		///
		///@param default_value - wartość default (false)
		///
		float getFloat(const std::string & node_name, const std::string & attrib_name = "", float default_value = 0.0f);

		///
		///Metoda zwraca atrybut wskazanego typu
		///
		///@param *parent - wskaźnik na węzeł dokumentu xml
		///
		///@param attrib_name - stała referencja na nazwę atrybutu dokumentu xml
		///
		///@param default_value - wartość default (false)
		///
		std::string	getString(xml_node<> *parent, const std::string & attrib_name = "");

		///
		///Metoda zwraca atrybut wskazanego typu
		///
		///@param node_name - stała referencja na nazwę węzła
		///
		///@param attrib_name - stała referencja na nazwę atrybutu dokumentu xml
		///
		///@param default_value - wartość default (false)
		///
		std::string	getString(const std::string & node_name, const std::string & attrib_name = "");

		///
		///Metoda zwraca atrybut wskazanego typu
		///
		///@param *parent - wskaźnik na węzeł dokumentu xml
		///
		///@param attrib_name - stała referencja na nazwę atrybutu dokumentu xml
		///
		std::wstring getWString(xml_node<> *parent, const std::string & attrib_name = "");

		///
		///Metoda zwraca atrybut wskazanego typu
		///
		///@param node_name - stała referencja na nazwę węzła
		///
		///@param attrib_name - stała referencja na nazwę atrybutu dokumentu xml
		///
		std::wstring getWString(const std::string & node_name, const std::string & attrib_name = "");


	private:

		xml_document<> m_xml_document; //dokument XML
		xml_node<> *m_xml_root; //wskaźnik na węzeł root dokumentu
		std::string m_filename; //nazwa pliku
		file<char> *m_file; //obiekt szablonu klasy rapidxml::file - plik
	};
}//namespace xml
#endif //H_XML_JACK
