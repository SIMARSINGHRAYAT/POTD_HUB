#include <iostream>
#include <vector>
using namespace std;

int max_disjoint_alliances(int n, int m, int t, const vector<int>& a, const vector<int>& b) {
    int i = 0, j = 0, count = 0;
    
    while (i < n && j < m) {
        if (a[i] < b[j] && a[i] + b[j] <= t) {
            count++;
            i++;
            j++;
        } else if (a[i] >= b[j]) {
            j++;
        } else {
            i++;
        }
    }
    
    return count;
}

int main() {
    int n, m, t;
    cin >> n >> m >> t;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int result = max_disjoint_alliances(n, m, t, a, b);
    cout << result << endl;
    
    return 0;
}
