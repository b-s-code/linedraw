import sys
import math

# params
radii = [100, 200, 300, 400]
n = int(sys.argv[1])
Φ = math.pi / int(sys.argv[2]) + int(sys.argv[3])

# get edges
edges = []
for i in range(n):
    θ = 2 * math.pi  * i / n
    p0 = (radii[0] * math.cos(θ), radii[0] * math.sin(θ))
    p1 = (radii[1] * math.cos(θ), radii[1] * math.sin(θ))
    p2 = (radii[2] * math.cos(θ), radii[2] * math.sin(θ))
    q0 = (radii[3] * math.cos(θ + Φ), radii[3] * math.sin(θ + Φ))
    q1 = (radii[3] * math.cos(θ - Φ), radii[3] * math.sin(θ - Φ))
    for i in range(3):
        edges += [
                  (p0, q0), (p0, q1),
                  (p1, q0), (p1, q1),
                  (p2, q0), (p2, q1)
                 ]

# print edges to standard output
print("\n".join([str(edge) for edge in edges]))