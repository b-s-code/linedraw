import random
import os

def rnum(a, b = 0):
    return random.randint(min(a, b), max(a, b))

def rpoint():
    x, y = rnum(500), rnum(500)
    return (x, y)

def rpertubation():
    x, y = rnum(-2, 2), rnum(-2, 2)
    return (x, y)

num_frames = 240 
# we represent each frame as a list of edges :)


points = [(-100,-100), (100,-100), (100,100), (-100,100)]
stable_points = [(-200,-200), (200,-200), (200,200), (-200,200)]

os.system("rm frame*")
os.system("rm myimage.gif")

for i in range(num_frames):
    for j, point in enumerate(points):
        xpert, ypert = rpertubation()
        candidatex = point[0] + xpert
        candidatey = point[1] + ypert
        newx = candidatex if candidatex in range(500) else point[0]
        newy = candidatey if candidatey in range(500) else point[1]
        points[j] = (newx, newy)
    edges = [[points[i], points[i + 1]] for i in range(len(points) - 1)]
    edges += [[points[0], points[len(points) - 1]]]
    
    # to solve shifting border issue
    edges += [[stable_points[i], stable_points[i + 1]] for i in range(len(stable_points) - 1)]

    with open("frame_" + str(i) + "_edges", "w") as f:
        for edge in edges:
            f.writelines(str(edge) + "\n")
    
    os.system("cat " + "frame_" + str(i) + "_edges" + " | ../../bin/LineDraw > " + "frame_" + str(i) + "_edges.ppm")

os.system("mogrify -format gif *.ppm")
os.system("convert -delay 5 -loop 0 *.gif myimage.gif")
os.system("firefox myimage.gif")
