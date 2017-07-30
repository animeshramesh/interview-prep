/* 
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/

string simplifyPath(string path) 
{
    deque<string> queue;    // You need a dequeue because reading from a stack is in reverse
    string cur; // current word
    for (int i = 0; i < path.length(); ++i) 
    {
        char c = path[i];
        if (c == '/') 
        {
            if (!cur.empty() && cur != "." && cur != "..") queue.push_back(cur);
            else if (cur == ".." && queue.size() > 0) queue.pop_back();
            cur.clear();    // Reset current word
        }
        else 
            cur.push_back(c);   // Keep building the current word
        
    }

    // One last case where cur would have some value
    if (!cur.empty() && cur != "." && cur != "..") queue.push_back(cur);
    else if (cur == ".." && queue.size() > 0) queue.pop_back();


    string res;
    for (auto ptr = queue.begin(); ptr != queue.end(); ptr++) 
    {
        res.push_back('/');
        res += (*ptr);
    }
    return res.length() > 0 ? res : "/";
}

