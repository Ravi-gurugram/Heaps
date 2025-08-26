class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        int n = s.size();
        vector<vector<char>> bucket(n + 1);

        for (auto& [ch, f] : freq) {
            bucket[f].push_back(ch);
        }

        string result;
        for (int f = n; f >= 1; f--) {
            for (char c : bucket[f]) {
                result.append(f, c);  // repeat c, f times
            }
        }
        return result;
    }
};