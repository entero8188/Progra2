#!/usr/bin/gnuplot
set terminal png size 1200,1200
set output "poisson2D.png"

set pm3d map
set xlabel "Eje x"
set ylabel "Eje y"
set view map
set palette defined (0 "blue", 1 "green", 2 "yellow", 3 "red")  # Puedes personalizar la paleta de colores según tus preferencias
splot "datos.dat" using 1:2:3 with image 
# reemplaza datos.dat por el nombre de tu archivo.
