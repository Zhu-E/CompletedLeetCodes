class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n = s.size();
        int alength = a.size();
        int blength = b.size();
        vector<int> a_indices;
        vector<int> b_indices;
        vector<int> ans;
        for(int i = 0; i < n; ++i){
            if(i+alength<=n&&s.substr(i, alength)==a){
                a_indices.push_back(i);                
            }
            if(i+blength<=n&&s.substr(i, blength)==b){
                b_indices.push_back(i);
            }
        }
        int i = 0;
        int j = 0;
        while(i < a_indices.size() && j < b_indices.size()){
            // cout<<a_indices[i]<<" "<<b_indices[j]<<endl;
            if(a_indices[i]-b_indices[j]>=-1*k&&a_indices[i]-b_indices[j]<=k){
                ans.push_back(a_indices[i]);
                ++i;
            }
            else if(a_indices[i]-b_indices[j]<-1*k){
                ++i;
            }
            else if(a_indices[i]-b_indices[j]>k){
                ++j;
            }
        }
        return ans;
    }
};
