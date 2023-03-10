1. La función running_thread obtiene el struct thread del hilo en ejecución, la función utiliza el valor del registro esp para obtener la estructura. ¿Por que no se utiliza una variable global tipo apuntador que contenga el apuntador del hilo en ejecución y cuando el hilo cambia solamente cambiar el apuntador por el nuevo hilo?

    Para comenzar, el uso de variables globales es peligroso(delicado) en cualquier lenguaje de programación. Al utilizar una variable global para almacenar el apuntador al hilo lo que se puede ocasionar son:
        - Condiciones de carrera.
        - Que se quiera modificar simultaneamente generando inconsistencias y errores.
    Esto solo generaría problemas de concurrencia  y sincronización.

2. La función switch_threads es la encargada de cambiar de ejecución un hilo por otro. En resumen, la función sustituye los valores de ciertos registros. El registro EIP (Instruction Pointer o Program Counter) guarda el valor de la siguiente instrucción a ejecutar. ¿Por qué la función switch_threads no sustituye dicho registro?

        Se debe a que la función no manipula ese registro, su manipulación es hecha mediante la instrucción ret en la pila. 

3. De las dos técnicas para implementar el calendarizador de prioridades: mantener la lista ordenada o buscar el máximo. ¿Cúal es más factible utilizar? y ¿Por qué?

    Ambas técnicas para implementar el calendarizador de prioridades tienen sus ventajas y desventajas. La técnica de mantener la lista ordenada es más eficiente cuando se realizan muchas inserciones y eliminaciones de elementos en la lista, ya que mantener la lista ordenada permite insertar y eliminar elementos en tiempo O(1) en el mejor caso y O(n) en el peor caso. Además, esta técnica también es útil cuando se necesita acceder frecuentemente al elemento de mayor prioridad, ya que se encuentra en el frente de la lista.

    Por otro lado, la técnica de buscar el máximo es más eficiente cuando se realizan muchas operaciones de búsqueda en la lista, ya que solo se necesita recorrer la lista en busca del elemento de mayor prioridad en el momento en que se necesita. Sin embargo, esta técnica puede ser menos eficiente cuando se realizan muchas inserciones y eliminaciones de elementos, ya que cada vez que se inserta o elimina un elemento, se debe recorrer toda la lista para encontrar el nuevo elemento de mayor prioridad.