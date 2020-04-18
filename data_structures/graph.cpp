#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <utility>
#include <set>
using namespace std;
#define INF 0x3f3f3f3f

class Graph {
    int V;
    list< pair<int, int> > *adj;
public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void shortestDistance(int s);
};

Graph::Graph(int V) {
    this->V = V;

    adj = new list< pair<int, int> >[V];
}

void Graph::addEdge(int u, int v, int w) {
    adj[v].push_back(make_pair(u, w));
    adj[u].push_back(make_pair(v, w));
}

void Graph::shortestDistance(int s) {
    vector<int> distance(V, INF);
    set<pair<int, int> > priority_queue;

    //distance of s = 0 && add source to queue
    priority_queue.insert(make_pair(0, s));
    distance[s] = 0;


    while(!(priority_queue.empty())) {
        // Extract first from the set as it is the current minimum distance.
        pair<int, int> tmp = *(priority_queue.begin());
        priority_queue.erase(priority_queue.begin());

        int u = tmp.second;

        //get all adjacent vertices of a vertex
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent of u.
            int v = (*i).first;
            int weight = (*i).second;

            //  If there is shorter path to v from u.
            if (distance[v] > distance[u] + weight) {
                //  If distance of v is not INF then it must be in set
                //  and must be removed to avoid duplicates.
                if (distance[v] != INF)
                    priority_queue.erase(priority_queue.find(make_pair(distance[v], v)));

                // Updating distance of v
                distance[v] = distance[u] + weight;
                priority_queue.insert(make_pair(distance[v], v));
            }
        }
    }

    for (int i = 1; i < V; i++) {
        if (distance[i] != INF && distance[i] != 0) {
            cout << distance[i] << " ";
        } else if (distance[i] == 0) {
            //do nothing?
            continue;
        } else {
            cout << -1 << " ";
        }
    }
    cout << endl;
}


int main() {
    int q, n, m, u, v, s, w;
    cin >> q;

    while(q-- > 0) {
        cin >> n >> m;

        Graph g(n+1);
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            g.addEdge(u, v, w);
        }

        cin >> s;

        g.shortestDistance(s);
    }

    return 0;
}
