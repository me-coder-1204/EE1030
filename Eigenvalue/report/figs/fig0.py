import numpy as np
import matplotlib.pyplot as plt

x_Shifted = np.loadtxt("../../benchShift.txt")
x_Hessen = np.loadtxt("../../benchHessen.txt")
x_Raw = np.loadtxt("../../benchRaw.txt")
plt.plot(x_Raw[:,0],x_Raw[:,1], label = "No Optimizations", color = "r")
plt.plot(x_Hessen[:,0],x_Hessen[:,1],label = "Hessenberg Reduction only", color = "b")
plt.plot(x_Shifted[:,0],x_Shifted[:,1], label = "Shifted Hessenberg", color = "g")
plt.legend(loc="best")
plt.savefig("./fig0.png")
plt.show()
