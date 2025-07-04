#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(const vector<int>& arr, int k, long long maxSum) {
    int count = 1;
    long long current = 0;
    for (int val : arr) {
        if (val > maxSum) return false;
        if (current + val > maxSum) {
            count++;
            current = val;
        } else {
            current += val;
        }
    }
    return count <= k;
}

long long fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int peculiarNumber(int n, int k, vector<int>& arr) {
    // Step 1: Transform the array
    for (int i = 0; i < n; ++i) {
        arr[i] = abs(arr[i] - i);
    }

    // Step 2: Binary search for minimum max partition sum
    long long low = *max_element(arr.begin(), arr.end());
    long long high = 0;
    for (int val : arr) high += val;

    long long result = high;
    while (low <= high) {
        long long mid = (low + high) / 2;
        if (isValid(arr, k, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    // Step 3: Return Fibonacci or result
    if (result < 100)
        return fibonacci(result);
    else
        return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    cout << peculiarNumber(n, k, arr) << endl;
    return 0;
}
