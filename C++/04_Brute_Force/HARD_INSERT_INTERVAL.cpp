/* 
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    vector<Interval> result;
    int i = 0;
    
    // add all the intervals ending before newInterval starts
    while (i < intervals.size() && intervals[i].end < newInterval.start)
        result.push_back(intervals[i++]);
    
    // merge all overlapping intervals to one considering newInterval
    while (i < intervals.size() && intervals[i].start <= newInterval.end) 
    {   int start = min(newInterval.start, intervals[i].start);
        int end = max(newInterval.end, intervals[i].end);
        Interval t(start, end);
        newInterval = t;
        i++;
    }
    
    result.push_back(newInterval); // add the union of intervals we got
    
    // add all the rest
    while (i < intervals.size()) result.push_back(intervals[i++]); 
    return result;
    
}