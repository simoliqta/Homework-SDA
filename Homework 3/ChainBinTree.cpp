#include<iostream>

using namespace std;
#define INITIAL_CAPACITY 10
template<typename T>
class ChainTree {
private:
	int indexRoot;
	T *a;
	int *b;
	int *c;
	int capacity;
	int size;
	void CopyTree(ChainTree<T> const&);
	void DeleteTree();
	void pr(int index) const;
	void resize(int _capacity);
public:
	ChainTree();
	~ChainTree();
	ChainTree(ChainTree<T> const&);
	ChainTree<T>& operator=(ChainTree<T> const&);
	T RootTree() const;
	bool empty() const;
	void print() const;
	void Create();
};
template<typename T>
void ChainTree<T>::CopyTree(ChainTree<T> const& _new) {
	a = new T[_new.capacity];
	b = new int[_new.capacity];
	c = new int[_new.capacity];
	size = _new.size;
	capacity = _new.capacity;
	indexRoot = _new.indexRoot;
	for (int i = 0; i < _new.size; i++) {
		a[i] = _new.a[i];
		b[i] = _new.b[i];
		c[i] = _new.c[i];
	}
}

template<typename T>
void ChainTree<T>::DeleteTree() {
	delete[] a;
	delete[] b;
	delete[] c;
}

template<typename T>
void ChainTree<T>::pr(int index) const {
	if (b[index] != -1) {
		pr(b[index]);
	}
	cout << a[index] << " ";
	if (c[index] != -1) {
		pr(c[index]);
	}
}

template<typename T>
ChainTree<T>::ChainTree() {
	a = new T[INITIAL_CAPACITY];
	b = new int[INITIAL_CAPACITY];
	c = new int[INITIAL_CAPACITY];
	indexRoot = 0;
	size = 0;
	capacity = INITIAL_CAPACITY;
}

template<typename T>
ChainTree<T>::~ChainTree() {
	DeleteTree();
}

template<typename T>
ChainTree<T>::ChainTree(ChainTree<T> const & _new) {
	CopyTree(_new);
}

template<typename T>
ChainTree<T>& ChainTree<T>::operator=(ChainTree<T> const & _new) {
	if (this != &_new)
	{
		DeleteTree();
		CopyTree(_new);
	}
	return *this;
}

template<typename T>
T ChainTree<T>::RootTree() const {
	return a[indexRoot];
}

template<typename T>
bool ChainTree<T>::empty() const {
	return size == 0;
}

template<typename T>
void ChainTree<T>::print() const {
	pr(indexRoot);
}

template<typename T>
void ChainTree<T>::Create() {
	T x;
	char verification;
	int sizeR = size;
	if (size == 0) {
		cout << "plese input a root: ";
		cin >> x;
		indexRoot = 0;
		a[indexRoot] = x;
	}
	else {
		if (size - 1 > capacity)
			resize(capacity);
		cin >> x;
		a[size] = x;
	}
	size++;

	cout << "Does " << x << " has a left tree? y/n";
	//we expect correct input of verification
	cin >> verification;
	if (verification == 'y') {
		b[size - 1] = size;
		Create();
	}
	else
		b[size - 1] = -1;

	cout << "Does " << x << " has a right tree? y/n";
	//we expect correct input of verification
	cin >> verification;
	if (verification == 'y') {
		c[sizeR] = size;
		Create();
	}
	else
		c[sizeR] = -1;
}

template<typename T>
void ChainTree<T>::resize(int _capacity) {
	T *_newA = new T[2 * _capacity];
	T *_newB = new int[2 * _capacity];
	T *_newC = new int[2 * _capacity];
	for (int i = 0; i < size; i++)
	{
		_newA[i] = a[i];
		_newB[i] = b[i];
		_newC[i] = c[i];
	}
	a = _newA;
	b = _newB;
	c = _newC;
	delete[] _newA;
	delete[] _newB;
	delete[] _newC;
	capacity = 2 * _capacity;
}
int main() {
	ChainTree<int> tree;
	tree.Create();
	cout << "Root of the tree is: "" " << tree.RootTree() << endl;
	tree.print();
	cout << endl;
	system("pause");
	return 0;
}
