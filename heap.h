#ifndef HEAP_H
#define HEAP_H
template<class HeapType>
struct Heap {
	void ReheapDown (int, int);
	void ReheapUp (int, const int, const int);
	void Swap (HeapType&, HeapType&);

	HeapType* elements; //array to be allocated dynamically
};
#include "heap.cpp"
#endif