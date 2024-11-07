
    Sebastian Gerritsen Ortiz A01643364
    Victor Jaziel Coronado Flores A01644090
    Angel Gabriel Arce Martinez A01736655
    Hecho en el 3 de Abril del 2024

    Este programa demuestra solicita al usuario las fechas de inicio y fin de búsqueda de 
    información (el intervalo debe ser cerrado, i.e., incluir los valores que lo delimitan), 
    indicando claramente al usuario que el formato requerido por el programa es el 
    siguiente: mes, día hora, minutos y segundos (e.g., Jun 01 00:22:36).
    Utiliza el mejor algoritmo de búsqueda que puedas para encontrar primero la fecha 
    inicial del rango y después la fecha final del rango seleccionado para la consulta.
    Verifica que ambas fechas se encuentre en la bitácora, en caso de que una de ellas no lo 
    esté informa al usuario. Despliega en pantalla los registros correspondientes a ese 
    rango de fechas. Almacena en un archivo llamado "bitacora_ordenada.txt" el resultado del 
    ordenamiento de la bitácora completa.
        segment: Esta función recorre el mapa y segmenta la fecha en segmentos. Dado que 
        recorre una estructura de datos, su complejidad depende del número de elementos en 
        el mapa. Supongamos que el mapa tiene N elementos. La complejidad de esta función 
        sería O(N), ya que debe procesar cada elemento una vez.
        quickSort: La complejidad del algoritmo de Quicksort en el peor caso es O(N^2), pero 
        en promedio es O(N log N). Esto se debe a que en cada paso se divide el arreglo en 
        dos subarreglos y se ordenan de forma recursiva. Por lo tanto, la complejidad de esta 
        función sería O(N log N) en promedio.
        bubbleSort: El Bubble Sort tiene una complejidad en el peor caso de O(N^2), ya que en 
        cada iteración se comparan y se intercambian elementos adyacentes si están en el orden 
        incorrecto. La complejidad de esta función sería O(N^2) en el peor caso.
        buscarRango(No Funcionando): Esta función realiza una búsqueda binaria en el vector de registros. La 
        búsqueda binaria tiene una complejidad de O(log N), donde N es el tamaño del vector. 
        Por lo tanto, la complejidad de esta función sería O(log N).
        guardarBitacora: Esta función recorre el vector de registros y los guarda en un 
        archivo externo. Similar a la función segment, su complejidad depende del número de 
        elementos en el vector. Por lo tanto, la complejidad de esta función sería O(N).
    GfG. (2023a, November 16). Substring in C. GeeksforGeeks. https://www.geeksforgeeks.org/substring-in-cpp/
    GfG. (2023b, November 21). Bubble Sort data structure and algorithm tutorials. GeeksforGeeks. https://www.geeksforgeeks.org/bubble-sort/
    GfG. (2024a, January 10). Binary Search Data Structure and algorithm Tutorials. GeeksforGeeks. https://www.geeksforgeeks.org/binary-search/
    GfG. (2024b, March 22). QuickSort Data structure and algorithm tutorials. GeeksforGeeks. https://www.geeksforgeeks.org/quick-sort/

