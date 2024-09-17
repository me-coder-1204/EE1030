from ctypes import *
import numpy as np
import matplotlib.pyplot as plt

from line.funcs import *

fig = plt.figure()
ax = fig.add_subplot(111)

pointtip = CDLL("./dist.so")

class Result(Structure):
    _fields_ = [("p1",c_double),
                ("p2",c_double)]

points = pointtip.points
points.argtype = [c_double,c_double,c_double,c_double,POINTER(Result)]
points.restype = None

A = np.array(([0,0])).reshape(-1,1)
y2 = -4
d = 5
result = Result()
points(c_double(A[0]),c_double(A[1]),c_double(y2),c_double(d),byref(result))

print(result.p1, result.p2)

x1 = result.p1
x2 = result.p2

B1 = np.array(([x1,y2])).reshape(-1,1)
B2 = np.array(([x2,y2])).reshape(-1,1)

x_AB1 = np.block(([A,B1]))
x_AB2 = np.block(([A,B2]))
plt.plot(x_AB1[0,:],x_AB1[1,:],label = "$AB_1$")
plt.plot(x_AB2[0,:],x_AB2[1,:],label = "$AB_2$")

tri_coords = np.block(([A,B1,B2]))
print(A,B1,B2)

plt.scatter(tri_coords[0,:],tri_coords[1,:])

plt.annotate(f'A\n({tri_coords[0,0]:.2f}, {tri_coords[1,0]:.2f})',
                 (tri_coords[0,0], tri_coords[1,0]), # this is the point to label
                 textcoords="offset points", # how to position the text
                 xytext=(20,-10), # distance from text to points (x,y)
                 ha='center') # horizontal alignment can be left, right or center

plt.annotate(f'B1\n({tri_coords[0,1]:.2f}, {tri_coords[1,1]:.2f})',
                 (tri_coords[0,1], tri_coords[1,1]), # this is the point to label
                 textcoords="offset points", # how to position the text
                 xytext=(20,-10), # distance from text to points (x,y)
                 ha='center') # horizontal alignment can be left, right or center

plt.annotate(f'B2\n({tri_coords[0,2]:.2f}, {tri_coords[1,2]:.2f})',
                 (tri_coords[0,2], tri_coords[1,2]), # this is the point to label
                 textcoords="offset points", # how to position the text
                 xytext=(20,-10), # distance from text to points (x,y)
                 ha='center') # horizontal alignment can be left, right or center

#ax = plt.gca()
#ax.spines['top'].set_color('none')
#ax.spines['left'].set_position('zero')
#ax.spines['right'].set_color('none')
#ax.spines['bottom'].set_position('zero')
#ax.spines['left'].set_visible(False)
#ax.spines['right'].set_visible(False)
#ax.spines['top'].set_visible(False)
#ax.spines['bottom'].set_visible(False)
#plt.xlabel('$x$')
#plt.ylabel('$y$')
#plt.legend(loc='best')
#plt.grid() # minor
#plt.axis('equal')

left,right = ax.get_xlim()
low,high = ax.get_ylim()

plt.arrow( left, 0, right-left,0,width=0.005,length_includes_head = True,head_width=0.01,overhang=0.5)
plt.arrow( 0, low, 0, high-low,width=0.005,length_includes_head = True,head_width=0.01,overhang=0.5)

plt.legend(loc='upper left')
plt.grid() # minor
plt.axis('equal')

plt.savefig("../figs/fig0.png")
plt.show()

