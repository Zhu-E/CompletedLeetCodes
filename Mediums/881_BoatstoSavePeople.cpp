class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();
        int r = n-1;
        int l = 0;
        int ans = 0;
        while(l<=r){
            if(l==r){
                ++ans;
                return ans;
            }
            if(people[l]+people[r]<=limit){
                ++l;
                --r;
                ++ans;
            }
            else{
                --r;
                ++ans;
            }
        }
        return ans;
    }
};
