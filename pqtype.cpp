template<class PriorityQueueType>
PriorityQueue<PriorityQueueType>::PriorityQueue (int max) {
	maxItems = max;
	items.elements = new PriorityQueueType[max];
	m_nElements = 0;
}
template<class PriorityQueueType>
PriorityQueue<PriorityQueueType>::~PriorityQueue () {
	delete [] items.elements;
}
template<class PriorityQueueType>
bool PriorityQueue<PriorityQueueType>::bIsFull () const {
	return (m_nElements == maxItems);
}
template<class PriorityQueueType>
bool PriorityQueue<PriorityQueueType>::bIsEmpty () const {
	return (m_nElements == 0);
}
template<class PriorityQueueType>
void PriorityQueue<PriorityQueueType>::enqueue (PriorityQueueType newItem) {
	items.elements[m_nElements] = newItem;
	m_nElements++;
	items.ReheapUp (0, m_nElements-1);
}
template<class PriorityQueueType>
void PriorityQueue<PriorityQueueType>::dequeue (PriorityQueueType& item) {
	item = items.elements[0];
	items.elements[0] = items.elements[m_nElements-1];
	m_nElements--;
	items.ReheapDown (0, m_nElements-1);
}
template<class PriorityQueueType>
int PriorityQueue<PriorityQueueType>::nElements () const {
	return m_nElements;
}
template<class PriorityQueueType>
PriorityQueueType* PriorityQueue<PriorityQueueType>::copy_elements () const {
	PriorityQueueType* copy = new PriorityQueueType[m_nElements];
	for (int i = 0; i < m_nElements; i++) {
		copy[i] = items.elements[i];
	}
	return copy;
}