'''
HashTable where get, add, delete operations take O(1) time
key = int
value = int
'''
import unittest

class HashTable:

    def __init__(self, k):
        self.k = k
        self.data = [[]] * k

    def _get_hash_code(self, val):
        return val % self.k

    def get(self, key):
        hash_code = self._get_hash_code(key)
        result = self.data[hash_code]
        if not result: return None
        for pair in result:
            if pair[0] == key:
                return pair[1]

        return None

    def put(self, key, value):
        hash_code = self._get_hash_code(key)
        for i, pair in enumerate(self.data[hash_code]):
            if pair[0] == key:
                self.data[hash_code][i][1] = value
                return True

        self.data[hash_code].append([key, value])
        return True

    def delete(self, key):
        hash_code = self._get_hash_code(key)
        if not self.data[hash_code]: return False
        for i, pair in enumerate(self.data[hash_code]):
            if pair[0] == key:
                self.data[hash_code].pop(i)
                return True

        return False

class TestHashTable(unittest.TestCase):
    def test(self):
        hash_table = HashTable(100)
        self.assertEqual(hash_table.get(10), None, "Should be None")
        self.assertEqual(hash_table.put(1, 10), True, "Should be True")
        self.assertEqual(hash_table.put(2, 20), True, "Should be True")
        self.assertEqual(hash_table.put(3, 30), True, "Should be True")
        self.assertEqual(hash_table.put(1, 20), True, "Should be True")
        self.assertEqual(hash_table.get(1), 20, "Should be 20")
        self.assertEqual(hash_table.delete(1), True, "Should be True")
        self.assertEqual(hash_table.delete(4), False, "Should be False")

if __name__ == '__main__':
    unittest.main()
