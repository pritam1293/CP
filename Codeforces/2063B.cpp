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

long long calculate(int st,int end,vector<int> &a,priority_queue<int> pq,long long sum) {
    priority_queue<int,vector<int>,greater<int>> minpq;
    for(int i=st;i<=end;i++) {
        minpq.push(a[i]);
    }
    while(!pq.empty() && !minpq.empty() && pq.top() > minpq.top()) {
        sum -= (long long)pq.top();
        sum +=  (long long)minpq.top();
        pq.pop();
        minpq.pop();
    }
    return sum;
}

void solve() {
    int n,l,r;
    cin>>n>>l>>r;
    l--;r--;//for indexing
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    priority_queue<int> pq;
    long long sum = 0;
    for(int i=l;i<=r;i++) {
        pq.push(a[i]);
        sum += (long long)a[i];
    }

    long long ans = min(calculate(0,l-1,a,pq,sum) , calculate(r+1,n-1,a,pq,sum));
    cout<<ans<<endl;
}
