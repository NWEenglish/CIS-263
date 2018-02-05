/**********************************************************************
*This program is basically an Almost Useless Data Structure (AUDS).
*This data structure will hold any type of object, through the use
*  of a class template.
*
* @author Nicholas English
* @version 1.0
* @date 2/5/2018
*
**********************************************************************/

#ifndef __H_AUDS__
#define __H_AUDS__

#include <iostream>
#include <random>
#include <string>

template <typename T>

class AUDS {

	public:

		AUDS() {
			data = new T[ maxSize ];
		}

		// (1) https://www.geeksforgeeks.org/copy-constructor-in-cpp/
		AUDS( const AUDS &other ) {

			// Sets the AUDS to the same size as the other AUDS.
			currentSize = other.currentSize;
			maxSize = other.maxSize;

			// Creates the data array.
			data = new T[ maxSize ];

			// The new AUDS copies the other AUDS' objects (deep copies).
			for ( int i = 0; i < currentSize; i++ )
				data[ i ] = other.data[ i ];

		}

		AUDS& operator=( AUDS other ) {

			// Using the swap function (also a deep copy).
			// https://gitpitch.com/irawoodring/263/master?p=cpp#/101
			std::swap( currentSize, other.currentSize );
			std::swap( maxSize, other.maxSize );
			std::swap( data, other.data );

			// Returns a reference to this object.
			return *this;
		}

		~AUDS() {
			delete[] data;
		}

		int size() {
			return currentSize;
		}

		void push( T x ) {

			// Adds the item to the end of the array.
			data[ currentSize ] = x;

			// Increases the current size for the new item.
			currentSize = currentSize + 1;

			// Resizes the array if not enough space (increases by 50%).
			if ( currentSize > maxSize )
				maxSize = maxSize * 1.5;

		}

		T pop( ) {

			// Holds a random number to be generated.
			int randomNum;

			// Generates a random number.
			// (1) http://en.cppreference.com/w/cpp/header/random
			// (2) http://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
			std::random_device rd;
			std::mt19937 gen( rd() );
			std::uniform_int_distribution<> dis( 0, currentSize );

			// Calls and creates a random number to be removed.
			randomNum = dis( gen );

			// Sets a temp value to the item being removed.
			T tempItem = data[ randomNum ];

			// Last item is sent to the address of the object removed.
			data[ randomNum ] = data[ currentSize - 1 ];

			// Reduces the size of the array.
			currentSize = currentSize - 1;

			// Returns whatever item was removed.
			return tempItem;
		}

	private:

		/* Variable(s) */
		// Holds the current max size of the array.
		int maxSize = 100;

		// Holds the current number of spaces taken.
		int currentSize = 0;

		// Points to the data array.
		T* data;
};

#endif // __H_AUDS__

