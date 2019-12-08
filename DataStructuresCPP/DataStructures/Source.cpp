#include <memory>
#include <iostream>
#include <vector>
#include <string>
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "CircularlyDoublyLinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "binarySearchTree.h"
#include "sorts.h"
#include "AVLtree.h"
#include "HeapTree.h"
#include "DirectedGraph.h"
#include "UndirectedGraph.h"
#include "HashMap.h"

int main()
{
	SinglyLinkedList<int> linkedList;
	DoublyLinkedList<int> dll;
	CircularlyDoublyLinkedList<int> cdll;
	Stack<int> stk;
	Queue<int> q;
	binarySearchTree<int> bst;
	Sorts<int> numbers;
	AVLtree<int> avltree;
	HeapTree<int> heap;
	DirectedGraph<int> grf;
	UndirectedGraph<int> ugrf;
	UndirectedGraph<int> ugrf2;
	HashMap hm;

	//12. hash map
	/*hm.HashFunction("hi");
	hm.HashFunction("ih");
	hm.HashFunction("what's up");
	hm.Add("hi", 1);
	hm.Add("yo", 2);
	hm.Add("hello", 3);
	hm.Add("what's up", 4);
	hm.Add("morning", 5);
	hm.Add("howdy", 6);
	//hm.Remove("morning", 5);
	//hm.Remove("yo", 2);
	hm.Display();
	hm.Add("okay", 7);
	hm.Add("its fine", 8);
	hm.Display();*/

	//11. weighted, directed graphs
	/*
	bool line1 = grf.AddEdge(grf.AddVertex(2), grf.AddVertex(9), 3);		//2 -> 9
	bool line2 = grf.AddEdge(grf.AddVertex(3), grf.AddVertex(10), 5);		//3 -> 10
	bool line3 = grf.AddEdge(grf.AddVertex(5), grf.Search(2).at(0), 4);		//5 -> 2
	bool line4 = grf.AddEdge(grf.AddVertex(4), grf.Search(2).at(0), 10);	//4 -> 2

	//works alone// bool result = grf.RemoveVertex(item);
	//works alone// grf.RemoveEdge(grf.Search(2).at(0), grf.Search(9).at(0));
	grf.RemoveVertex(grf.Search(2).at(0));
	grf.GetEdge(grf.Search(3).at(0), grf.Search(10).at(0));
	*/

	//10. unweighted, undirected graphs
	/*
	bool line5 = ugrf.AddEdge(ugrf.AddVertex(2), ugrf.AddVertex(9));		//2 <-> 9
	bool line6 = ugrf.AddEdge(ugrf.AddVertex(3), ugrf.AddVertex(10));		//3 <-> 10
	bool line7 = ugrf.AddEdge(ugrf.AddVertex(5), ugrf.Search(2).at(0));		//5 <-> 2
	bool line8 = ugrf.AddEdge(ugrf.AddVertex(4), ugrf.Search(2).at(0));		//4 <-> 2
	//ugrf.RemoveVertex(ugrf.Search(2).at(0));  //utilizes RemoveEdge so I know that works too!
	ugrf.BreadthFirstTraversal(ugrf.Search(4).at(0));
	ugrf.DepthFirstTraversal(ugrf.Search(4).at(0));
	
	bool line9 = ugrf2.AddEdge(ugrf2.AddVertex(9), ugrf2.AddVertex(5));
	bool line10 = ugrf2.AddEdge(ugrf2.Search(9).at(0), ugrf2.AddVertex(12));
	bool line11 = ugrf2.AddEdge(ugrf2.Search(5).at(0), ugrf2.AddVertex(3));
	bool line12 = ugrf2.AddEdge(ugrf2.Search(5).at(0), ugrf2.AddVertex(7));
	bool line13 = ugrf2.AddEdge(ugrf2.Search(12).at(0), ugrf2.AddVertex(11));
	bool line14 = ugrf2.AddEdge(ugrf2.Search(12).at(0), ugrf2.AddVertex(14));
	ugrf2.BreadthFirstTraversal(ugrf2.Search(9).at(0));
	ugrf2.DepthFirstTraversal(ugrf2.Search(9).at(0));
	*/

	//9. heap tree
	/*heap.Add(3);
	heap.Add(10);
	heap.Add(5);
	heap.Add(6);
	heap.Add(4);
	heap.Pop();
	heap.Pop();
	heap.Pop();*/

	//8. avl tree
	/*avltree.Add(4);
	avltree.Add(9);
	avltree.Add(13);
	avltree.Add(2);
	avltree.Add(6);
	avltree.Add(1);
	avltree.Add(2);
	avltree.Add(3);
	avltree.Add(4);
	avltree.Add(5);
	avltree.Add(6);
	avltree.Add(7);
	avltree.Add(8);
	avltree.Add(9);
	avltree.Add(10);
	avltree.Add(9);
	avltree.Add(8);
	avltree.Add(7);
	avltree.Add(6);
	avltree.Add(4);
	avltree.Add(5);
	//avltree.Add(3);
 	avltree.Remove(6);*/

	//7. sorts
	/*
	//doing sorts with arrays: learn more about this!
	//std::array<int, 4>;
	//std::vector<int> numbers;

	//5, 2, 4, 10, 15, 9, 13
	numbers.toSort.push_back(5);
	numbers.toSort.push_back(2);
	numbers.toSort.push_back(4);
	numbers.toSort.push_back(10);
	numbers.toSort.push_back(15);
	numbers.toSort.push_back(9);
	numbers.toSort.push_back(13);

	//numbers.BubbleSort();
	//numbers.SelectionSort(); 
	//numbers.InsertionSort();
	//numbers.MergeSort(0, numbers.toSort.size());
	//numbers.QuickSort(0, numbers.toSort.size());

	for (int i = 0; i < numbers.toSort.size(); i++)
	{
		std::cout << numbers.toSort.at(i) << std::endl;
	}
	*/

	//6. binary search tree
	/*
	bst.Add(10);
	bst.Add(5);
	bst.Add(15);
	bst.Add(13);
	bst.Add(17);
	bst.Add(16);
	bst.Add(8);
	bst.Add(14);
	//bst.Remove(16); //works
	//bst.Remove(13); //works
	//bst.Remove(5); //works
	//bst.Remove(17); //works
	//bst.Remove(8); //works
	//bst.Remove(15); //works
	//bst.Remove(10); //works
	bst.Search(17);
	bst.TraversePreOrder(bst.Root.get());
	while (bst.order->IsEmpty() != true)
	{
		std::cout << bst.order->Pop() << std::endl;
	}
	bst.TraversePostOrder(bst.Root.get());
	while (bst.order->IsEmpty() != true)
	{
		std::cout << bst.order->Pop() << std::endl;
	}
	bst.TraverseInOrder(bst.Root.get());
	while (bst.order->IsEmpty() != true)
	{
		std::cout << bst.order->Pop() << std::endl;
	}
	bst.TraverseLevelOrder();
	while (bst.order->IsEmpty() != true)
	{
		std::cout << bst.order->Pop() << std::endl;
	}
	*/

	// 5. queue
	/*
	q.Enqueue(2);
	q.Enqueue(3);
	q.Enqueue(4);
	q.Enqueue(5);
	std::cout << q.Dequeue() << std::endl;  //2
	std::cout << q.Peek() << std::endl;  //3
	q.Clear();
	*/

	// 4. stack
	/*
	stk.Push(3);
	stk.Push(8);
	stk.Push(12);
	std::cout << stk.Peak() << std::endl;
	std::cout << stk.Pop() << std::endl;
	std::cout << stk.Pop() << std::endl;
	//checking for memory leaks.. all good
	while (true)
	{
		for (size_t i = 0; i < 10000; i++)
		{
			stk.Push(i);
		}
		stk.Clear();
	}
	*/

	// 3. circularly doubly linked list
	/*
	cdll.AddAtHead(8);    // 8
	cdll.AddAtHead(4);    // 4 8
	cdll.AddAtTail(10);   // 4 8 10
	cdll.AddAt(6, 1);     // 4 6 8 10
	cdll.DeleteAtTail();  // 4 6 8
	cdll.DeleteAt(2);     // 4 6
	cdll.DeleteAt(0);     // 6
	cdll.AddAtTail(7);
	cdll.AddAtTail(8);
	cdll.AddAtTail(9);
	cdll.AddAtTail(10);   // 6 7 8 9 10
	cdll.DeleteValue(8);  // 6 7 9 10
	*/

	// 2. doubly linked list
	/*
	dll.AddAtEnd(1);
	dll.AddAtEnd(2);
	dll.AddAtEnd(3);
	dll.AddAtEnd(4);
	dll.AddAtStart(0);
	dll.GetAllForward();
	dll.DeleteValue(2);
	dll.GetAllForward();
	dll.AddAt(7, 2);
	dll.GetAllForward();
	dll.DeleteAtEnd();
	dll.GetAllForward();
	dll.DeleteAtStart();
	dll.GetAllForward();
	dll.DeleteAt(1);
	dll.GetAllForward();
	*/

	// 1. singly linked list
	/*
	linkedList.Add(1);
	linkedList.Add(2);
	linkedList.Add(3);
	linkedList.Add(4);
	linkedList.Add(5);
	linkedList.Add(6);
	linkedList.GetAll();
	linkedList.Found(6);  //true
	linkedList.Found(66); //false
	linkedList.Delete(6);
	linkedList.GetAll();
	*/

	std::cout << "end!" << std::endl;
	system("pause");
	
	return 0;
} 
