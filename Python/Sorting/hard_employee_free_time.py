'''
Key points:

- recognize that this is very similar to merging intervals (https://leetcode.com/problems/merge-intervals/description/)
- it doesn't matter which employee an interval belongs to, so just flatten
- can build result array while merging, don't have to do afterward (and don't need full merged arr)
'''

def employeeFreeTime(self, schedule):
    ints = sorted([i for s in schedule for i in s], key=lambda x: x.start)
    res, pre = [], ints[0]
    for i in ints[1:]:
        if i.start <= pre.end and i.end > pre.end:
            pre.end = i.end
        elif i.start > pre.end:
            res.append(Interval(pre.end, i.start))
            pre = i
    return res
