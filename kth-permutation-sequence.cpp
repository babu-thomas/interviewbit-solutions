int fact[13];
void generate_factorials() {
    fact[0] = 1;
    int p = fact[0];
    for(int i = 1; i <= 12; i++) {
        p *= i;
        fact[i] = p;
    }
}

int factorial(int n) {
    if(n > 12) {
        return INT_MAX;
    }
    
    return fact[n];
}

// Time - O(N^2), Space - O(N)
string kth_permutation(vector<string> nums, int k) {
    int n = nums.size();
    if(n == 0) {
        return "";
    }
    
    int first_index = k / factorial(n - 1);
    string first_digit = nums[first_index];
    k %= factorial(n - 1);
    nums.erase(nums.begin() + first_index);
    
    return first_digit.append(kth_permutation(nums, k));
}

string Solution::getPermutation(int A, int B) {
    generate_factorials();
    vector<string> nums(A);
    for(int i = 0; i < A; i++) {
        nums[i] = to_string(i + 1);
    }
    
    return kth_permutation(nums, B - 1);
}
