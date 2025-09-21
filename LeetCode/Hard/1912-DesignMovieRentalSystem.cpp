struct PairHash {
    size_t operator()(const std::pair<int, int>& p) const {
        return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
    }
};

class MovieRentingSystem {
public:
    // movie -> unrented, sorted
    // rentedMovies == movies rented, sorted
    unordered_map<int, set<pair<int,int>>> movieIdToUnrentedPairs;
    unordered_map<pair<int,int>,int, PairHash> movieIdAndShopIdToPrice;
    set<tuple<int,int,int>> rentedMovies; 

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& entry : entries) {
            int shopId = entry[0], movieId = entry[1], price = entry[2];
            movieIdToUnrentedPairs[movieId].insert(make_pair(price, shopId));
            movieIdAndShopIdToPrice[make_pair(movieId,shopId)] = price;
        }
    }
    
    vector<int> search(int movie) {
        vector<int> cheapestStores;
        for (auto& pr : movieIdToUnrentedPairs[movie]) {
            if (cheapestStores.size() == 5) break;
            cheapestStores.push_back(pr.second);
        }
        return cheapestStores;
    }
    
    void rent(int shop, int movie) {
        movieIdToUnrentedPairs[movie].erase(make_pair(movieIdAndShopIdToPrice[make_pair(movie, shop)], shop));
        rentedMovies.insert({movieIdAndShopIdToPrice[make_pair(movie, shop)], shop, movie});
    }
    
    void drop(int shop, int movie) {
        rentedMovies.erase({movieIdAndShopIdToPrice[make_pair(movie, shop)], shop, movie});
        movieIdToUnrentedPairs[movie].insert(make_pair(movieIdAndShopIdToPrice[make_pair(movie, shop)], shop));
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> finishedReport;
        for (auto& tup : rentedMovies) {
            if (finishedReport.size() == 5) break;
            int shop = std::get<1>(tup), movie=std::get<2>(tup);
            finishedReport.push_back({shop, movie});
        }

        return finishedReport;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */