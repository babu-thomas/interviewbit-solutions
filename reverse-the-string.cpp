// Time - O(N), Space - O(N)
void Solution::reverseWords(string &A) {
    string result;
    int n = A.size();
    int start = 0, end = n - 1;

    while(end >= 0 && A[end] == ' ') {
        end--;
    }

    for(int i = end; i >= 0; ) {
        end = i;
        while(i >= 0 && A[i] != ' ') {
            i--;
        }
        start = i + 1;
        
        result += A.substr(start, end - start + 1);

        while(i >= 0 && A[i] == ' ') {
            i--;
        }

        if(i >= 0) {
            result += " ";
        }
    }

    A = result;
}
