#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define CEIL(m,n) ((m)+(n)-1)/(n)
using namespace __gnu_pbds;
using namespace std;
     
template <typename T>
using pbds = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>; //find_by_order, order_of_key
typedef priority_queue<int,vector<int>,greater<int>> PQ;
typedef priority_queue<int> MPQ;
const int MOD = 1e9 + 7;
#define heeho(n) ((((n)%MOD)+MOD)%MOD)
#define pow2(n) (n && !(n & (n - 1)))
#define kthbit(n,k) (n >> (k-1)) & 1
#define lsb(n) (n & -n)
#define currbit(n, i) (1ll & n >> i)
const int MAX =1e9;
const ll int INF = 1e17;

// binary coefficients
vector<vector<ll int>> binarycoefficients(int n){
    vector<vector<ll int>> C(n+1, vector<ll int>(n+1));
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= min(i, n); j++){
            if(j == 0 || j == i){
                C[i][j] = 1;
            }else{
                C[i][j] = C[i-1][j-1] + C[i-1][j];
            }
        }
    }
    return C;
}

// binary exponentiation
ll binpow_mod(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

// Primes till n
vector<ll int> sieveofEratosthenes(ll int n){
    vector<ll int> primes;
    vector<bool> isprime(n+1, true);
    isprime[0] = isprime[1] = false;
    for (ll int i = 2; i*i <= n; i++){
        if(isprime[i]){
            for (ll int j = i*i; j <= n; j += i){
                isprime[j] = false;
            }
        }
    }
    for (ll int i = 2; i <= n; i++){
        if(isprime[i]){
            primes.push_back(i);
        }
    }
    return primes;
}

// Factors of n
vector<ll int> factors(int n){
    vector<ll int> f;
    for (int i = 2; i*i <= n; i++){
        while(!(n%i)){
            f.push_back(i);
            n /= i;
        }
    }
    if(n > 1){
        f.push_back(n);
    }
    return f;
}

// prime factors of n
vector<ll int> primefactors(ll int n){
    vector<ll int> factors;
    while(n%2 == 0){
        factors.push_back(2);
        n/=2;
    }
    for (ll int i = 3; i*i <= n; i+=2){
        while(n%i == 0){
            factors.push_back(i);
            n/=i;
        }
    }
    if(n > 2){
        factors.push_back(n);
    }
    return factors;
}

// dijkstra
vector<ll int> dijkstra(vector<vector<pair<ll int, ll int>>>& graph,ll int src ,ll int n) {
    vector<ll int> dist(n, 1e17);
    priority_queue<pair<ll int, ll int>, vector<pair<ll int, ll int>>, greater<pair<ll int, ll int>>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        pair<ll int, ll int> top = pq.top();
        ll int u = top.second;
        ll int d = top.first;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto& edge : graph[u]) {
            ll int v = edge.first;
            ll int weight = edge.second;
            
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

// negative weights bellmanford
vector<ll int> bellmanford(vector<vector<pair<ll int, ll int>>>& graph, ll int src, ll int n){
    vector<ll int> dist(n, 1e17);
    dist[src] = 0;
    for (int i = 0; i < n-1; i++){
        for (int u = 0; u < n; u++){
            for (auto& edge : graph[u]){
                ll int v = edge.first;
                ll int weight = edge.second;
                if(dist[u] + weight < dist[v]){
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }
    return dist;
}

// floyd warshall all pairs shortest path
vector<vector<ll int>> floydwarshall(vector<vector<ll int>>& graph, ll int n){
    vector<vector<ll int>> dist(n, vector<ll int>(n, 1e17));
    for (int i = 0; i < n; i++){
        dist[i][i] = 0;
        for (int j = 0; j < graph[i].size(); j++){
            ll int v = graph[i][j];
            dist[i][v] = 1;
        }
    }
    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if(dist[i][k] < 1e17 && dist[k][j] < 1e17){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    return dist;
}

// bfs
void bfs(vector<vector<ll int>>& graph, ll int src, vector<bool>& visited){
    queue<ll int> q;
    q.push(src);
    visited[src] = true;
    while(!q.empty()){
        ll int x = q.front();
        q.pop();
        for(int i = 0; i < graph[x].size(); i++){
            ll int v = graph[x][i];
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

// dfs
void dfs(vector<vector<ll int>>& graph, ll int src, vector<bool>& visited){
    visited[src] = true;
    for(int i = 0; i < graph[src].size(); i++){
        ll int v = graph[src][i];
        if(!visited[v]){
            dfs(graph, v, visited);
        }
    }
}

// topological sort
void topologicalsort(vector<vector<ll int>>& graph, ll int src, vector<bool>& visited, stack<ll int>& s){
    visited[src] = true;
    for(int i = 0; i < graph[src].size(); i++){
        ll int v = graph[src][i];
        if(!visited[v]){
            topologicalsort(graph, v, visited, s);
        }
    }
    s.push(src);
}

// euler tour
void euler_tour(vector<vector<ll int>>& graph, ll int src, vector<bool>& visited, vector<ll int>& tour){
    visited[src] = true;
    tour.push_back(src);
    for(int i = 0; i < graph[src].size(); i++){
        ll int v = graph[src][i];
        if(!visited[v]){
            euler_tour(graph, v, visited, tour);
            tour.push_back(src);
        }
    }
}

// gcd
ll int gcd(ll int a, ll int b){
    if(b == 0){return a;}
    return gcd(b, a%b);
}

// dsu
struct Edge {
    ll int u, v, weight;

    bool operator<(Edge const &other) {
        return weight < other.weight;
    }
};

vector <ll int> parent;
vector <ll int> rank_;

void make_set(int v) {
    parent[v] = v;
    rank_[v] = 1;
}

int find_set(ll int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(ll int a, ll int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank_[a] < rank_[b])
            swap(a, b);
        parent[b] = a;
        rank_[a] += rank_[b];
    }
}
//kruskal
void kruskal(ll int n, vector<Edge> &edges_) {
    for (int i = 0; i < n; i++) {
        make_set(i);
    }
    sort(edges_.begin(), edges_.end());
    ll int tree = n - 1, i = 0;
    while (tree) {
        if (find_set(edges_[i].u) != find_set(edges_[i].v)) {
            union_sets(edges_[i].u, edges_[i].v);
            tree--;
        }
        i++;
    }
}

// longest increasing subsequence
ll int lis(vector<ll int>& a){
    ll int n = a.size();
    vector<ll int> dp(n, 1);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            if(a[i] > a[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

// longest common subsequence
ll int lcs(string a, string b){
    ll int n = a.size(), m = b.size();
    vector<vector<ll int>> dp(n+1, vector<ll int>(m+1));
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }else if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

// longest decreasing subsequence
ll int lds(vector<ll int>& a){
    ll int n = a.size();
    vector<ll int> dp(n, 1);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            if(a[i] < a[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

// longest palindromic subsequence
ll int lps(string a){
    ll int n = a.size();
    vector<vector<ll int>> dp(n, vector<ll int>(n));
    for (int i = 0; i < n; i++){
        dp[i][i] = 1;
    }
    for (int l = 2; l <= n; l++){
        for (int i = 0; i < n-l+1; i++){
            int j = i + l - 1;
            if(a[i] == a[j] && l == 2){
                dp[i][j] = 2;
            }else if(a[i] == a[j]){
                dp[i][j] = dp[i+1][j-1] + 2;
            }else{
                dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
            }
        }
    }
    return dp[0][n-1];
}

// longest common substring
ll int lcsubstring(string a, string b){
    ll int n = a.size(), m = b.size();
    vector<vector<ll int>> dp(n+1, vector<ll int>(m+1));
    ll int result = 0;
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }else if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
                result = max(result, dp[i][j]);
            }else{
                dp[i][j] = 0;
            }
        }
    }
    return result;
}

// longest palindromic substring
string lpsubstring(string a){
    ll int n = a.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    ll int start = 0, maxlen = 1;
    for (int i = 0; i < n; i++){
        dp[i][i] = true;
    }
    for (int i = 0; i < n-1; i++){
        if(a[i] == a[i+1]){
            dp[i][i+1] = true;
            start = i;
            maxlen = 2;
        }
    }
    for (int l = 3; l <= n; l++){
        for (int i = 0; i < n-l+1; i++){
            int j = i + l - 1;
            if(a[i] == a[j] && dp[i+1][j-1]){
                dp[i][j] = true;
                if(l > maxlen){
                    start = i;
                    maxlen = l;
                }
            }
        }
    }
    return a.substr(start, maxlen);
}

// z function
vector<ll int> zfunction(string s){
    ll int n = s.size();
    vector<ll int> z(n);
    for (ll int i = 1, l = 0, r = 0; i < n; i++){
        if(i <= r){
            z[i] = min(r-i+1, z[i-l]);
        }
        while(i+z[i] < n && s[z[i]] == s[i+z[i]]){
            z[i]++;
        }
        if(i+z[i]-1 > r){
            l = i;
            r = i+z[i]-1;
        }
    }
    return z;
}

// kmp
vector<ll int> kmp(string s, string p){
    ll int n = s.size(), m = p.size();
    vector<ll int> lps(m);
    vector<ll int> ans;
    for (ll int i = 1, len = 0; i < m; i++){
        if(p[i] == p[len]){
            len++;
            lps[i] = len;
        }else{
            if(len != 0){
                len = lps[len-1];
                i--;
            }else{
                lps[i] = 0;
            }
        }
    }
    for (ll int i = 0, j = 0; i < n; i++){
        if(s[i] == p[j]){
            j++;
        }else{
            if(j != 0){
                j = lps[j-1];
                i--;
            }
        }
        if(j == m){
            ans.push_back(i-j+1);
            j = lps[j-1];
        }
    }
    return ans;
}

// lca using binary lifting
vector<vector<ll int>> lca(vector<vector<ll int>>& graph, vector<vector<ll int>>& up, vector<ll int>& depth, ll int u, ll int v){
    if(depth[u] < depth[v]){
        swap(u, v);
    }
    ll int n = graph.size();
    ll int k = up[0].size();
    for (ll int i = k-1; i >= 0; i--){
        if(depth[up[u][i]] >= depth[v]){
            u = up[u][i];
        }
    }
    if(u == v){
        return {{u}};
    }
    for (ll int i = k-1; i >= 0; i--){
        if(up[u][i] != up[v][i]){
            u = up[u][i];
            v = up[v][i];
        }
    }
    return {{u}, {v}};
}

// binary lifting
void binarylifting(vector<vector<ll int>>& graph, vector<vector<ll int>>& up, vector<ll int>& depth, ll int u, ll int p){
    up[u][0] = p;
    for (ll int i = 1; i < up[0].size(); i++){
        up[u][i] = up[up[u][i-1]][i-1];
    }
    for (ll int v : graph[u]){
        if(v != p){
            depth[v] = depth[u] + 1;
            binarylifting(graph, up, depth, v, u);
        }
    }
}

// knapsack
ll int knapsack(vector<ll int>& wt, vector<ll int>& val, ll int w){
    ll int n = wt.size();
    vector<vector<ll int>> dp(n+1, vector<ll int>(w+1));
    for (ll int i = 0; i <= n; i++){
        for (ll int j = 0; j <= w; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }else if(wt[i-1] <= j){
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}

// bitmask dp
ll int bitmaskdp(vector<vector<ll int>>& dp, vector<vector<ll int>>& cost, ll int mask, ll int pos, ll int n){
    if(mask == (1<<n)-1){
        return 0;
    }
    if(dp[mask][pos] != -1){
        return dp[mask][pos];
    }
    ll int ans = 1e17;
    for (ll int i = 0; i < n; i++){
        if(!(mask & (1<<i))){
            ans = min(ans, cost[pos][i] + bitmaskdp(dp, cost, mask | (1<<i), i, n));
        }
    }
    return dp[mask][pos] = ans;
}

// tasks dp problem
ll int tasksdp(vector<ll int>& a, vector<ll int>& b, vector<ll int>& c, ll int n){
    vector<vector<ll int>> dp(n, vector<ll int>(3));
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];
    for (ll int i = 1; i < n; i++){
        dp[i][0] = a[i] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = b[i] + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = c[i] + max(dp[i-1][0], dp[i-1][1]);
    }
    return max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
}

// diameter of graph
ll int diameter(vector<vector<ll int>>& graph, ll int src, vector<bool>& visited, ll int& node){
    queue<pair<ll int, ll int>> q;
    q.push({src, 0});
    visited[src] = true;
    ll int maxdist = 0;
    while(!q.empty()){
        pair<ll int, ll int> x = q.front();
        q.pop();
        if(x.second > maxdist){
            maxdist = x.second;
            node = x.first;
        }
        for(int i = 0; i < graph[x.first].size(); i++){
            ll int v = graph[x.first][i];
            if(!visited[v]){
                visited[v] = true;
                q.push({v, x.second+1});
            }
        }
    }
    return maxdist;
}

void solve() {
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    solve();
}