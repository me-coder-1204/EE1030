import numpy as np
from line.funcs import *

A = np.array(([1,2,3])).reshape(-1,1)
B = np.array(([4,6,8])).reshape(-1,1)

C = line_gen(A,B)
