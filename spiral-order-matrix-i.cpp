vector<int> Solution::spiralOrder(const vector<vector<int> > &A)
{
    int rs = 0;
    int cs = 0;
    int re = A.size();
    int ce = A[0].size();
    
    vector<int> result;
    
    while(rs < re && cs < ce) {
        // First remaining row from left to right
        for(int i = cs; i < ce; i++)
            result.push_back(A[rs][i]);
        rs++;
        // Last remaining column from up to down
        for(int i = rs; i < re; i++)
            result.push_back(A[i][ce - 1]);
        ce--;
        // Last remaining row from right to left
        if(rs < re) {
            for(int i = ce - 1; i >= cs; i--)
                result.push_back(A[re - 1][i]);
            re--;
        }
        // First remaining column from down to up
        if(cs < ce) {
            for(int i = re - 1; i >= rs; i--)
                result.push_back(A[i][cs]);
            cs++;
        }
    }
    
    return result;
}
