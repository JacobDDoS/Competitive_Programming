class TaskManager {
public:
    unordered_map<int, int> taskToUser, taskToPriority;
    unordered_map<int, set<int>> priorityToTasks;
    map<int, int> priorities;
    TaskManager(vector<vector<int>>& tasks) {
        for (vector<int>& task : tasks) {
            int userId = task[0], taskId = task[1], priority = task[2];
            taskToUser[taskId] = userId;
            taskToPriority[taskId] = priority;
            priorityToTasks[priority].insert(taskId);
            priorities[priority]++;
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskToUser[taskId] = userId;
        taskToPriority[taskId] = priority;
        priorityToTasks[priority].insert(taskId);
        priorities[priority]++;
    }
    
    void edit(int taskId, int newPriority) {
        int oldPriority = taskToPriority[taskId];
        priorityToTasks[oldPriority].erase(taskId);
        priorityToTasks[newPriority].insert(taskId);
        if (priorityToTasks[oldPriority].size() == 0) {
            priorityToTasks.erase(oldPriority);
        }
        priorities[oldPriority]--;
        if (priorities[oldPriority] == 0) {
            priorities.erase(oldPriority);
        }
        priorities[newPriority]++;
        taskToPriority[taskId] = newPriority;
    }
    
    void rmv(int taskId) {
        int priority = taskToPriority[taskId];
        priorities[priority]--;
        if (priorities[priority] == 0) {
            priorities.erase(priority);
        }

        priorityToTasks[priority].erase(taskId);
        if (priorityToTasks[priority].size() == 0) {
            priorityToTasks.erase(priority);
        }
        taskToPriority.erase(taskId);
        taskToUser.erase(taskId);
    }
    
    int execTop() {
        if (priorities.size() == 0) {
            return -1;
        }
        int highestPriority = (priorities.rbegin()->first);
        int highestTaskId = *(priorityToTasks[highestPriority].rbegin());

        priorities[highestPriority]--;
        if (priorities[highestPriority] == 0) {
            priorities.erase(highestPriority);
        }

        priorityToTasks[highestPriority].erase(*priorityToTasks[highestPriority].rbegin());
        if (priorityToTasks[highestPriority].size() == 0) {
            priorityToTasks.erase(highestPriority);
        }
        return taskToUser[highestTaskId];
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