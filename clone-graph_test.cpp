#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x)                                                               \
    do {                                                                       \
        std::cout << #x << ": " << x << " ";                                   \
    } while (0)
#define DEBUGL(x)                                                              \
    do {                                                                       \
        std::cout << #x << ": " << x << "\n";                                  \
    } while (0)

#define MOD 1000000007

template <typename T> void print_vector(vector<T> a) {
    for (auto &i : a) {
        cout << i << " ";
    }
    cout << "\n";
}

template <typename T> void print_matrix_2d(vector<vector<T>> a) {
    int r = 0;
    for (auto &i : a) {
        cout << r << ": ";
        for (auto &j : i) {
            cout << j << " ";
        }
        r++;
        cout << "\n";
    }
    cout << "\n";
}

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x){};
};

void bfs(UndirectedGraphNode *node) {
    unordered_set<UndirectedGraphNode *> visited_nodes;
    queue<UndirectedGraphNode *> to_visit;
    to_visit.push(node);
    while (!to_visit.empty()) {
        auto cur_node = to_visit.front();
        to_visit.pop();
        cout << cur_node->label << " : ";
        visited_nodes.insert(cur_node);
        for (auto neighbour : cur_node->neighbors) {
            cout << neighbour->label << ", ";
            // visited_nodes.insert(neighbour);
            if (visited_nodes.count(neighbour) == 0) {
                to_visit.push(neighbour);
            }
        }
        cout << "\n";
    }
    cout << "\n";
}

// Time - O(N), Space - O(N)
UndirectedGraphNode *solve(UndirectedGraphNode *node) {
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> copied_nodes;
    auto copy = new UndirectedGraphNode(node->label);
    copied_nodes[node] = copy;
    queue<UndirectedGraphNode *> to_visit;
    to_visit.push(node);
    while (!to_visit.empty()) {
        auto cur_node = to_visit.front();
        to_visit.pop();
        for (auto neighbour : cur_node->neighbors) {
            if (copied_nodes.count(neighbour) == 0) {
                auto neighbour_copy = new UndirectedGraphNode(neighbour->label);
                copied_nodes[neighbour] = neighbour_copy;
                to_visit.push(neighbour);
            }
            copied_nodes[cur_node]->neighbors.push_back(
                copied_nodes[neighbour]);
        }
    }

    return copy;
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    /*
        +----+
        | 0  |
   +----+    +-------+
   |    +----+       |
   |                 |
+--+-+            +--+-+     +----+
| 1  |            |  2 |     | 3  |
|    |            |    +-----+    |
+----+            +----+     +----+

    */
    // Create above graph
    UndirectedGraphNode *node = new UndirectedGraphNode(0);
    node->neighbors.push_back(new UndirectedGraphNode(1));
    node->neighbors.push_back(new UndirectedGraphNode(2));
    node->neighbors[node->neighbors.size() - 1]->neighbors.push_back(
        new UndirectedGraphNode(3));

    bfs(node);
    auto copy = solve(node);
    bfs(copy);

    return 0;
}
