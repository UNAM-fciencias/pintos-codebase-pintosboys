3.2. Preguntas (3 pto)

Incluye estas preguntas y sus respuestas en el archivo readme.

1. ¿Por qué el espacio virtual de memoria del Kernel esta junto al espacio virtual del proceso de
usuario?

RESPUESTA: Se debe a 3 principales puntos:

- Eficiencia: Al colocar el espacio virtual del kernel junto al espacio virtual del proceso de usuario, se evita la necesidad de cambiar constantemente entre diferentes espacios de direcciones durante las transiciones entre el modo kernel y el modo de usuario. 
Esto mejora la eficiencia del sistema operativo al evitar cambios frecuentes de contexto.

- Acceso a datos compartidos: Al tener el espacio virtual del kernel y el espacio virtual del proceso de usuario en la misma región de memoria, es más fácil para el kernel acceder y compartir datos con los procesos de usuario. 
Esto es especialmente útil cuando se necesita transferir información entre el kernel y los programas de usuario, como parámetros de llamadas al sistema o resultados de operaciones del kernel.

- Protección y seguridad: Al estar en el mismo espacio virtual, el kernel puede proteger su propia memoria y recursos del acceso no autorizado por parte de los procesos de usuario. 
Esto se logra mediante el uso de mecanismos de protección de memoria, como permisos de página y tablas de páginas, para controlar el acceso a las áreas del espacio virtual del kernel.


2. ¿De que forma se garantiza que un proceso de usuario solamente pueda acceder a su propia memoria?

RESPUESTA: Algunas de las tecnicas que se utilizan para logarlo son:

- Espacios virtuales separados: Cada proceso de usuario tiene asignado un espacio virtual separado y privado. Esto significa que cada proceso tiene su propia tabla de páginas que mapea las direcciones virtuales a direcciones físicas en memoria. 
Cada proceso tiene su propio rango de direcciones virtuales y no puede acceder directamente a la memoria de otros procesos.

- Permisos de página: En el espacio virtual de cada proceso, se asignan permisos de página para controlar el acceso a la memoria. Cada página de memoria puede tener permisos como lectura, escritura o ejecución, que se establecen en función de las necesidades del proceso. 
De esta manera, el proceso solo puede acceder a las páginas con los permisos adecuados.

- Tablas de páginas y protección: Cada proceso mantiene su propia tabla de páginas, que es una estructura de datos que mapea las direcciones virtuales a las direcciones físicas correspondientes y almacena información sobre los permisos de página. 
Estas tablas de páginas se utilizan para administrar y proteger la memoria del proceso, evitando que acceda a las páginas de otros procesos.

- Modo de usuario y modo kernel: Los procesadores modernos tienen modos de ejecución diferentes, como el modo de usuario y el modo kernel. Los procesos de usuario se ejecutan en el modo de usuario, mientras que el kernel se ejecuta en el modo kernel. 
El modo kernel tiene privilegios más altos y acceso directo a la memoria física y los recursos del sistema. El cambio entre modos se realiza mediante instrucciones privilegiadas que solo pueden ser ejecutadas por el kernel, lo que garantiza que los procesos de usuario no puedan acceder directamente a la memoria del kernel ni a los recursos protegidos.


3. ¿Por qué es el sistema operativo es el encargado de colocar los parámetros iniciales de un proceso?

RESPUESTA: El sistema operativo es responsable de administrar los recursos del sistema, incluyendo la asignación y gestión de la memoria. Al colocar los parámetros iniciales de un proceso en la memoria, el sistema operativo puede garantizar que los recursos necesarios para la ejecución del proceso estén disponibles y se utilicen de manera adecuada. 
Esto implica reservar espacio para los parámetros, copiarlos en la memoria y configurar adecuadamente las estructuras de datos necesarias para su acceso durante la ejecución del proceso.
Además al ser el encargado de colocar los parámetros iniciales de un proceso, el sistema operativo puede asegurarse de que no se produzcan accesos no autorizados a la memoria por parte del proceso o de otros procesos. El sistema operativo establece los permisos de acceso adecuados para los parámetros iniciales, garantizando que el proceso solo pueda acceder a ellos de manera segura y que no se corrompan o modifiquen inadvertidamente.


4. ¿En qué casos el sistema operativo no puede cargar un programa de usuario?

RESPUESTA: Algunos de estos casos son:

- Archivo ejecutable dañado: Si el archivo ejecutable del programa de usuario está dañado o tiene un formato incorrecto.

- Recursos insuficientes: Si el sistema operativo no tiene suficientes recursos disponibles, como memoria o espacio en disco.

- Dependencias faltantes: Si el programa de usuario depende de bibliotecas o archivos externos que no están presentes en el sistema.

- Permisos insuficientes: i el usuario que intenta ejecutar el programa no tiene los permisos adecuados para acceder al archivo ejecutable o a los recursos necesarios.


5. ¿Cual es la diferencia entre modo kernel y modo usuario del CPU?

RESPUESTA:
ChatGPT
La diferencia principal entre el modo kernel y el modo usuario del CPU radica en los privilegios y el nivel de acceso que tienen los programas en cada modo.

Modo Kernel:

-Tiene acceso completo y sin restricciones a los recursos del sistema, como la memoria 

-Puede ejecutar instrucciones privilegiadas que los programas en modo usuario no pueden ejecutar, como cambiar el estado de interrupciones, modificar tablas de páginas o acceder a dispositivos de hardware directamente.

-El código en modo kernel se ejecuta con el nivel más alto de privilegio y puede realizar cualquier operación permitida por el hardware y el sistema operativo.

Modo Usuraio:

- Tiene restricciones y acceso limitado a los recursos del sistema.

- No puede ejecutar instrucciones privilegiadas ni acceder directamente a recursos de hardware.

- El código en modo usuario se ejecuta con un nivel de privilegio más bajo y está restringido a un conjunto limitado de instrucciones y operaciones.
