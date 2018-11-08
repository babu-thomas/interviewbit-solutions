// Time - O(N), Space - O(1)
int Solution::majorityElement(const vector<int> &A) {
    const vector<int>& nums = A;

    int n = nums.size();
    int cur_ele = nums[0], count = 0;
    for(int i = 0; i < n; i++) {
        if(count == 0) {
            cur_ele = nums[i];
            count++;
        }
        else if(nums[i] == cur_ele) {
            count++;
        }
        else {
            count--;
        }
    }

    return cur_ele;
}
