class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26,0);
        for(auto i : s){
            freq[i-'a']++;
        }
        int maxVowel=0;
        int maxCons=0;
        for(int i = 0; i < 26; ++i){
            if(i==0||i==4||i==8||i==14||i==20){
                maxVowel=max(maxVowel,freq[i]);
            }
            else{
                maxCons=max(maxCons,freq[i]);
            }
        }
        return maxVowel+maxCons;
    }
};
