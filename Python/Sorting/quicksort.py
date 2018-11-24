
def quicksort(nums, start, end):
    if start < end:
        pivot = partition(nums, start, end)
        quicksort(nums, low, pivot-1)
        quicksort(nums, pivot+1, end)

def partition(nums, start, end)
    pivot = nums[end]
    i = low - 1

    for j in range(start, end):
        if nums[j] <= pivot:
            i += 1
            nums[i], nums[j] = nums[j], nums[i]

    nums[i+1], nums[end] = nums[end], nums[i+1]
    return i+1
