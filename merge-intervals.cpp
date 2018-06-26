/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool cmp(Interval lhs, Interval rhs)
{
    return lhs.start < rhs.start;
}

vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end(), cmp);
    int n = intervals.size();
    stack<Interval> s;
    s.push(intervals[0]);
    for(int i = 1; i < n; i++) {
        Interval top = s.top();
        if(intervals[i].start > top.end) {
            s.push(intervals[i]);
        }
        else if(intervals[i].end > top.end) {
            top.end = intervals[i].end;
            s.pop();
            s.push(top);
        }
    }
    vector<Interval> merged(s.size());
    for(int i = merged.size() - 1; i >= 0; i--) {
        merged[i] = s.top();
        s.pop();
    }
    return merged;
}
