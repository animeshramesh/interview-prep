def isSubsequence(self, main_str, subsequence):
    """
    :type s: str
    :type t: str
    :rtype: bool
    """
    if not main_str:
        return True

    i = 0
    for x in subsequence:
        if x == main_str[i]:
            i += 1
        if i == len(subsequence):
            return True
    return False
