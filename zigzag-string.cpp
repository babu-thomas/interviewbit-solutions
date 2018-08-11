// Time - O(N), Space - O(N)
string Solution::convert(string A, int B) {
    int n = A.size();
    
    if(B == 1) {
        return A;
    }
    
    bool down = true;
    int row = 0;
    vector<string> lines(B);
    lines[0].push_back(A[0]);
    row++;
    for(int i = 1; i < n; i++) {
        lines[row].push_back(A[i]);
        
        if(row == 0 || row == B - 1) {
            down = !down;
        }
        
        if(down) {
            row++;
        }
        else {
            row--;
        }
    }
    
    string result;
    for(auto& i : lines) {
        result.append(i);
    }
    
    return result;
}
