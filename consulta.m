realloc (libre)
Sintaxis (realloc)
#include <stdlib.h>

void *realloc (Pointer, Size)
void *Pointer;
size_t Size;
Descripción (reasignación)
La subrutina realloc cambia el tamaño del objeto de memoria al que apunta el parámetro Puntero por el número de bytes especificado por el parámetro Tamaño . El Puntero debe apuntar a una dirección devuelta por una rutina de asignación de subsistema malloc y no debe haberse desasignado previamente. Los resultados no definidos se producen si Puntero no cumple estos criterios.

El contenido del objeto de memoria permanece sin cambios hasta el menor de los tamaños antiguo y nuevo. Si el objeto de memoria actual no se puede ampliar para satisfacer la solicitud, la subrutina realloc adquiere un nuevo objeto de memoria y copia los datos existentes en el nuevo espacio. A continuación, se libera el objeto de memoria antiguo. Si no se puede adquirir ningún objeto de memoria para acomodar la solicitud, el objeto permanece sin cambios.

Si el parámetro Puntero es nulo, la subrutina realloc es equivalente a una subrutina malloc del mismo tamaño.

Si el parámetro Tamaño es 0 y el parámetro Puntero no es nulo, la subrutina realloc es equivalente a una subrutina free del mismo tamaño.

Parámetros (realloc)
Elemento
Descripción
Puntero	Especifica un Puntero para el espacio asignado anteriormente por el subsistema malloc .
Tamaño	Especifica el nuevo tamaño, en bytes, del objeto de memoria.
Valores de retorno (reasignación)
Cuando se completa correctamente con argumentos distintos de cero, la subrutina realloc devuelve un puntero al espacio asignado (posiblemente movido). Si el parámetro Tamaño es 0 y el parámetro Puntero no es nulo, el comportamiento de retorno es equivalente al de la subrutina free . Si el parámetro Puntero es nulo y el parámetro Tamaño no es cero, el comportamiento de retorno es equivalente al de la subrutina malloc .

Códigos de error (reasignación)
Elemento
Descripción
ENOMEM	No hay suficiente espacio de almacenamiento disponible para dar servicio a la solicitud.
calloc
Sintaxis (calloc)
#include <stdlib.h>

void *calloc (NumberOfElements, ElementSize)
size_t NumberOfElements;
size_t ElementSize;
Descripción (calloc)
La subrutina calloc asigna espacio para un array que contiene los objetos NumberOfElements. El parámetro ElementSize especifica el tamaño de cada elemento en bytes. Una vez asignada la matriz, todos los bits se inicializan en 0.

El orden y la contigüidad de almacenamiento asignados por llamadas sucesivas a la subrutina calloc no se han especificado. El puntero ha devuelto puntos a la primera dirección de byte (más baja) del espacio asignado. El espacio asignado se alinea para que se pueda utilizar para cualquier tipo de datos. Los resultados no definidos se producen si el espacio asignado por la subrutina calloc se ha desbordado.

Parámetros (calloc)
Elemento
Descripción
NumberOfElements	Especifica el número de elementos de la matriz.
ElementSize	Especifica el tamaño, en bytes, de cada elemento de la matriz.
Valores de retorno (calloc)
Al finalizar correctamente, la subrutina calloc devuelve un puntero a la matriz asignada de inicialización cero. Si el tamaño solicitado es 0, la subrutina calloc devuelve NULL en circunstancias normales. Sin embargo, si el programa se ha compilado con la macro _LINUX_SOURCE_COMPAT definida, la subrutina calloc devuelve un puntero válido a un espacio de tamaño 0.

Si la solicitud no se puede satisfacer por algún motivo, la subrutina calloc devuelve NULL.

Códigos de error (calloc)
Elemento
Descripción
ENOMEM	No hay suficiente espacio de almacenamiento disponible para dar servicio a la solicitud.