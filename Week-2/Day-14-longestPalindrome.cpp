class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> m;
        int res = 0, flag = 0;
        for(char c : s) m[c]++;
        for(auto it=m.begin(); it!=m.end(); it++) {
            if((*it).second % 2 == 0)   res += (*it).second;
            else {
                res += (*it).second-1;
                flag++;
            }
        }
        if(flag)    res++;
        return res;
    }
};
