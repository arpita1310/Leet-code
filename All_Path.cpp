class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& answer, vector<int>& path, int idx){
        path.push_back(idx);

        if(idx == graph.size()-1) answer.push_back(path);
        else{
            for(auto &v : graph[idx]){
                dfs(graph, answer, path, v);
            }
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> answer;
        vector<int> path;
        dfs(graph, answer, path, 0);
        return answer;
    }
};