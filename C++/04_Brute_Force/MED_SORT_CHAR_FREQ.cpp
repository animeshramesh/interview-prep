// Given a string, sort it in decreasing order based on the frequency of characters.

// My solution
string frequencySort(string s) {
    map<char,int> counts;
    for (int i = 0; i<s.size(); i++)
    {   if (counts.find(s[i]) == counts.end() ) 
            counts[s[i]] = 1;
        else counts[s[i]]++;
    }
    map<int, string> ref;
    map<char, int>::iterator it;

    for (it=counts.begin(); it!=counts.end(); it++)
    {
        if (ref.find(it->second) == ref.end())
        {
            ref[it->second] = string(1, it->first);
        }
        else ref[it->second] += it->first;
    }
    string ans = "";
    map<int, string>::iterator it1;
    for (it1 = ref.begin(); it1!=ref.end(); it1++)
    {   for (int i = 0; i<it1->second.size(); i++)
            ans += string(it1->first, it1->second[i]);
            
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// Optimal solution
string frequencySort(string s) {
    unordered_map<char,int> freq;
    vector<string> bucket(s.size()+1, "");
    string res;
    
    //count frequency of each character
    for(char c:s) freq[c]++;
    //put character into frequency bucket
    for(auto& it:freq) {
        int n = it.second;
        char c = it.first;
        bucket[n].append(n, c);
    }
    //form descending sorted string
    for(int i=s.size(); i>0; i--) {
        if(!bucket[i].empty())
            res.append(bucket[i]);
    }
    return res;
}