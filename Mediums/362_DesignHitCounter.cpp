class HitCounter {
    set<int> timestamps;
    unordered_map<int, int> hits_at_time;
public:
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        timestamps.insert(timestamp);
        hits_at_time[timestamp]++;
    }
    
    int getHits(int timestamp) {
        int ans = 0;
        auto cutoff = timestamps.lower_bound(timestamp - 299);
        timestamps.erase(timestamps.begin(), cutoff);
        for(int i : timestamps){
            ans+=hits_at_time[i];
        }
        return ans;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
