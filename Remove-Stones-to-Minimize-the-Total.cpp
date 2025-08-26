class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(), piles.end());

        while (k-- > 0) {
            int x = pq.top(); pq.pop();
            x -= x / 2;  // remove floor(x/2), so keep ceil(x/2)
            pq.push(x);
        }

        long long sum = 0;
        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
        return (int)sum;
    }
};
