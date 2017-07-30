/* 
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?
*/

/*
At the first glance, a queue seems enough for this problem, because of its FIFO property. 
However,  the questions also requires "Recently", which means both "input" and "visit" are "recent actions" for the data. 
If you have the data "<1,1>"  the least recently used element in the queue <1,1> <2,2><3,3>, 
if method "get(1)" is called, "<1,1>" is now becoming the last (recently used) element in the queue. (<2,2,><3,3,><1,1>)

Consider the basic operations we need:
(1) Insert a new <key, value> pair to the beginning of the list.
(2) delete a <key, value> pair (if the cache is full).
(3) move a <key, value> pair to the beginning. (when it is used)
(3) change the value in a <key, value> pair and move it to the beginning.

Therefore,  a double linked list can handle the above methods well. 
A map<key, pair<int, int>>  is a good way tracking the position of the node according to its key.

Be careful with the following cases:
(1) List is empty
(2) List has one node
(3) Initialization
(4) Don't forget delete the element in the map when it is removed from list.
*/

class LRUCache {
public:
    unordered_map<int, list<pair<int,int>>::iterator> map_;
    list<pair<int, int>> list_;
    int capacity;
    
    LRUCache(int c) 
    {
        capacity = c;
    }
    
    int get(int key) 
    {
        if (map_.find(key) == map_.end())
            return -1;
        
        // Cache exists in list. We need to push it to front
        moveToFront(key, map_[key]->second);
        return map_[key]->second;
        
    }
    
    void put(int key, int value) 
    {   
        // The second condition is important
        // Delete from back only when the list if full and when the key is not available.
        if (list_.size() == capacity && map_.find(key) == map_.end())
        {
            auto toDelete = list_.back();   // toDelete is a pair
            list_.pop_back();
            map_.erase(toDelete.first); // remove from map too
        }
     
        moveToFront(key, value);
    }
    
    void moveToFront(int key, int value)
    {   // If key is in cache, it erases it.
        // Then creates a new pair in the beginning of the list
        
        auto it = map_.find(key);
        if (it != map_.end())       // Case where key exists in list
            list_.erase(it->second);

        list_.push_front(make_pair(key, value));
        map_[key]= list_.begin();
    }
};
