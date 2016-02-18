#ifndef HEAP_H
#define HEAP_H
// Assumes ItemType either a built-in simple data
// type or a class with overloaded relational operators.
template<class HeapType>
struct Heap {
	void ReheapDown (int, int);
	void ReheapUp (int, int);
	void Swap (HeapType&, HeapType&);

	HeapType* elements; //array to be allocated dynamically
};
#include "heap.cpp"
#endif