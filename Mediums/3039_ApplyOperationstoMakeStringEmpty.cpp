class Solution {
public:
    string lastNonEmptyString(string s) {
        vector<pair<int, int>> chars(26, pair<int, int>({0, -1}));
        int n = s.size();
        for(int i = 0; i < n; ++i){
            chars[s[i]-'a'].first++;
            chars[s[i]-'a'].second=i;
        }

        int maximum = INT_MIN;
        for(auto i : chars){
            maximum=max(maximum, i.first);
        }
        vector<pair<int, int>> chars_still_standing;
        for(int i = 0; i < 26; ++i){
            if(chars[i].first==maximum){
                chars_still_standing.push_back(pair<int, int>({chars[i].second, i}));
            }
        }
        sort(chars_still_standing.begin(), chars_still_standing.end());
        string ans;
        for(auto i : chars_still_standing){
            ans += (char)(i.second+'a');
        }
        return ans;

    }
};
