"""
Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters
represent different tasks.Tasks could be done without original order.
Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks,
there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.

Example 1:
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
"""


"""
Solution: You can use a priority queue or use sorting

Space complexity: (O(k)), where k is the number of unqiue Tasks
Time complexity: O(n), where n = time. (This is a bit confusing)
"""


from collections import defaultdict

class Solution(object):
    def leastInterval(self, tasks, n):
        """
        :type tasks: List[str]
        :type n: int
        :rtype: int
        """

        ref = defaultdict(int)
        for task in tasks:
            ref[task]+=1

        # You need to understand that you don't need the task name
        # Just the frequency of the tasks is enough
        ref = ref.values()

        # Huge tasks come first
        ref.sort(reverse=True)
        time = 0

        while ref and ref[0] > 0:
            i = 0
            while i <= n:

                # This is important. You can have +1 issues if you dont have this.
                if ref[0] == 0:
                    break

                if i < len(ref) and ref[i] > 0:
                    ref[i]-=1
                time += 1
                i += 1

            ref.sort(reverse=True)

        return time
