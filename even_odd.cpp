#include"bits/stdc++.h"
using namespace std;

int modulo = 1000000007;

vector<vector<int>> ncr_matrix(int k) {
    vector<vector<int>> matrix(k+1, vector<int> (k+1));
    for(int i = 0; i < k+1; i++) {
        matrix[i][0] = 1;
    }
    for(int i = 1; i < k+1; i++) {
        for(int j = 1; j < k+1; j++) {
            matrix[i][j] = (matrix[i-1][j-1] + matrix[i-1][j]) % modulo;
        }
    }
    return matrix;
} 

int main() {
    int low, high;
    cin >> low >> high;
    int k;
    cin >> k;
    vector<vector<int>> matrix = ncr_matrix(k);
    int no_of_even = 0, no_of_odd = 0;
    for(int i = low; i <= high; i++) {
        if(i % 2 == 0) {
            no_of_even++;
        }
        else {
            no_of_odd++;
        }
    }
    int total_permutations = 0;
    for(int i = 0; i <= (k - (k%2)); i+=2) {
        int val = 1;
        for(int j = 0; j < i; j++) {
            val = (val * no_of_odd) % modulo;
        }
        for(int j = 0; j < k - i; j++) {
            val = (val * no_of_even) % modulo;
        }
        total_permutations = (total_permutations + ((val * matrix[k][i]) % modulo)) % modulo;
    }
    cout << total_permutations << "\n";
}