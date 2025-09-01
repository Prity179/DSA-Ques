class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long start = 1, end = 0, mid, ans = 0;
        int n = piles.size();

        for(int i = 0; i < n; i++) {
            end = max(end, (long long)piles[i]);
        }

        while(start <= end) {
            mid = start + (end - start) / 2;
            long long total_time = 0;

            for(int i = 0; i < n; i++) {
                total_time += piles[i] / mid;
                if(piles[i] % mid) total_time++;
            }

            if(total_time > h) {
                start = mid + 1;
            } else {
                ans = mid;
                end = mid - 1;
            }
        }
        return (int)ans;
    }
};
