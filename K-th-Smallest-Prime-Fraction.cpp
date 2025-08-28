class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        // Min-heap: {value, numerator index, denominator index}
        auto cmp = [&](auto &a, auto &b) {
            return (double)arr[a.first] / arr[a.second] > (double)arr[b.first] / arr[b.second];
        };
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
        
        // push first row fractions arr[0]/arr[j]
        for (int j = 1; j < n; j++) {
            pq.push({0, j});  // numerator index = 0, denominator index = j
        }
        
        while (--k) {
            auto [i, j] = pq.top(); pq.pop();
            if (i + 1 < j) {
                pq.push({i + 1, j});
            }
        }
        
        auto [i, j] = pq.top();
        return {arr[i], arr[j]};
    }
};
