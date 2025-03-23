class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> recently_used;
        int i = 0;
        int cur = 0;
        int sol = 0;
        int start = -1;
        for (auto& letter : s)
        {
            if (recently_used.find(letter) == recently_used.end())
            {
                recently_used[letter] = i;
                cur++;
            }
            else
            {
                if (recently_used[letter] > start)
                    start = recently_used[letter];
                cur = i - start;
                recently_used[letter] = i;
            }
            sol = max(sol, cur);
            i++;
        }
        return sol;
    }
};