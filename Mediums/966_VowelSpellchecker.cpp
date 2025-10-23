class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_map<string, int> caseSensitive;
        unordered_map<string, int> capitalization;
        unordered_map<string, int> vowel;
        int n = wordlist.size();
        for(int i = n-1; i >= 0; --i){
            caseSensitive[wordlist[i]]=i;
            capitalization[lowerCase(wordlist[i])]=i;
            vowel[vowelsToA(wordlist[i])]=i;
        }
        vector<string> ans;
        for(auto i : queries){
            if(caseSensitive.count(i)==1){
                ans.push_back(wordlist[caseSensitive[i]]);
            }
            else if(capitalization.count(lowerCase(i))==1){
                ans.push_back(wordlist[capitalization[lowerCase(i)]]);
            }
            else if(vowel.count(vowelsToA(i))==1){
                ans.push_back(wordlist[vowel[vowelsToA(i)]]);
            }
            else{
                ans.push_back("");
            }
        }
        return ans;

    }
    string lowerCase(string word){
        // cout<<"WORD WAS "<<word<<endl;
        string newString = "";
        for(auto i : word){
            if(i>='A'&&i<='Z'){
                newString+= (i+32);
            }
            else{
                newString += i;
            }
        }
        // cout<<"WORD IS NOW "<<newString<<endl;
        return newString;
    }
    string vowelsToA(string word){
        word = lowerCase(word);
        string newString = "";
        for(auto i : word){
            if(i=='e'||i=='i'||i=='o'||i=='u'){
                newString+='a';
            }
            else{
                newString+=i;
            }
        }
        return newString;
    }
};
