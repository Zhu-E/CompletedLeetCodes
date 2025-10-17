class FoodRatings {
private:
    unordered_map<string, int> food_ratings;
    struct Comp {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
            if (a.first != b.first)
                return a.first < b.first;  // higher rating first
            return a.second > b.second;   // lexicographically smaller name first
        }
    };
    unordered_map<string, string> food_to_cuisine;
    unordered_map<string, priority_queue<pair<int, string>, vector<pair<int,string>>, Comp>> top_cuisines;


public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0; i < n; ++i){
            food_ratings[foods[i]] = ratings[i];
            top_cuisines[cuisines[i]].push(pair<int, string>({ratings[i], foods[i]}));
            food_to_cuisine[foods[i]]=cuisines[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        food_ratings[food] = newRating;
        top_cuisines[food_to_cuisine[food]].push(pair<int, string>({newRating, food}));
    }
    
    string highestRated(string cuisine) {
        while(top_cuisines[cuisine].top().first!=food_ratings[top_cuisines[cuisine].top().second]){
            top_cuisines[cuisine].pop();
        }
        return top_cuisines[cuisine].top().second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
