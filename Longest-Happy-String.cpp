class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});
        
        string result = "";
        
        while (!pq.empty()) {
            auto [cnt1, ch1] = pq.top(); pq.pop();
            
            int n = result.size();
            if (n >= 2 && result[n-1] == ch1 && result[n-2] == ch1) {
                // can't use ch1 now, try next best
                if (pq.empty()) break;
                auto [cnt2, ch2] = pq.top(); pq.pop();
                result.push_back(ch2);
                if (--cnt2 > 0) pq.push({cnt2, ch2});
                pq.push({cnt1, ch1}); // push back ch1 untouched
            } else {
                // safe to use ch1
                result.push_back(ch1);
                if (--cnt1 > 0) pq.push({cnt1, ch1});
            }
        }
        
        return result;
    }
};
