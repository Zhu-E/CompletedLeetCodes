class Solution {
public:
    string reorganizeString(string s) {
        vector<int> count(26, 0);
        for(char c : s){
            ++count[c-'a'];
        }
        priority_queue<pair<int, int>> pq;
        for(int i = 0 ; i < 26 ; ++i){
            if(count[i]>0){
                pq.push(pair<int,int>({count[i],i}));
            }
        }
        string ans = "";
        char lastChar='0';
        while(!pq.empty()){
            bool lastLetter = true;
            pair<int, int> firstChoice = pq.top();
            pq.pop();
            pair<int, int> secondChoice;
            if(!pq.empty()){
                lastLetter=false;
                secondChoice = pq.top();
                pq.pop();
            }
            if(lastLetter&&(lastChar==firstChoice.second+'a'||firstChoice.first>1)){
                return "";
            }
            if(firstChoice.second+'a'==lastChar){
                lastChar = secondChoice.second+'a';
                secondChoice.first=secondChoice.first-1;
                ans+=(secondChoice.second+'a');
                if(secondChoice.first!=0){
                    pq.push(secondChoice);
                }

                pq.push(firstChoice);
            }
            else{
                lastChar = firstChoice.second+'a';
                firstChoice.first=firstChoice.first-1;
                ans+=firstChoice.second+'a';
                if(firstChoice.first!=0){
                    pq.push(firstChoice);
                }
                if(secondChoice.first!=0){
                    pq.push(secondChoice);
                }
            }

        }
        return ans;
    }
};
