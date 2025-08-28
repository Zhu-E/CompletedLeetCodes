class AuthenticationManager {
public:
    AuthenticationManager(int timeToLive) {
        TTL=timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        idToExpiryTime[tokenId]=currentTime+TTL;
        sortedExpiryTimes.push_back(currentTime+TTL);
        ++numTokens;
    }
    
    void renew(string tokenId, int currentTime) {
        if(idToExpiryTime[tokenId]<=currentTime){
            return;
        }
        int oldExpiryTime=idToExpiryTime[tokenId];
        idToExpiryTime[tokenId]=currentTime+TTL;
        sortedExpiryTimes.push_back(currentTime+TTL);
        auto i = upper_bound(sortedExpiryTimes.begin(),sortedExpiryTimes.end(), oldExpiryTime-1);
        sortedExpiryTimes.erase(i);
    }
    
    int countUnexpiredTokens(int currentTime) {
        return numTokens-(upper_bound(sortedExpiryTimes.begin(),sortedExpiryTimes.end(), currentTime)-sortedExpiryTimes.begin());
    }
private: 
    int TTL;
    unordered_map<string,int> idToExpiryTime;
    vector<int> sortedExpiryTimes;
    int numTokens=0;
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
