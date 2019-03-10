/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

struct myclass {
  bool operator() (const Interval& interval1, const Interval& interval2) { return interval2.start>interval1.start;}
} myobject;

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() <= 1)
            return intervals;
        
        sort(intervals.begin(), intervals.end(), myobject);
        
        vector<Interval> result;
        
        int start = intervals[0].start;
        int end = intervals[0].end;
        
        for(auto interval : intervals){
            if(interval.start <= end){
                end = max(end, interval.end);
            }else{
                Interval temp = Interval(start, end);
                result.push_back(temp);
                start = interval.start;
                end = interval.end;
            }
        }
        Interval temp(start, end);
        result.push_back(temp);
        return result;
    }
};