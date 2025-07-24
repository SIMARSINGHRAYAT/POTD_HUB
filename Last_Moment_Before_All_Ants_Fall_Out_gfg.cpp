class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int lastMoment = 0;
        
        for (int pos : left) {
            // Time for ants moving left to fall = position itself
            lastMoment = max(lastMoment, pos);
        }
        
        for (int pos : right) {
            // Time for ants moving right to fall = distance to right edge
            lastMoment = max(lastMoment, n - pos);
        }
        
        return lastMoment;
    }
};
