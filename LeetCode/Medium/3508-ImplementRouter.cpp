class Router {
public:
    unordered_map<unsigned long long, bool> dup;
    unordered_map<int, vector<int>> destToTime;
    unordered_map<int, int> destToStartItr;
    queue<vector<int>> q;
    int maxSize;

    Router(int memoryLimit) {
        maxSize = memoryLimit;
    }

    unsigned long long hash(vector<int> packet) {
        unsigned long long num = 348 + packet[0] + packet[2] - packet[1];
        for (int i : packet) {
            num ^= std::hash<int>()(i) + 0x9e3779b9 + (num << 6) + (num >> 2);
        }
        return num;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        vector<int> packet = {source, destination, timestamp};
        if (dup[hash(packet)]) {
            return false;
        } else {
            if (q.size() == maxSize) {
                vector<int> oldPacket = q.front();
                q.pop();
                destToStartItr[oldPacket[1]]++;
                dup[hash(oldPacket)] = false;
            }
            dup[hash(packet)] = true;
            q.push(packet);
            destToTime[packet[1]].push_back(packet[2]);
        }
        return true;
    }
    
    vector<int> forwardPacket() {
        if (q.size() == 0) return {};
        vector<int> packet = q.front();
        q.pop();
        dup[hash(packet)] = false;
        destToStartItr[packet[1]]++;
        return packet;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto begin = (destToTime[destination].begin()+(destToStartItr[destination]));
        int endIdx = lower_bound(begin, destToTime[destination].end(), endTime+1) - begin;
        int startIdx = lower_bound(begin, destToTime[destination].end(), startTime) - begin;
        return endIdx - startIdx;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */