#ifndef HEAP_H
#define HEAP_H
// Assumes ItemType either a built-in simple data
// type or a class with overloaded relational operators.
template<class ItemType >
struct HeapType {
	void ReheapDown (int root, int bottom) ;
	void ReheapUp (int root, int bottom) ;
	void Swap (ItemType&, ItemType&);

	ItemType* elements; //array to be allocated dynamically
	int numElements;
};
#include "heap.cpp"
#endif