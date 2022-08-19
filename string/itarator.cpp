#include <bits/stdc++.h>

using namespace std;

int main() {
  string name = "Antar Das";
//   string::iterator it;
//   for (it = name.begin(); it != name.end(); it++) {
//     cout << *it << endl;
//   }

// Reverse Iterator
/*     string::reverse_iterator it;
    for(it = name.rbegin(); it != name.rend(); it++){
        cout<<*it<<endl;
    }
} */

// easy way

for(auto it = name.rbegin(); it != name.rend(); it++){
    cout<<*it<<endl;
}
}