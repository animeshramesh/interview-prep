"""
n = 2
logs =
["0:start:0",
 "1:start:2",
 "1:end:5",
 "0:end:6"]
Output:[3, 4]
"""

"""
Solution
- Given that we are working with start and end times, it's suitable to use stacks here.
- But what do we push to the stack?
- We would push the current function id and keep track of the elapsed time for each function id
- Top of stack would contain the most recent function id
- O(n/2) time and O(k) space where k = # of functions, n = log size
"""

class Solution(object):
    def exclusiveTime(self, n, logs):

        res = [0]*n
        s = logs[0].split(":")
        prev_time = int(s[2])

        stack = []
        stack.append(int(s[0]))

        for i in range(1, len(logs)):
            s = logs[i].split(":")
            cur_time = int(s[2])

            if s[1] == 'start':
                if stack:
                    res[stack[-1]] += cur_time - prev_time
                stack.append(int(s[0]))
                prev_time = int(s[2])
            else:
                res[stack[-1]] += cur_time - prev_time + 1
                stack.pop()
                prev_time = int(s[2])+1

        return res
