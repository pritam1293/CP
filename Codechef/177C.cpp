#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t=1;
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    vector<pair<int,int>> idx;
    int i = 0;
    while(i < n) {
        if(s1[i] == s2[i]) {
            i++;
            continue;
        }

        int st = i;
        int end = i;
        while(end < n && s1[end] != s2[end]) {
            end++;
        }
        i = end;
        idx.push_back({st+1, end});
    }
    cout<<idx.size()<<endl;
    for(auto pair : idx) {
        cout<<"1 "<<pair.first<<" "<<pair.second<<endl;
    }
}