1. ¿Por qué sizeof("Hola") devuelve 5, pero strlen("Hola") devuelve 4?

"Hola" es una cadena literal, lo que implica que incluye un carácter nulo (\0) al final.

sizeof("Hola") evalúa el tamaño total en bytes, incluyendo el \0.
 "H", "o", "l", "a", "\0" → 5 bytes.

strlen("Hola") cuenta solo los caracteres visibles, hasta antes del \0.
 Resultado: 4.

2. ¿Cuál es la diferencia práctica entre declarar una cadena como arreglo (char saludo[]) y como puntero (char *saludo)?

char saludo[] = "Hola";
 Arreglo: la cadena se almacena en la memoria del stack y es mutable (puedes modificar sus caracteres).

char *saludo = "Hola";
 Puntero a literal de cadena: apunta a una zona de memoria de solo lectura. Intentar modificar la cadena puede causar un error en tiempo de ejecución (segmentation fault).

3. ¿Cómo evitas un "buffer overflow" al copiar o concatenar cadenas?

Usando funciones seguras como:

strncpy(dest, src, tamaño_destino - 1); → luego aseguras dest[tamaño_destino - 1] = '\0';
strncat(dest, src, tamaño_restante_en_destino - 1); O mejor, en C moderno (si está disponible), usar snprintf() para concatenar o copiar con control de tamaño.

Siempre:

Verifica los límites del buffer.
Asegura el carácter nulo final (\0).
Prefiere usar fgets() sobre gets() al leer cadenas.

4. ¿Qué hace exactamente la función strcspn() y por qué es útil usarla junto con fgets()?

strcspn(cadena, conjunto) devuelve la posición del primer carácter en cadena que coincide con cualquiera en conjunto.

Ejemplo con fgets():

fgets(buffer, sizeof(buffer), stdin);
buffer[strcspn(buffer, "\n")] = '\0'; // Elimina el salto de línea

¿Por qué es útil?

Porque fgets() incluye el \n si hay espacio suficiente.
Usar strcspn() permite reemplazar el salto de línea por \0, haciendo la cadena más fácil de manejar.

5. ¿Qué pasos debes seguir para manejar correctamente una cadena reservada dinámicamente con malloc()?

'Reservar memoria:

char *cadena = malloc(tamaño);
if (cadena == NULL) {
    // manejar error de memoria
}

Usar la cadena con cuidado:

Copiar con strncpy(), snprintf(), etc., respetando el tamaño reservado.
Evitar desbordamientos.

'Liberar la memoria al final:

free(cadena);
cadena = NULL; // buena práctica para evitar dangling pointers