#include <bits/stdc++.h>

using namespace std;

/**
0 ----- 1
       / \
      2---3

 */

int main() {
    int nodes = 4;

    vector<int>adj_list[nodes];

    adj_list[0] = { 1 };
    adj_list[1] = { 0, 2,3 };
    adj_list[2] = { 1,3 };
    adj_list[3] = { 1,2 };




    return 0;
}