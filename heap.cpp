//  IMPLEMENTATION  OF RECURSIVE HEAP MEMBER FUNCTIONS
template<class HeapType>
void Heap<HeapType>::ReheapUp (int nNodeIndex, int nGenerations, const int nElements)
//This function checks
//if a node has higher priority than a number of its predecessors, and
//if it does,
//it swaps the node's place in the heap with its predecessors.
{
	int nParentNodeIndex;

	if (nNodeIndex > 0 && nNodeIndex < nElements && nGenerations > 0) {
	//if the node's index is positive, and
	//   the node's index is an index for a placed node, and
	//   the number of generations to heap up is positive

		//A node X has 2 children at:
		//A. 2 * X's index + 1, and
		//B. 2 * X's index + 2.
		//So a node Y can have a parent at:
		//A. (Y's index - 1) / 2, or
		//B. (Y's index - 2) / 2,
		//depending on which child it is,
		//left child or right child.
		//Left children's indexes are always odd, meaning
		//left chidren's indexes % 2 will equal 1.
		//Right children's indexes are always even, meaning
		//right children's indexes % 2 will equal 0.

		if (nNodeIndex % 2 == 0) {
		//if the node's index is even, meaning
		//if the node is a right child

			nParentNodeIndex = (nNodeIndex - 2) / 2;
			//the node's parent's index is the difference of
			//the node's index and two,
			//divided by two.
		} else {
		//if the node's index is not even, meaning
		//if the node's index is odd, meaning
		//if the node is a left child

			nParentNodeIndex = (nNodeIndex - 1) / 2;
			//the node's parent's index is the difference of
			//the node's index and one,
			//divided by two.
		}

		//Using what we know about even numbers, and integers,
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
template<class HeapType>
void Heap<HeapType>::ReheapDown (int nNodeIndex, int nGenerations, const int nElements)
// Pre:  root is the index of the node that may violate the
// heap order property
// Post: Heap order property is restored between root and bottom
{
	int maxChild ;
	int rightChild ;
	int leftChild ;

	leftChild = 2 * nNodeIndex + 1;
	rightChild = 2 * nNodeIndex + 2;

	if (nNodeIndex >= 0 && nNodeIndex < nElements  && nGenerations > 0) {
	//if the node's index is positive, or zero, and
	//   the node's index is an index for a placed node, and
	//   the number of generations to heap up is positive.

		if (leftChild <= nElements - 1) {
		//if the left child is within the heap

			if (leftChild == nElements - 1)
			//if the left child is the last element

				maxChild = leftChild;
				//the right child is not within the heap, so
				//the left child is the bigger valid child

			else {
			//if the left child is not the last element, meaning
			//both left and right children could be promoted

				if (elements[leftChild] < elements[rightChild])
				//if the left child's priority
				//is lesser than
				//the right child's priority

					maxChild = rightChild;
					//the right child is the bigger child

				else
				//if the left child's priority
				//is not lesser than
				//the right child's priority

					maxChild = leftChild;
					//the left child is the bigger child,
					//in this case, due the job class member
					//job will prevent equal priority.
					//in other cases, ties are possible,
					//but not important, left child is chosen
					//just because one has to be chosen.
			}
			if (elements[nNodeIndex] < elements[maxChild]) {
			//if the node's priority
			//is lesser than
			//the bigger child's priority
				
				//the heap's rules are violated.
				//To fix that we start by

				Swap (elements[nNodeIndex], elements[maxChild]);
				//swapping the node with it's bigger child

				nGenerations--;
				//note that we've gone down a generation

				ReheapDown (maxChild, nGenerations, nElements);
				//and repeating until the requirements are met.
			}
		}
	}
}
template<class HeapType>
void Heap<HeapType>::Swap (HeapType& a, HeapType& b) {
	HeapType temp;
	temp = a;
	a = b;
	b = temp;
}