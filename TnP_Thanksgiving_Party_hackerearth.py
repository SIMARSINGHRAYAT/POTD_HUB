class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end = False

class Trie:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, word):
        cur = self.root
        for c in word:
            if c not in cur.children:
                cur.children[c] = TrieNode()
            cur = cur.children[c]
        cur.is_end = True

    def starts_with_any(self, prefix):
        cur = self.root
        for c in prefix:
            if c not in cur.children:
                return False
            cur = cur.children[c]
        return True  # Means prefix exists in some path

# Input Reading & Logic

# ✅ Memory-optimized prefix hashing approach

# Read number of students
n = int(input())
preferred = input().split()

# Store all unique prefixes from preferred pizzas
prefix_set = set()
for word in preferred:
    for i in range(1, len(word) + 1):
        prefix_set.add(word[:i])

# Read number of party days
q = int(input())

# Process each day
for _ in range(q):
    m, s = map(int, input().split())
    pizzas = input().split()
    liked = 0
    for pizza in pizzas:
        if pizza in prefix_set:
            liked += 1
    print("Yes" if liked >= s else "No")
