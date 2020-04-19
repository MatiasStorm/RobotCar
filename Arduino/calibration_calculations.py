# 2 s forward:
# 150 = 75
# 200 = 91
# 235 = 103
# 255 = 120 cm.

# .5 s = 90 degrees.
# 1 s = 180 degrees
# 1625 = 360 degrees.


import matplotlib.pyplot as plt
import numpy as np
from sklearn.linear_model import LinearRegression

forward_speed = [150, 200, 235, 255]
forward_distance = [75, 91, 103, 120]

m, b = np.polyfit(forward_distance, forward_speed, 1)

print(m, " * x + ", b)

fig, ax = plt.subplots()
ax.plot(forward_distance, forward_speed)

plt.show()


