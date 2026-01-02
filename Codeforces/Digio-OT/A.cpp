#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    int t=1;
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

bool compare(pair<int, int> &a, pair<int, int> &b) {
    return a.second > b.second;
}

void solve() {
    int n, k;
    cin>>n>>k;
    vector<int> a(2*n);
    for(int i = 0; i < 2*n; i++) {
        cin>>a[i];
    }
    vector<int> first(n+1), second(n+1);
    for(int i = 0; i < n; i++) {
        first[a[i]]++;
        second[a[i+n]]++;
    }
    vector<pair<int, int>> left, right;
    for(int i = 1; i <= n; i++) {
        if(first[i]) left.push_back({i, first[i]});
        if(second[i]) right.push_back({i, second[i]});
    }
    sort(left.begin(), left.end(), compare);
    sort(right.begin(), right.end(), compare);
    // for(auto& [f, s] : left) {
    //     cout<<f<<" "<<s<<endl;
    // }
    int size = 2*k;
    vector<int> single;
    int i = 0;
    while(size > 0) {
        if(left[i].second == 2) {
            cout<<left[i].first<<" "<<left[i].first<<" ";
            size -= 2;
        }
        else {
            cout<<left[i].first<<" ";
            single.push_back(left[i].first);
            size--;
        }
        i++;
    }
    cout<<endl;
    size = 2*k - (int)single.size();
    for(auto& e : single) {
        cout<<e<<" ";
    }
    i = 0;
    while(size > 0) {
        cout<<right[i].first<<" "<<right[i].first<<" ";
        i++;
        size -= 2;
    }
    cout<<endl;
    // cout<<endl;
}