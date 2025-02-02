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

void solve() {
    string s;
    cin>>s;
    int n = s.size();

    int i = 0;
    while(i < n && s[i] == '1') {
        i++;
    }

    if(i == n) i = n-1;
    int k = i-1;
    int j=0;

    for(int j=i;j<n && k >= 0;j++,k--) {
        if(s[j] == '1') break;
    }
    k++;

    cout<<"1 "<<n<<" "<<k+1<<" "<<k+n-i<<endl;
}
