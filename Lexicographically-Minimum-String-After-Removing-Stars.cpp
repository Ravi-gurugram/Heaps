class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        vector<vector<int>> pos(26);   // indices of each letter seen so far
        vector<char> keep(n, 1);       // mark characters to keep
        int p = 0;                     // smallest letter that currently exists

        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                while (p < 26 && pos[p].empty()) ++p; // find smallest available
                if (p < 26) {                         // problem guarantees feasible
                    keep[pos[p].back()] = 0;          // delete that letter
                    pos[p].pop_back();
                }
                keep[i] = 0;                          // delete the star itself
            } else {
                int c = s[i] - 'a';
                pos[c].push_back(i);
                if (c < p) p = c;                     // update smallest present
            }
        }

        string res;
        res.reserve(n);
        for (int i = 0; i < n; ++i)
            if (keep[i] && s[i] != '*') res.push_back(s[i]);
        return res;
    }
};
