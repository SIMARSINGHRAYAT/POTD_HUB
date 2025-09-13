class Solution {
public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        sort(x.rbegin(), x.rend());
        sort(y.rbegin(), y.rend());
        
        int i = 0, j = 0;
        int hz = 1, vt = 1;
        int cost = 0;
        
        while(i < x.size() && j < y.size()) {
            if(x[i] >= y[j]) {
                cost += x[i] * hz;
                vt++;
                i++;
            } else {
                cost += y[j] * vt;
                hz++;
                j++;
            }
        }
        while(i < x.size()) {
            cost += x[i] * hz;
            i++;
        }
        while(j < y.size()) {
            cost += y[j] * vt;
            j++;
        }
        return cost;
    }
};
