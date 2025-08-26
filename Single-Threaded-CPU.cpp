class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<array<int,3>> arr; 
        for (int i = 0; i < n; i++) {
            arr.push_back({tasks[i][0], tasks[i][1], i});
        }
        sort(arr.begin(), arr.end());  // sort by enqueueTime

        // Min-heap: {processingTime, index}
        using T = pair<int,int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        vector<int> result;
        long long time = 0;
        int i = 0;

        while (i < n || !pq.empty()) {
            if (pq.empty() && time < arr[i][0]) {
                time = arr[i][0];  // jump forward if idle
            }

            while (i < n && arr[i][0] <= time) {
                pq.push({arr[i][1], arr[i][2]}); // push (processingTime, index)
                i++;
            }

            auto [pTime, idx] = pq.top();
            pq.pop();
            time += pTime;
            result.push_back(idx);
        }

        return result;
    }
};
