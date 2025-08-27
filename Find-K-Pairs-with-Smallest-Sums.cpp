#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        if (nums1.empty() || nums2.empty() || k == 0) return result;

        // Min-heap: {sum, i, j}
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> minHeap;

        // Push pairs (nums1[i], nums2[0]) into heap
        for (int i = 0; i < nums1.size() && i < k; i++) {
            minHeap.emplace(nums1[i] + nums2[0], i, 0);
        }

        while (!minHeap.empty() && result.size() < k) {
            auto [sum, i, j] = minHeap.top();
            minHeap.pop();

            result.push_back({nums1[i], nums2[j]});

            // Move to next element in nums2
            if (j + 1 < nums2.size()) {
                minHeap.emplace(nums1[i] + nums2[j+1], i, j+1);
            }
        }

        return result;
    }
};
