#pragma once
#include<iostream>
#include "LList.h"
using namespace std;
typedef LList<int> IntList;
typedef LList<IntList> IntGraph;

class Graph
{
	IntGraph g;
public:
	elem_link<int>* Point(int a);
	void AddTop(int a);
	void AddRib(int a, int b);
	void create_graph();
	void print();
	bool isTree();
	bool isTop(int a);
};

elem_link<int>* Graph::Point(int a)
{
	g.IterStart();
	elem_link<IntList>*p;
	elem_link<int> *q;
	do
	{
		p = g.Iter();
		p->inf.IterStart();
		q = p->inf.Iter();
	} while (q->inf != a);
	return q;
}
void Graph::AddTop(int a)
{
	IntList l;
	l.ToEnd(a);
	g.ToEnd(l);
}
void Graph::AddRib(int a, int b)
{
	elem_link<int> * q = Point(a), *p;
	while (q->link) q = q->link;
	p = new elem_link<int>;
	p->inf = b;
	p->link = NULL;
	q->link = p;
}
void Graph::create_graph()
{
	char c;
	do
	{
		cout << "top_of_graph: ";
		int x; cin >> x;
		AddTop(x);
		cout << "Top y/n? "; cin >> c;
	} while (c == 'y');
	cout << "Ribs:\n";
	do
	{
		cout << "start top: ";
		int x; cin >> x;
		cout << "end top: ";
		int y; cin >> y;
		AddRib(x, y);
		cout << "next: y/n? "; cin >> c;
	} while (c == 'y');
}
void Graph::print()
{
	g.IterStart();
	elem_link<IntList> *p = g.Iter();
	while (p)
	{
		p->inf.print();
		p = p->link;
	}
	cout << endl;
}
bool Graph::isTop(int a) {
	g.IterStart();
	elem_link<IntList>*p=g.Iter();
	elem_link<int> *q;
	while (p) {
		p->inf.IterStart();
		q = p->inf.Iter();
		if (q->inf == a) return true;
		else {
			p = g.Iter();
			if (!p) return false;
			p->inf.IterStart();
			q = p->inf.Iter();
		}
	}
}
//bool Graph::isTree() {
//
//}