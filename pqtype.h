#ifndef PQTYPE_H
#define PQTYPE_H
#include "heap.h"
template<class ItemType>
class PQType {
	public: PQType (int);
	public: ~PQType ();
	public: void makeEmpty ();
	public: bool bIsEmpty () const;
	public: bool bIsFull () const;
	public: void enqueue (ItemType);
	public: void dequeue (ItemType&);
	private: int length;
	private: HeapType<ItemType> items;
	private: int maxItems;
	public: int nElements () const;
	public: ItemType* copy_elements () const;
};
#include "pqtype.cpp"
#endif