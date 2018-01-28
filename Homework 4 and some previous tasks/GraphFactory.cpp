#include <iostream>
using namespace std;

int main() {

    int v;
    int sum = 0;

    cin >> v;

    int i = vertexes;
    while (i--) {
        int num;
        cin >> num;
        sum+= num;
    }
    
    if(sum / 2 == v - 1) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
