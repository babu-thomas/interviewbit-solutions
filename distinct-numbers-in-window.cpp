// Time - O(N), Space - O(K)
// where K = window size
vector<int> solve(vector<int>& nums, int window_size) {
    int n = nums.size();
    vector<int> result;

    if(n == 0 || window_size > n) {
        return result;
    }

    unordered_map<int, int> element_counts;
    int distinct = 0;
    for(int i = 0; i < window_size; i++) {
        int element = nums[i];
        if(element_counts[element] == 0) {
            distinct++;
        }
        element_counts[element] += 1;
    }

    result.push_back(distinct);

    for(int i = window_size; i < n; i++) {
        int removed_element = nums[i - window_size];
        if(element_counts[removed_element] == 1) {
            distinct--;
        }
        element_counts[removed_element] -= 1;
        int new_element = nums[i];
        if(element_counts[new_element] == 0) {
            distinct++;
        }
        element_counts[new_element] += 1;

        result.push_back(distinct);
    }

    return result;
}

vector<int> Solution::dNums(vector<int> &A, int B) {
    return solve(A, B);
}
