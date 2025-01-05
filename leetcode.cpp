#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

int countPalindromicSubsequence(string s) {
    vector<int> first(26,-1) , last(26,-1);
    for(int i=0;i<s.size();i++) {
        int idx = s[i]-'a';
        if(first[idx] == -1) {
            first[idx] = i;
        }
        else {
            last[idx] = i;
        }
    }

    // for(int i=0;i<26;i++) {
    //     cout<< (char)(i+'a')<<"  "<<first[i]<<" " <<last[i]<<endl;
    // }
    // cout<<endl;

    int cnt = 0;
    for(int i=0;i<26;i++) {
        if(last[i] != -1) {
            set<char> st;
            for(int idx = first[i]+1;idx <= last[i]-1;idx++) {
                st.insert(s[idx]);
            }
            cnt += st.size();
            cout<<st.size()<<endl;
        }
    }
    cout<<endl;
    return cnt;
}

void solve() {
    string s = "bbcbaba";
    cout<<countPalindromicSubsequence(s);
}
