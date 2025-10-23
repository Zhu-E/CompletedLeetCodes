class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size()>2){
            string newString = "";
            int n = s.size();
            for(int i = 0; i < n-1; ++i){
                newString+=to_string(((int)(s[i]-'0')+(int)(s[i+1]-'0'))%10);
            }
            s=newString;
        }
        return s[0]==s[1];
    }
};
