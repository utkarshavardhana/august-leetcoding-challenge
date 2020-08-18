class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> p(num_people, 0);
        int c = 1;
        while(candies) {
            for(int &i : p) {
                if(!candies)    break;
                if(candies >= c) {
                    i += c;
                    candies -= c;
                } else {
                    i += candies;
                    candies = 0;
                }
                c++;
            }
        }
        return p;
    }
};
