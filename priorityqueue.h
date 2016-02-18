#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include "heap.h"
template<class PriorityQueueType>
class PriorityQueue {
	public: PriorityQueue (int);
	public: PriorityQueue (const PriorityQueue&);
	public: ~PriorityQueue ();
	private: int m_nCapacity;
	public: int nCapacity () const;
	public: bool bIsFull () const;
	public: bool bIsEmpty () const;
	public: void enqueue (PriorityQueueType);
	public: void dequeue (PriorityQueueType&);
	private: int m_nElements;
	public: int nElements () const;
	private: Heap<PriorityQueueType> items;
	public: PriorityQueueType element (int) const;
};
#include "priorityqueue.cpp"
#endif