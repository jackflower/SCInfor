//  ________________________________
// | RefCntPtr.h - class definition |
// | Jack Flower October 2012       |
// |________________________________|
//

#ifndef H_REF_CNT_PTR_JACK
#define H_REF_CNT_PTR_JACK

#include <cstdio>

//Inteligentny wska�nik, kt�ry zlicza referencje do obiektu.
//Przy braku referencji zwalnia obiekt.
//Wska�nik pozwala na to, aby mie� warto�� nullptr

//Wymagania co do klas wewnatrz-szablonowych:
//	void Release(); - metoda uruchamiana zamiast destruktora przy braku referencji
//	int &GetRefCnt(); - metoda zwraca referencje do licznika referencji (poczatkowo 0)
//	konstruktor kopiuj�cy zeruje licznik referecji
//Najpro�ciej jest dziedziczy� po CRefPoolable
//Przyk�ad: typedef RefCntPtr<EffectSource> EffectSourcePtr;

namespace memory
{

	///
	///Szablon reprezentuje inteligentny wska�nik
	///
	template<class T>
	class RefCntPtr
	{
	public:

		///
		///Konstruktor domy�lny
		///
		RefCntPtr()
		:
			obj(nullptr)//inicjuje wska�nik na nullptr
		{
		}

		///
		///Konstruktor parametryczny
		///
		///@param *obj - wska�nik na obiekt jakiego� typu
		///
		RefCntPtr(T *obj)
		:
			obj(obj)
		{
			if (obj != nullptr)//je�li na co� wskazuje, zwi�ksza licznik referencji
				Attach();
		}
		
		///
		///Konstruktor parametryczny
		///
		///@param &other - sta�a referencja na jaki� obiekt
		///
		RefCntPtr(const RefCntPtr<T> &other)
		{
			obj = other.obj;
			if (obj != nullptr)//je�li na co� wskazuje, zwi�ksza licznik referencji
				Attach();
		}

		///
		///Destruktor
		///
		~RefCntPtr()
		{
			if (obj != nullptr)//je�li wska�nik na co� wskazuje,
							//a jaki� obiekt si� zniszczy,
							//to destruktor zmniejsza licznik referencji
				Detach();
		}

		///
		///Operator * - zwraca wska�nik na obiekt
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
		///Operator & - zwraca referencj� do obiektu
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

		T *obj;	//wska�nik na jakis obiekt (zak�adamy, �e na co� musi wskazywa�)

		//Metoda zwi�ksza licznik referencji
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
