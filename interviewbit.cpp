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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}


int m = 1e5;

vector<int> prime(m+1, true);



void primeNumbers() {
    prime[0] = false;
    prime[1] = false;
    for(int i = 2; i*i <= m; i++) {
        if(prime[i]) {
            for(int j = i; j <= m; j += i) {
                prime[j] = false;
            }
        }
    }
}

void solve() {
    primeNumbers();
    int k = 3;
    vector<int> a = {2, 3, 5, 7};
    int n = a.size();
    int l = 0;
    int ans = 0;
    deque<int> dqmin, dqmax;
    for(int r = 0; r < n; r++) {
        while(!dqmax.empty() && a[r] > dqmax.back()) dqmax.pop_back();
        while(!dqmin.empty() && a[r] < dqmin.back()) dqmin.pop_back();
 
        dqmax.push_back(a[r]);
        dqmin.push_back(a[r]);
 
        while(dqmax.front() - dqmin.front() > k) {
            if(dqmax.front() == a[l]) dqmax.pop_front();
            if(dqmin.front() == a[l]) dqmin.pop_front();
            l++;
        }
        if(r-l+1 >= 2) {
            ans += (long long)(r-l+1);
        }
    }
    cout<<ans<<endl;
}
