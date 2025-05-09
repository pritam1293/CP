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

int calculate(int a, int b, int c, int d) {
    int diff = INT_MIN;

    vector<int> arr = {a, b, c, d};
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            if(i != j) diff = max(diff, abs(arr[i] - arr[j]));
        }
    }
    return diff;
}

void solve() {
    int n1;
    cin>>n1;
    vector<int> caps(n1);
    for(int i=0;i<n1;i++) cin>>caps[i];
    sort(caps.begin(), caps.end());
    
    int n2;
    cin>>n2;
    vector<int> shirts(n2);
    for(int i=0;i<n2;i++) cin>>shirts[i];
    sort(shirts.begin(), shirts.end());

    int n3;
    cin>>n3;
    vector<int> pants(n3);
    for(int i=0;i<n3;i++) cin>>pants[i];
    sort(pants.begin(), pants.end());

    int n4;
    cin>>n4;
    vector<int> shoes(n4);
    for(int i=0;i<n4;i++) cin>>shoes[i];
    sort(shoes.begin(), shoes.end());

    cap = caps[0];
    shirt = shirts[0];
    pant = pants[0];
    shoe = shoes[0];

    int a = 0, b = 0, c = 0, d = 0;
    int minm = INT_MAX;

    while(a < n1 && b < n2 && c < n3 && d < n4) {
        int diff = calculate(caps[a], shirts[b], pants[c], shoes[d]);

        if(minm > diff) {
            minm = diff;
            cap = caps[a];
            shirt = shirts[b];
            pant = pants[c];
            shoe = shoes[d];
        }

        if(caps[a] <= shirts[b] && caps[a] <= pants[c] && caps[a] <= shoes[d]) {
            a++;
        }
        else if (shirts[b] <= caps[a] && shirts[b] <= pants[c]  && shirts[b] <= shoes[d]) {
            b++;   
        }
        else if(pants[c] <= caps[a] && pants[c] <= shirts[b] && pants[c] <= shoes[d]) {
            c++;
        }
        else if(shoes[d] <= caps[a] && shoes[d] <= shirts[b] && shoes[d] <= pants[b]) {
            d++;
        }
    }
    cout<<cap<<" "<<shirt<<" "<<pant<<" "<<shoe<<endl;
}