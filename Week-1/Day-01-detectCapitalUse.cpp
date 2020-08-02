class Solution {
public:
    bool detectCapitalUse(string word) {
        bool alllower = true;
        bool allupper = true;
        bool firstCap = true;
        int i=0;
        for (auto c: word){
            if (c >= 'A' && c<='Z'){
                // upper case
                alllower = false;
                if (i>0){
                    firstCap = false;
                }
            }else{
                //lower case
                allupper = false;
                if (i==0){
                    firstCap == false;
                }
            }
            i++;
        }
        return alllower || allupper || firstCap;
    }
};
