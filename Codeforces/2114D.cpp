#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s  second
void solve();
int32_t main() {
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

void solve() {
    int n;
    cin>>n;
    vector<pair<int,int>> a(n);
    vector<int> x(n), y(n);
    map<int,int> xcnt, ycnt;
    int minx = 1e9, miny = 1e9;
    int maxx = 0, maxy = 0;
    for(int i=0;i<n;i++) {
        cin>>a[i].f>>a[i].s;
        x[i] = a[i].f;
        y[i] = a[i].s;
        xcnt[a[i].f]++;
        ycnt[a[i].s]++;
    }
    if(n == 1) {
        cout<<"1"<<endl;
        return;
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int ans = (x[n-1] - x[0] + 1) * (y[n-1] - y[0] + 1);
    int min_x1 = x[0];
    int min_x2 = x[1];
    int min_y1 = y[0];
    int min_y2 = y[1];

    int max_x1 = x[n-1];
    int max_x2 = x[n-2];
    int max_y1 = y[n-1];
    int max_y2 = y[n-2];

    for(int i=0;i<n;i++) {
        int xx = a[i].f;
        int yy = a[i].s;

        int minx;
        if(xx == min_x1 && xcnt[min_x1] == 1) minx = min_x2;
        else minx = min_x1;

        int maxx;
        if(xx == max_x1 && xcnt[max_x1] == 1) maxx = max_x2;
        else maxx = max_x1;

        int miny;
        if(yy == min_y1 && ycnt[min_y1] == 1) miny = min_y2;
        else miny = min_y1;

        int maxy;
        if(yy == max_y1 && ycnt[max_y1] == 1) maxy = max_y2;
        else maxy = max_y1;

        int area = (maxx - minx + 1) * (maxy - miny + 1);
        if(area +1 == n) area += min(maxx - minx + 1, maxy - miny + 1);
        ans = min(ans, area);
 
    }
    cout<<ans<<endl;
}