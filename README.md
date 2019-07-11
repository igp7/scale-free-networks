# Scale Free Networks
La creación de una red libre de escala siguiendo el modelo de Barabasi consiste en dados los valores _**m(>0)**_, el número de enlaces con los que entra un nodo nuevo a la red, y _**t(>0)**_, el número de pasos del modelo. Supondremos que _**m0 = m + 1**_ y que en la configuración inicial todos los nodos están unidos con todos. En estas redes el número de nodos es dependiente del número de pasos dados en el modelo: _**N(t) = m0 + t**_.

Tras la ejecucion del progrma se crearan dos ficheros .csv uno con los nodos de la red y otro con las aristas.

# Requisitos
- En __inputsRedBarabasi.txt__ el primer campo es el número de nodos que tiene la red, el segundo es el número de enlaces que tendrá cada nodo al ser añadido a la red.

# Obtención y ejecución
```sh
$ git clone https://github.com/igp7/scale-free-networks.git
$ g++ -std=c++11 -o <output> GeneraBarabasi.cpp
$ ./<output>
```

# Licencia
Este codigo tiene licencia [MIT](https://github.com/igp7/scale-free-networks/blob/master/LICENSE).
