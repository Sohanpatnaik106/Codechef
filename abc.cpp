#include"bits/stdc++.h"
using namespace std;

int main() {
    int a = 1, b = 2, c = 3, d = 4;

    for(int i = 1; i <= 20; i++) {
        cout << (a ^ (1ul << i)) + (b ^ (1ul << i)) + (c ^ (1ul << i)) + (d ^ (1ul << i)) << " ";
    }
    
    cout << "\n" << (1ul << 20) << "\n";
    return 0;
}