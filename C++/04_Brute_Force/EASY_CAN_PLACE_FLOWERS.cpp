/* 
Suppose you have a long flowerbed in which some of the plots are planted and some are not. 
However, flowers cannot be planted in adjacent plots - they would compete for water and both would die.

Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty), and a number n, 
return if n new flowers can be planted in it without violating the no-adjacent-flowers rule.


GREEDY!

*/

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    flowerbed.insert(flowerbed.begin(),0);
    flowerbed.push_back(0);
    for(int i = 1; i < flowerbed.size()-1; ++i)
    {
        if(flowerbed[i-1] + flowerbed[i] + flowerbed[i+1] == 0)
        {
            --n;
            ++i;
        }
            
    }
    return n <=0;
}