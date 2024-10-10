import numpy as np
import matplotlib.pyplot as plt
import os

# Load the points from the text file
points = np.loadtxt("line_points.txt", delimiter=',', max_rows=len(list(open("./line_points.txt"))))
# Extract the x and y coordinates
centre=np.array([points[0][0],points[0][1]])
x1 = points[:-24, 0]
y1 = points[:-24, 1]
x2 = points[-24:-12,0]
y2 = points[-24:-12,1]
x3 = points[-12:,0]
y3 = points[-12:,1]
plt.figure()
x5 = [0 for i in range(12)]
plt.plot(x1, y1, label='x^2=4y', color='blue')
plt.plot(x2, y2, label='', color='red')
plt.plot(x3, y3, label='', color='red')
#plt.plot(x5, y3, label='', color='black')
where_l = []
for i in range(2002):
    if y1[i]<=4 and y1[i]>=2 and x1[i]>=0:
        where_l.append(True)
    else: where_l.append(False)
plt.fill_betweenx(y1, x1, 0, where=where_l, color='green', alpha=0.5, label='Required Area')

#plt.fill_between(y1, x1, x2, where=(x2*x2 >= x1*x1 and y1<=8), color='orange', alpha=0.5)
#plt.fill_between(x1, y1, y2, where=(y2 >= y1), color='lightblue', alpha=0.5)
plt.gca().set_aspect('equal', adjustable='box')
#vector_max = max(np.abs(directionvector).max(), np.abs(normalvector).max())
#plt.xlim(-vector_max * 3, vector_max * 3)
#plt.ylim(-vector_max * 3, vector_max * 3)
#plt.xlim(-1,0.5)
plt.axhline(0, color='black',linewidth=1)  # x-axis
plt.axvline(0, color='black',linewidth=1)  # x-axis
#plt.ylim(-15,15)
plt.xlabel("x")
plt.ylabel("y")
plt.title(" ")
plt.grid(True)
#plt.legend()
plt.savefig("../figs/fig1.png")
plt.show()

