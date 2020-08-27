class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for(int i=1; i<=n; i++) {
            string str = "";
            if(i%3 == 0)    str += "Fizz";
            if(i%5 == 0)    str += "Buzz";
            if(i%3 and i%5) str += to_string(i);
            res.push_back(str);
        }
        return res;
    }
};
