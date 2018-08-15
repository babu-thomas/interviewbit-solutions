// Time - O(N), Space - O(N)
string Solution::simplifyPath(string A) {
    int n = A.size();
    
    vector<string> dirs;
    string name;
    for(int i = 1; i < n; i++) {
        name.clear();
        
        while(A[i] == '/') {
            i++;
        }
        
        while(i < n && A[i] != '/') {
            name.push_back(A[i]);
            i++;
        }
        
        if(name.compare("..") == 0) {
            if(!dirs.empty()) {
                dirs.pop_back();
            }
        }
        else if(name.compare(".") == 0) {
            continue;
        }
        else if(name.size() != 0) {
            dirs.push_back(name);
        }
    }
    
    string result;
    if(dirs.empty()) {
        result.append("/");
        return result;
    }
    
    for(auto& d: dirs) {
        result.append("/" + d);
    }
    
    return result;
}
