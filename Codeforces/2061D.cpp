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
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    vector<int> b(n);
    for(int i=0;i<m;i++) {
        cin>>b[i];
    }
    priority_queue<int> pq;

    for (int i=0;i<m;i++) {
        pq.push(b[i]);
    }

    map<int,int> mp;

    for (int i=0;i<n;i++) {
        mp[a[i]]++;
    }

    bool flag = true;

    for (int i=0; i< n-m+n;i++) {
        if (pq.empty()) {
            flag = false;
            break;
        }

        int x = pq.top();
        pq.pop();

        if (mp[x] == 0) {
            pq.push(x/2);
            pq.push((x+1)/2);
        }
        else {
            mp[x]--;
        }
    }

    if (flag && pq.empty()) {
        cout<<"Yes"<<endl;
    } 
    else {
        cout<<"No"<<endl;
    }
}
