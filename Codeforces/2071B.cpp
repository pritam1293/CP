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
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

bool square(long long num) {
    long long root = sqrt(num);
    if(root * root == num) return true;
    return false;
}

void solve() {
    int n;
    cin>>n;
    vector<long long> perm(n);
    for(int i=0;i<n;i++) {
        perm[i] = i+1;
    }
    long long sum = 0;
    for(int i=0;i<n;i++) {
        sum += perm[i];
        if(square(sum)) {
            if(i+1 < n) {
                swap(perm[i] , perm[i+1]);
                sum += 1ll;
            }
            else {
                cout<<"-1"<<endl;
                return;
            }
        }
    }
    for(auto it : perm) {
        cout<<it<<" ";
    }
    cout<<endl;
}