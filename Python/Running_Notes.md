# General
- Check for empty Input
- Ask if input is non-negative
- Clarify if it's 0 or "0"/1 or "1"
- NP-completeness
- MVC patterns
- Primary keys/foreign keys
- How does SQL index keys? (hash maps?)
- What is immutable/mutable? (immutable objects are container-friendly, thread-safe and memory-friendly)
- Harvard Quora video: https://www.youtube.com/watch?v=eJjg2MkYPaY
- https://zxi.mytechroad.com/blog/

# Python
- append is amortized O(1), not O(1)
- Floating point division is default in Python 3. // for integer division
- One line if-else
  x if val < root.val else y
- Flatten 2D list -> `[i for s in list_2D for i in s]`
- [[0] * cols for _ in range(rols)] -> To create a 2D list of size m x n
- `a.sort(key=lambda x: x.start, reverse=False)`
- `sorted()` returns the list
- `''.join(word)` -> To create a list from a string
- `my_dict.pop('key', None)` -> To remove a key from a dictionary
- Keys in a dictionary need not be sorted
- "animesh"[1:] -> "nimesh", "animesh"[:1] -> "a"
- "animesh"[-1:] -> "h", "animesh"[:-1] -> "animes"
- s[start_idx:end_idx+1]
- range vs xrange
- Exception handling
- List vs tuple
- Python 2.7 vs Python3
- args and kwargs
- "@decorator"
- isdigit(), isalpha(), isalnum()
- range([start], stop[, step]), Example: range(3, -1, -1)
    start: Starting number of the sequence.
    stop: Generate numbers up to, but not including this number.
    step: Difference between each number in the sequence.
- from collection import Counter, defaultdict
- raise NotImplementedError

# Strings
- `word.strip()` for trimming spaces
- `word = ''.join(arr)` to create a string from a list
- String matching algorithms
- `string[::-1]` reverses string
- word.lower()/word.islower()
- s.find(word) substring search
- s.find(word, idx) substring search from that index

# Sorting
- Merge sort vs Quick sort
- Bucket sort (Used in top k most frequent elements)

# Sets
```s = set()
s.add(1)
s.remove(1)
s1.intersection(s2)
s1.symmetric_difference(s2) # items in either s1 or s2, but not both
```

# Hash maps
```from collections import defaultdict
defaultdict(lambda:1)
x = {'a':1}
del x['a']
min(x) = 'a'
Open addressing vs chaining for resolving collisions
```

# Stacks
```
stack = []
stack[-1]      # peek at top of stack
stack.pop()    # pops & returns the item
# LIFO
```

# Queues
```
queue = collections.deque()
queue.append(1)
queue.popleft()
# FIFO
```

# Linked List
- Use double ended linked list
- Fast and slow to detect cycle
- Reverse a linked list in place

# Trees
- Traversals
    1. Inorder Traversal (Left-Root-Right)
       You visit all the left nodes of a root first. Come back to the root. Then do the same for root.right
    2. Preorder Traversal (Root-Left-Right)
    3. Postorder Traversal (Left-Right-Root)
    4. Level Order Traversal is BFS!!
- Iterative traversals (Preorder, inorder, Postorder)
    - Avoid stack overflow, recursion uses extensive use of the call stack
    - Faster because no overhead to call functions
    https://stackoverflow.com/questions/15346774/are-recursive-methods-always-better-than-iterative-methods-in-java

- Pros and cons of DFS vs BFS
- DFS time= |V| + |E|, space = O(h), h = height of tree
- BFS better for shortest path type problems
- BFS, time= |V| + |E|, space = O(V)
The time complexity can be expressed as O(|V|+|E|), since every vertex and every edge will be explored in the worst case.
|V| is the number of vertices and |E| is the number of edges in the graph.
Note that O(|E|) may vary between O(1) and O(|V|^2), depending on how sparse the input graph is.
- You can take the cost/depth as a second value while iterating in BFS

- Iterative DFS, BFS
- DFS fails when the destination is very close to the starting point
- In both BFS and DFS, you need to keep track of visited nodes.
- Tries
- Balanced binary tree -> At least one of Red/Black tree, Splay tree, AVL Tree
- Segment tree
- KD Tree
- AVL tree - balance factor (0, 1, -1). its just an efficient bst
  worst search - logn
  left-left, left-right, right-left, right-right

# Graphs
- Represent a weighted graph using dict of dicts
- Topological sort -> Indegree and out_degree. (Append nodes with outdegree == 0 to queue and decrement out_degree)
- Dijkstra -> Greedy BFS for shortest path from starting node to ending node + heap
- A * search -> Exactly like Dijkstra, but with a heuristic function
- Minimum spanning tree, Floyd Warshall, Bellman Ford
- Max flow problem, ford fulkerson
- Union Find -> to detect cycle in graph

# Heaps
- It's a complete binary tree
- Max-heap -> All children of a node are <= root
- O(log n) insertion, O(1) lookup for max element, O(logn) for deletion of max element
- By default, heapq implements min-heap
- By default, heapq will sort on the first element of the tuple. (If elements are all tuples)
```
import heapq
heapq.heapify(arr)  # in-place
heapq.heappush(heap, element)
heapq.heappop(heap)
arr[0] will have the smallest element
```

# OOPS
- Abstraction - abstract method declared, but no implementation
- Inheritance
- Cohesion
- Coupling
- Encapsulation
- Polymorphism
- Static methods

# System design
- Handle ambiguity
- Elastic load balancers
- MVC
- HTTP
- Encryption?
- Realtime -> web sockets

# Operating System
- Processes vs threads
  Process - Instance of a running program. Each process provides all the resources needed to run the program.
  A process has a virtual address space, executable code, open handles to system objects, a security context, a unique process identifier, environment variables, a priority class, minimum and maximum working set sizes, and at least one thread of execution
  All threads of a process share its virtual address space and system resources
- Concurrency issues - Resource sharing, parallelism (shared bathroom)
  Multiple processes in OS and multiple threads within a process
  You don't have to worry about concurrency while reading data.
  Race conditions
- Locks, mutex, semaphore, monitor
  Mutex - objects owned by a thread at a time. Once the thread finishes the task, it releases the mutex.
  Ensures atomicity.
  Semaphore - restricts the number of simultaneous threads accessing a resource. It's more of a signaling mechanism, rather than a lock. Semaphore is more like a bike renting service.
  Monitor - Object which can be accessed by multiple threads. Ex: a bathroom. They allow mutually exclusive access to a shared object.
- Deadlock, livelock, how to avoid them
  Deadlock can be avoided with banker's algorithm.
  Livelock happens when multiple processes attempt to recover from deadlock. Only should 1 should take an action
- Context switching
- Job scheduling
- "Modern" concurrency constructs

# Sorting
- Merge sort
    Stable sort (Equal keys appear in the same order)
    Out of place algorithm
    30% lesser comparisons than quick sort
    Best/Avg/Worst is all nlogn
    This isn't susceptible to poor pivot choice
    Well suited for multi-threading
    Worst case for merge sort is nlogn, while for quick sort its n^2
- Quick Sort
    Not stable
    In place algorithm, so memory efficient
    Worst case is O(n^2)
    Stable sort is needed where you need to sort on the basis of first letter of names


# Problems
575. Distribute candies
277. Find celebrity -> https://leetcode.com/problems/find-the-celebrity/discuss/178129/Python-Solution-Beats-93-O(N)-Time-and-O(1)-space
759. Employee Free time -> Which employee does not matter. So flatten schedule.
     https://leetcode.com/problems/employee-free-time/discuss/170551/Simple-Python-9-liner-beats-97-(with-explanation)
295. Median in a data stream -> You don't need to sort the entire stream. You just need to keep track of the median. Use two heaps.
632. Smallest Range in k sorted lists -> https://www.youtube.com/watch?v=Fqal25ZgEDo
303. Range Sum Query: sum(i, j) = cumulative_sum(i) - cumulative_sum(j)



# ToDo
- How are sets implemented?
- How do hash maps work? How are collisions resolved?
- Sets vs Maps
- P vs NP (NP complete, NP hard)
- Longest increasing subsequence
- Union Find
- Reservoir sampling
- Serialize n-ary tree
- OOPs in Python
- Buddy Strings
- Concept of generating random numbers
- Iterative tree traversals
- Quick sort


# Problems to memorize
ARRAYS
- Random pick weight
- Set matrix zeroes
- Range addition
- Product of array except self
- Spiral Matrix
- Heaters

TWO_POINTER
- Longest substring with at most two distinct characters

SORTING
- Wiggle sort
- Employee Free Time
- Task scheduler
- Queue Reconstruction

HASH MAPS
- Encode and Decode URL
- Number of corner rectangles

STACKS
- Exclusive time of functions
- Basic calculator
- Next greater element
- Asteroid collision

HEAPS:
- Task scheduler
- Meeting Rooms II

LINKED LIST
- LRU Cache
- Copy list with random pointer
- Reverse LL
- Reorder list (Split into a and b, reverse b and merge a & b)
- Intersection of two lists (two pointer)

DFS
- Number of Islands
- Longest Increasing path in matrix
- Course schedule (Cycle detection)
- Robot Room Cleaner (You need to memorize this)
- Surrounded Regions (First consider border 'O's)
- Redundant Connection

BFS
- Evaluate division
- Bus routes
- The Maze
- Word Ladder

TREES
- Insert into BST
- Trie (children + word)
- Serialize and Deserialize Binary Tree (Pre-order DFS)
- Lowest Common Ancestor

DYNAMIC PROGRAMING
- Word Break
- Perfect Squares
- Decode ways
- Frog Jump (time complexity?)
- House Robber 3

BACKTRACKING
- Letter combinations of a phone number -> O(4^n) time and O(n) space
- Subset
- Permutations Swap A[i] and A[j], O(n x n!)
- Generate Valid Paranthesis
- 24 Game (ToDo)
