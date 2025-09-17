class FoodRatings {
public:
    unordered_map<string, map<int, set<string>>> mp;
    unordered_map<string, string> foodToCuisine;
    unordered_map<string, int> foodToRating;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i=0;i<foods.size();i++) {
            mp[cuisines[i]][ratings[i]].insert(foods[i]);
            foodToCuisine[foods[i]] = cuisines[i];
            foodToRating[foods[i]] = ratings[i];
        }

    }
    
    void changeRating(string food, int newRating) {
        mp[foodToCuisine[food]][foodToRating[food]].erase(food);
        if (mp[foodToCuisine[food]][foodToRating[food]].size() == 0) {
            mp[foodToCuisine[food]].erase(foodToRating[food]);
        }
        mp[foodToCuisine[food]][newRating].insert(food);
        foodToRating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        pair<int,set<string>> ptr = *mp[cuisine].rbegin();
        return *ptr.second.begin();
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */