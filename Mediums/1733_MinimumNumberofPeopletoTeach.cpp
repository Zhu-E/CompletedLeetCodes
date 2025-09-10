class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        vector<vector<int>> need_to_fix;
        for(auto i : friendships){
            if(!canCommunicate(languages,i[0]-1,i[1]-1)){
                need_to_fix.push_back(i);
            }
        }
        vector<int> common_language_count(n+1,0);
        unordered_set<int> seen_users;
        for(auto i : need_to_fix){
            if(seen_users.count(i[0])==0){
                for(auto j : languages[i[0]-1]){
                    common_language_count[j]++;
                }
                seen_users.insert(i[0]);
            }
            if(seen_users.count(i[1])==0){
                for(auto j : languages[i[1]-1]){
                    common_language_count[j]++;
                }
                seen_users.insert(i[1]);
            }
        }
        int max_count=0;
        for(auto i : common_language_count){
            max_count=max(max_count,i);
        }
        return seen_users.size()-max_count;

    }
    bool canCommunicate(vector<vector<int>>& languages, int left, int right){
        for(auto i : languages[left]){
            for(auto j : languages[right]){
                if(i==j){
                    return true;
                }
            }
        }
        return false;
    }
};
