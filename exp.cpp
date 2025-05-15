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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

int fnc(int s, vector<int> &a, int n) {
    if(s < 0) return 0;
    int l = 0;
    int ans = 0;
    int sum = 0;
    for(int r=0;r<n;r++) {
        sum += a[r];
        while(sum > s) {
            sum -= a[l];
            l++;
        }
        ans += r-l+1;
    }
    return ans;
}

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    cout<< fnc(k, a, n) - fnc(k-1, a, n)<<endl;
    
}
