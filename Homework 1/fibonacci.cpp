#include<iostream>

using namespace std;

int fibonacci(int n) {
	if (n == 1) return n;
	if (n == 0) return n;
	return fibonacci(n - 1) + fibonacci(n - 2);
}
unsigned long long fibonacciOpt(unsigned long long n) {
	unsigned long long *p = new unsigned long long[n + 1];
	p[0] = 0;
	p[1] = 1;
	for (int i = 2; i <= n; i++) {
		p[i] = p[i - 1] + p[i - 2];
	}
	return p[n];
	delete[] p;
}
int main() {
	unsigned long long x;
	cin >> x;
	//cout << fibonacci(x) << endl;
	cout << fibonacciOpt(x) << endl;

	system("pause");
	return 0;
}