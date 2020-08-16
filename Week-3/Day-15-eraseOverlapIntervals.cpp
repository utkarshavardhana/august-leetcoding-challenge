class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ret = 0;
        int n = intervals.size();
        if (n < 1)    return ret;
        sort(intervals.begin(), intervals.end(),[]
             (const vector<int> & l, const vector<int> & r)->bool {
                if (l[1] < r[1])
                    return true;
                if (l[1] == r[1] && l[0] < r[0])
                    return true;
                return false;
            }
        );
        int i = 0;
        for (int j = 1; j < n; ++j) {
            if (intervals[j][0] >= intervals[i][1])
                i = j;
            else
                ++ret;
        }
        return ret;
    }
};
