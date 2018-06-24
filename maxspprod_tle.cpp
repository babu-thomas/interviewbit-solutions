// Time limit exceeded as this is a O(N^2) solution

int Solution::maxSpecialProduct(vector<int> &A)
{
    long product = 0;
    long max_product = 0;
    for(int i = 1; i < A.size(); i++) {
        int left = 0;
        int right = A.size() - 1;
        
        int lsv = 0;
        int rsv = 0;
        
        while(left < i) {
            if(A[left] > A[i]) {
                lsv = left;
            }
            left++;
        }
        
        while(right > i) {
            if(A[right] > A[i]) {
                rsv = right;
            }
            right--;
        }
        
        product = (lsv * rsv) % 1000000007;
        max_product = max(max_product, product);
    }
    
    return max_product;
}
