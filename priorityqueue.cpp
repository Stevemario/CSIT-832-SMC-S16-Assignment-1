template<class PriorityQueueType>
PriorityQueue<PriorityQueueType>::PriorityQueue (int nCapacity) {
	m_nCapacity = nCapacity;
	items.elements = new PriorityQueueType[nCapacity];
	m_nElements = 0;
}
template<class PriorityQueueType>
PriorityQueue<PriorityQueueType>::PriorityQueue (const PriorityQueue& pqToCopy) {
	m_nCapacity = pqToCopy.nCapacity ();
	items.elements = new PriorityQueueType[m_nCapacity];
	m_nElements = pqToCopy.nElements ();
	for (int i = 0; i < m_nElements; i++) {
		items.elements[i] = pqToCopy.element (i);
	}
}
template<class PriorityQueueType>
PriorityQueue<PriorityQueueType>::~PriorityQueue () {
	delete [] items.elements;
}
template<class PriorityQueueType>
int PriorityQueue<PriorityQueueType>::nCapacity () const {
	return m_nCapacity;
}
template<class PriorityQueueType>
bool PriorityQueue<PriorityQueueType>::bIsFull () const {
	return (m_nElements >= m_nCapacity);
}
template<class PriorityQueueType>
bool PriorityQueue<PriorityQueueType>::bIsEmpty () const {
	return (m_nElements == 0);
}
template<class PriorityQueueType>
void PriorityQueue<PriorityQueueType>::enqueue (PriorityQueueType newItem) {
	int nHeight;
	items.elements[m_nElements] = newItem;
	m_nElements++;
	nHeight = nGeneration (m_nElements);
	items.ReheapUp (m_nElements - 1, nHeight, m_nElements);
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
PriorityQueueType PriorityQueue<PriorityQueueType>::element (int nIndex) const {
	PriorityQueueType element = items.elements[nIndex];
	return element;
}
template<class PriorityQueueType>
int PriorityQueue<PriorityQueueType>::nGeneration (const int nIndex) {
	int nGeneration = 0;
	int nFactor;
	bool bMultiple = true;
	while (bMultiple) {
		nGeneration++;
		bMultiple = false;
		nFactor = 1;
		for (int i = 0; i < nGeneration; i++) {
			nFactor *= 2;
		}
		if ((nIndex / nFactor) > 0)
			bMultiple = true;
	}
	return nGeneration;
}