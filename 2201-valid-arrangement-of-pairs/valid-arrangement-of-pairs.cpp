class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>>adj;

        unordered_map<int,int>indegree,outdegree;

        for(auto&edge:pairs){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            outdegree[u]++;
            indegree[v]++;
        }

        int startNode = pairs[0][0];
        for(auto &it:adj){
            int node = it.first;

            if(outdegree[node]-indegree[node]==1){
                startNode = node;
                break;
            }
        }

        vector<int>path;
        stack<int>st;
        st.push(startNode);
        while(!st.empty()){
            int curr = st.top();
            if(!adj[curr].empty()){
                int neighbour = adj[curr].back();
                adj[curr].pop_back();
                st.push(neighbour);
            }else{
                path.push_back(curr);
                st.pop();
            }

        }


        reverse(begin(path),end(path));


        vector<vector<int>> result;
        for(int i=0;i<path.size()-1;i++){
            result.push_back({path[i],path[i+1]});
        }
        return result;
    }
};