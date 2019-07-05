#ifndef MAXHEAP_H
#define MAXHEAP_H
#include"BitArray.h"

template<class T>
class MaxHeap
{
	BitArray*nodeStatus;
	T *node;
	int maxNodes;
	int height;
	int noOfNodes;

	void removeChilds(int i);
	void ancestors(int);
	void descendents(int);
	int measureHeightOfTree(int);
	void VLR(int i);
	void LRV(int i);
	void LVR(int i);
	void parenthesizedView(int);
	void reBuildHeap();
	void mySwap(T &a, T &b);
public:
	MaxHeap();
	MaxHeap(int h);
	~MaxHeap();

	void setRoot(T v);
	T getRoot();
	bool isEmpty();
	void setHeight(T h);
	void insert(T);
	T getParent(T node);
	int searchInd(T val);
	void remove(T nod);
	void diplayAncestors(T nod);
	void displayDescendents(T nod);
	int heightOfTree();
	void preOrder();
	void postOrder();
	void inOrder();
	void levelOrder();
	void displayLevel(int levelNo);
	int findLevelOfNode(T nod);
	void displayParenthesizedView();
	void displayExplorerView();
};

#endif
