#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        long long N;
        cin >> N;
        int sum_even = 0, sum_odd = 0;
        while (N) {
            int digit = N % 10;
            if (digit % 2 == 0)
                sum_even += digit;
            else
                sum_odd += digit;
            N /= 10;
        }
        if (sum_even > sum_odd)
            cout << "friendly" << endl;
        else
            cout << "evil" << endl;
    }
    return 0;
}
