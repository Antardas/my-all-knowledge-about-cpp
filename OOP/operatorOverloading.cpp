#include <bits/stdc++.h>

using namespace std;

class Sum {
public:
    int x;
    Sum(int a) { x = a; }
    Sum operator+(Sum obj) {
        Sum ans(0);
        ans.x = obj.x + x;

        cout << obj.x << endl;
        return ans;
    }
};

int main() {
    Sum a(20), b(20), c(50);
    Sum ans = a + b;
    Sum anotherAns = ans + c;
    cout << anotherAns.x << endl;
    return 0;
}