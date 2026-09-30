# Tarea 1: Programa que crea procesos

**Materia:** Sistemas Operativos
**Alumno:** Moreno Saenz Sebastian
**Boleta:** 2025630357
**Grupo:** 4CM1

## Descripción

Programa en C que usa la llamada al sistema `fork()` para crear un proceso hijo.

- **Proceso padre:** imprime los números del 1 al 10,000.
- **Proceso hijo:** imprime los números del 10,000 al 1.

El padre espera al hijo con `wait()` para evitar procesos zombie.

## Entorno

- Sistema operativo: macOS (entorno UNIX), autorizado por el profesor
- Compilador: gcc (clang de Xcode Command Line Tools)

## Archivos

- `Procesos.c`: código fuente
- `salida.txt`: salida completa de una ejecución (20,000 líneas)

## Compilación y ejecución

```bash
gcc Procesos.c -o procesos
./procesos > salida.txt
```

## Nota sobre la salida

Como padre e hijo se ejecutan de forma concurrente, las líneas de ambos procesos
aparecen intercaladas y el orden cambia en cada ejecución. Es el comportamiento
esperado, no un error. Cada línea lleva la etiqueta `[PADRE pid]` o `[HIJO pid]`
para distinguir qué proceso la imprimió.
