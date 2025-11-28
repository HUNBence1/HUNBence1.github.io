#include <bits/stdc++.h>
using namespace std;
 
struct Edge {
    int to, cost;
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> adj(n + 1);
 
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
 
    const long long INF = 1e18;
    vector<vector<long long>> dist(n + 1, vector<long long>(2, INF));
    dist[1][0] = 0;
 
 
    priority_queue<tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>> pq;
    pq.emplace(0, 1, 0);
 
    while (!pq.empty()) {
        auto [cost, u, used] = pq.top(); pq.pop();
 
        if (cost > dist[u][used]) continue;
 
        for (auto &e : adj[u]) {
            int v = e.to;
            int price = e.cost;
 
 
            if (dist[v][used] > cost + price) {
                dist[v][used] = cost + price;
                pq.emplace(dist[v][used], v, used);
            }
 
 
            if (used == 0) {
                long long half_price = price / 2;
                if (dist[v][1] > cost + half_price) {
                    dist[v][1] = cost + half_price;
                    pq.emplace(dist[v][1], v, 1);
                }
            }
        }
    }
 
    cout << min(dist[n][0], dist[n][1]) << "\n";
 
    return 0;
}