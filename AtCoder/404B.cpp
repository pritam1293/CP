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

int moves(vector<string> &s, vector<string> &t, int n) {
    int cnt = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(s[i][j] != t[i][j]) cnt++;
        }
    }
    return cnt;
}

void rotate90(vector<string> &mat, int n){ 
    for (int i = 0; i < n/2; i++){
        for (int j = 0; j < n; j++){
            swap(mat[i][j], mat[n - i - 1][j]);
        }
    }
        
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }
}

void solve() {
    int n;
    cin>>n;
    vector<string> s(n), t(n);
    for(int i=0;i<n;i++) {
        cin>>s[i];
    }
    for(int i=0;i<n;i++) {
        cin>>t[i];
    }
    int ans = INT_MAX;
    int cnt = moves(s, t, n);
    ans = min(cnt, ans);

    rotate90(s, n);
    cnt = moves(s, t, n);
    ans = min(1+cnt , ans);

    rotate90(s, n);
    cnt = moves(s, t, n);
    ans = min(2+cnt , ans);

    rotate90(s, n);
    cnt = moves(s, t, n);
    ans = min(3+cnt , ans);

    cout<<ans<<endl;
}