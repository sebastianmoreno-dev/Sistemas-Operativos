# Tarea 2: Programación con hilos (POSIX Threads)

- **Materia:** Sistemas Operativos
- **Alumno:** Moreno Saenz Sebastian
- **Boleta:** 2025630357
- **Grupo:** 4CM1

## Descripción

Programa en C que resuelve el mismo problema de la Tarea 1, pero con hilos POSIX (`pthread`) en lugar de procesos creados con `fork()`.

- **Hilo 1:** imprime los números del 1 al 10,000.
- **Hilo 2:** imprime los números del 10,000 al 1.

El hilo principal crea ambos hilos con `pthread_create()` y espera a que terminen con `pthread_join()`.

## De procesos a hilos

|                             | Tarea 1                              | Tarea 2                                                                   |
| --------------------------- | ------------------------------------ | ------------------------------------------------------------------------- |
| Mecanismo                   | `fork()` (procesos)                  | `pthread_create()` (hilos)                                                |
| Memoria                     | Cada proceso tiene su propio espacio | Los hilos comparten el espacio del proceso                                |
| Espera                      | `wait()`                             | `pthread_join()`                                                          |
| Identificación en la salida | PID de cada proceso                  | Etiqueta `[HILO 1]` / `[HILO 2]` (todos los hilos comparten el mismo PID) |

## Entorno

- Sistema operativo: macOS (entorno UNIX, autorizado por el profesor)
- Compilador: gcc (clang de Xcode Command Line Tools)
- Biblioteca: pthread

## Archivos

- `Hilos.c`: código fuente
- `salida.txt`: salida completa de una ejecución (20,000 líneas)

## Compilación y ejecución

```bash
gcc Hilos.c -o hilos -pthread
./hilos > salida.txt
```

## Nota sobre la salida

Los dos hilos se ejecutan de forma concurrente, por lo que sus líneas aparecen intercaladas y el orden cambia en cada ejecución. Es el comportamiento esperado, no un error. Se desactiva el búfer de `stdout` con `setvbuf` para que el intercalado se vea tal como ocurre.

Los hilos no comparten variables, por lo que no se requiere un mutex para este problema.
