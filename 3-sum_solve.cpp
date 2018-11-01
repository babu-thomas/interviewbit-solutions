// Time - O(N^2), Space - O(1)
int Solution::threeSumClosest(vector<int> &A, int B) {
    vector<int> &nums = A;
    int target = B;

    sort(nums.begin(), nums.end());
    int n = nums.size();
    int result = 0;
    int min_diff = INT_MAX;
    for (int first = 0; first < n - 2; first++) {
        int second = first + 1;
        int third = n - 1;

        while (second < third) {
            int sum = nums[first] + nums[second] + nums[third];
            int cur_diff = abs(sum - target);

            if (cur_diff < min_diff) {
                min_diff = cur_diff;
                result = sum;
            }

            if (sum < target) {
                second++;
            } else if (sum > target) {
                third--;
            } else {
                return sum;
            }
        }
    }

    return result;
}
