import math

# number of vertices for complete graph K_n 
n = 13

# distance of vertices from origin
radius = 250

# determine 1/k of a revolution in radians
Φ = 2 * math.pi / n

# get vertices of complete graph K_n on unit circle
vertices = [(math.cos(Φ * i), math.sin(Φ * i)) for i in range(n)]

# give vertices appropriate radius
# and round off coords for bitmap reasons
vertices = [(x * radius, y * radius) for (x, y) in vertices]

# make edges from vertices
edges = []
while (len(vertices) > 1):
    p1 = vertices[0]
    edges += [(p1, p2) for p2 in vertices[1:]]
    vertices.pop(0)

# print edges to standard output
print("\n".join([str(edge) for edge in edges]))
