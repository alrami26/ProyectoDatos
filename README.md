#“Manual de Usuario I Proyecto” #
##Instituto Tecnológico de Costa Rica ##
###ESCUELA DE INGENIERIA EN COMPUTACION ###
###Estructuras de datos ###

**Profesor:** 

Msc.Armando Arce

**Estudiantes:** 

Jose Daniel Azofeifa Ugalde

Albin Ramírez Cubillo


## • Introducción##
Esta aplicación ha sido desarrollada para ver diversos gráficos relacionados con shapefiles, además de poder ver los diversos mapas podrá realizar zoom y moverse por todo el mapa de una forma amigable con el usuario.

## • Descripción del contenido a desplegar##
Con esta aplicación se podrán desplegar diversos gráficos como lo pueden ser calles, polígonos, y diversas figuras geométricas pertenecientes al shapefile.

## • Definición de estructuras de datos utilizadas##
Para esta aplicación se utilizaron listas basadas en arreglos, además de arboles de búsqueda binaria para la graficación.

## • Descripción del algoritmo de simplificación y la representación mediante árbol binario##
Para esta aplicación hemos utilizado el algoritmo de simplificación de Ramer-Douglas-Peucker el cual consiste en ir dividiendo la línea. Al principio le dan todos los puntos. Automáticamente marca un punto general. Entonces busca el punto que es lejano del segmento de línea del punto general. Si el punto está más cerca al segmento de línea entonces cualquier punto no marcado para guardar se puede desechar. Si el punto más lejano del segmento de línea es mayor que la aproximación entonces el punto se debe guardar. El algoritmo recurrentemente se llama con el primer punto y el peor punto y luego con el peor punto y el último punto. Cuando la simplificación se completa una nueva curva de la salida se puede generar con  todos aquellos puntos que se han guardado.

![imgsimpli][simplificacion]
[simplificacion](C:\Users\DANI\arbol.png)

## • Forma de compilación, ejecución y utilización de la aplicación##
Esta aplicación se debe compilar utilizando Dev-cpp 4.9.9.2 además de utilizar la librería FLTK 1.1.7 previamente agregada al Dev-cpp.

Se debe de ejecutar con el Dev-cpp o con  ProyectoDatos.exe.
Los shapefiles primero se deberán convertir a formato txt con shp2text.exe.

A continuación se explicar como utilizar la aplicación: 

Primero deberá abrir ProyectoDatos.exe

![img1][op1]
[op1](https://www.dropbox.com/s/vufl9ebs3e8idnj/1.png)

Como segundo paso deberá oprimir el botón de open y se desplegara la siguiente pantalla en la cual deberá escribir la dirección en la que se encuentra el archivo txt generado con anterioridad.

![img2][op2]
[op2](C:\Users\Albin\Dropbox\I Proyecto C\2.png)

Luego de oprimir open, si la dirección es correcta se desplegara el siguiente mensaje:

![img3][op3]
[op3](C:\Users\Albin\Dropbox\I Proyecto C\3.png)

Y seguidamente se dibujara el grafico.

![img4][op4]
[op4](C:\Users\Albin\Dropbox\I Proyecto C\4.png)

Se podrá realizar zoom in

![img5][op5]
[op5](C:\Users\Albin\Dropbox\I Proyecto C\5.png)

Además de zoom out

![img6][op6]
[op6](C:\Users\Albin\Dropbox\I Proyecto C\6.png)

Tambien podrá restablecer el tamaño original

![img7][op7]
[op7](C:\Users\Albin\Dropbox\I Proyecto C\7.png)

Y podrá desplazarse por lo largo del mapa gracias a las scrollbar en el costado inferior y del lado derecho.

![img8][op8]
[op8](C:\Users\Albin\Dropbox\I Proyecto C\8.png)

## • Ejemplos de datos a utilizar como pruebas##
Se podrá utilizar el archivo calles.txt generado por el calles.shp perteneciente a  la carpeta SANJOSE.

## • Limitaciones observadas y posibles mejoras##
Consideramos que se debería poder utilizar los shapefiles si tener que crear un .txt con anterioridad, además el algoritmo de simplificación es difícil de implementar, el cual no logramos implementar. Tomando en cuenta que los proyectos son acumulativos se debería de brindar más tiempo para poder realizar de excelente forma el primer proyecto (La base de los siguientes proyectos). 

