import sys
import string
import math
import random
import operator
from fractions import Fraction, gcd
from decimal import Decimal, getcontext
from itertools import product, permutations, combinations
from collections import Counter, defaultdict
getcontext().prec = 100

MOD = 10**9 + 7
INF = float("+inf")

n = int(raw_input())

names = [raw_input() for _ in xrange(n)]


edges = {}
back_edges = defaultdict(set)
for c in string.ascii_lowercase:
    edges[c] = set()

for i in xrange(n - 1):
    s1 = names[i]
    s2 = names[i + 1]
    for c1, c2 in [zip(s1, s2)]:
        if c1 != c2:
            if c2 not in edges[c1]:
                edges[c1].add(c2)
                back_edges[c2].add(c1)
            if c1 in edges[c2]:
                print "Impossible"
                quit()
            break
    else:
        if len(s1) > len(s2):
            print "Impossible"
            quit()

from collections import deque

visited = set()
topsort = deque()
indexes = {}

def topsort_dfs(v):
    visited.add(v)
    for u in edges.get(v, ()):
        if u not in visited:
            topsort_dfs(u)
    topsort.appendleft(v)
    indexes[v] = len(edges) - len(topsort)

for v in edges.keys():
    if v not in visited:
        topsort_dfs(v)

for v, us in edges.iteritems():
    for u in us:
        if indexes[v] > indexes[u]:
            print "Impossible"
            quit()

print "".join(topsort)