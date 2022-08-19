
// https://vjudge.net/contest/507340#problem/E
// antar100
#include<bits/stdc++.h>
#define SIZE 100005
using namespace std;
int a[SIZE], n;
long long update(int i, int val)
{

    while (i <= n) { // 1 3 // 2 3
        a[i] = a[i] + val; //  2 + 3
        i = i + (i & (-i)); // 2 + 2
    }

}

long long query(int i)
{
    long long ans;
    ans = 0;

    while (i > 0) {
        ans = ans + a[i];
        i = i - (i & (-i));
    }

    return ans;
}

int main()
{
    int t, x, y, w, choice, q, ch;

    long long ans;
    cin >> t; // 1
    for (int cs = 1; cs <= t; cs++) {
        cin >> n >> q; // N = 5 q=6 // n global variable for size of array and q for number of queries
        memset(a, 0, sizeof a); // initializing array to 0

        for (int i = 1; i <= n; i++) {
            cin >> x; // 3 -> 2 1 4 5
            update(i, x); // i=1 x=3
        }



        printf("Case %d:\n", cs);
        for (int i = 0; i < q; i++) {
            cin >> ch;

            switch (ch) {
            case 1:
                cin >> x;
                x++;
                ans = query(x) - query(x - 1);
                update(x, -ans);
                cout << ans << endl;
                break;
            case 2:
                cin >> x;
                x++;
                cin >> w;
                update(x, w);
                break;

            case 3:
                cin >> x >> y;
                x++;
                y++;
                ans = query(y) - query(x - 1);
                cout << ans << endl;
                break;

            }
        }
    }
}




/* 
    sort this
    ["abc", "Abc", "ABc", "Bac", "BaC", "CaB", "ABC", "CAB", caB, "cAB"]
    ["ABC", "ABc", "Abc", "abc", "BaC", "Bac","CAB", "CAB" "CaB", "CaB" ]
    

 */

// sort array of  string
// https://www.geeksforgeeks.org/sort-an-array-of-strings-in-alphabetical-order/
// https://www.geeksforgeeks.org/sort-an-array-of-strings-in-alphabetical-order-using-merge-sort/
