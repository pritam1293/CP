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

void solve() {
    int n, q;
    cin>>n>>q;
    vector<int> x(q);
    for (int i=0;i<q;i++) {
        cin>>x[i];
    }

    vector<int> box(n+1);
    vector<int> ans(q);

    for (int i=0;i<q;i++) {
        if (x[i] >= 1) {
            box[x[i]]++;
            ans[i] = x[i];
        } else {
            int cnt = box[1], idx = 1;
            for (int j=2;j<=n;j++) {
                if (box[j] < cnt) {
                    cnt = box[j];
                    idx = j;
                }
            }
            box[idx]++;
            ans[i] = idx;
        }
    }
    for (int i=0;i<q;i++) {
        cout<<ans[i]<<" ";
    }
}