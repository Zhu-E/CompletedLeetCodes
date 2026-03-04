class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> map;
        for(string path : paths){
            // int n = path.size();
            int cursor = path.find(" ");
            if(cursor==-1){
                continue;
            }
            string root = path.substr(0, cursor);
            ++cursor;
            while(-1!=path.find(")", cursor+1)){
                string filePath = root+"/"+path.substr(cursor, path.find("(", cursor+1)-cursor);
                string content = path.substr(path.find("(", cursor+1)+1, path.find(")", cursor+1)-path.find("(", cursor+1));
                map[content].push_back(filePath);
                cursor = path.find(")", cursor+1)+2;
            }
        }
        vector<vector<string>> ans;
        for(auto i : map){
            if(i.second.size()>1){
                ans.push_back(i.second);
            }
        }
        return ans;
    }
    
};
