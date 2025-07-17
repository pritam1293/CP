#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    int t=1;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n, q;
    cin>>n>>q;
    vector<int> next(n);
    vector<vector<int>> before(n);
    for(int i=0;i<n;i++) {
        cin>>next[i];
        next[i]--;
        before[next[i]].push_back(i);
    }
    vector<int> cycle_id(n, -2);
    /*
    -2 : not visited yet
    -1 : part of a tree
    0 : id of the cycle, the planet belongs to
    */
    vector<map<int,int>> cycles;//index of a planet in a cycle
    for(int p=0;p<n;p++) {
        if(cycle_id[p] != -2) continue;
        vector<int> path = {p};
        int at = p;
        while(cycle_id[next[at]] == -2) {
            at = next[at];
            cycle_id[at] = -3;//
            path.push_back(at);
        }
        map<int,int> cycle;
        bool in_cycle = false;
        for(auto& node : path) {
            in_cycle = in_cycle || node == next[at];
            if(in_cycle) cycle[i] = cycle.size();
            cycle_id[node] = in_cycle ? cycles.size() : -1;
        }
        cycles.push_back(cycle);
    }
}