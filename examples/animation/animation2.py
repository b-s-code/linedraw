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

num_frames = 50
# we represent each frame as a list of edges :)

points = [(-100,-100), (100,-100), (100,100), (-100,100)]
stable_points = [(-200,-200), (200,-200), (200,200), (-200,200)]

os.system("rm frame*")
os.system("rm myimage.gif")

target = (-175, -175)

for i in range(num_frames):
    points[0] = (points[0][0] + 1, points[0][1] + 1)
    points[2] = (points[2][0] - 1, points[2][1] - 1)

    edges = [[points[i], points[i + 1]] for i in range(len(points) - 1)]
    edges += [[points[0], points[len(points) - 1]]]
    
    # to solve shifting border issue
    edges += [[stable_points[i], stable_points[i + 1]] for i in range(len(stable_points) - 1)]

    # to solve frame sorting problem between frame production and animated gif creation
    # we use leading zeros
    indexx = str(i).zfill(len(str(num_frames)))

    with open("frame_" + indexx + "_edges", "w") as f:
        for edge in edges:
            f.writelines(str(edge) + "\n")

    os.system("cat " + "frame_" + indexx + "_edges" + " | ../../bin/LineDraw > " + "frame_" + indexx + "_edges.ppm")

os.system("mogrify -format png *.ppm")
os.system("rm *edges")
os.system("rm *ppm")
os.system("convert -delay 20 -loop 0 *.png myimage.gif")
os.system("rm *png")
os.system("firefox myimage.gif")
