class Solution {
  public:
    int maxKPower(int n, int k) {
        // Step 1: Factorize k
        map<int, int> primeFactors;
        for (int i = 2; i * i <= k; ++i) {
            while (k % i == 0) {
                primeFactors[i]++;
                k /= i;
            }
        }
        if (k > 1) primeFactors[k]++;

        // Step 2: Use standard iterator syntax
        int result = INT_MAX;
        for (auto it = primeFactors.begin(); it != primeFactors.end(); ++it) {
            int p = it->first;
            int a = it->second;
            int count = 0;
            int base = p;
            while (base <= n) {
                count += n / base;
                base *= p;
            }
            result = min(result, count / a);
        }
        return result;
    }
};
