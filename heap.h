#ifndef HEAP_H
#define HEAP_H
template<class HeapType>
struct Heap {
	HeapType* elements; //array to be allocated dynamically
	void ReheapUp (int, int, const int);
	void ReheapDown (int, int, const int);
	void Swap (HeapType&, HeapType&);
};
#include "heap.cpp"
#endif