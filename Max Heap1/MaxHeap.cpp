#include "MaxHeap.h"
#include"NotAllowed.h"


template <class T> MaxHeap<T>::MaxHeap::MaxHeap()
{
	height = 0; maxNodes = pow(2.0, height) - 1; node = 0; nodeStatus = 0; noOfNodes = 0;
}
template <class T> MaxHeap<T>::MaxHeap::MaxHeap(int h)
{
	height = h;
	maxNodes = pow(2.0, h) - 1;
	node = new T[maxNodes];
	nodeStatus = new BitArray(maxNodes);
	noOfNodes = 0;
}
template <class T>void MaxHeap<T>::setRoot(T v)
{
	node[0] = v;
	nodeStatus->on(0);
	noOfNodes = noOfNodes + 1;;
}
template <class T>bool MaxHeap<T>::isEmpty()
{
	if (!node)
		return true;
	return false;
}
template <class T>void MaxHeap<T>::setHeight(T h)
{
	maxNodes = pow(2.0, h) - 1; height = h; nodeStatus = new BitArray(maxNodes); node = new T[pow(2.0, (double)h - 1)];
}
template <class T>T MaxHeap<T>::getRoot()
{
	try
	{
		if (!node[0])
			throw NotAllowed("Root Not Exist");
		return node[0];
	}
	catch (NotAllowed&n)
	{
		n.printMsg();
	}
}
template <class T>void MaxHeap<T>::insert(T nod)
{
	int i = noOfNodes;
	bool flag = false;
	if (i > 0 && i < maxNodes)
	{
		node[i] = nod;
		nodeStatus->on(i);
		flag = true;
		noOfNodes = noOfNodes + 1;
	}
	if (flag == false)
		return;
	reBuildHeap();
}
template <class T>void MaxHeap<T>::mySwap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <class T>void MaxHeap<T>::reBuildHeap()
{
	int i = noOfNodes - 1;
	bool flag = false;
	while (i > 0 && !flag)
	{
		if (i % 2 == 0 && i < maxNodes)
		{
			if (node[i] > node[(i / 2) - 1])
			{
				mySwap(node[i], node[(i / 2) - 1]);
				i = (i / 2) - 1;
			}
			else
			{
				flag = true;
			}
		}
		else if (i % 2 == 1 && i < maxNodes)
		{
			if (node[i] > node[i / 2])
			{
				mySwap(node[i], node[i / 2]);
				i = i / 2;
			}
			else
			{
				flag = true;
			}
		}
	}
}
template <class T>void MaxHeap<T>::levelOrder()
{
	if (!isEmpty())
	{
		int i = 0;
		while (i < maxNodes)
		{
			if (nodeStatus->checkBitStatus(i))
			{
				cout << node[i] << " ";
			}
			i++;
		}
	}
}

template <class T>void MaxHeap<T>::LVR(int i)
{
	if (!node)
		return;
	if ((2 * i + 1 < maxNodes) && (nodeStatus->checkBitStatus(2 * i + 1)))
	{
		LVR(2 * i + 1);
	}
	cout << node[i] << " ";
	if ((2 * i + 2 < maxNodes) && (nodeStatus->checkBitStatus(2 * i + 2)))
	{
		LVR(2 * i + 2);
	}
}
template <class T>void MaxHeap<T>::inOrder()
{
	LVR(0);
}
template <class T> MaxHeap<T>::~MaxHeap()
{
	if (!node)
		return;
	delete node;
	node = 0;
	delete nodeStatus;
	nodeStatus = 0;
}


template MaxHeap<int>;