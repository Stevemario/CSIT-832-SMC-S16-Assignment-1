#ifndef PQTYPE_H
#define PQTYPE_H
#include "heap.h"
template<class ItemType>
class PQType {
	public: PQType (int);
	public: ~PQType ();
	public: void MakeEmpty ();
	public: bool IsEmpty () const;
	public: bool IsFull () const;
	public: void Enqueue (ItemType);
	public: void Dequeue (ItemType&);
	private: int length;
	private: HeapType<ItemType> items;
	private: int maxItems;
	public: int nElements () const;
};
#include "pqtype.cpp"
#endif