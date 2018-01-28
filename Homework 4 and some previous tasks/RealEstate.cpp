#include<iostream>
#include"LList.h"
#include"Graph.h"

using namespace std;

int main() {
	int Tests;
	cin >> Tests;
	for (int j = 0; j < Tests; j++) {
		Graph plan;
		int E;
		cin >> E;
		int cityCount = 0;
		int X, Y;
		for (int i = 0; i < E; i++) {
			cin >> X;
			cin >> Y;
			if (!plan.isTop(X)) {
				plan.AddTop(X);
				cityCount++;
			}
			if (!plan.isTop(Y)) {
				plan.AddTop(Y);
				cityCount++;
			}
		}
		cout <<"Number of cities bought in "<<j+1<<" test is:"<< cityCount << endl;

	}
	return 0;
}