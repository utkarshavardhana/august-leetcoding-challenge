class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> res;
        for(int i : A) {
            if(i%2) res.push_back(i);
            else    res.insert(res.begin(), i);
        }
        return res;
    }
};
