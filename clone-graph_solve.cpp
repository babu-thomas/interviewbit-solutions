/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

// Time - O(N), Space - O(N)
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
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
