#include <iostream>
#include <queue>
#include <vector>

#define NMAX 10005
#define INTMAX 0x7fffffff

using namespace std;

// v表示节点，cost表示出发点到v点的距离
struct Node {
    int v;
    int cost;
    Node(int vv = 0, int c = 0) {
        v = vv, cost = c;
    }
    // 优先队列将按距离从小到大排列
    friend bool operator<(Node n1, Node n2) {
        return n1.cost > n2.cost;
    }
};

// v表示边的另一端节点，cost表示该边的权重
struct Edge {
    int v;
    int cost;
    Edge(int vv = 0, int c = 0) {
        v = vv, cost = c;
    }
};

vector<Edge>G[NMAX];    // 无向图
bool marked[NMAX];      // D算法中每个顶点仅处理一遍
int disto[NMAX];        // 出发点到某点距离
int costo[NMAX];        // 接通该点需要增加的边的权重
int N, M;

void dijkstra(int s) {
    for (int i = 0; i <= N; i++) {
        costo[i] = disto[i] = INTMAX;
        marked[i] = false;
    }
    disto[s] = 0;
    costo[s] = 0;
    priority_queue<Node>pq;     // 保存<v,disto[v]>且按disto[v]升序排列
    pq.push(Node(s, 0));

    Node tmp;
    while (!pq.empty()) {
        tmp = pq.top();
        pq.pop();
        int v = tmp.v;
        if (!marked[v]) {
            int len = G[v].size();
            for (int i = 0; i < len; i++) {
                int vv = G[v][i].v;
                int cost = G[v][i].cost;
                if (!marked[vv]) {
                    int newdist = disto[v] + cost;
                    if (disto[vv] > newdist) {
                        disto[vv] = newdist;
                        costo[vv] = cost;   // 增加的内容
                        pq.push(Node(vv, disto[vv]));
                    }
                    // 增加的内容
                    // 加入点vv时若出现多种距离相同的方案，选取新边最小那个
                    if (disto[vv] == newdist) {
                        costo[vv] = min(costo[vv], cost);
                    }
                }
            }
        }
    }
}

int main(void) {
    cin >> N >> M;

    int s, e, c;
    for (int i = 0; i < M; i++) {
        cin >> s >> e >> c;
        G[s].push_back(Edge(e, c));
        G[e].push_back(Edge(s, c));
    }
    dijkstra(1);

    // 统计边权重
    int res = 0;
    for (int i = 2; i <= N; i++) {
        res += costo[i];
    }
    cout << res << endl;

    return 0;
}
