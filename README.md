# Taller-1

Taller N°1 de Estructura de Datos.

# Compilación y Ejecución 

Para compilar, linkear y ejecutar el código, utilizar estas lineas de comando en orden:

g++ Biblioteca.cpp MatBiblio.cpp Sistema.cpp User.cpp Libro.cpp Revista.cpp -c

g++ Biblioteca.cpp MatBiblio.cpp Sistema.cpp User.cpp Libro.cpp Revista.cpp -o biblio.exe

./biblio.exe

# Objetos

El objeto Sistema es el objeto encargado del manejo de tanto los materiales como los usuarios, almacenandolos y tambien operando con los mismos, ya sea para buscar un material o usuario especifico, como para añadirlos o eliminarlos.

Sistema no tiene constructor, ya que no se le asigna ningun dato al ser instanciado.
Sistema es un Singleton.

El objeto MatBiblio es la clase padre de Libro y Revista. Libro y Revista heredan de MatBiblio y tienen
sus propios datos independientes. Aqui unos ejemplos de Libro y Revista respectivamente.

libro1: { nombre:"Libro1", isbn:"9781234567897", autor:"Roberto Manfinfla", prestado:"0" 
(puede ser 1 o 0 para true o false), fechaPublicación:"02-04-2003", resumen:"habia una vez...truz", tipo:"libro"}

revista1: { nombre:"Revista1", isbn:"9781523567897", autor:"Don Pollo", prestado:"1" 
(puede ser 1 o 0 para true o false), numeroEdicion:"22", mesPublicacion:"Enero", tipo:"libro"}

El objeto User es el objeto encargado de guardar los datos de los usuarios, siendo estos nombre, id y materiales prestados. Un ejemplo de Usuario a continuación:

usuario1: { nombre:"Pepe", id:"3441", material1:"9781234567897", material2:"n", material3:"n", material4:"n", material5;"n" }

Los materiales se guardan como "n" si no hay ningun material asignado, "n" refiriendo a nullptr. De otra manera, se guarda el isbn del material, con el cual durante la ejecucion del programa se guardan los punteros de los materiales para poder trabajar con los mismos.

# Integrantes


Andres Giovanni Hidalgo Ramallo - Rut: 21.795.550-5 - Paralelo: C1

Diego Javier Ravanal Vanzi - Rut: 22.228.327-2 - Paralelo: C2