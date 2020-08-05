class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num < 0) return false;
        return ((__builtin_popcount(num) == 1) and (__builtin_ctz(num)%2 == 0));
    }
};
