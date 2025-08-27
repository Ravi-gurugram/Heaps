class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int,int>> arr;  // {nums2[i], nums1[i]}
        
        for (int i = 0; i < n; i++) {
            arr.push_back({nums2[i], nums1[i]});
        }
        
        // Sort by nums2 descending
        sort(arr.rbegin(), arr.rend());
        
        long long ans = 0, sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq; // min-heap for nums1
        
        for (auto &p : arr) {
            int n2 = p.first, n1 = p.second;
            
            pq.push(n1);
            sum += n1;
            
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            
            if (pq.size() == k) {
                ans = max(ans, sum * 1LL * n2);
            }
        }
        
        return ans;}} ;