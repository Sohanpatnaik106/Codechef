#include"bits/stdc++.h"
using namespace std;

int subMain() {
    long long n, answer = 0;
    cin >> n;
    vector<long long> xor_sum;
    long long x;
    for(long long i = 1; i <= 20; i++) {
        cout << 1 << " " << (1ul << i) << "\n";
        cout.flush();
        cin >> x;
        xor_sum.push_back(x);
    }
    reverse(xor_sum.begin(), xor_sum.end());
    long long sum = xor_sum[0] - n * (1ul << 20);
    for(long long i = 1; i < xor_sum.size(); i++) {
        if(xor_sum[i] >= sum) {
            xor_sum[i] = ((n - (xor_sum[i] - sum) / (1ul << (xor_sum.size() - i))) / 2);
        }
        else {
            xor_sum[i] = (n + (sum - xor_sum[i]) / (1ul << (xor_sum.size() - i))) / 2;
        }
    }
    for(int i = 1; i < xor_sum.size(); i++)
        if(xor_sum[i] % 2 != 0) 
            answer+=1ul<<(xor_sum.size() - i);
    if(sum % 2 != 0)
        answer++;
    cout << 2 << " " << answer << "\n";
    cout.flush();
    int result;
    cin >> result;
    return result;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--) {
        if(!subMain()) 
            break;
        cout << "\n";
        cout.flush();
    }
    return 0;
}