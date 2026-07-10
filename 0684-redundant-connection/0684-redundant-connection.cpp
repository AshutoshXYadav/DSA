class Solution {
public:
    bool hasPath(int src, int target, int n, vector<vector<int>>& adj) {
        vector<bool> visit(n + 1, false);
        queue<pair<int, int>> q;
        
        q.push({src, -1});
        visit[src] = true;
        
        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            if (node == target) return true;
            
            for (auto adjNode : adj[node]) {
                if (!visit[adjNode]) {
                    visit[adjNode] = true;
                    q.push({adjNode, node});
                }
                else if (adjNode != parent) {
                    return true;
                }
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            if (hasPath(u, v, n, adj)) {
                return edge;
            }
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        return {};
    }
};