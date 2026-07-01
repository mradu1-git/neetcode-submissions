class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> vec(n);
        for (int i = 0; i < n; i++) {
            vec[i] = {position[i], speed[i]};
        }
        sort(vec.rbegin(), vec.rend());
        int ans = 1;
        double prev = (double) ((target - vec[0].first) * 1.0) / vec[0].second;
        for (auto &p : vec) {
            double time = (double) ((target - p.first) * 1.0 )/ p.second;
            if (time > prev) {
                ans++;
                prev = time;
            }
        }
        return ans;
    }
};
