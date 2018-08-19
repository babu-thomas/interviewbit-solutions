bool is_valid(array<int, 4>& quad) {
    return (quad[0] < quad[1] && quad[2] < quad[3]
        && quad[0] < quad[2] && quad[1] != quad[3]
        && quad[1] != quad[2]);
}

// Time - O(N^2), Space - O(N^2)
vector<int> solve_equal(const vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, array<int, 2>> seen;
    vector<array<int, 4>> equal_indices;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            int sum = nums[i] + nums[j];
            if(seen.count(sum)) {
                array<int, 2> pair_seen = seen[sum];
                equal_indices.push_back({pair_seen[0], pair_seen[1], i, j});
            }
            else {
                seen[sum] = {i, j};
            }
        }
    }
    sort(equal_indices.begin(), equal_indices.end());

    vector<int> result;
    for(auto& quad: equal_indices) {
        if(is_valid(quad)) {
            for(auto& i: quad) {
                result.push_back(i);
            }
            break;
        }
    }

    return result;
}

vector<int> Solution::equal(vector<int> &A) {
    return solve_equal(A);
}
