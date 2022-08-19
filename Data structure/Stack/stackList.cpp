#include <bits/stdc++.h>
#include "STACKLIST.H"

using namespace std;

int main() {
    Stack <float> st;
    st.push(1.7);
    st.push(2.5);
    st.push(3.5);
    // cout << "POP : " << st.pop() << endl;
    // cout << "Empty : " << st.empty() << endl;
    // cout << "POP : " << st.pop() << endl;
    while (st.empty() == false) {
    cout << "POP : " << st.pop() << endl;
        
    }

    return 0;
}