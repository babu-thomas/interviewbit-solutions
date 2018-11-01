// Time - O(N^2), Space - O(1)
vector<vector<int> > Solution::threeSum(vector<int> &A) {
    vector<vector<int>> result;
    vector<int>& a = A;
    sort(a.begin(), a.end());
    int size = a.size();
    for(int i = 0; i < size - 2; i++) {
        // Skip duplicates of first number
        if(i > 0 && a[i] == a[i - 1])
            continue;
            
        int first = a[i];
        int left = i + 1;
        int right = size - 1;
        while(left < right) {
            int second = a[left];
            int third = a[right];
            int sum = first + second + third;
            if(sum == 0) {
                result.push_back({first, second, third});
                // Skip duplicates of second number
                while(left < right && a[left] == second)
                    left++;
                // Skip duplicates of third number
                while(left < right && a[right] == third)
                    right--;
            }
            else if(sum < 0) {
                left++;
            }
            else {
                right--;
            }
        }
    }
    
    return result;
}
