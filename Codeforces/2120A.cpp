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

bool check(int l1, int l2, int l3, int b1, int b2, int b3) {
    return (l1 + l2 == l3 && b1 == b2 && b1 + b3 == l3);
}

void solve() {
    int l1, b1, l2, b2, l3, b3;
    cin>>l1>>b1>>l2>>b2>>l3>>b3;
    int area = l1 * b1  + l2 * b2 + l3 * b3;
    int root = sqrt(area);
    if(root * root != area) {
        cout<<"No"<<endl;
        return;
    }
    if((l1 == l2 && l2 == l3 && b1 + b2 + b3 == l1) || (b1 == b2 && b2 == b3 && l1 + l2 + l3 == b1)) {
        cout<<"Yes"<<endl;
        return;
    }
    bool flag = false;
    if(check(l1, l2, l3, b1, b2, b3))  {
        flag = true;
    }
    if(check(l2, l3, l1, b2, b3, b1)) {
        flag = true;
    }
    if(check(l3, l1, l2, b3, b1, b2)) flag = true;
    if(check(b1, b2, b3, l1, l2, l3)) flag = true;
    if(check(b2, b3, b1, l2, l3, l1)) flag = true;
    if(check(b3, b1, b2, l3, l1, l2)) flag = true;
    if(flag) {
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
}