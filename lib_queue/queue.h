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
	size_t end;


	Queue(int size1) {

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

	friend std::ostream& operator<<  <Type>(std::ostream& out, const Queue& stack);

	~Queue() {
		delete[] data;
	}
};
template <class Type>
std::ostream& operator<< (std::ostream& out, const Queue<Type>& stack) {
	for (int i = 0; i <= Queue.top; i++)
	{
		std::cout << "\n| " << Queue.datd[i] << " |";
	}
}