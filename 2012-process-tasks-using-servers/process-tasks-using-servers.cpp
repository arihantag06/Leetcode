class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupiedServers;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> freeServers;

        for (int i = 0; i < servers.size(); i++) {
            freeServers.push({servers[i], i});
        }

        vector<int> ans;
        int currentTime = 0;

        for (int i = 0; i < tasks.size(); i++) {
            currentTime = max(currentTime, i);
            
            while (!occupiedServers.empty() && occupiedServers.top().first <= currentTime) {
                auto p = occupiedServers.top();
                occupiedServers.pop();
                freeServers.push({servers[p.second], p.second});
            }

            if (freeServers.empty()) {
                currentTime = occupiedServers.top().first;
                while (!occupiedServers.empty() && occupiedServers.top().first <= currentTime) {
                    auto p = occupiedServers.top();
                    occupiedServers.pop();
                    freeServers.push({servers[p.second], p.second});
                }
            }

            auto t = freeServers.top();
            freeServers.pop();
            ans.push_back(t.second);
            occupiedServers.push({currentTime + tasks[i], t.second});
        }

        return ans;
    }
};
