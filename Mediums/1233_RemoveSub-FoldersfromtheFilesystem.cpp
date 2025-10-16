class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        int n = folder.size();
        string base = "";
        for(int i = 0; i < n; ++i){
            // cout<<base<<" "<<folder[i].substr(0,base.size())<<" "<<folder[i]<<endl;
            if(base==""||!(folder[i].substr(0,base.size())==base&&folder[i][base.size()]=='/')){
                base = folder[i];
                ans.push_back(folder[i]);
            }
        }
        return ans;
    }
};
