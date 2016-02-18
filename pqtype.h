#ifndef PQTYPE_H
#define PQTYPE_H
#include "heap.h"
template<class PriorityQueueType>
class PriorityQueue {
	public: PriorityQueue (int);
	public: ~PriorityQueue ();
	private: int maxItems;
	public: bool bIsFull () const;
	public: bool bIsEmpty () const;
	public: void enqueue (PriorityQueueType);
	public: void dequeue (PriorityQueueType&);
	private: int m_nElements;
	public: int nElements () const;
	private: Heap<PriorityQueueType> items;
	public: PriorityQueueType* copy_elements () const;
};
#include "pqtype.cpp"
#endif