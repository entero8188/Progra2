set terminal pdfcairo enhanced 

set output "Interpolacion_energia_potencial.pdf"
set title "gráfico de datos interpolados donde se aprecia como \ndecae exponencialmente respector a t"
set xlabel "t"
set ylabel "exp(t)"
plot "archivo_interpolacion2.dat" using 1:2 w l, "datos.dat" using 1:2, "archivo_interpolacion.dat" using 1:2 w l
