#include<iostream>
using namespace std;
#include"MaxHeap.h"
int main()
{
	MaxHeap<int>m(4);
	m.setRoot(20);
	m.insert(11);
	m.insert(15);
	m.insert(10);
	m.insert(8);
	m.insert(12);
	m.levelOrder();
	cout << endl;
	m.insert(21);
	m.levelOrder();
}