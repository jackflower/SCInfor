//  ________________________________
// | CPool.h - class definition     |
// | Jack Flower October 2012       |
// |________________________________|
//

#ifndef H_POOL_JACK
#define H_POOL_JACK

//
//	Klasa implementujaca pule obiektow.
//	Wymagania co T: dziedziczy po CPoolable (lub udostepnia jego interfejs), czyli:
//		- konstruktor bezparametrowy, bedzie wykorzystany przez placement new
//		- destruktor - bedzie wykorzystany jawnie
//		- metoda Bind(CPool<T> *) - potrzebna, jesli obiekt ma sam sie niszczyc
//	Wszelka dalsza inicjalizacja musi byc wykonana po stronie uzytkownika.
//
//	Mozna tez dziedzic po CRefPoolable, jesli porzadany jest mechanizm
//	zliczania referencji.
//
//	Sugeruje, by blockSize byl potega dwojki, to kompilator zoptymalizuje
//	operacje modulo - a sa one powszechne. Proponuje go rowniez dobrac rozsadnie
//	- czas dzialania rosnie liniowo z liczba blokow, zuzycie pamieci rosnie liniowo
//    z wielkoscia bloku. Domyslna wartosc to 1024.
//

#include <vector>
#include <cstdio>
#include <cassert>
#include "CPoolBase.h"

namespace memory
{
	///
	///Szablom klasy zarz¹dzaj¹cej pamiêci¹
	///
	template<class T,int blockSize = 1024>
	class CPool: public CPoolBase
	{

	public:
	    
		///
		///Konstruktor
		///
		CPool()
		:
			m_first(0),
			m_last(0)
		{
			assert(sizeof(obj_t) == sizeof(T));
			AllocBlock();
		}
	    
		///
		///Destruktor wirtualny
		///
		virtual ~CPool()
		{
			for (unsigned int i = 0; i < m_vector.size(); i++)
				delete m_vector[i];
		}

		///
		///Metoda alukuje pamiêæ
		///
		inline T* Alloc()
		{
			// kluczowa jest kolejnoœæ: 
			// najpierw zapamiêtujemy wartoœci z m_first
			unsigned int list = m_first/blockSize;
			unsigned int index = m_first%blockSize;
			// jeœli zu¿yliœmy ostatni kawa³ek pamiêci, trzeba go "od³¹czyæ"
			if (m_first == m_last)
				m_last = 0;
			// potem przesuwamy m_first
			Advance();
			// potem nadpisujemy tam pamiêæ
			T *obj = new( (T*) (m_vector[list]+index)) T();
			obj->Bind(this);
			// i wreszcie zwracamy to, co zainicjowaliœmy
			//fprintf(stderr,"alocated %p\n",obj);
			return obj;
		}

		///
		///Metoda dealokuje pamiêæ
		///
		///@param *obj - wskaŸnik na obiekt jakiegoœ typu
		///
		inline void Dealloc(T* obj)
		{
			assert(obj != nullptr);
			for (unsigned int i = 0; i < m_vector.size(); i++){
				// arytmetyka wskaznikow
				// nie dzielic przez sizeof
				int diff = (obj_t*)obj - m_vector[i]; 
				if ((diff >= 0) && (diff < blockSize)){
					//fprintf(stderr,"deallocating %p at m_vector[%u][%d]==%p\n",obj,i,diff,m_vector[i]+diff);
					obj->~T(); // ... jawne wywolanie destruktora :)
					Reuse(i,diff);
					//PrintWholeLinkage();
					return;
				}
			}
		}

		///
		///Metoda dealokuje obiekt tej klasy
		///
		///@param *obj - wskaŸnik na obiekt jakiegoœ typu
		///
		virtual void DeallocMe(void *obj)
		{
			Dealloc((T*)obj);
		}
		
		///
		///Metoda zwraca pojemoœæ wektora jako iloczyn jego elementów i rozmiaru bloku pamiêci
		///
		inline unsigned int CurrentCapacity()
		{
			return (int)m_vector.size() * blockSize;
		}
		
		///
		///Metoda zwraca rozmiar bloku pamiêci
		///
		inline int BlockSize()
		{
			return blockSize;
		}

	private:

		//dwa rodzaje indeksowania:
		//list (ktory blok pamieci w m_vector) i index (indeks w tym bloku)
		//node/link (blockSize*numer_bloku + indeks w bloku)

		struct obj_t	//struktura opisuj¹ca jakiœ obiekt
		{
		public:
			char data[sizeof(T)/sizeof(char)];	//tablica danych wewn¹trz tej struktury
		};
		
		std::vector<obj_t*>		m_vector;	//wektor blókow pamiêci
		unsigned int			m_first;	//pierwszy element
		unsigned int			m_last;		//ostatni element
	    
		//metoda...
		inline bool GoodNode(unsigned int list, unsigned int index)
		{
			return GoodNode(list*blockSize+index);
		}
		
		//metoda...
		inline bool GoodNode(unsigned int node)
		{
			return (node < CurrentCapacity()) && (node >= 0);
		}

		//metoda...
		inline void Advance()
		{
			if (m_first >= CurrentCapacity())
			{
				AllocBlock();//alokacja pamiêci
				//PrintWholeLinkage();
			}
			assert(GoodNode(m_first));
			m_first = GetLink(m_first);
		}

		//metoda...
		inline int GetLink(unsigned int list, unsigned int index)
		{
			assert(GoodNode(list,index));
			int result = *((int*)(m_vector[list]+index));
			return result;
		}
		
		//metoda...
		inline int GetLink(unsigned int node)
		{
			return GetLink(node/blockSize,node%blockSize);
		}

		//metoda...
		inline void SetLink(unsigned int list, unsigned int index, unsigned int link)
		{
			assert(GoodNode(list,index));
			*((int*)(m_vector[list]+index))=link;
		}

		//metoda...
		inline void SetLink(unsigned int node, unsigned int link)
		{
			SetLink(node/blockSize,node%blockSize,link);
		}

		//metoda...
		inline void AllocBlock()
		{
			m_vector.push_back(new obj_t[blockSize]());
			unsigned int list = (int)m_vector.size()-1;
			for (unsigned int i = 0; i < blockSize; i++) SetLink(list,i,list*blockSize+i+1);
			assert(GoodNode(m_last));
			if (m_last!=0)
				SetLink(m_last,((int)m_vector.size()-1)*blockSize);
			m_last = CurrentCapacity()-1;
		}

		//metoda...
		inline void Reuse(unsigned int list, unsigned int index)
		{
			assert(GoodNode(list,index));
			assert(GoodNode(m_last));
			SetLink(list,index,GetLink(m_last));
			SetLink(m_last,list*blockSize+index);
			m_last = list*blockSize+index;
		}

		//metoda...
		inline void PrintWholeLinkage()
		{
			fprintf(stderr,"linkage: ");
			unsigned int node = m_first;
			while(node != m_last)
			{
				fprintf(stderr,"%u, ",node); node = GetLink(node);
			}
			fprintf(stderr,"%u.\n",m_last);
		}
	};
}//namespace memory
#endif//H_POOL_JACK
