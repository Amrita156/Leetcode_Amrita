class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& a) {
        vector<vector<pair<int, int>>> adj_list(a.size(), vector<pair<int, int>>());
        for(int i = 0 ; i < a.size(); i++) {
            vector<int> curr = a[i];
            for(int j = 0; j < a.size(); j++) {
                if(j == i) continue;
                adj_list[i].push_back({abs(curr[0] - a[j][0]) + abs(curr[1] - a[j][1]), j});
            }
        }
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>>> pq;
        vector<int> visited(a.size(), 0);
        pq.push({0, 0});
        int ans = 0;
        while(!pq.empty()) {
            int curr = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            if(visited[curr]) continue;
            visited[curr] = true;
            ans += wt;
            for(pair<int, int> neighb: adj_list[curr]) {
                if(visited[neighb.second]) continue;
                pq.push(neighb);
            }
        }
        return ans;
    }
};
