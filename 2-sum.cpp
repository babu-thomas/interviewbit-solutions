// Time - O(N), Space - O(N)
vector<int> solve(const vector<int>& nums, int target) {
    unordered_map<int, int> seen;
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        int to_find = target - nums[i];
        if(seen.count(to_find)) {
            return {seen[to_find], i + 1};
        }

        if(seen.count(nums[i]) == 0) {
            seen[nums[i]] = i + 1;
        }
    }

    return vector<int>();
}

vector<int> Solution::twoSum(const vector<int> &A, int B) {
    return solve(A, B);
}
