#include <bits/stdc++.h>

using namespace std;

template<typename T> T myMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << myMax<int>(7, 3) << endl;
    cout << myMax<float>(7.5, 3) << endl;
    cout << myMax<string>("antar", "das") << endl;
    return 0;
}
