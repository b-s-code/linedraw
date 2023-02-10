import sys
import math

edges = []
numrevs = 10
coeffx1 = 500
coeffx2 = 500
vertlen = 150
waveheight = 150
for x in range(0, int(numrevs * 2 * math.pi)):
    x /= numrevs
    edges += [
              ((x * 100, math.sin(coeffx1 * x) * waveheight), (x * 100, math.sin(coeffx1 * x) * waveheight - vertlen)),
              ((x * 100, math.sin(coeffx2 * x) * waveheight), (x * 100 + 2, math.sin(coeffx2 * x) * waveheight - vertlen))
             ]

# print edges to standard output
print("\n".join([str(edge) for edge in edges]))
