//  _______________________________
// | CSafePtr.h - class definition |
// | Jack Flower October 2012      |
// |_______________________________|
//

#ifndef H_SAFE_PTR_JACK
#define H_SAFE_PTR_JACK

#include <cstdio>

namespace memory
{
	template<class T> class CSafePtrable;

	///
	///Szablon klasy reprezentuje inteligentny, bezpieczny wakaünik, ktÛry przyjmuje wartoúÊ nullptr po zniszczeniu obiektu
	///
	template<class T>
	class CSafePtr
	{
	public:

		///
		///Konstruktor
		///
		CSafePtr(const CSafePtr<T> &other)
		{
			Attach(other);
		}
		
		///
		///Destruktor
		///
		~CSafePtr()
		{
			Detach();
		}

		///
		///Operator
		///
		inline T& operator*() const
		{
			return *obj;
		}

		///
		///Operator
		///
		inline T *operator->() const
		{
			return obj;
		}

		///
		///Operator
		///
		inline bool operator == (const CSafePtr<T> &other) const
		{
			return obj == other.obj;
		}

		///
		///Operator
		///
		inline bool operator == (T* other) const
		{
			return obj == other;
		}
	    
		///
		///Operator
		///
		inline bool operator != (const CSafePtr<T> &other) const
		{
			return obj != other.obj;
		}

		///
		///Operator
		///
		inline bool operator != (T* other) const
		{
			return obj != other;
		}

		///
		///Operator
		///
		inline CSafePtr<T> &operator = (const CSafePtr<T> &other)
		{
			Detach();
			Attach(other);
			return *this;
		}

		///
		///Metoda usuwa obiekt
		///
		inline void DeleteObject()
		{
			delete obj;
		}

		///
		///Metoda statyczna
		///
		inline static CSafePtr<T> NullPtr()
		{
			return CSafePtr((T*)nullptr);
		}
	
	private:

		//Deklaracja przyjaüni
		friend class CSafePtrable<T>;

		T *obj;							//wskaünik na jakiú obiekt
		mutable CSafePtr<T> *next;		//wskaünik
		mutable CSafePtr<T> *prev;		//wskaünik
		
		explicit CSafePtr()
		{
		}
		
		explicit CSafePtr(T *obj)
		:
			obj(obj)
		{
			next = this;
			prev = this;
		}
		
		void Attach(const CSafePtr<T> &other)
		{
			obj = other.obj;
			next = other.next;
			prev = ((CSafePtr<T>*)(&other));
			prev->next = this;
			next->prev = this;
		}
		
		inline void Detach()
		{
			next->prev = prev;
			prev->next = next;
			prev = this;
			next = this;
		}
		
		inline void NullAll()
		{
			obj = nullptr;
			CSafePtr<T> *n = next;
			Detach();
			if (n != this)
				n->NullAll();
		}
	};
}//namespace memory
#endif//H_SAFE_PTR_JACK
