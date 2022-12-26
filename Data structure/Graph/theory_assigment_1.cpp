// Write a program for check it's bidirectional or not

#include <bits/stdc++.h>

using namespace std;


/*
https://postimg.cc/XBWdVgmZ

1>2
2>4
2-5
5-3
3>4
------
5 5
1 2
2 4
2 5
5 3
3 4

 */

const int N = 1e5;
vector<int>adj_list[N];
int visited[N];
/**
 *@brief this code check our graph is bi-direction/undirected graph or not, each time it's take a node then check node
 *
 * @param node
 * @return true
 * @return false
 */
bool check_bi_directional(int node) {
    for (int adj_node : adj_list[node]) {
        bool found = false;
        cout << adj_node << "=>";
        for (int adj_sub_node : adj_list[adj_node]) {
            cout << adj_sub_node << " ";
            if (adj_sub_node == node) {
                found = true;
            }
        }
        cout << endl;
        if (found == false) {
            return false;
        }
    }
    return true;
}


void dfs(int root) {
    queue<int>q;

    visited[root] = 1;
    q.push(root);
    bool is_bi_direction = true;
    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        cout << head << endl;

        is_bi_direction = check_bi_directional(head);
        if (is_bi_direction == false) {
            cout << "Graph is Directional " << endl;

            return;
        }

        for (int adj_node : adj_list[head]) {
            if (visited[adj_node] == 0) {
                visited[adj_node] = 1;
                q.push(adj_node);
            }
        }

    }

    if (is_bi_direction == true) {
        cout << "Graph is Bi Directional " << endl;

        return;
    }

}

int main() {
    // n = number of nodes
    // m = number of edges
    int n, m;
    cin >> n >> m;


    for (int i = 0; i < m; i++) { // loop over the number of edges
        int u, v;
        cin >> u >> v; // There exists a directed edge from u to v
        adj_list[u].push_back(v);
        // adj_list[v].push_back(u);
    }

    dfs(1);

    return 0;
}