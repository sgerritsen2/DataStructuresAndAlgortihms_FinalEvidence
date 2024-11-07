# 📝 Proyecto: Programa de Búsqueda en Bitácora

**Autor:** Sebastián Gerritsen Ortiz  
**Matrícula:** A01643364  
**Fecha de creación:** 3 de Abril del 2024  

---

## Descripción del Programa

Este programa solicita al usuario las **fechas de inicio y fin** de búsqueda de información. El intervalo debe ser cerrado, es decir, debe **incluir los valores que lo delimitan**. Se le indica claramente al usuario que el formato requerido es el siguiente:

- **Formato de fecha:** mes, día, hora, minutos y segundos (e.g., `Jun 01 00:22:36`)

### Funcionalidades

1. **Búsqueda de Fechas:**
   - Utiliza el mejor algoritmo de búsqueda disponible para encontrar la **fecha inicial** y **fecha final** del rango seleccionado.
   - Verifica que ambas fechas se encuentren en la bitácora. Si alguna no está, informa al usuario.

2. **Despliegue de Registros:**
   - Muestra en pantalla los registros correspondientes al rango de fechas seleccionado.

3. **Almacenamiento de la Bitácora Ordenada:**
   - Guarda los registros ordenados en un archivo llamado `bitacora_ordenada.txt`.

---

## Funciones Principales y Complejidad

### `segment`
- **Descripción:** Recorre el mapa y segmenta la fecha en partes.
- **Complejidad:** `O(N)`, donde `N` es el número de elementos en el mapa.

### `quickSort`
- **Descripción:** Algoritmo de ordenamiento QuickSort.
- **Complejidad:** `O(N log N)` en promedio, pero en el peor caso es `O(N^2)`.

### `bubbleSort`
- **Descripción:** Algoritmo de ordenamiento Bubble Sort.
- **Complejidad:** `O(N^2)` en el peor caso.

### `buscarRango` (No Funcionando)
- **Descripción:** Realiza una búsqueda binaria en el vector de registros.
- **Complejidad:** `O(log N)`, donde `N` es el tamaño del vector.

### `guardarBitacora`
- **Descripción:** Recorre el vector de registros y los guarda en un archivo externo.
- **Complejidad:** `O(N)`.

---

## Referencias

- GfG. (2023a, November 16). **Substring in C**. *GeeksforGeeks*. [https://www.geeksforgeeks.org/substring-in-cpp/](https://www.geeksforgeeks.org/substring-in-cpp/)
- GfG. (2023b, November 21). **Bubble Sort data structure and algorithm tutorials**. *GeeksforGeeks*. [https://www.geeksforgeeks.org/bubble-sort/](https://www.geeksforgeeks.org/bubble-sort/)
- GfG. (2024a, January 10). **Binary Search Data Structure and algorithm Tutorials**. *GeeksforGeeks*. [https://www.geeksforgeeks.org/binary-search/](https://www.geeksforgeeks.org/binary-search/)
- GfG. (2024b, March 22). **QuickSort Data structure and algorithm tutorials**. *GeeksforGeeks*. [https://www.geeksforgeeks.org/quick-sort/](https://www.geeksforgeeks.org/quick-sort/)


