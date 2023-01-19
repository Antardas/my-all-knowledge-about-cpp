// https://cses.fi/problemset/task/1197


#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const long long INF = 1e18;
vector<pair<int, int>>adj_list[N];
long long d[N];
int parent[N];
int n, m;
bool negative_cycle = false;
int last_updated_node = -1;

void bellman_ford() {
    for (int i = 1; i <= n; i++) {
        for (int node = 1; node <= n; node++) {
            for (pair<int, int> adj_node : adj_list[node]) {
                int u = node;
                int v = adj_node.first;
                int w = adj_node.second;

                if (d[u] + w < d[v]) {
                    d[v] = d[u] + w;
                    parent[v] = u;
                    if (n == i) {
                        negative_cycle = true;
                        last_updated_node = v;
                    }
                }
            }
        }
    }


    // for (int i = 1; i <= n;i++) {
    //     cout << d[i] << " ";
    // }
}


int main() {

    cin >> n >> m;
    for (int i = 0; i <= n;i++) {
        d[i] = INF;
    }

    for (int i = 0; i < m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({ v,w });
    }

    // int src = 1;

    // d[src] = 0;

    bellman_ford();

    if (negative_cycle) {
        cout << "YES" << endl;
        int selected_node = last_updated_node;

        for (int i = 1; i <= n - 1;i++) {
            selected_node = parent[last_updated_node];
        }

        vector<int>cycle;
        int first_node = selected_node;
        cycle.push_back(selected_node);

        while (true)
        {
            selected_node = parent[selected_node];
            cycle.push_back(selected_node);

            if (first_node == selected_node) break;
        }

        reverse(cycle.begin(), cycle.end());

        for (int node : cycle) {
            cout << node << " ";
        }
        cout << endl;



    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}