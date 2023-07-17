#!/usr/bin/python3
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# leer los datos del archivo
data = np.loadtxt('archivo.dat')
x = data[:,0]
t = data[:,1]
temperature = data[:,2]
# obtener las dimensiones de x, t y la temperatura
nx = len(np.unique(x))
nt = len(np.unique(t))

# reorganizar los datos en una matriz bidimensional
temperature = temperature.reshape((nt,nx))

#Crear una cuadricula 2D a partir de los datos
X, T = np.meshgrid(np.unique(x), np.unique(t))

#Graficar la superficie
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(X,T,temperature, cmap='viridis')
ax.set_xlabel('Posición')
ax.set_ylabel('Tiempo')
ax.set_zlabel('Temperatura')
plt.show()
