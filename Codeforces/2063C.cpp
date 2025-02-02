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

bool notChild(vector<int> &arr , int child) {
    for(auto it : arr) {
        if(it == child) return false;
    }
    return true;
} 

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    vector<int> deg(n+1);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    vector<int> nodes(n);
    for(int i = 0; i < n; ++i){
        nodes[i] = i + 1;
    }

    sort(nodes.begin(), nodes.end(), [&](const int a, const int b){
        if(deg[a] != deg[b]) return deg[a] > deg[b];
        return a < b;
    });

    for(int i=1;i<=n;i++){
        sort(adj[i].begin(),adj[i].end());
    }

    long long max1 = 0;

    for(int i=0;i<n;i++){
        int u = nodes[i];

        for(int j=i+1;j<n;j++){
            int v = nodes[j];

            if(!binary_search(adj[u].begin(), adj[u].end(), v)){
                long long temp = (long long)deg[u] + (long long)deg[v] - 1ll;
                max1 = max(max1, temp);
                break; 
            }
        }
    }

    long long max2 = 0;
    for(int u=1;u<=n;u++){
        for(auto &v : adj[u]){
            if(u < v){ 
                long long temp = (long long)(deg[u]) + (long long)deg[v] - 2ll;
                max2 = max(max2, temp);
            }
        }
    }
    cout<<max(max1 , max2)<<endl;
}
