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
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n;
    cin>>n;
    vector<long long> head , len;
    long long shift = 0;
    int idx = 0;

    for(int i=0;i<n;i++) {
        int q;
        cin>>q;
        if(q == 1) {
            long long l;
            cin>>l;

            long long newhead = 0;
            if(!len.empty()) {
                newhead = head.back() + len.back();
            }
            len.push_back(l);
            head.push_back(newhead);
        }
        else if(q == 2) {
            long long m = len[idx];
            idx++;
            // len.erase(len.begin());
            // head.erase(head.begin());
            shift += m;
        }
        else {
            int k;
            cin>>k;
            cout<<(head[idx + k-1] - shift)<<endl;
        }
    }
}
