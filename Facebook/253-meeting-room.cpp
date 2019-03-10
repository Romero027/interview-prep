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
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty())
            return 0;
        
        sort(intervals.begin(), intervals.end(), [](Interval& l, Interval& r) {return l.start < r.start;});
        priority_queue<int, vector<int>, greater<int>> pq;//min pq
        
        pq.push(intervals[0].end);
        for(int i = 1; i < intervals.size(); i++ ) {
            
            //if the current meeting starts after the pq.top(), there is no need to schedule another 
            //meeting room, so merge 
            if(pq.top() <= intervals[i].start)
                pq.pop();
            pq.push(intervals[i].end);
        }
        
        
        
        return pq.size();
    }
};