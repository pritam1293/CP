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

int minXor(int n , int m) {
    int cnt = 0;
    while(m){
        if(m % 2) cnt++;
        m /= 2;
    }
    vector<int> num(31);
    int i=31;
    while(n) {
        if(n % 2) num[i] = 1;
        n /= 2;
        i--;
    }
    vector<int> ans(31);
    for(int j=0;j<31 && cnt;j++) {
        if(num[j] == 1 && cnt) {
            ans[j] = 1;
            cnt--;
        }
    }
    for(int j=30;j>=0;j--) {
        if(cnt && ans[j] == 0) {
            ans[j] = 1;
            cnt--;
        }
    }
    reverse(ans.begin(),ans.end());
    int answer = 0;
    for(int j=0;j<31;j++) {
        answer += ans[j] * pow(2,j);
    }
    return answer;
    // return i;
}

void solve() {
    int n,m;
    cin>>n>>m;
    cout<<minXor(n,m)<<endl;
    // cout<<(1<<30);
}
