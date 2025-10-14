class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int ans = 0;
        int curPos = startFuel;
        int index = 0;
        int n = stations.size();
        priority_queue<int> maxFuel;
        while(curPos<target){
            // cout<<"LOOPING"<<endl;
            while(index<n&&stations[index][0]<=curPos){
                // cout<<"HERE!"<<endl;
                maxFuel.push(stations[index][1]);
                ++index;
            }
            if(maxFuel.empty()){
                return -1;
            }
            cout<<maxFuel.top()<<endl;
            curPos += maxFuel.top();
            maxFuel.pop();
            ++ans;
            // cout<<curPos<<endl;
        }
        return ans;
        
    }
};
