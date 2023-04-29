4. Preguntas (3 pts)


1. Describe tu solución a detalle.

Respuesta:
En nuestro caso para empezar el padre de nuestra rama es la practica01 ya que nos acomodamos más trabajando con un lista que con un arreglo. A grandes rasgos podemos resumir lo que hicimos a continuación:
-Comenzamos por declarar estas variables en thread.h:
	int priorities[9];        /* Lista de prioridades donadas */
	int size;                 /* Tamaño de la lista de prioridades donadas */
	int donation_number;      /* Número de locks que están donando su prioridad */
	struct lock *waiting_for; /* Lock para el cual el hilo está bloqueado esperando */
-También declaramos la siguiente variable en synch.h:
	bool is_donated; /* Verifica si el lock ha sido donado a un hilo o no */

- Modificamos la funcion thread_set_priority:
	En esta modificación, la nueva prioridad del hilo se guarda en el primer elemento del arreglo priorities dentro de la estructura thread. Si el hilo solo tiene un semáforo o un lock 
	en su lista de semáforos o locks bloqueados (size es igual a 1), la prioridad del hilo se actualiza a la nueva prioridad y se llama a thread_yield(), lo que hace que el hilo ceda 
	el CPU al hilo con la mayor prioridad.

- Modificamos la función lock_aquire:
	Esta modificación de lock_acquire() implementa la sincronización por donación de prioridades, donde un hilo que está bloqueando un lock dona su prioridad al hilo que está esperando 
	a adquirir ese lock. Esto asegura que el hilo en espera obtenga el lock lo antes posible, en lugar de esperar a que se desbloquee en algún momento en el futuro.
- Modificamos la función lock_release:
	 Esta modificación de lock_release() implementa la eliminación de la donación de prioridades, donde se elimina la prioridad donada por un hilo cuando se libera un lock. Esto asegura
	 que la prioridad de un hilo se restablezca a su valor original cuando ya no necesita esperar por un lock y permite que otros hilos puedan obtener ese lock de manera justa.
-Modificamos la funcion cond_signal:
	La modificación agregada implementa un mecanismo de "ordenación por semáforos" para asegurarse de que los hilos en espera se despierten en el orden correcto en función de la prioridad
	de cada hilo. Además, se utiliza un bucle while para despertar a todos los hilos en espera, y no solo a uno, para evitar posibles inanición.

2. La implementación de semáforos de pintos utiliza un while en lugar de un if, explica porque es
necesario esto.

Respuesta: La implementación de semáforos en Pintos utiliza un while en lugar de un if para evitar la llamada a dormir y despertar procesos innecesarios. Esto se debe a que los semáforos son una herramienta importante para la sincronización y la comunicación entre procesos en un sistema operativo.

Cuando un proceso intenta adquirir un semáforo que ya está en uso, se coloca en una lista de espera asociada al semáforo. El uso de un "if" en este caso significaría que el proceso solo comprobaría una vez si el semáforo está disponible, y si no lo está, se bloquearía y se llamaría a la función "sleep" para esperar a que se libere el semáforo.

En cambio, el uso de un "while" significa que el proceso seguirá comprobando si el semáforo está disponible hasta que finalmente lo esté. Esto evita la llamada innecesaria a "sleep" y reduce el tiempo de espera para el proceso, ya que el proceso se reanudará tan pronto como el semáforo esté disponible.

Por lo tanto, el uso de un "while" en la implementación de semáforos en Pintos ayuda a garantizar la eficiencia y la rapidez en la sincronización y comunicación entre procesos.






3. ¿Por qué es mejor utilizar primitivas de sincronización en lugar de apagar y encender la interrup-
ciones directamente?

Respuesta: Cuando se apagan las interrupciones directamente, se deshabilita temporalmente el procesamiento de interrupciones en el sistema, lo que puede provocar una inestabilidad en el funcionamiento del sistema y una posible pérdida de datos. Además, apagar y encender las interrupciones puede ser una solución ineficiente, ya que requiere tiempo y recursos para desactivar y luego volver a activar las interrupciones.

Por otro lado, las primitivas de sincronización, como semáforos y monitores, proporcionan una forma más segura y eficiente de sincronizar los procesos y garantizar que los datos se compartan correctamente entre ellos. Estas primitivas se diseñan específicamente para evitar la inestabilidad del sistema y garantizar una sincronización precisa y segura entre los procesos.

Además, las primitivas de sincronización también son herramientas más flexibles y pueden ser utilizadas por diferentes procesos para resolver diferentes problemas de sincronización.




4. En pintos un lock es un semaphore inicializado en 1 ¿Por qué no usar directamente un semaphore?

Respuesta: Los locks se utilizan para asegurar que sólo un proceso tenga acceso a un recurso compartido en un momento dado (exclusión mutua). Por otro lado, los semáforos se utilizan para controlar el acceso a un recurso compartido cuando hay más de un recurso disponible, lo que se conoce como sincronización.

Inicializar un semáforo en 1 significa que el semáforo se puede adquirir una sola vez antes de que se bloquee, lo que equivale a la semántica de un lock. Sin embargo, la implementación de un lock como un semáforo inicializado en 1 es más eficiente en términos de memoria y de uso del procesador que la implementación de un semáforo. Esto se debe a que el lock no necesita mantener una lista de espera de procesos, ya que sólo un proceso puede adquirir el lock a la vez.

Además, en Pintos, los locks y los semáforos son tipos de datos distintos, y el uso de un lock inicializado como un semáforo simplifica la implementación y evita la necesidad de crear un nuevo tipo de datos.
