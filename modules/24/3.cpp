#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {
        int d;
        cin >> d;

        int earned_money[d], spent_money[d];

        for (int i = 0; i < d; i++) {
            cin >> earned_money[i];
        }

        for (int i = 0; i < d; i++) {
            cin >> spent_money[i];
        }

        int total_earning[d];

        total_earning[0] = earned_money[0];
        for (int i = 1; i < d; i++) {
            total_earning[i] = total_earning[i - 1] + earned_money[i];
        }

        int total_spent[d];

        total_spent[0] = spent_money[0];
        for (int i = 1; i < d; i++)
        {
            total_spent[i] = total_spent[i - 1] + spent_money[i];
        }

        int q;
        cin >> q;

        int ans[q];
        int index = 0;
        while (q--)
        {
            int x;
            cin >> x;
            int available = total_earning[x];
            int spent = total_spent[x];

            int result = available - spent;

            if (result < 0) {

                ans[index++] = 0;
            }
            else {
                ans[index++] = 1;
            }
        }

        for (int i = 0; i < index; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}
