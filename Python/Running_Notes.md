# General
- Check for empty Input
- Ask if input is non-negative
- Clarify if it's 0 or "0"/1 or "1"
- NP-completeness
- MVC patterns
- Primary keys/foreign keys
- How does SQL index keys? (hash maps?)
- What is immutable/mutable? (immutable objects are container-friendly, thread-safe and memory-friendly)

# Python
- append is amortized O(1), not O(1)
- Floating point division is default in Python 3. // for integer division
- One line if-else
  x if val < root.val else y
- Flatten 2D list -> `[i for s in list_2D for i in s]`
- `a.sort(key=lambda x: x.start, reverse=False)`
- `sorted()` returns the list
- `''.join(word)` -> To create a list from a string
- `my_dict.pop('key', None)` -> To remove a key from a dictionary
- Keys in a dictionary need not be sorted
- "animesh"[1:] -> "nimesh", "animesh"[:1] -> "a"
- "animesh"[-1:] -> "h", "animesh"[:-1] -> "animes"
- range vs xrange
- Exception handling
- List vs tuple
- Python 2.7 vs Python3
- args and kwargs
- "@decorator"
- isdigit(), isalpha(), isalnum()


# Strings
- `word.strip()` for trimming spaces
- `word = ''.join(arr)` to create a string from a list
- String matching algorithms

# Sorting
- Merge sort vs Quick sort
- Bucket sort (Used in top k most frequent elements)

# Sets
```s = set()
s.add(1)
s.remove(1)```

# Hash maps
- from collections import defaultdict
- x = {'a':1}
- del x['a']

# Stacks
stack = []
stack[-1] -> peek at top of stack
stack.pop() -> pops & returns the item
LIFO

# Queues
queue = collections.deque()
queue.append(1)
queue.popleft()
FIFO

# Linked List
- Use double ended linked list

# Trees
- Traversals
    1. Inorder Traversal (Left-Root-Right)
       You visit all the left nodes of a root first. Come back to the root. Then do the same for root.right
    2. Preorder Traversal (Root-Left-Right)
    3. Postorder Traversal (Left-Right-Root)
    4. Level Order Traversal is BFS!!
- Iterative traversals
    - Avoid stack overflow, recursion uses extensive use of the call stack
    - Faster because no overhead to call functions
    https://stackoverflow.com/questions/15346774/are-recursive-methods-always-better-than-iterative-methods-in-java


- Pros and cons of DFS vs BFS
- DFS time= |V| + |E|, space = O(h), h = height of tree
- BFS better for shortest path type problems
- Iterative DFS, BFS
- DFS fails when the destination is very close to the starting point
- In DFS, you need to keep track of visited nodes.
- Tries
- Balanced binary tree -> At least one of Red/Black tree, Splay tree, AVL Tree
- Segment tree
- KD Tree

# Graphs
- Represent a weighted graph using dict of dicts
- Topological sort -> https://www.youtube.com/watch?v=ddTC4Zovtbc (Use set + stack)
- Dijkstra, Minimum spanning tree, Floyd Warshall, Bellman Ford
- A * search
- Max flow problem, ford fulkerson
- Union Find -> to detect cycle in graph

# Heaps
- It's a complete binary tree
- Max-heap -> All children of a node are <= root
- O(log n) insertion, O(1) lookup for max element, O(logn) for deletion of max element
- heapq.heapify(arr) -> in-place heapify
- heapq.heappush(heap, element)
- heapq.heappop(heap)
- By default, heapq implements min-heap


# Dynamic Programming
- 1D, 2D

# OOPS
- Abstraction
- Inheritance
- Cohesion
- Coupling

# System design
- Handle ambiguity
- Elastic load balancers
- MVC
- HTTP
- Encryption?
- Realtime -> web sockets

# Operating System
- Processes vs threads
- Concurrency issues
- Locks, mutex, semaphore, monitor
- Deadlock, livelock, how to avoid them
- Context switching
- Job scheduling
- "Modern" concurrency constructs

# Problems
17. Letter combinations of a phone number ->
575. Distribute candies
54. Spiral Matrix
146. LRU Cache: Think about queue, then linked list and then DLL
720. Longest word in dictionary -> keep word[:-1] in set/ Trie + DFS/BFS solution
277. Find celebrity -> https://leetcode.com/problems/find-the-celebrity/discuss/178129/Python-Solution-Beats-93-O(N)-Time-and-O(1)-space
224. Basic Calculator -> Positive integers. Use stacks to handle ( and ). Keep track of result, current number and sign
759. Employee Free time -> Which employee does not matter. So flatten schedule.
     https://leetcode.com/problems/employee-free-time/discuss/170551/Simple-Python-9-liner-beats-97-(with-explanation)
236. Lowest Common Ancestor of Binary Tree -> O(n)
295. Median in a data stream -> You don't need to sort the entire stream. You just need to keep track of the median. Use two heaps.




# ToDo
- How are sets implemented?
- How do hash maps work? How are collisions resolved?
- Sets vs Maps
- P vs NP
- Longest increasing subsequence
