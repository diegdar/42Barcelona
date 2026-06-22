# Archivo de trabajo
file =		"H o l a \n M u n d o  \n ¿  Q  u  é  t ' ' a  l  ?  \n" \0
posiciones = 	 0 1 2 3 4  5 6 7 8 9  10 11 12 13 14 15 16 17 18 19 20  21

# Macros utilizadas
BUFFER_SIZE = 20;

# Variables utilizadas dentro de get_next_line.c
```c
ssize_t     nrbytes;  // Devuelve el número de bytes leídos por read().
char        *buffer;  // Es el cubo que se utiliza para extraer los bytes del archivo fd con read().
char        *line;    // Es la línea obtenida hasta el '\n'.
int         i; // para recorrer los caracteres del buffer
static char *storage; // Almacena todo lo que le pasa buffer (incluyendo el \n y todo lo que venga después), y solo se vaciará o recortará después de que se haya extraído la línea a devolver por get_next_line.
```

## Funciones necesarias en get_next_line_utils.c
- ft_strlen: para obtener la longitud de la linea para reservar memoria con malloc.
- ft_strchr: para encontrar la posicion en la que termina la linea.
- ft_strjoin: para ir agregando los bytes obtenidos con el buffer en storage.
- ft_strdup: 
	- Para devolver una copia de la linea resultante al usuario.
	- Para guardar el trozo sobrante (desde el \n hasta el final) que se quedara en la variable 		
	estatica para la siguiente llamada.
