import numpy as np
import numpy.linalg as LA
import matplotlib.pyplot as plt
import matplotlib.image as mpimg

#local imports
from line.funcs import *
from triangle.funcs import *
from conics.funcs import circ_gen

fig = plt.figure()
ax = fig.add_subplot(111)

#Given points
A = np.array(([4, 3])).reshape(-1,1) 
B = np.array(([6, 4])).reshape(-1,1)  
C = np.array(([5,-6])).reshape(-1,1)
D = np.array(([-3,5])).reshape(-1,1)

points = [A,B,C,D]

f1 = open("x_AB.dat","r")
f2 = open("x_AC.dat","r")
f3 = open("x_AD.dat","r")
f4 = open("x_BC.dat","r")
f5 = open("x_BD.dat","r")
f6 = open("x_CD.dat","r")

x_AB = np.loadtxt(open("x_AB.dat","r")).T
x_AC = np.loadtxt(open("x_AC.dat","r")).T
x_AD = np.loadtxt(open("x_AD.dat","r")).T
x_BC = np.loadtxt(open("x_BC.dat","r")).T
x_BD = np.loadtxt(open("x_BD.dat","r")).T
x_CD = np.loadtxt(open("x_CD.dat","r")).T

#Plotting all lines
plt.plot(x_AB[0,:],x_AB[1,:],label='$AB$')
plt.plot(x_BC[0,:],x_BC[1,:],label='$BC$')
plt.plot(x_CD[0,:],x_CD[1,:],label='$CD$')
plt.plot(x_AD[0,:],x_AD[1,:],label='$DA$')
plt.plot(x_AC[0,:],x_AC[1,:],label='$AC$')
plt.plot(x_BD[0,:],x_BD[1,:],label='$BD$')

#Labeling the coordinates
colors = np.arange(1,5)
tri_coords = np.block([[A,B,C,D]])
plt.scatter(tri_coords[0,:], tri_coords[1,:], c=colors)
vert_labels = ['A','B','C','D']

    #plt.annotate(txt, # this is the text
plt.annotate(f'A\n({tri_coords[0,0]:.2f}, {tri_coords[1,0]:.2f})',
              (tri_coords[0,0], tri_coords[1,0]), # this is the point to label
              textcoords="offset points", # how to position the text
              xytext=(25,5), # distance from text to points (x,y)
              ha='center') # horizontal alignment can be left, right or center
plt.annotate(f'B\n({tri_coords[0,1]:.2f}, {tri_coords[1,1]:.2f})',
              (tri_coords[0,1], tri_coords[1,1]), # this is the point to label
              textcoords="offset points", # how to position the text
              xytext=(25,5), # distance from text to points (x,y)
              ha='center') # horizontal alignment can be left, right or center
plt.annotate(f'C\n({tri_coords[0,2]:.2f}, {tri_coords[1,2]:.2f})',
              (tri_coords[0,2], tri_coords[1,2]), # this is the point to label
              textcoords="offset points", # how to position the text
              xytext=(25,5), # distance from text to points (x,y)
              ha='center') # horizontal alignment can be left, right or center
plt.annotate(f'D\n({tri_coords[0,3]:.2f}, {tri_coords[1,3]:.2f})',
              (tri_coords[0,3], tri_coords[1,3]), # this is the point to label
              textcoords="offset points", # how to position the text
              xytext=(25,5), # distance from text to points (x,y)
              ha='center') # horizontal alignment can be left, right or center


left,right = ax.get_xlim()
low,high = ax.get_ylim()

plt.arrow( -8, 0, 16,0,width=0.005,length_includes_head = True,head_width=0.3,overhang=0.5)
plt.arrow( 0, low, 0, high-low,width=0.005,length_includes_head = True,head_width=0.3,overhang=0.5)

plt.legend(loc='upper left')
plt.grid() # minor
plt.axis('equal')


plt.savefig('../figs/fig1.png')


plt.show()


f1.close()
f2.close()
f3.close()
f4.close()
f5.close()
f6.close()
