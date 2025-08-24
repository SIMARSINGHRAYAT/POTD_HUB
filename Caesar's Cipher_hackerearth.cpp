#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    int tc;
    cin >> tc;                      // Number of testcases

    while(tc--) {
        string a, b;
        cin >> a >> b;              // Input two strings of equal length
        ll x;
        set<int> st;                // To store unique shift values

        for(int i = 0; i < a.length(); i++) {
            x = (b[i] - a[i] + 26) % 26;    // Calculate shift for each character (wraps around alphabet)
            st.insert(x);                   // Store the shift in set (only unique values will be kept)
        }

        if(st.size() > 1) 
            cout << -1 << endl;     // If more than one unique shift, output -1
        else    
            cout << x << endl;      // Otherwise, output the (unique) shift value
    }
}
