// template linked list by https://github.com/clamtime

#pragma once
#include <iostream>

template <typename T>
struct Node
{
	Node(T data) :mData(data), mNextNode(nullptr)
	{
	}

	T	  mData;
	Node* mNextNode;
};

template <typename T>
class LinkedList
{
private:
	Node<T>* mHeadNodePtr = nullptr;
	int   mNodeCount   = 0;

	Node<T>* getNodeAtIndex(int i);

public:
	~LinkedList<T>();

	void insert(T data);
	int getCount();
	T getDataAtIndex(int index);
	void clear();

	friend std::ostream& operator <<(std::ostream& out, LinkedList<T>& list)
	{
		if (list.getCount() == 0)
		{
			out << "Empty list.\n";
		}
		else
		{
			std::string next = "->";
			for (int i = 0; i < list.getCount(); i++)
			{
				if (i > list.getCount() - 2)
					next = "\n";

				out << list.getDataAtIndex(i) << next;
			}
		}
		return out;
	}
};

template<typename T>
LinkedList<T>::~LinkedList()
{
	clear();
}


template<typename T>
Node<T>* LinkedList<T>::getNodeAtIndex(int index)
{
	Node<T>* toReturn = nullptr;
	Node<T>* tmp = mHeadNodePtr;

	for (int i = 0; i < mNodeCount; i++)
	{
		if (i == index)
		{
			toReturn = tmp;
			break;
		}
		tmp = tmp->mNextNode;
	}

	return toReturn;
}

template <typename T>
void LinkedList<T>::insert(T data)
{
	if (mNodeCount == 0)
	{
		Node<T>* newNode = new Node<T>(data);
		mHeadNodePtr = newNode;
	}
	else if (mNodeCount == 1)
	{
		Node<T>* newNode = new Node<T>(data);
		mHeadNodePtr->mNextNode = newNode;
	}
	else
	{
		Node<T>* newNode = new Node<T>(data);
		getNodeAtIndex(mNodeCount-1)->mNextNode = newNode;
	}
	mNodeCount++;
}

template<typename T>
inline int LinkedList<T>::getCount()
{
	return mNodeCount;
}

template<typename T>
T LinkedList<T>::getDataAtIndex(int index)
{
	return getNodeAtIndex(index)->mData;
}

template<typename T>
void LinkedList<T>::clear()
{
	Node<T>* tmp = mHeadNodePtr;
	Node<T>* toDelete = tmp;

	for (int i = 0; i < mNodeCount; i++)
	{
		tmp = tmp->mNextNode;

		delete toDelete;
		toDelete = nullptr;

		toDelete = tmp;
	}

	mNodeCount = 0;
}