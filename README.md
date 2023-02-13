# Pintos Laboratorio de Sistemas Operativos

## Introduction
Este es el repositorio base para realizar las practicas del laboratorio del sitemas operativos

## Dependencias

Para poder ejecutar Pintos es necesario tener:

* Consola de comandos (bash para linux, terminal para MacOS, powershell windows)
* Docker y Docker deamon


## Instalación

Abrir una terminal y ejecutar el siguiente comando para entrar en el contenedor de Docker:

Para Linux/MacOS:
```bash
./docker-open-terminal
```

Para Windows, usar powershell y correr como administrador:
```powershell
# Sino se tienen permisos de ejecución de scripts
Set-ExecutionPolicy Unrestricted

& "./docker-open-terminal.ps1"
```

Para verificar la instalación:


1. Una vez dentro de la consola, ir al directorio `threads` y compilar el código:
```bash
cd /app/src/threads
make
```
2. Ejecutamos una prueba para revisar que todo está correcto:
```bash
cd /app/src/threads/build
pintos -q run alarm-single
# Para verificar si la prueba pasa:
make build/tests/threads/alarm-single.result
