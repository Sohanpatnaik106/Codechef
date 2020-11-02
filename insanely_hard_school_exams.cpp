#include"bits/stdc++.h"
using namespace std;

bool sort_by_val(const pair<long long, long long> &a, const pair<long long, long long> &b) {
    return (a.second >= b.second);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long t;
    cin >> t;

    while(t--) {
        long long n, c, k;
        cin >> n >> c >> k;
        vector<long long> ai(n), bi(n), ci(n);
        for(long long i = 0; i < n; i++) {
            cin >> ai[i] >> bi[i] >> ci[i];
        }
        vector<long long> v(c);
        for(long long i = 0; i < c; i++) {
            cin >> v[i];
        }        
        //long long erase = v[0];
        map<long long, long long> lines;
        for(long long i = 0; i < n; i++) {
            if(lines.find(ci[i]) != lines.end()) {
                lines[ci[i]]++;
            }
            else {
                lines.insert({ci[i], 1});
            }
        }
        long long number_of_triangles = 0;
        vector<pair<long long, long long>> line_cont;
        map<long long, long long> :: iterator it;
        /*for(it = lines.begin(); it != lines.end(); it++) {
            line_cont.push_back(make_pair(it->first, it->second));
        }

        sort(line_cont.begin(), line_cont.end(), sort_by_val);
        long long number_of_triangles = 0;
        
        vector<pair<long long, long long>> :: iterator it1;
        it1 = line_cont.begin();
        long long delete_times = k / erase;
        long long deleted = 0;
        while(deleted < delete_times && it1 != line_cont.end()) {
            if(it1->second <= 2) {
                //line_cont.erase(it1);
                it1++;
                //k = k - erase;
                //it1->second = it1->second - 1;
            }
            else {
                deleted++;
                it1->second = it1->second - 1;
            }
        }
        
        it1 = line_cont.begin();
        while(it1 != line_cont.end()) {
            number_of_triangles = number_of_triangles + (((it1->second) * (it1->second-1) * (it1->second-2)) / 6);
            it1++;
        } */
        vector<long long> count;
        for(it = lines.begin(); it != lines.end(); it++) {
            count.push_back(it->second);
        }
        //long long delete_times = k / erase;
        //long long deleted = 0;
        /*while(deleted < delete_times) {
            *(max_element(count.begin(), count.end())) = *(max_element(count.begin(), count.end())) - 1;
            deleted++;
        } */
        long long index;
        while(k >= 0) {
            index = max_element(count.begin(), count.end()) - count.begin();
            k = k - v[index];
            if(k <= 0) {
                break;
            } 
            *(max_element(count.begin(), count.end())) = *(max_element(count.begin(), count.end())) - 1;
        }

        for(int i = 0; i < count.size(); i++) {
            number_of_triangles = number_of_triangles + (((count[i]) * (count[i] - 1) * (count[i] - 2)) / 6);
        }
        cout << number_of_triangles << "\n"; 
    }
    return 0;
}