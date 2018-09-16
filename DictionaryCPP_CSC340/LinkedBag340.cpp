// ConsoleApplication4.cpp : Defines the entry point for the console application.
//
//By. Saad Bouayad


#include <cstddef>
#include "Node.h"
#include "LinkedBag.h"
#include <cstdlib>
#include <iostream>
#include <time.h>


//******Question 1*******

//***************Remove Second Node************************
template<typename ItemType>
bool LinkedBag<ItemType>::removeSecondNode340() {
	if (!isEmpty() && itemCount >= 2) {
		Node<ItemType>* nodeToDeletePtr = headPtr;
		headPtr = headPtr->getNext();
		headPtr->setItem(nodeToDeletePtr->getItem());
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;
		itemCount--;
		return true;
	}
	return false;
}


//******Question 2*******

// ****************** Add at the End of the LinkedBag ****************
template<typename ItemType>
bool LinkedBag<ItemType>::addEnd340(const ItemType& anItem) {
	if (!isEmpty()) {
		Node<ItemType>* currentNode = headPtr;
		Node<ItemType>* newNode = new Node<ItemType>(anItem, nullptr);
		for (int i = 0; i < getCurrentSize340Recursive() - 1; i++) {
			currentNode = currentNode->getNext();
		}
		currentNode->setNext(newNode);
		itemCount++;
		return true;
	}
	return false;
}


//******Question 3*******

//******************* Get Size of the Bag Iteratively ****************
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Iterative() const {
	int count = 0;
	Node<ItemType>* currentNode = headPtr;
	while (currentNode != nullptr) {
		count++;
		currentNode = currentNode->getNext();
	}
	return count;
}


//******Question 4*******

//********** Get current Size Recursively*************
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Recursive() const {
	return getCurrentSize340RecursiveHelper(headPtr);
}
//*****HelperFunction***********
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveHelper(Node<ItemType>* currentNode) const {
	if (currentNode != nullptr) {
		return 1 + getCurrentSize340RecursiveHelper(currentNode->getNext());
	}
	else {
		return 0;
	}
}



//******Question 5*******
//**************Get frequency of an item Recursively*********
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340Recursive(const ItemType& item) const {
	return getFrequencyOf340RecursiveHelper(headPtr, item);
}
//********HelperFunction*******
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveHelper(Node<ItemType>* currentNode, const ItemType& item) const {
	if (currentNode != nullptr) {
		if (currentNode->getItem() == item) {
			return 1 + getFrequencyOf340RecursiveHelper(currentNode->getNext(), item);
		}
		else {
			return 0 + getFrequencyOf340RecursiveHelper(currentNode->getNext(), item);
		}
	}
	else {
		return 0;
	}
}

//********Question 6 **********

//************Remove a Random Node (use srand())*****************
template<typename ItemType>
ItemType LinkedBag<ItemType>::removeRandom340() {
	Node<ItemType>* nodeToCopyTo = headPtr;
	ItemType deletedData{NULL};
	if (!isEmpty()) {
		srand((unsigned)time(0));
		//randomNode has to be in the range of the linkedBag
		int randomNode = (std::rand() % getCurrentSize340Recursive() + 1);
		for (int i = 0; i < randomNode - 1; i++) {
			nodeToCopyTo = nodeToCopyTo->getNext();
		}
		deletedData = nodeToCopyTo->getItem();
		nodeToCopyTo->setItem(headPtr->getItem());
		Node<ItemType>* nodeToDeletePtr = headPtr;
		headPtr = headPtr->getNext();
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;
		itemCount--;
	}
	return deletedData;
}