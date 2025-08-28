class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> projects;
        for (int i = 0; i < n; i++) {
            projects.push_back({capital[i], profits[i]});
        }

        sort(projects.begin(), projects.end());  // sort by required capital

        priority_queue<int> maxProfit; // max-heap
        int idx = 0;

        for (int i = 0; i < k; i++) {
            // add all affordable projects
            while (idx < n && projects[idx].first <= w) {
                maxProfit.push(projects[idx].second);
                idx++;
            }
            if (maxProfit.empty()) break; // nothing affordable
            w += maxProfit.top();
            maxProfit.pop();
        }

        return w;
    }
};

