class Node:
    def __init__(self):
        self.children = {}
        self.word = None


class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = Node()


    def insert(self, word):
        """
        Inserts a word into the trie.
        :type word: str
        :rtype: void
        """
        root = self.root

        for ch in word:
            if ch in root.children:
                root = root.children[ch]
            else:
                new_node = Node()
                root.children[ch]=new_node
                root = new_node

        root.word = word


    def search(self, word):
        """
        Returns if the word is in the trie.
        :type word: str
        :rtype: bool
        """
        root = self.root
        for ch in word:
            if ch in root.children:
                root = root.children[ch]
            else:
                return False

        return root.word == word


    def startsWith(self, prefix):
        """
        Returns if there is any word in the trie that starts with the given prefix.
        :type prefix: str
        :rtype: bool
        """
        root = self.root
        for ch in prefix:
            if ch in root.children:
                root = root.children[ch]
            else:
                return False
        return True
