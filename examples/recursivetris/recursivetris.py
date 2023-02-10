import sys
import math

firstSideLength = 1000
numTris = 8 

edges = []
x, y = firstSideLength, firstSideLength
for i in range(numTris):
    x /= 2
    y /= 2
    edges += [((0,y),(x,y)),
              ((x,y),(x,0)),
              ((x,0),(0,y))
             ]

# print edges to standard output
print("\n".join([str(edge) for edge in edges]))
