class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> g(n);
        for(int i = 0; i < paths.size(); i++){
            g[paths[i][0] - 1].push_back(paths[i][1] - 1);
            g[paths[i][1] - 1].push_back(paths[i][0] - 1);
        }
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++){
            int color[5] = {0};
            for(int j = 0; j < g[i].size(); j++){
                color[ans[g[i][j]]] = 1; 
            }
            for(int c = 1; c <= 4; c++){
                if(color[c] == 0){
                    ans[i] = c;
                    break;
                }
            }
        }
        return ans;
    }
};