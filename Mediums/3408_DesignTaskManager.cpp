class TaskManager {
private:
    priority_queue<pair<int, int>> pq; //.first is prio .second is taskid
    unordered_map<int, int> taskPriority; //taskId->prio
    unordered_map<int, int> taskIDToUser; //taskId -> userID

public:
    TaskManager(vector<vector<int>>& tasks) {
        for(auto i : tasks){
            pq.push(pair<int, int>(i[2], i[1]));
            taskPriority[i[1]]=i[2];
            taskIDToUser[i[1]]=i[0];
        }
    }
    
    void add(int userId, int taskId, int priority) {
        pq.push(pair<int, int>(priority, taskId));
        taskPriority[taskId]=priority;
        taskIDToUser[taskId]=userId;
    }
    
    void edit(int taskId, int newPriority) {
        taskPriority[taskId]=newPriority;
        pq.push(pair<int, int>(newPriority, taskId));
    }
    
    void rmv(int taskId) {
        taskPriority.erase(taskId);
        taskIDToUser.erase(taskId);
    }
    
    int execTop() {
        while(!pq.empty()){
            pair<int, int> cur = pq.top();
            // cout<<cur.first<<" "<<cur.second<<endl;
            // for(auto i : taskPriority){
            //     cout<<i.first<<" "<<i.second<<endl;
            // }
            if(taskPriority.count(cur.second)&&cur.first==taskPriority[cur.second]){
                pq.pop();
                taskPriority.erase(cur.second);
                int userId = taskIDToUser[cur.second];
                taskIDToUser.erase(cur.second);
                return userId;
            }
            pq.pop();
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
