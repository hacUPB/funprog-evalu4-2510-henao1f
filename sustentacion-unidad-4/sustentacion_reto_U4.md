1. EXPLICACION DEL ANALISIS DEL PROBLEMA

El problema consistía en crear un programa en lenguaje C que leyera un archivo de texto, analizara su contenido y permitiera realizar modificaciones básicas, al poder entender los requerimientos, identifiqué que debía obtener estadísticas como el número de caracteres, palabras, espacios y líneas, además de contar la frecuencia de las vocales, también debía ofrecer la opción de reemplazar una palabra por otra y guardar todo el resultado en un nuevo archivo. Para abordar esto, decidí dividir el programa en funciones específicas,esto facilitó su desarrollo y organización, luego utilicé la memoria dinámica para poder leer archivos de cualquier tamaño y ise que este recorriera el texto carácter por carácter para asegurar un análisis preciso, tambien implementé una interacción sencilla con el usuario mediante la consola, lo que permite introducir el nombre del archivo y las palabras a reemplazarla, a lo ultimo, programé la función de guardado para conservar todos los resultados en un archivo externo, esta estructura me permitió desarrollar una solución funcional, clara y fácil de mantener.

2. ESTRATEGIA DE SOLUCION

La estrategia de solucion se baso en estructurar el programa de una forma modular, dividiendolo en funciones especificas que cumplen tareas concretas y se comunican entre si desde la funcion principal (main), este flujo inicia con la funcion de
´´
leerArchivo
´´
que solicita al usuario el nombre del archivo y carga su contenido completo en memoria usando una memoria dinamica, luego, se llama a la funcion
´´
 estadisticas
´´
para calcular el numero de caracteres (excluyendo saltos de linea), palabras, espacios y lineas presentes en el texto, luego la funcion
´´
contarVocales
´´
recorre el texto para poder contar cuantas veces aparece cada vocal, considerando mayusculas y minusculas, una vez hecho el analisis el programa solicita al usuario 2 palabras: la que desea reemplazar y la nueva. con esta informacion se utiliza la funcion
´´
reemplazar
´´
que genera una nueva version del texto con los cambios solicitados, por ultimo, todos los resultados, junto con el texto modificado, se guardan en un archivo llamado resultados.txt mediante la funcion
´´
guardarArchivo
´´
esta organizacion en modulos independientes permite mantener el codigo ordenado, facilita la depuracion y hace posible reutilizar funciones si se desea ampliar el programa en el futuro.

3. TABLA DE VARIABLES
´´´
{leerArchivo()}

Parametro          Tipo          Descripcion

Entrada              —           No recibe parámetros

Salida             char*         Puntero al texto completo leído del archivo


{estadisticas(const char *txt, int *c, int *p, int *esp, int *l)}

Parámetro          Tipo          Descripción

Entrada          const char*     Texto original leído del archivo

Salida             int* c        Número total de caracteres (sin saltos de línea)

Salida             int* p        Número total de palabras

Salida             int* esp      Número total de espacios

Salida             int* l        Número total de líneas


{contarVocales(const char *txt, int *a, int *e, int *i, int *o, int *u)}

Parámetro          Tipo          Descripción

Entrada         const char*      Texto original leído del archivo

Salida             int* a        Frecuencia de la vocal 'a'

Salida             int* e        Frecuencia de la vocal 'e'

Salida             int* i        Frecuencia de la vocal 'i'

Salida             int* o        Frecuencia de la vocal 'o'

Salida             int* u        Frecuencia de la vocal 'u'


{reemplazar(const char *txt, const char *buscar, const char *reemp)}

Parámetro          Tipo          Descripción

Entrada       const char* txt    Texto original a modificar

Entrada     const char* buscar   Palabra a buscar y reemplazar

Entrada      const char* reemp   Palabra nueva por la que se reemplaza

Salida             char*         Texto con los reemplazos aplicados


{guardarArchivo(const char *nombre, const char *txt, int c, int p, int esp, int l, int a, int e, int i, int o, int u)}

Parámetro          Tipo          Descripción

Entrada     const char* nombre   Nombre del archivo de salida

Entrada       const char* txt    Texto final a guardar

Entrada            int c         Número de caracteres

Entrada            int p         Número de palabras

Entrada            int esp       Número de espacios

Entrada            int l         Número de líneas

Entrada     int a, e, i, o, u    Frecuencias de cada vocal

Salida               —           No retorna valor, escribe en archivo
´´´

4. DIAGRAMAS, ESQUEMAS O PSEUDOCODIGOS

{PSEUDOCODIGO}

Inicio
    
    mostrar "Archivo a leer"
    Leer nombreArchivo
    texto <- leer Archivo(nombreArchivo)
    Si texto es NULL entonces
        Mostrar "Error al leer el archivo"
        Terminar programa
    Fin Si

    Llamar a estadisticas(texto, caracteres, palabras, espacios, lineas)

    Llamar a contarVocales(texto, a, e, i, o, u)
    
    Mostrar estadisticas y frecuencias de vocales

    Mostrar "¿Que palabra quieres reemplazar?"
    Leer buscar
    Mostrar "¿por que palabra quieres reemplazarla?"
    Leer reemplazo

    texto modificado <- reemplazar(texto, buscar, reemplazo)
    Si textoModificado es NULL entonces
        Mostrar "Error al reemplazar la palabra"
        Terminar programa
    Fin Si

    Llamar a guardarArchivo("resultados.txt", textoModificado, caracteres, palabras, espacios, lineas, a, e, i, o, u)

    Liberar memoria de texto y textoModificado

Fin


