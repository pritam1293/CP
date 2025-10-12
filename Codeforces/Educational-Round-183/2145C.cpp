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

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int left = -1;
    int a = 0, b = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'a') a++;
        else b++;
        if(a == b) {
            a = 0, b = 0;
            left = i;
        }
    }
    int right = -1;
    a = 0; b = 0;
    for(int i = n-1; i >= 0; i--) {
        if(s[i] == 'a') a++;
        else b++;
        if(a == b) {
            a = 0, b = 0;
            right = i;
        }
    }
    if(left == -1 && right == -1) {
        cout<<"-1"<<endl;
    }
    else if(left == n-1 || right == 0) {
        cout<<"0"<<endl;
    }
    else {
        int ans = n;
        if(left != -1) {
            ans = min(ans, n - 1 - left);
        }
        if(right != -1) {
            ans = min(ans, right);
        }
        if(left != -1 && right != -1 && right > left) {
            ans = min(ans, right - left -1);
        }
        cout<<(ans == n ? -1 : ans)<<endl;
    }
}