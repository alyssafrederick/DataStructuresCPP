#include <memory>
#include "DoublyLinkedNode.cpp"

template <typename T>
class DoublyLinkedList
{
public:
	int Size;
	std::unique_ptr<DoublyLinkedNode<T>> First;
	void AddAtEnd(T);
	void AddAtStart(T);
	void AddAt(T, int);
	void Clear();
	void DeleteAtEnd();
	void DeleteAtStart();
	void DeleteValue(T);
	void DeleteAt(int);
	bool Found(T);
	void GetAllForward();
	bool IsEmpty();
	DoublyLinkedList();
	~DoublyLinkedList();
};
