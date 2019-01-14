def findRadius(self, houses, heaters):
    """
    :type houses: List[int]
    :type heaters: List[int]
    :rtype: int
    """
    heaters.sort()           #first sort the heaters
    n = len(heaters) - 1
    maxDist = 0
    for h in houses:         #then for each house search for the nearest heater
        Lo = 0
        Hi = n
        while Hi - Lo > 1:   #stop when there are two candidates (instead of one)
            Mid = (Lo+Hi) // 2
            if heaters[Mid] < h:
                Lo = Mid     #instead of Lo = mid+1 in common binary search cases
            else:
                Hi = Mid
        maxDist = max(maxDist,min(abs(heaters[Lo]-h),abs(heaters[Hi]-h)))
    return maxDist
