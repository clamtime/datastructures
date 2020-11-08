// template binary search tree by https://github.com/clamtime

#pragma once
#include <iostream>

template <typename T>
struct Node
{
	T	  mData;
	Node* mLeftNode;
	Node* mRightNode;

	Node(T data) :mData(data), mLeftNode(nullptr), mRightNode(nullptr)
	{
	}
};

template <typename T>
class BinarySearchTree
{
private:
	Node<T>* mHeadNodePtr = nullptr;
	int		 mNodeCount = 0;

	void recursiveInsert(T data, Node<T>* nodePtr);
	void recursivePrint(Node<T>* nodePtr);
	void recursiveClear(Node<T>* nodePtr, Node<T>* lastNodePtr);
public:
	~BinarySearchTree();

	void insert(T data);
	void print();
	void clear();
};

template<typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
	clear();
}


template<typename T>
void BinarySearchTree<T>::insert(T data)
{
	if (mNodeCount == 0)
	{
		mHeadNodePtr = new Node<T>(data);
	}
	else
	{
		Node<T>* tmpPtr = new Node<T>(T());
		tmpPtr = mHeadNodePtr;
		
		recursiveInsert(data, tmpPtr);
		
		tmpPtr = nullptr;
		delete tmpPtr;
	}
	mNodeCount++;
}


template<typename T>
void BinarySearchTree<T>::recursiveInsert(T data, Node<T>* nodePtr)
{
	if (data < nodePtr->mData) // go left
	{
		if (nodePtr->mLeftNode == nullptr)
			if (data < nodePtr->mData) // go left

		nodePtr->mLeftNode = new Node<T>(data);
	else
		recursiveInsert(data, nodePtr->mLeftNode);
	}
	else if (data > nodePtr->mData) // go right
	{
		if (nodePtr->mRightNode == nullptr)
			nodePtr->mRightNode = new Node<T>(data);
		else
			recursiveInsert(data, nodePtr->mRightNode);
	}
}

template <typename T>
void BinarySearchTree<T>::print()
{
	Node<T>* tmpPtr = new Node<T>(T());
	tmpPtr = mHeadNodePtr;

	recursivePrint(tmpPtr);

	delete tmpPtr;
	tmpPtr = nullptr;
}

template <typename T>
void BinarySearchTree<T>::recursivePrint(Node<T>* nodePtr)
{
	if (nodePtr->mLeftNode != nullptr) // go left
	{
		std::cout << nodePtr->mData << "(left of previous)\n";
		nodePtr = nodePtr->mLeftNode;
		recursivePrint(nodePtr);
	}
	if (nodePtr->mRightNode != nullptr) // go right
	{
		std::cout << nodePtr->mData << "(right of previous)\n";
		nodePtr = nodePtr->mRightNode;
		recursivePrint(nodePtr);
	}
}

template <typename T>
void BinarySearchTree<T>::clear()
{
	Node<T>* tmpPtr = new Node<T>(T());
	tmpPtr = mHeadNodePtr;
	Node<T>* tmpLastPtr = new Node<T>(T());
	tmpLastPtr = tmpPtr;

	recursiveClear(tmpPtr, tmpLastPtr);
	mNodeCount = 0;

	delete tmpPtr;
	tmpPtr = nullptr;
}

template <typename T>
void BinarySearchTree<T>::recursiveClear(Node<T>* nodePtr, Node<T>* lastNodePtr)
{
	if (nodePtr->mLeftNode != nullptr) // go left
	{
		lastNodePtr = nodePtr;
		nodePtr = nodePtr->mLeftNode;
		recursiveClear(nodePtr, lastNodePtr);
	}
	else if (nodePtr->mRightNode != nullptr) // go right
	{
		lastNodePtr = nodePtr;
		nodePtr = nodePtr->mRightNode;
		recursiveClear(nodePtr, lastNodePtr);
	}
	else // both children are null, delete current node, reset nodePtr to lastNodePtr
	{
		delete nodePtr;
		nodePtr = nullptr;

		nodePtr = new Node<T>(T());
		nodePtr = lastNodePtr;
	}
}