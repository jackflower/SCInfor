//  ________________________________
// | RefCntPtr.h - class definition |
// | Jack Flower October 2012       |
// |________________________________|
//

#ifndef H_REF_CNT_PTR_JACK
#define H_REF_CNT_PTR_JACK

#include <cstdio>

//Inteligentny wskaŸnik, który zlicza referencje do obiektu.
//Przy braku referencji zwalnia obiekt.
//WskaŸnik pozwala na to, aby mieæ wartoœæ nullptr

//Wymagania co do klas wewnatrz-szablonowych:
//	void Release(); - metoda uruchamiana zamiast destruktora przy braku referencji
//	int &GetRefCnt(); - metoda zwraca referencje do licznika referencji (poczatkowo 0)
//	konstruktor kopiuj¹cy zeruje licznik referecji
//Najproœciej jest dziedziczyæ po CRefPoolable
//Przyk³ad: typedef RefCntPtr<EffectSource> EffectSourcePtr;

namespace memory
{

	///
	///Szablon reprezentuje inteligentny wskaŸnik
	///
	template<class T>
	class RefCntPtr
	{
	public:

		///
		///Konstruktor domyœlny
		///
		RefCntPtr()
		:
			obj(nullptr)//inicjuje wskaŸnik na nullptr
		{
		}

		///
		///Konstruktor parametryczny
		///
		///@param *obj - wskaŸnik na obiekt jakiegoœ typu
		///
		RefCntPtr(T *obj)
		:
			obj(obj)
		{
			if (obj != nullptr)//jeœli na coœ wskazuje, zwiêksza licznik referencji
				Attach();
		}
		
		///
		///Konstruktor parametryczny
		///
		///@param &other - sta³a referencja na jakiœ obiekt
		///
		RefCntPtr(const RefCntPtr<T> &other)
		{
			obj = other.obj;
			if (obj != nullptr)//jeœli na coœ wskazuje, zwiêksza licznik referencji
				Attach();
		}

		///
		///Destruktor
		///
		~RefCntPtr()
		{
			if (obj != nullptr)//jeœli wskaŸnik na coœ wskazuje,
							//a jakiœ obiekt siê zniszczy,
							//to destruktor zmniejsza licznik referencji
				Detach();
		}

		///
		///Operator * - zwraca wskaŸnik na obiekt
		///
		T& operator*()
		{
			return *obj;
		}

		///
		///Operator ()
		///
		T *operator->()
		{
			return obj;
		}

		///
		///Operator ==
		///
		inline bool operator==(const RefCntPtr<T> &other) const
		{
			return obj == other.obj;
		}

		///
		///Operator !=
		///
		inline bool operator!=(const RefCntPtr<T> &other) const
		{
			return obj != other.obj;
		}

		///
		///Operator & - zwraca referencjê do obiektu
		///
		inline RefCntPtr<T> &operator=(const RefCntPtr<T> &other)
		{
			if (&other == this)
				return *this;
			if (obj!=nullptr)
				Detach();
			obj = other.obj;
			if (obj!=nullptr)
				Attach();
			return *this;
		}
	
	private:

		T *obj;	//wskaŸnik na jakis obiekt (zak³adamy, ¿e na coœ musi wskazywaæ)

		//Metoda zwiêksza licznik referencji
		inline void Attach()
		{
			obj->GetRefCnt()++;
		}
		
		//Metoda zmniejsza licznik referencji
		inline void Detach()
		{
			obj->GetRefCnt()--;
			if (obj->GetRefCnt()<=0)
				obj->Release();
		}
	};
}//namespace memory
#endif//H_REF_CNT_PTR_JACK
