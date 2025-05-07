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

bool isPossible(string s, int n, vector<int> &a, string &pat, int idx) {
    for(int i=0;i<=idx;i++) {
        s[a[i]] = '1';
    }
    int j = 0;
    for(int i=0;i<n && j < pat.size();i++) {
        if(s[i] == pat[j]) {
            j++;
        }
    }

    return j == (int)pat.size();
}

void solve() {
    string s;
    string pat;
    cin>>s>>pat;
    int n = s.size();
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
        a[i]--;
    }

    int maxm = -1;
    int low = 0, high = n-1;
    while(low <= high) {
        int mid = (low + high) /2;
        if(isPossible(s, n, a, pat, mid)) {
            low = mid+1;
            maxm = mid;
        }
        else {
            high = mid-1;
        }
    }
    cout<<maxm+1<<endl;
}