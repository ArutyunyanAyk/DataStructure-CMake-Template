#include <iostream>
#include <ostream>

template <class Type> class Queue;
template <class Type> std::ostream& operator <<(std::ostream& out, const Queue<Type>& pair);

template <class Type>
class Queue
{
	Type* data;
	size_t top;
	size_t size;
	int end;

public:

	Queue(size_t size1) {

		if (size1 < 1)
		{
			throw std::logic_error("Error!!! Size cant be <1");
		}
		size = size1;
		top = 0;
		end = -1;
		data = new Type[size1];
	}

	Type Pop()
	{
		if (!isEmpty()) {
			Type copy = this->Top();
			top++;
			return copy;
		}
		else {
			throw std::logic_error("Error!!! Queue is empty");
		}
	}
	Type Top() {
		if (this->isEmpty())
		{
			throw std::logic_error("Error!!! Queue is empty");
		}
		return data[this->top];
	}

	Type End()
	{
		if (this->isEmpty())
		{
			throw std::logic_error("Error!!! Queue is empty");
		}
		return data[this->end];
	}

	void push(const Type& val)
	{
		if (!isFull()) {
			end++;
			data[end] = val;
		}
		else {
			throw std::logic_error("Error!!!Queue is full");
		}
	}

	bool isFull() {
		if (end == (size - 1))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool isEmpty() {
		if (end < top)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	friend std::ostream& operator<<  <Type>(std::ostream& out, const Queue& q);

	~Queue() {
		delete[] data;
	}
};
template <class Type>
std::ostream& operator<< (std::ostream& out, const Queue<Type>& q) {
	for (int i = q.top; i <= q.end; i++)
	{
		std::cout << "\n| " << q.data[i] << " |";
	}
}