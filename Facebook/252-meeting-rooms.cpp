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
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), myobject);
        
        int size = intervals.size() - 1;
        for(int i = 0; i < size; ++i){
            if(intervals[i].end > intervals[i + 1].start)
                return false;
        }
        return true;
    }
};
