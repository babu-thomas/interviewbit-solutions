// Time - O(N), Space - O(N)
int Solution::evalRPN(vector<string> &A) {
    int n = A.size();
    unordered_map<string, bool> is_operator{{"+", true}, {"-", true}, {"*", true}, {"/", true}};
    stack<int> operands;
    for(int i = 0; i < n; i++) {
        if(is_operator[A[i]]) {
            int second = operands.top();
            operands.pop();
            int first = operands.top();
            operands.pop();
            int result;
            
            if(A[i] == "+") {
                result = first + second;
            }
            else if(A[i] == "-") {
                result = first - second;
            }
            else if(A[i] == "*") {
                result = first * second;
            }
            else if(A[i] == "/") {
                result = first / second;
            }
            
            operands.push(result);
        }
        else {
            operands.push(stoi(A[i]));
        }
    }
    
    return operands.top();
}
