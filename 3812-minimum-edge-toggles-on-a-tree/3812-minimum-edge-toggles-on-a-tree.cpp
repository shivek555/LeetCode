class Solution {
public:
        vector<int> res;
        vector<vector<pair<int,int>>> adj;
        vector<int> diff;

        bool dfs(int u, int parent, int edgeIdx){
            int curr = diff[u];

            for(auto &[v,idx]: adj[u]){
                if(v==parent) continue;
                if(dfs(v,u,idx)) curr^=1;
            }
            if(curr==1){
                if (parent ==-1) return true;
                res.push_back(edgeIdx);
                return true;
            }
            return false;
        }
    vector<int> minimumFlips(int n, vector<vector<int>>& edges, string start, string target) { adj.assign(n, {});
        diff.assign(n, 0);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back({v, i});
            adj[v].push_back({u, i});
        }

        for (int i = 0; i < n; i++) {
            diff[i] = (start[i] - '0') ^ (target[i] - '0');
        }

        if (dfs(0, -1, -1))
            return {-1};

        sort(res.begin(), res.end());
        return res;
        
    }
};