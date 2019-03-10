
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        bool insert_new = false;
        
        /*
        Case 1: if we haven't insert the new interval and current interval ends before the new interval starts
        Case 2: if the current interval starts after the new interval ends, insert the new interval and the current interval
        Case 3: if the current interval overlaps the new interval
        */
        for (Interval& i : intervals) {
            if (insert_new || i.end < newInterval.start) {
                res.push_back(i);
            } else if (i.start > newInterval.end) {
                if (!insert_new) {
                    res.push_back(newInterval);
                    insert_new = true;
                }
                res.push_back(i);
            } else {
                newInterval.start = min(i.start, newInterval.start);
                newInterval.end = max(i.end, newInterval.end);
            }
        }
        //Edge case
        if (!insert_new) res.push_back(newInterval);
        return res;
    }
};