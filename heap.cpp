//  IMPLEMENTATION  OF RECURSIVE HEAP MEMBER FUNCTIONS
template<class HeapType>
void Heap<HeapType>::Swap (HeapType& a, HeapType& b) {
	HeapType temp;
	temp = a;
	a = b;
	b = temp;
}
template<class HeapType>
void Heap<HeapType>::ReheapDown (int root, int bottom)
// Pre:  root is the index of the node that may violate the
// heap order property
// Post: Heap order property is restored between root and bottom
{
	int maxChild ;
	int rightChild ;
	int leftChild ;

	leftChild  =  root * 2 + 1;
	rightChild  =  root * 2 + 2;
	if (leftChild  <=  bottom) {
		if (leftChild == bottom)
			maxChild  =  leftChild ;
		else {
			if (elements [leftChild] <= elements [rightChild])
				maxChild  =  rightChild ;
			else
			maxChild  =  leftChild ;
		}
		if (elements [root] < elements [maxChild]) {
			Swap (elements [root] , elements [maxChild]);
			ReheapDown (maxChild, bottom);
		}
	}
}
template<class HeapType>
void Heap<HeapType>::ReheapUp (int nNodeIndex, int nGenerations, const int nElements)
//This function checks
//if a node has higher priority than a number of its predecessors, and
//if it does,
//it swaps the node's place in the heap with its predecessors.
{
	int nParentNodeIndex;

	if (nNodeIndex > 0 && nNodeIndex < nElements) {
	//if the node's index is positive, and
	//   the node's index is an index for a placed node.

		if (nGenerations > 0) {
		//if the number of generations to heap up is positive

			//A node X has 2 children at:
			//A. 2 * X's index, and
			//B. 2 * X's index + 1.
			//So a node Y can have a parent at:
			//A. Y's index / 2, or
			//B. (Y's index - 1) / 2,
			//depending on which child it is,
			//left child or right child.
			//Left children's indexes are always odd, meaning
			//left chidren's indexes % 2 will equal 1.
			//Right children's indexes are always even, meaning
			//right children's indexes % 2 will equal 0.

			if (nNodeIndex % 2 == 0) {
			//if the node's index is even, meaning
			//if the node is a left child
				nParentNodeIndex = nNodeIndex / 2;
				//the node's parent's index is the node's index divided by two.
			} else {
			//if the node's index is not even, meaning
			//if the node's index is odd, meaning
			//if the node is a right child
				nParentNodeIndex = (nNodeIndex - 1) / 2;
				//the node's parent's index is the difference of
				//the node's index and one,
				//divided by two.
			}

			//Using what we know about even and odd numbers,
			//we can simplify to
			//PROFESSOR KENT'S CODE:
			//parent = (bottom - 1) / 2;

			if (elements[nParentNodeIndex] < elements[nNodeIndex]) {
			//if the parent node's priority
			//is lesser than
			//the child node's priority

				//the heap's rules are violated.
				//To fix that we start by

				Swap (elements[nParentNodeIndex], elements[nNodeIndex]);
				//swapping the node with it's parent

				nGenerations--;
				//note that we've gone up a generation

				ReheapUp (nParentNodeIndex, nGenerations, nElements);
				//and repeating until the requirements are met.
			}
		}
	}
}