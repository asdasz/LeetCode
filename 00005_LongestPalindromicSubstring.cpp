class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 1) return s;
        int center = 0;
        int longest = 0;
        int current = 0;
        for (int i = 1; i < s.size(); i++)
        {
            current = 0;
            //parzyste
            if (s[i] == s[i - 1])
            {
                current = 2;
                for (int j = 1; i - j > 0 && i + j < s.size(); j++)
                {
                    if (s[i - 1 - j] == s[i + j]) current += 2;
                    else break;
                }


            }
            //nieparzyste
            if (current > longest)
            {
                longest = current;
                center = i;
            }

            current = 1;
            for (int j = 1; i - j >= 0 && i + j < s.size(); j++)
            {
                if (s[i - j] == s[i + j]) current += 2;
                else break;
            }


            if (current > longest)
            {
                longest = current;
                center = i;
            }
        }

        s = s.substr(center - longest / 2, longest);

        return s;
    }
};