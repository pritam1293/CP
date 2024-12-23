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

void solve() {
    int n;
    cin>>n;
    if(n <= 1) {
    	cout<<1<<endl;
    }
    else if(n <=4) {
    	cout<<2<<endl;
    }
    else if(n <= 10) {
    	cout<<3<<endl;
    }
    else if(n <= 22) {
    	cout<<4<<endl;
    }
    else if(n <= 46) {
    	cout<<5<<endl;
    }
    else if(n <= 94) {
    	cout<<6<<endl;
    }
    else if(n <= 190) {
    	cout<<7<<endl;
    }
    else if(n <= 382) {
    	cout<<8<<endl;
    }
    else if(n <= 766) {
    	cout<<9<<endl;
    }
    else if(n <= 1534) {
    	cout<<10<<endl;
    }
    else if(n <= 3070) {
    	cout<<11<<endl;
    }
    else if(n <= 6142) {
    	cout<<12<<endl;
    }
    else if(n <= 12286) {
    	cout<<13<<endl;
    }
    else if(n <= 24574) {
    	cout<<14<<endl;
    }
    else if(n <= 49150) {
    	cout<<15<<endl;
    }
    else if(n <= 98302) {
    	cout<<16<<endl;
    }
    else {
    	cout<<17<<endl;
    }
}
