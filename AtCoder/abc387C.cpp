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

long long power(int a , int n) {
    long long ans = 1;
    for(int i=0;i<n;i++) {
        ans *= (long long)a;
    }
    return ans;
}

long long snakeNumbers(long long r) {
    vector<int> digit;
    while(r) {
        digit.push_back(r % (long long)10);
        r /= (long long)10;
    }

    reverse(digit.begin(),digit.end());
    int n = digit.size();

    long long ans = 0;
    for(int i=1;i<=n;i++) {
        if(i == n) {
            ans += 1ll;
            break;
        }
        ans += (long long)min(digit[0] , digit[i]) * power(digit[0] , n-1-i);
        if(digit[i] >= digit[0]) break;
    }

    for(int i=0;i<n;i++) {
        int mx = (i ? 9 : digit[0]-1);

        for(int j=1;j<=mx;j++) {
            ans += power(j , n-1-i);
        }
    }

    return ans;
}

void solve() {
    long long l,r;
    cin>>l>>r;
    // cout<<snakeNumbers(100);
    cout<<snakeNumbers(r) - snakeNumbers(l-1ll)<<endl;
}
