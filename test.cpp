#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

char findChar(int level, int pos, vector<int> &lengths, string &s) {
    if(level == 0ll) return s[pos];
    int left = lengths[level-1ll];
    int dollar = level;
    int right = left + dollar;

    if(pos < left) {
        return findChar(level-1ll, pos, lengths, s);
    }
    else if(pos < right) {
        return '$';
    }
    else{
        int rev_pos = pos - right;
        int org_pos = left - 1ll - rev_pos;
        return findChar(level-1ll, org_pos, lengths, s);
    }
}

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int q;
    cin>>q;
    vector<int> lengths;
    lengths.push_back((int)s.size());
    int level = 0;
    int limit = 1e18;
    while(lengths.back() < limit) {
        int prev = lengths.back();
        lengths.push_back(prev + level + 1ll + prev);
        level++;
    }
    while(q--) {
        int pos;
        cin>>pos;
        pos--;
        int l = level;

        while(l >= 0 && lengths[l] > pos) l--;
        cout<<findChar(l + 1ll, pos, lengths, s)<<endl;
    }
}