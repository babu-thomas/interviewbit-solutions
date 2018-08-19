vector<int> int_to_vec(int num)
{
    vector<int> result;
    while(num != 0) {
        result.push_back(num % 10);
        num = num / 10;
    }
    if(result.size() == 0) {
        result.push_back(0);
    }
    reverse(result.begin(), result.end());
    return result;
}

// Time - O(N^2), Space - O(N^2)
int Solution::colorful(int A) {
    vector<int> digits = int_to_vec(A);
    int n = digits.size();
    unordered_map<int, bool> seen;
    int product;
    for(int i = 0; i < n; i++) {
        product = 1;
        for(int j = i; j < n; j++) {
            product *= digits[j];
            if(seen[product]) {
                return 0;
            }
            seen[product] = true;
        }
    }
    
    return 1;
}
