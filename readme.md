# Sistemas Operativos

Repositorio con las tareas y prácticas de la materia de Sistemas Operativos,
Ingeniería en Sistemas Computacionales, ESCOM-IPN.

**Alumno:** [Tu nombre completo]
**Boleta:** [Tu boleta]
**Grupo:** [Tu grupo]
**Semestre:** [Semestre]

## Entorno de desarrollo

- Sistema operativo: macOS (entorno UNIX, autorizado por el profesor)
- Lenguaje: C
- Compilador: gcc (clang de Xcode Command Line Tools)

## Estructura del repositorio

```
Sistemas-Operativos/
├── README.md
└── Tarea-1/
    ├── README.md
    ├── Procesos.c
    └── salida.txt
```

## Cómo compilar y ejecutar

Cada tarea trae su propio README con instrucciones específicas. En general:

```bash
cd Tarea-1
gcc Procesos.c -o procesos
./procesos > salida.txt
```

## Notas

- Los programas se probaron en macOS. Al ser POSIX, deben compilar igual en Linux.
- Los binarios compilados no se incluyen en el repo (ver `.gitignore`).
