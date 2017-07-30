// Time complexity - O(n)
// Space complexity - O(n), where n = number of intervals
int minMeetingRooms(vector<Interval>& intervals) 
{   int len = intervals.size(); 
    int count = 0, maxCount = 0;
    vector<pair<int, int>> table; // total len of table should be 2xlen since we have both start and end
    for(int i=0; i<len; i++)
    {
        // pick up the start, mark with 1
        table.push_back(pair<int, int>(intervals[i].start, 1));
        // pick up the end, mark with -1
        table.push_back(pair<int, int>(intervals[i].end, -1));
    }
    
    // sort the vector with first - exactly what we need
    sort(table.begin(), table.end());
    for(int i=0; i<table.size(); i++)
    {
        if(table[i].second == 1) count++;
        else count--;
        maxCount = max(count, maxCount);
    }
    
    return maxCount;
}

// Without using pairs
int minMeetingRooms(vector<Interval>& intervals) {
    vector<int> starts, ends;
    for (const auto& i : intervals) {
        starts.push_back(i.start);
        ends.push_back(i.end);
    }
    
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());
    
    int min_rooms = 0, cnt_rooms = 0;
    int s = 0, e = 0;
    while (s < starts.size()) 
    {   if (starts[s] < ends[e]) 
        {
            ++cnt_rooms;  // Acquire a room.
            // Update the min number of rooms.
            min_rooms = max(min_rooms, cnt_rooms);
            ++s;
        } 
        else 
        {
            --cnt_rooms;  // Release a room.
            ++e;
        }
    }
    return min_rooms;
}

// There's another solution using min-heap or priority queue
int minMeetingRooms(vector<Interval>& intervals) {
    
    sort(intervals.begin(), intervals.end(), [](Interval i1, Interval i2)
        {return i1.start < i2.start || (i1.start == i2.start && i1.end < i2.end);})
    ;

    // Min heap
    // Why is there a greater than sign?
    auto comp = [](Interval i1, Interval i2){return i1.end > i2.end;};
    priority_queue<Interval, vector<Interval>, decltype(comp)>pq(comp);
    int ans = 0;
    

    // Size of the heap correpsonds to the number of rooms currently in use
    for(auto interval : intervals)
    {   while(!pq.empty() && pq.top().end <= interval.start) pq.pop();
        pq.push(interval);
        ans = max(ans, pq.size());
    }
    return ans;
}