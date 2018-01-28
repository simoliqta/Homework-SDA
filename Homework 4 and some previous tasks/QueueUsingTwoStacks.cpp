#include<iostream>

using namespace std;

template<typename T>
struct node {
	T data;
	node* next;
};

template<typename T>
class LStack {
private:
	node<T>* topNode;
	void copy(node<T>* toCopy);
	void eraseStack();
	void copyStack(LStack const&);
public:
	LStack();
	LStack(LStack const&);
	LStack& operator=(LStack const&);
	~LStack();

	bool empty() const;
	void push(T const& x);
	T pop();
	T top() const;
	T findMax()const;
};

template<typename T>
LStack<T>::LStack() : topNode(nullptr) {}

template<typename T>
bool LStack<T>::empty() const {
	return topNode == nullptr;
}

template<typename T>
void LStack<T>::push(T const& x) {
	node<T>* p = new node<T>;
	p->data = x;
	p->next = topNode;
	topNode = p;
}

template<typename T>
T LStack<T>::pop() {
	if (empty()) {
		cerr << "empty stack!\n";
		return 0;
	}
	node<T>* p = topNode;
	topNode = topNode->next;
	T x = p->data;
	delete p;
	return x;
}

template<typename T>
T LStack<T>::top() const {
	if (empty()) {
		cerr << "empty stack!\n";
		return 0;
	}
	return topNode->data;
}

template<typename T>
void LStack<T>::eraseStack() {
	while (!empty()) {
		pop();
	}
}

template<typename T>
LStack<T>::~LStack() {
	eraseStack();
}

template<typename T>
void LStack<T>::copy(node<T>* toCopy) {
	if (toCopy == nullptr)
		return;
	copy(toCopy->next);
	push(toCopy->data);
}

template<typename T>
void LStack<T>::copyStack(LStack const& ls) {
	topNode = nullptr;
	copy(ls.topNode);
}

template<typename T>
LStack<T>::LStack(LStack const& ls) {
	copyStack(ls);
}

template<typename T>
LStack<T>& LStack<T>::operator=(LStack const& ls) {
	if (this != &ls) {
		eraseStack();
		copyStack(ls);
	}
	return *this;
}

template <typename T>
class QueueUsingTwoStacks
{
	LStack<T> PushStack;
	LStack<T> PopStack;
public:
	void enqueue(T const &x);
	T dequeue();
	T top()
	{
		return PushStack.top();
	}
};
template <typename T>
void QueueUsingTwoStacks<T>::enqueue(T const &x)
{
	while (!PushStack.empty())
	{
		PopStack.push(PushStack.pop());
	}
	PushStack.push(x);
	while (!PopStack.empty())
	{
		PushStack.push(PopStack.pop());
	}
}
template <typename T>
T QueueUsingTwoStacks<T>::dequeue()
{
	if (PushStack.empty())
	{
		std::cout << "Queue is empty\n";
		return T();
	}
	return PushStack.pop();
}

int main()
{
	QueueUsingTwoStacks<int> queue;
	int number;
	int counter = 0;
	cin >> number;
	int* topPrint = new int[number];
	for (int i = 0; i < number; i++)
	{
		int query;
		cin >> query;
		switch (query)
		{
		case 1:
			int x;
			cin >> x;
			queue.enqueue(x);
			break;
		case 2:
			queue.dequeue();
			break;
		case 3:
			topPrint[counter] = queue.top();
			counter++;
			break;
		}
	}
	for (int i = 0; i < counter; i++)
	{
		cout << topPrint[i] << std::endl;
	}
	return 0;
}