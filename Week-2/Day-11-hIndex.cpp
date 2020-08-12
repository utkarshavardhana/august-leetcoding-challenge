class Solution {
public:
    int hIndex(vector<int>& a) {
        sort(a.begin(), a.end(), greater<int>());
        int res = 0;
        for(int i=0; i<a.size(); i++) {
            if(min(i+1, a[i]) > res) {
                res = min(i+1, a[i]);
            } else {
                return res;
            }
        }
        return res;
    }
};
