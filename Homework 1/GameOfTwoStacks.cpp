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

int main() {
	int number_of_games;
	cin >> number_of_games;
	LStack<int> stackA1;
	LStack<int> stackA;
	LStack<int> stackB1;
	LStack<int> stackB;
	int numA, numB, x, element, counter = 0, sum = 0;
	for (int i = 0; i < number_of_games; i++) {
		cin >> numA >> numB >> x;
		for (int j = 0; j < numA; j++) {
			cin >> element;
			stackA1.push(element);
		}
		for (int p = 0; p < numB; p++) {
			cin >> element;
			stackB1.push(element);
		}
		for (int j = 0; j < numA; j++) {
			stackA.push(stackA1.pop());
		}
		for (int p = 0; p < numB; p++) {
			stackB.push(stackB1.pop());
		}
	}

	while (sum <= x) {
		counter++;
		if (stackA.top() > stackB.top()) {
			sum += stackB.top();
			stackB.pop();
		}
		else {
			sum += stackA.top();
			stackA.pop();
		}
	}
	cout << counter - 1 << endl;
	/*cout << endl;
	for (int j = 0; j < numA; j++) {
		cout<<stackA.pop()<<" ";
	}
	cout << endl;
	for (int p = 0; p < numB; p++) {
		cout << stackB.pop() << " ";
	}
	cout << endl;*/
	return 0;
}