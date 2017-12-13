# Prácticas de Informática Gráfica

Prácticas realizadas en la asignatura de Informática Gráfica, cursada en el
tercer curso del grado de Ingeniería Informática de la Universidad de Granada.

## Requisitos y dependencias

  * OpenGL (Open Graphics Library)
  * GLUT (OpenGL Utility Toolkit)
  * GLU (OpenGL Library Utility)

  El comando `apt-get install freeglut3-dev` debería instalar las tres librerías
  mencionadas anteriormente.

## Práctica 1: Modelado y Visualización de objetos 3D sencillos

  En esta etapa se construyen dos objetos simples, un cubo, y un tetraedro.
  Para se ellos crean las estructuras de datos necesarias para definirlos y se
  utilizan las primitivas de dibujo de OpenGL.
  Para la contrucción de los objetos se introducen a mano las coordenadas de sus
  vértices y los vértices que componen cada uno de los triángulos en los que se
  divide el objeto.

## Práctica 2: Modelos PLY y Poligonales

  Esta práctica consiste por una parte, en visualizar objetos almacenados en
  ficheros de texto en formato PLY, los cuales contienen toda la información
  necesaria para generar el objeto que definen, y por otra, generar objetos
  poligonales sencillos como los de la práctica 1 de forma automática, mediante
  la técnica de generación por revolución.

## Práctica 3: Modelos Jerárquicos

  En esta práctica trabajamos con objetos algo más complejos, construidos mediante
  composición de objetos más simples, ya creados en la practica 1 y la practica 2.
  Para ello es necesario hacer uso de las transformaciones que nos proporciona
  OpenGL, lo que también nos permite realizar animaciones sencillas en los objetos.

  En esta práctica se ha construido un regulador de Watt a partir de cilindros,
  esferas y cubos.

## Práctica 4: Iluminación y Texturas

  En desarrollo. (Iluminación implementada desde la práctica 1).

## Práctica 5: Interacción

  En desarrollo.

## Mapa de teclas

### Controles generales

  * Modos de visualización:
    * P: activa/desactiva el modo de dibujado por puntos.
    * L: activa/desactiva el modo de dibujado alambre.
    * S: activa/desactiva el modo de dibujado por superficie.
    * C: activa/desactiva el modo de dibujado ajedrez.

  * Control de la cámara:
    * RePag: aumenta el zoom.
    * AvPag: reduce el zoom.
    * :arrow_up:: mueve la cámara hacia arriba.
    * :arrow_down:: mueve la cámara hacia abajo.
    * :arrow_left:: mueve la cámara hacia la izquierda.
    * :arrow_right:: mueve la cámara hacia la derecha.

  * Transformaciones:
    * Rotaciones:
      * R: activa/desactiva la rotación en el eje X.
      * T: activa/desactiva la rotación en el eje Y.
      * Y: activa/desactiva la rotación en el eje Z.
    * Escalados:
      * :heavy_plus_sign:: aumenta el objeto.
      * :heavy_minus_sign:: reduce el objeto.
    * Traslaciones:
      * :zero:: mueve el objeto negativamente en el eje Y.  (Y-1)
      * :one:: mueve el objeto en la diagonal XZ.           (X-1, Z+1)
      * :two:: mueve el objeto positivamente en el eje Z.   (Z+1)
      * :three:: mueve el objeto en la diagonal XZ.         (X+1, Z+1)
      * :four:: mueve el objeto negativamente en el eje X.  (X-1)
      * :five:: mueve el objeto positivamente en el eje Y.  (Y+1)      
      * :six:: mueve el objeto positivamente en el eje X.   (X+1)
      * :seven:: mueve el objeto en la diagonal XZ.         (X-1, Z-1)
      * :eight:: mueve el objeto negativamente en el eje Z. (Z-1)
      * :nine:: mueve el objeto en la diagonal XZ.          (X+1, Z-1)

  * Iluminación:
    * L: activa/desactiva el modo iluminación.
    * O: activa/desactiva la luz.

### Controles específicos de la práctica 3

  * J: aumenta la velocidad de rotación del regulador de Watt.
  * k: reduce la velocidad de rotación del regulador de Watt.

## Notas adicionales

  * Para cambiar el color de fondo descomentar o editar la línea `glClearColor`
