struct sorter{
    bool operator()(const pair<long long, int>& left, const pair<long long, int>& right){
        if (left.first != right.first){
            return left.first > right.first;
        }
        return left.second > right.second;
    }
};

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, sorter> rooms; //First index is time available, second is room
        for(int i = 0; i < n; ++i){
            rooms.push(pair<long long,int>(0, i));
        }
        vector<int> usage(n, 0);
        sort(meetings.begin(),meetings.end());
        for(auto i : meetings){
            // cout<<i[0]<<" "<<i[1]<<endl;
            // cout<<rooms.top().first<<" "<<rooms.top().second<<endl;
            while(i[0]>rooms.top().first){
                rooms.push(pair<long long,int>(i[0], rooms.top().second));
                rooms.pop();
            }
            if(i[0]==rooms.top().first){
                usage[rooms.top().second]++;
                rooms.push(pair<long long,int>(i[1], rooms.top().second));
                // cout<<i[1]<<" "<<rooms.top().second<<endl;
                rooms.pop();
                // cout<<rooms.size()<<endl;
            }
            else{
                usage[rooms.top().second]++;
                int duration = i[1]-i[0];
                rooms.push(pair<long long,int>(rooms.top().first+duration, rooms.top().second));
                rooms.pop();
            }
        }
        int ans = -1;
        int maxVal = 0;
        for(int i = 0; i < n; ++i){
            // cout<<usage[i]<<" ";
            if(usage[i]>maxVal){
                maxVal = usage[i];
                ans = i;
            }
        }
        return ans;

    }
};
