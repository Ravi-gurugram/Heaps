class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double,int>> workers;  // {ratio, quality}
        
        for (int i = 0; i < n; i++) {
            double ratio = (double)wage[i] / quality[i];
            workers.push_back({ratio, quality[i]});
        }
        
        // Sort by ratio ascending
        sort(workers.begin(), workers.end());
        
        priority_queue<int> pq; // max heap for qualities
        int sumQuality = 0;
        double result = 1e18;
        
        for (auto& [ratio, q] : workers) {
            pq.push(q);
            sumQuality += q;
            
            if (pq.size() > k) {
                sumQuality -= pq.top();
                pq.pop();
            }
            
            if (pq.size() == k) {
                result = min(result, ratio * sumQuality);
            }
        }
        
        return result;
    }
};
