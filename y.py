import matplotlib.pyplot as plt
from pylab import genfromtxt

xx=genfromtxt("out.txt")

plt.plot(xx[:,0], xx[:,1], label = "data 1")
plt.plot(xx[:,0], xx[:,2], "bs" ,label = "data 2")
plt.xlabel('x variable')
plt.ylabel('y variable')

plt.legend()
plt.show()

print("test for Github")
