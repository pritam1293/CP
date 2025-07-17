#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t=1;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

bool basePalin(int n, int &b) {
    vector<int> a;
    while(n) {
        a.push_back(n % b);
        n /= b;
    }
    int i = 0, j = a.size()-1;
    while(i < j) {
        if(a[i] != a[j]) return false;
        i++;j--;
    }
    return true;
}

void solve() {
    int b, n;
    cin>>b>>n;
    int sum = 0;
    for(int i = 1;;i++){
        string s = to_string(i);
        string t = s;
        reverse(t.begin(), t.end());
        s += t.substr(1);
        int num = stoll(s);
        if(basePalin(num, b) && num <= n) sum += num;
        if(num > n) break;
    }
    for(int i = 1;;i++){
        string s = to_string(i);
        string t = s;
        reverse(t.begin(), t.end());
        s += t;
        int num = stoll(s);
        if(basePalin(num, b) && num <= n) sum += num;
        if(num > n) break;
    }
    cout<<sum<<"\n";
}