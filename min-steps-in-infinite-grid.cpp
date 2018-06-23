int Solution::coverPoints(vector<int> &A, vector<int> &B)
{
    int x_s = A[0];
    int y_s = B[0];
    
    int steps = 0;
    
    for(int i = 0; i < A.size(); i++) {
        int x_e = A[i];
        int y_e = B[i];
        
        int dx = abs(x_s - x_e);
        int dy = abs(y_s - y_e);
        
        steps += abs(dx - dy) + min(dx, dy);
        
        x_s = x_e;
        y_s = y_e;
    }
    
    return steps;
}
