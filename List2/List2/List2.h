#pragma once
template<typename _Ty>
class List2
{
public:
	List2();
	~List2();

	void push_back(_Ty data);
	void push_front(_Ty data);
	void pop_back();
	void pop_front();
	void removeAT(size_t index);
	_Ty& at(size_t index);
	void clear();
	int GetSize();
	void insert(_Ty data, size_t index);
	_Ty& operator[](const size_t index);

private:
	template<typename _Ty>
	class Node
	{
	public:
		Node* pNext;
		Node* pBack;
		_Ty data;
		Node(_Ty data = _Ty(), Node* pNext = nullptr, Node* pBack = nullptr)
		{
			this->data = data;
			this->pBack = pBack;
			this->pNext = pNext;

		}
	};
	int size;
	Node<_Ty>* head;
};

template<typename _Ty>
inline List2<_Ty>::List2()
{
	size = 0;
	head = nullptr;
}

template<typename _Ty>
inline List2<_Ty>::~List2()
{
	clear();
}

template<typename _Ty>
inline void List2<_Ty>::push_back(_Ty data)
{
	if (head == nullptr)
	{
		head = new Node<_Ty>(data);
	}
	else
	{
		Node<_Ty>* current = this->head;
		Node<_Ty>* currentBack = nullptr;
		Node<_Ty>* Newcurrent = new Node<_Ty>(data);
		while (current->pNext != nullptr)
		{
			currentBack = current;
			current = current->pNext;
		}
		current->pNext = Newcurrent;
		Newcurrent->pBack = current;
		current->pBack = currentBack;
	}
	++size;
}

template<typename _Ty>
inline void List2<_Ty>::push_front(_Ty data)
{
	if (head == nullptr)
	{
		head = new Node<_Ty>(data);
	}
	else
	{
		Node<_Ty>* current = new Node<_Ty>(data);
		this->head->pBack = current;
		current->pNext = head;
		this->head = current;
	}
	++size;
}

template<typename _Ty>
inline void List2<_Ty>::pop_back()
{
	removeAT(size - 1);
}

template<typename _Ty>
inline void List2<_Ty>::pop_front()
{
	if (head == nullptr)
	{
		return;
	}
	else
	{
		Node<_Ty>* temp = head;
		head = head->pNext;
		if(head != nullptr)
		{
			head->pBack = nullptr;
		}
		delete temp;
		--size;
	}
	
}

template<typename _Ty>
inline void List2<_Ty>::removeAT(size_t index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<_Ty>* previous = head;
		for (size_t i = 0; i < index - 1; ++i)
		{
			previous = previous->pNext;
		}
		Node<_Ty>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		--size;
	}
}

template<typename _Ty>
inline _Ty& List2<_Ty>::at(size_t index)
{
	if (index > size - 1)
	{
		throw std::string("you are outside the list");
	}
	else
	{
		int counter = 0;
		Node<_Ty>* current = this->head;
		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->data;
			}
			current = current->pNext;
			++counter;
		}
	}

}

template<typename _Ty>
inline void List2<_Ty>::clear()
{
	while (size)
	{
		pop_front();
	}
}

template<typename _Ty>
inline int List2<_Ty>::GetSize()
{
	return size;
}

template<typename _Ty>
inline void List2<_Ty>::insert(_Ty data, size_t index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<_Ty>* previous = this->head;
		for (size_t i = 0; i < index - 1; ++i)
		{
			previous = previous->pNext;
		}
		Node<_Ty>* newNode = new Node<_Ty>(data, previous->pNext, previous->pBack);
		Node<_Ty>* Next = previous->pNext;
		newNode->pBack = previous;
		Next->pBack = newNode;
		previous->pNext = newNode;
		++size;
	}
}

template<typename _Ty>
inline _Ty& List2<_Ty>::operator[](const size_t index)
{
	int counter = 0;
	Node<_Ty>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		++counter;
	}
}
