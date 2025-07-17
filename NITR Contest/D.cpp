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
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;

    vector<int> freq(26);
    for(char c : s) {
        freq[c-'a']++;
    }

    int ans = 0;
    int mx = 0;
    bool flag = false;
    for(int val : freq) {
        if(val % 2 == 0) {
            ans += val; 
        }
        else {
            flag = true;
            ans += val-1;
        }
    }
    if(flag) {
        ans++;
    }

    cout<< ans <<endl;
}