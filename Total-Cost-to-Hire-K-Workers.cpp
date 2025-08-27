#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        long long ans = 0;

        priority_queue<int, vector<int>, greater<int>> leftHeap, rightHeap;
        int left = 0, right = n - 1;

        // Fill initial candidates
        for (int i = 0; i < candidates && left <= right; i++) {
            leftHeap.push(costs[left++]);
        }
        for (int i = 0; i < candidates && left <= right; i++) {
            rightHeap.push(costs[right--]);
        }

        // Hire k workers
        for (int i = 0; i < k; i++) {
            int leftVal = leftHeap.empty() ? INT_MAX : leftHeap.top();
            int rightVal = rightHeap.empty() ? INT_MAX : rightHeap.top();

            if (leftVal <= rightVal) {
                ans += leftVal;
                leftHeap.pop();
                if (left <= right) leftHeap.push(costs[left++]);
            } else {
                ans += rightVal;
                rightHeap.pop();
                if (left <= right) rightHeap.push(costs[right--]);
            }
        }

        return ans;
    }
};
