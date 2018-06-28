bool cmp(string a, string b)
{
    return a + b > b + a;
}

string Solution::largestNumber(const vector<int> &A)
{
    vector<string> As;
    for(auto& i: A) {
        As.push_back(to_string(i));
    }
    sort(As.begin(), As.end(), cmp);
    string result;
    for(auto& i: As) {
        result.append(i);
    }
    int pos = 0;
    while(result[pos] == '0' && pos + 1 < result.size()) {
        pos++;
    }
    return result.substr(pos);
}
