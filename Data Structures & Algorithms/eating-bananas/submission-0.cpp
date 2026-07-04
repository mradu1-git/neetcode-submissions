class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int upper = 0;
        int n = piles.size();
        for (int i = 0; i < n; i++) {
            upper = max(upper, piles[i]);
        }
        if (h < n) return -1;
        int lower = 1;
        int ans = upper;
        while (lower <= upper) {
            int k = lower + (upper - lower) / 2;
            long long totalTime = 0;

            for (int p : piles) {
                totalTime += ceil(1.0 * p / k);
            }

            if (totalTime <= h) {
                ans = k;
                upper = k - 1;
            } else {
                lower = k + 1;
            }
        }

        return ans;
    }
};
