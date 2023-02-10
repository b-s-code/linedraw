import sys
import math

edges = []
numrevs = 20
coeffx1 = 500
coeffx2 = 500
vertlen = 50
waveheight = 150
for x in range(0, int(numrevs * 2 * 1.3 * math.pi)):
    x /= numrevs
    edges += [
              ((x * 100, math.sin(coeffx1 * x) * waveheight - x ** 3), (x * 100, math.sin(coeffx1 * x) * waveheight * ((x) /(2 * 1.3 * math.pi)) - vertlen - x ** 3))
             ]

# print edges to standard output
print("\n".join([str(edge) for edge in edges]))
