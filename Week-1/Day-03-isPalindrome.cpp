class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for(char c : s) {
            if((c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z') or (c >= '0' and c <= '9'))  
                str += toupper(c);
        }
        s = str;
        reverse(str.begin(), str.end());
        return s == str;
    }
};
