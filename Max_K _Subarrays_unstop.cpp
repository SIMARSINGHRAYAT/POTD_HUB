#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
int findMaxKSubarraySums(int n, int k, vector<int>& arr) {
    priority_queue<ll> maxHeap;
    for (int i = 0; i < n; ++i) {
        ll sum = 0;
        for (int j = i; j < n; ++j) {
            sum += arr[j];
            maxHeap.push(sum);
        }
    }
    ll result = 0;
    while (k-- && !maxHeap.empty()) {
        result += maxHeap.top();
        maxHeap.pop();
    }
    return result;
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    cout << findMaxKSubarraySums(n, k, arr) << endl;
    return 0;
}
