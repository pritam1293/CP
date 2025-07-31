#include<bits/stdc++.h>
using namespace std;
// #define int long long
void solve();
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t=1;
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

int fnc(int a, int b, map<int,int> &ca, map<int,int> &cb, map<int,int> &ia, map<int,int> &ib, multiset<int> &sa, multiset<int> &sb) {
    int sum = 0;
    if(ca[a] == 1 && cb[b] == 1 && ia[a] == ib[b]) {
        int c = *prev(sa.end(), 2);
        sum = b + c;
        c = *prev(sb.end(), 2);
        sum = max(sum, a + c);
    }
    else sum = a + b;
    return sum;
}

void solve() {
    int n;
    cin>>n;
    multiset<int> sa, sb, sc;
    map<int,int> ca, cb, cc, ia, ib, ic;
    vector<int> a(n), b(n), c(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        sa.insert(a[i]);
        ca[a[i]]++;
        ia[a[i]] = i;

    }
    for(int i = 0; i < n; i++) {
        cin>>b[i];
        sb.insert(b[i]);
        cb[b[i]]++;
        ib[b[i]] = i;
    }
    for(int i = 0; i < n; i++) {
        cin>>c[i];
        sc.insert(c[i]);
        cc[c[i]]++;
        ic[c[i]] = i;
    }
    int ans = 0;
    for(int i = 0; i < n-2; i++) {
        auto it = sa.find(a[i]);
        sa.erase(it);
        it = sb.find(b[i]);
        sb.erase(it);
        it = sc.find(c[i]);
        sc.erase(it);
        ca[a[i]]--;
        cb[b[i]]--;
        cc[c[i]]--;

        int la = *sa.rbegin();
        int lb = *sb.rbegin();
        int lc = *sc.rbegin();

        ans = max(ans, a[i] + fnc(lb, lc, cb, cc, ib, ic, sb, sc));
        ans = max(ans, b[i] + fnc(la, lc, ca, cc, ia, ic, sa, sc));
        ans = max(ans, c[i] + fnc(la, lb, ca, cb, ia, ib, sa, sb));
    }
    cout<<ans<<endl;
}