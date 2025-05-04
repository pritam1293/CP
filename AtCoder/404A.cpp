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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    string s;
    cin>>s;
    vector<int> freq(26);
    for(char c : s) {
        freq[c-'a']++;
    }
    for(int i=0;i<26;i++) {
        if(freq[i] == 0) {
            cout<<char('a' + i)<<endl;
            break;
        }
    }
}