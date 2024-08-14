import numpy as np

a = np.array([[41,-62,125],[71, -41, 45]])

for i in range(len(a[1])):
    a[1][i] = a[1][i]/a[1][0] * a[0][0]

print(a)
