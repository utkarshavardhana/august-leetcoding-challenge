class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0)   return {1};
        if(rowIndex == 1)   return {1,1};
        vector<int> res = {1,1};
        rowIndex--;
        while(rowIndex--) {
            vector<int> temp;
            temp.push_back(res.front());
            for(int i=1; i<res.size(); i++) {
                temp.push_back(res[i] + res[i-1]);
            }
            temp.push_back(res.back());
            res = temp;
        }
        return res;
    }
};
