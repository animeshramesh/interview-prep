'''
Below are some examples of word abbreviations:

a) it                      --> it    (no abbreviation)

     1
b) d|o|g                   --> d1g

              1    1  1
     1---5----0----5--8
c) i|nternationalizatio|n  --> i18n

              1
     1---5----0
d) l|ocalizatio|n          --> l10n
Assume you have a dictionary and given a word, find whether its abbreviation is
unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary
has the same abbreviation.

Have you met this question in a real interview?
Example
Given dictionary = [ "deer", "door", "cake", "card" ]
isUnique("dear") // return false
isUnique("cart") // return true
isUnique("cane") // return false
isUnique("make") // return true
'''

'''
Solution:
There are only 2 conditions we return true for isUnique("word")
1. The abbr does not appear in the dict.
2. The abbr is in the dict && the word appears one and only once in the dict. (CATCH)
'''
class ValidWordAbbr:

    def get_abb(self, word):
        if len(word) <= 2:
            return word
        else:
            return word[0] + str(len(word)-2) + word[-1]

    """
    @param: dictionary: a list of words
    """
    def __init__(self, dictionary):
        self.dictionary = dictionary
        self.abbvs = {}
        for word in self.dictionary:
            abbv = self.get_abb(word)
            if abbv not in self.abbvs:
                self.abbvs[abbv] = [word]
            else:
                self.abbvs[abbv].append(word)

    """
    @param: word: a string
    @return: true if its abbreviation is unique or false
    """
    def isUnique(self, word):
        abbv = self.get_abb(word)
        if abbv not in self.abbvs:
            return True
        else:
            return len(self.abbvs[abbv]) == 1 and self.abbvs[abbv][0] == word
