/*
Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.

Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that all houses could be covered by those heaters.

So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius standard of heaters.
*/

// My solution. 
// I knew I had to do better than O(n2). 
// Was thinking of O(mlogn), where we use some sort of binary search for optimal heater.
int getClosestHeater(int house, vector<int> & heaters)
{   
    if (house <= heaters[0]) {
        return heaters[0]-house;
    }
    else if (house >= heaters[heaters.size()-1])
    {
        return house-heaters[heaters.size()-1];
    }
    
    int start = 0, end = heaters.size()-1;
    
    int minDist = INT_MAX;
    
    for (int i = 0; i<heaters.size(); i++)
    {   int dist = abs(heaters[i] - house);
        if (dist < minDist) minDist = dist;
    }
    return minDist;
}

int findRadius(vector<int>& houses, vector<int>& heaters) {
    
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());
    
    int maxDistance = 0;
    
    for (int i = 0; i<houses.size(); i++)
    {   int dist = getClosestHeater(houses[i], heaters);
        if (dist > maxDistance) maxDistance = dist;
    }
    
    return maxDistance;
}

// Optimal Solution - O(n) : Traverses through houses and heaters at the same time!! + O(nlogn) for sorting
int findRadius(vector<int>& A, vector<int>& H) {
    sort(A.begin(), A.end());
    sort(H.begin(), H.end());
    vector<int> res(A.size(), INT_MAX); 
    
    // For each house, calculate distance to nearest RHS heater
    for (int i = 0, h = 0; i < A.size() && h < H.size(); ) {
        if (A[i] <= H[h]) { res[i] = H[h] - A[i]; i++; }
        else { h++; }
    }
    
    // For each house, calculate distance to nearest LHS heater
    for (int i = A.size()-1, h = H.size()-1; i >= 0 && h >= 0; ) {
        if (A[i] >= H[h]) { res[i] = min(res[i], A[i] - H[h]); i--; }
        else { h--; }
    }
   
    return *max_element(res.begin(), res.end());
}