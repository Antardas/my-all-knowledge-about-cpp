#include <bits/stdc++.h>
#include "STACKLIST.H"

using namespace std;

int main() {
    Stack <char> st;
    st.push('a');
    st.push('b');
    st.push('c');
    // cout << "POP : " << st.pop() << endl;
    cout << "Empty : " << st.empty() << endl;
    // cout << "POP : " << st.pop() << endl;
    while (st.empty() == false) {
    cout << "POP : " << st.pop() << endl;
        
    }

    return 0;
}