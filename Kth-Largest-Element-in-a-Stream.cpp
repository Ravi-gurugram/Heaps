class KthLargest {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int K;

public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for (int n : nums) {
            minHeap.push(n);
            if (minHeap.size() > K) {
                minHeap.pop();
            }
        }
    }

    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > K) {
            minHeap.pop();
        }
        return minHeap.top(); // kth largest
    }
};


/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */