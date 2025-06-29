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


set<pair<int,int>> edges;

pair<int,int> make_edge(int u, int v) {
    if (u > v) swap(u,v);
    return {u,v};
}

vector<pair<int,int>> cycle_edges(const vector<int> &cycle) {
    vector<pair<int,int>> edges;
    int k = cycle.size();
    for (int i = 0; i < k; i++) {
        edges.push_back(make_edge(cycle[i], cycle[(i+1) % k]));
    }
    return edges;
}

int ans = INT_MAX;

void backtrack(vector<int> &unused,vector<vector<int>> &current_partition, int depth) {
    if (unused.empty()) {
        set<pair<int,int>> candidate_edges;
        for (auto &cycle : current_partition) {
            auto c_edges = cycle_edges(cycle);
            for (auto &e : c_edges) {
                candidate_edges.insert(e);
            }
        }

        int diff = 0;
        for (auto &e : edges) {
            if (candidate_edges.count(e) == 0) diff++;
        }
        for (auto &e : candidate_edges) {
            if (edges.count(e) == 0) diff++;
        }
        ans = min(ans, diff);
        return;
    }

    int start = unused[0];
    int sz = unused.size();

    for (int length = 3; length <= sz; length++) {
        vector<int> to_choose(unused.begin() + 1, unused.end());

        vector<bool> select_mask((int)to_choose.size(), false);
        fill(select_mask.begin(), select_mask.begin() + length - 1, true);

        
        do {
            vector<int> cycle;
            cycle.push_back(start);
            for (int i = 0; i < (int)to_choose.size(); i++) {
                if (select_mask[i]) cycle.push_back(to_choose[i]);
            }

            vector<int> rest(cycle.begin() + 1, cycle.end());
            sort(rest.begin(), rest.end());
            do {
                vector<int> full_cycle = {start};
                full_cycle.insert(full_cycle.end(), rest.begin(), rest.end());

                // Prepare next unused vector
                vector<int> next_unused;
                set<int> cycle_set(full_cycle.begin(), full_cycle.end());
                for (int v : unused) {
                    if (cycle_set.count(v) == 0) next_unused.push_back(v);
                }

                current_partition.push_back(full_cycle);
                backtrack(next_unused, current_partition, depth+1);
                current_partition.pop_back();

            } while (next_permutation(rest.begin(), rest.end()));

        } while (prev_permutation(select_mask.begin(), select_mask.end()));
    }
}

void solve() {
    int n, m;
    cin>>n>>m;
    for (int i=0;i<m;i++) {
        int a, b;
        cin>>a>>b;
        edges.insert(make_edge(a,b));
    }

    vector<int> unused;
    for (int i = 1; i <= n; i++) {
        unused.push_back(i);
    }
    vector<vector<int>> current_partition;
    ans = INT_MAX;

    backtrack(unused, current_partition, 0);

    cout << ans << endl;
}
