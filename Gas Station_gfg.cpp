class Solution {
public:
    int startStation(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0, total_cost = 0, tank = 0, start = 0, n = gas.size();
        for (int i = 0; i < n; ++i) {
            total_gas += gas[i];
            total_cost += cost[i];
            tank += gas[i] - cost[i];
            if (tank < 0) { // can't start from current start, reset
                start = i + 1;
                tank = 0;
            }
        }
        return (total_gas >= total_cost) ? start : -1;
    }
};
