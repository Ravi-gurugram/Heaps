class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MOD = 1e9 + 7;
        using T = tuple<int,int,int>; // (sum, start, next)
        priority_queue<T, vector<T>, greater<T>> pq;
        
        // push each starting element
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i, i+1});
        }
        
        long long ans = 0;
        for (int k = 1; k <= right; k++) {
            auto [sum, i, j] = pq.top(); pq.pop();
            if (k >= left) ans = (ans + sum) % MOD;
            if (j < n) { // extend subarray
                pq.push({sum + nums[j], i, j+1});
            }
        }
        return (int)ans;
    }
};
