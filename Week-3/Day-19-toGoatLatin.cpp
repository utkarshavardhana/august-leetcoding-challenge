class Solution {
public:
    string toGoatLatin(string S) {
        string res;
        set<char> vow = {'a', 'e', 'i', 'o', 'u'};
        int j = 0, count = 1;
        for(int i=0; i<S.size(); i++) {
            if(S[i] == ' ') {
                if(vow.count(tolower(S[j])) == 0) {
                    char c = S[j];
                    S.erase(S.begin()+j);
                    S.insert(S.begin()+i-1, c);
                }
                int shift = 2+count;
                string trail = "ma" + string(count++, 'a');
                S.insert(i, trail);
                i = i+shift;    j = i+1;
            } else if(i == S.size()-1) {
                if(vow.count(tolower(S[j])) == 0) {
                    char c = S[j];
                    S.erase(S.begin()+j);
                    S += c;
                }
                int shift = 2+count;
                string trail = "ma" + string(count++, 'a');
                S += trail;
                i = i+shift;    j = i+1;
            }
        }
        return S;
    }
};
