#include <memory>
#include "DoublyLinkedNode.cpp"

template <typename T>
class DoublyLinkedList
{
public:
	int Size;
	std::unique_ptr<DoublyLinkedNode<T>> First;
	void Add(T);
	void Clear();
	void Delete(T);
	bool Found(T);
	void GetAllForward();
	DoublyLinkedList();
	~DoublyLinkedList();
};
