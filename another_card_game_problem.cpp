#include"bits/stdc++.h"
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    int pc, pr;

    while(t--) {
        cin >> pc >> pr;

        int chef_score = pc/9;
        int rick_score = pr/9;

        if(pc % 9 != 0) {
            chef_score = chef_score + 1;
        }

        if(pr % 9 != 0) {
            rick_score = rick_score + 1;
        }

        if(chef_score < rick_score) {
            cout << "0 " << chef_score << "\n";
        }
        else {
            cout << "1 " << rick_score << "\n";
        }
    }
    return 0;
}