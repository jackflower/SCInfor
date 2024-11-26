// MemoryBlock.h
#pragma once
#include <iostream>
#include <algorithm>

class MemoryBlock
{
public:

   // Konstruktor
   explicit MemoryBlock(size_t length)
      : _length(length)
      , _data(new int[length])
   {
      std::cout << "In MemoryBlock(size_t). length = "
                << _length << "." << std::endl;
   }

   // Destruktor
   ~MemoryBlock()
   {
      std::cout << "In ~MemoryBlock(). length = "
                << _length << ".";

      if (_data != nullptr)
      {
         std::cout << " Deleting resource.";
         // Delete the resource.
         delete[] _data;
      }

      std::cout << std::endl;
   }

   // Konstruktor kopiujący
   MemoryBlock(const MemoryBlock& other)
      : _length(other._length)
      , _data(new int[other._length])
   {
      std::cout << "In MemoryBlock(const MemoryBlock&). length = "
                << other._length << ". Copying resource." << std::endl;

      std::copy(other._data, other._data + _length, _data);
   }
   
	// Konstruktor przenoszący
	MemoryBlock(MemoryBlock&& other)
	   : _data(nullptr)
	   , _length(0)
	{
	   std::cout << "In MemoryBlock(MemoryBlock&&). length = "
				 << other._length << ". Moving resource." << std::endl;

	   // Copy the data pointer and its length from the
	   // source object.
	   _data = other._data;
	   _length = other._length;

	   // Release the data pointer from the source object so that
	   // the destructor does not free the memory multiple times.
	   other._data = nullptr;
	   other._length = 0;
	}
	
	// Konstruktor przenoszący - another
	MemoryBlock(MemoryBlock&& other)
	   : _data(nullptr)
	   , _length(0)
	{
	   *this = std::move(other);
	}

   // Przeciążony operator przypisania kopiowania
   MemoryBlock& operator=(const MemoryBlock& copy)
   {
      std::cout << "In operator=(const MemoryBlock&). length = "
                << copy._length << ". Copying resource." << std::endl;

      if (this != &copy)
      {
         // Free the existing resource.
         delete[] _data;

         _length = copy._length;
         _data = new int[_length];
         std::copy(copy._data, copy._data + _length, _data);
      }
      return *this;
   }
   
	// Przeciążony operator przypisania przenoszenia
	MemoryBlock& operator=(MemoryBlock&& other)
	{
	   std::cout << "In operator=(MemoryBlock&&). length = "
				 << other._length << "." << std::endl;

	   if (this != &other)
	   {
		  // Free the existing resource.
		  delete[] _data;

		  // Copy the data pointer and its length from the
		  // source object.
		  _data = other._data;
		  _length = other._length;

		  // Release the data pointer from the source object so that
		  // the destructor does not free the memory multiple times.
		  other._data = nullptr;
		  other._length = 0;
	   }
	   return *this;
	}   
	
   // Retrieves the length of the data resource.
   size_t Length() const
   {
      return _length;
   }

private:
   size_t _length; // The length of the resource.
   int* _data; // The resource.
};
