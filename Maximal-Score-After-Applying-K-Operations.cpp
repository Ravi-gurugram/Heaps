class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> pq;  // max-heap
        for (int x : nums) pq.push(x);

        long long score = 0;
        while (k--) {
            long long x = pq.top(); pq.pop();
            score += x;
            pq.push((x + 2) / 3);  // ceil(x/3)
        }
        return score;
    }
};
