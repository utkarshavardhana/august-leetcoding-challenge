class Solution {
    vector<int> res;
public:
    void traverse(int dig, int N, int K, int n) {
        if(dig == N) {
            res.push_back(n);
            return;
        }
        for(int i=0; i<=9; i++) {
            if(n == 0 or abs(n%10 - i) == K) {
                if(n!=0 or i!=0)   traverse(dig+1, N, K, n*10 + i);
            }
        }
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        if(N == 1)  return {0,1,2,3,4,5,6,7,8,9};
        traverse(0, N, K, 0);
        return res;
    }
};
