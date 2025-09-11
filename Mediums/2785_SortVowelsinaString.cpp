class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;
        for(auto c : s){
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U'){
                vowels.push_back(c);
            }
        }
        sort(vowels.begin(),vowels.end());
        int n = s.size();
        int index = 0;
        for(int i = 0; i < n; ++i){
            char c = s[i];
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U'){
                s[i]=vowels[index];
                ++index;
            }
        }
        return s;
    }
};
