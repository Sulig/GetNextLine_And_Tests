# GetNextLine_And_Tests

Resumen: El objetivo de este proyecto es simple: programar una función que devuelva una línea leída de un file descriptor.

## Contenido del repositorio:
- Get Next Line + Bonus
- Tests basicos + test manual *(Bonus no incluidos!)
- Carpeta de los archivos para testear

## !! Importante Antes de ejecutar 'make'!!
1. En el Makefile cambia la variable "DIR" por el directorio de tu get_next_line
2. En el archivo "test_getnextline.h", cambia el directorio donde esta incluido tu "get_next_line.h"
3. Guarda todo y ya esta listo para usar!
***
## Comandos:
### Tests:

Auto Test

    make test

Test Manual

    make
    ./test.out + Directorio/Archivo.txt

### Debuggeador:

    make debug

*Valgrind (Solo funcionara si tienes valgrind)*

    make valgrind

### Limpiar archivos innecessarios:

Limpia solo *.o y los .out

    make clean

Limpieza profunda + borrado de .out.dSYM

    make fclean
    
Igual que fclean + limpia la pantalla

    make clear

***
~ Made by sadoming ~
***
