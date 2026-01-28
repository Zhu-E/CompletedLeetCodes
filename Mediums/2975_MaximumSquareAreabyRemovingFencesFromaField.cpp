class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        unordered_set<int> possibleHorz;
        possibleHorz.insert(n-1);
        priority_queue<int> possibleVert;
        possibleVert.push(m-1);
        int numHorzFences = hFences.size();
        int numVertFences = vFences.size();
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        for(int i = 0; i < numHorzFences; ++i){
            if(m-hFences[i]>0){
                possibleVert.push(m-hFences[i]);
            }
            possibleVert.push(hFences[i]-1);
            for(int j = i+1 ; j < numHorzFences; ++j){
                possibleVert.push(hFences[j]-hFences[i]);
            }
        }
        for(int i = 0; i < numVertFences; ++i){
            if(n-vFences[i]>0){
                possibleHorz.insert(n-vFences[i]);
            }
            possibleHorz.insert(vFences[i]-1);
            // cout<<n-vFences[i]<<endl;
            for(int j = i+1 ; j < numVertFences; ++j){
                possibleHorz.insert(vFences[j]-vFences[i]);    
            }
        }
        // cout<<possibleVert.size();
        while(!possibleVert.empty()){
            // cout<<possibleVert.top()<<" ";
            if(possibleHorz.count(possibleVert.top())==1){
                return ((long)possibleVert.top()*(long)possibleVert.top())%1000000007;
            }
            else{
                possibleVert.pop();
            }
        }
        return -1;

    }
};
