import sys
from itertools import permutations
word = sys.argv[1]
ini_str = word
permutation = [''.join(p) for p in permutations(word)]
permutation.sort()
print(int(permutation.index(word))+1)
