vector<pair<int, int>> disjoint_set_initialize(int size) {
    vector<pair<int, int>> parents(size);
    for (int i = 0; i < size; i++) {
        parents[i] = {i, 1};
    }

    return parents;
}

int disjoint_set_get_root(vector<pair<int, int>> &parents, int element) {
    int cur_element = element;
    while (parents[cur_element].first != cur_element) {
        parents[cur_element].first = parents[parents[cur_element].first].first;
        cur_element = parents[cur_element].first;
    }

    return cur_element;
}

bool disjoint_set_find(vector<pair<int, int>> &parents, int element1,
                       int element2) {
    int root1 = disjoint_set_get_root(parents, element1);
    int root2 = disjoint_set_get_root(parents, element2);

    if (root1 == root2) {
        return true;
    }

    return false;
}

void disjoint_set_union(vector<pair<int, int>> &parents, int element1,
                        int element2) {
    int root1 = disjoint_set_get_root(parents, element1);
    int root2 = disjoint_set_get_root(parents, element2);
    int set1_size = parents[root1].second;
    int set2_size = parents[root2].second;
    if (set1_size < set2_size) {
        parents[root1].first = parents[root2].first;
        parents[root2].second += parents[root1].second;
        parents[root1].second = 0;
    } else {
        parents[root2].first = parents[root1].first;
        parents[root1].second += parents[root2].second;
        parents[root2].second = 0;
    }
}

int mst_cost_kruskal(const vector<pair<int, pair<int, int>>> weights,
                     vector<pair<int, int>> &parents) {
    int edges = weights.size();
    int min_cost = 0;
    for (int i = 0; i < edges; i++) {
        int edge_from = weights[i].second.first;
        int edge_to = weights[i].second.second;
        int cost = weights[i].first;
        if (!disjoint_set_find(parents, edge_from, edge_to)) {
            min_cost += cost;
            disjoint_set_union(parents, edge_from, edge_to);
        }
    }

    return min_cost;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    int node_count = A;
    const vector<vector<int>> &bridges = B;

    auto parents = disjoint_set_initialize(node_count + 1);
    vector<pair<int, pair<int, int>>> weights;
    int edge_count = bridges.size();
    for (int i = 0; i < edge_count; i++) {
        int edge_from = bridges[i][0];
        int edge_to = bridges[i][1];
        int weight = bridges[i][2];
        weights.push_back({weight, {edge_from, edge_to}});
    }
    sort(weights.begin(), weights.end());
    int min_cost = mst_cost_kruskal(weights, parents);

    return min_cost;
}
