class Solution {
  public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        vector<pair<int, int>> events;

        // Step 1: Convert intervals into start and end events
        for (auto& interval : intervals) {
            events.push_back({interval[0], 1});         // Start of interval
            events.push_back({interval[1] + 1, -1});     // End of interval (+1 for closed interval)
        }

        // Step 2: Sort events by position
        sort(events.begin(), events.end());

        int active = 0;
        int maxPowerful = -1;

        // Step 3: Sweep through events
        for (int i = 0; i < events.size(); ++i) {
            active += events[i].second;

            // If next event is at a different position, check if current position is powerful
            if (i + 1 < events.size() && events[i].first != events[i + 1].first) {
                if (active >= k) {
                    maxPowerful = events[i + 1].first - 1;
                }
            }
        }

        return maxPowerful;
    }
};
