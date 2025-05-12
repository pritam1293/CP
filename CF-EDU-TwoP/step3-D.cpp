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

int cap;
int pant;
int shirt;
int shoe;

vector<int> caps;
vector<int> shirts;
vector<int> pants;
vector<int> shoes;
int n1, n2, n3, n4;

int calculate(int a, int b, int c, int d) {
    if(b < 0 || c < 0 || d < 0 || b >= n2 || c >= n3 || d >= n4) return INT_MAX;
    int diff = INT_MIN;
    a = caps[a];
    b = shirts[b];
    c = pants[c];
    d = shoes[d];
    vector<int> arr = {a, b, c, d};
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            if(i != j) diff = max(diff, abs(arr[i] - arr[j]));
        }
    }
    return diff;
}

void update(int &minm, int diff, int a, int b, int c, int d) {
    if(minm > diff) {
        minm = diff;
        cap = caps[a];
        shirt = shirts[b];
        pant = pants[c];
        shoe = shoes[d];
    }
}

void solve() {
    cin>>n1;
    caps.resize(n1);
    for(int i=0;i<n1;i++) cin>>caps[i];
    sort(caps.begin(), caps.end());
    
    cin>>n2;
    shirts.resize(n2);
    for(int i=0;i<n2;i++) cin>>shirts[i];
    sort(shirts.begin(), shirts.end());

    cin>>n3;
    pants.resize(n3);
    for(int i=0;i<n3;i++) cin>>pants[i];
    sort(pants.begin(), pants.end());

    cin>>n4;
    shoes.resize(n4);
    for(int i=0;i<n4;i++) cin>>shoes[i];
    sort(shoes.begin(), shoes.end());

    cap = caps[0];
    shirt = shirts[0];
    pant = pants[0];
    shoe = shoes[0];

    int b = 0, c = 0, d = 0;
    int minm = INT_MAX - 3;
    for(int i=0;i<n1;i++) {
        while(b < n2 && shirts[b] <= caps[i]) b++;
        while(c < n3 && pants[c] <= caps[i]) c++;
        while(d < n4 && shoes[d] <= caps[i]) d++;

        for(int j = 0; j < 8; j++) {
            int b1 = b - (1 & (j >> 0));
            int c1 = c - (1 & (j >> 1));
            int d1 = d - (1 & (j >> 2));
            int diff = calculate(i, b1, c1, d1);
            update(minm, diff, i , b1, c1, d1);
        }
    }    
    cout<<cap<<" "<<shirt<<" "<<pant<<" "<<shoe<<endl;
}