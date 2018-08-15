// Time - O(N), Space - O(N)
string Solution::reverseString(string A) {
    stack<char> s;
    for(auto& i: A) {
        s.push(i);
    }
    
    string result;
    while(!s.empty()) {
        result.push_back(s.top());
        s.pop();
    }
    
    return result;
}
