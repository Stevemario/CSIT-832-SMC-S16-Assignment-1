template<class ItemType>
PQType<ItemType>::PQType (int max) {
	maxItems = max;
	items.elements = new ItemType[max];
	length = 0;
}
template<class ItemType>
PQType<ItemType>::~PQType () {
	delete [] items.elements;
}
template<class ItemType>
void PQType<ItemType>::MakeEmpty () {
	length = 0;
}
template<class ItemType>
bool PQType<ItemType>::IsEmpty () const {
	return (length == 0);
}
template<class ItemType>
bool PQType<ItemType>::IsFull () const {
	return (length == maxItems);
}
template<class ItemType>
void PQType<ItemType>::Enqueue (ItemType newItem) {
	items.elements[length] = newItem;
	length++;
	items.ReheapUp (0, length-1);
}
template<class ItemType>
void PQType<ItemType>::Dequeue (ItemType& item) {
	item = items.elements[0];
	items.elements[0] = items.elements[length-1];
	length--;
	items.ReheapDown (0, length-1);
}
template<class ItemType>
int PQType<ItemType>::nElements () const {
	return length;
}
template<class ItemType>
ItemType* PQType<ItemType>::copy_elements () const {
	ItemType* copy = new ItemType[length];
	for (int i = 0; i < length; i++) {
		copy[i] = items.elements[i];
	}
	return copy;
}