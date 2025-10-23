class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> asteroid;
        vector<int> ans;
        for(auto i : asteroids){
            if(i>0){
                asteroid.push(i);
                continue;
            }
            while(!asteroid.empty()&&abs(i)>asteroid.top()){
                asteroid.pop();
            }
            if(asteroid.empty()){
                ans.push_back(i);
            }
            else if(asteroid.top()==abs(i)){
                asteroid.pop();
            }
        }
        vector<int> temp;
        while(!asteroid.empty()){
            temp.push_back(asteroid.top());
            asteroid.pop();
        }
        int n = temp.size();
        for(int i = n-1; i >= 0; --i){
            ans.push_back(temp[i]);
        }
        return ans;
    }
};
