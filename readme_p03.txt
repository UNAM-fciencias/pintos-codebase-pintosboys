1. ¿Por qué no utilizamos para el valor load_average simplemente el número de threads de la
ready_list?

    R= Porque queremos tener la información completa del último minuto y no soló la información del 
    instante de la ready_list.


2. ¿Por qué razón al utilizar el módulo de punto flotante vuelve más lento al kernel?

    R= Porque sabemos que Pintos no guarda el estado de registro de las operaciones de punto 
    flotante en los threads, por lo tanto si utulizamos el módulo de punto flotante se tendria que guardar dicha información lo cual vuelve mas lento al kernel.


3. ¿Como garantiza tu solución que los threads bloqueados (los que no están en la read\_list)
aumentan su prioridad cuando se desbloquean?

    R= el algoritmo de planificación MLFQ en Pintos garantiza que los hilos bloqueados aumenten su prioridad cuando se desbloquean utilizando un enfoque de prioridad en espera y ajustando su prioridad según el tiempo que han estado esperando en la cola de bloqueados. Esto asegura que todos los hilos tengan una 
    oportunidad justa de ejecutarse en el sistema operativo.

4. En la práctica 1 cambiaste la implementación de timer_sleep para que no se utilizara una es-
pera ocupada. ¿Una implementación de timer_sleep con espera ocupada afectaría en algo a tu
implementación del calendarizador MLFQ?

    R= Sí, una implementación de timer_sleep con espera ocupada podría afectar a la implementación del calendarizador MLFQ en Pintos.

La razón es que cuando un hilo usa la espera ocupada, está utilizando activamente los recursos del procesador mientras espera a que transcurra un tiempo determinado. Esto puede hacer que otros hilos en la cola de listos tengan que esperar más tiempo para ejecutarse, lo que afectaría 
negativamente a la eficiencia, el uso de espera ocupada en la implementación de timer_sleep podría provocar que los hilos en la cola de listos que tienen una prioridad más alta se vean bloqueados en espera de recursos del procesador que están siendo utilizados por hilos que están esperando en espera ocupada. Como resultado, estos hilos de alta prioridad pueden experimentar un retraso en su ejecución, lo que afectaría la capacidad del sistema operativo para responder de manera rápida y eficiente a las 
solicitudes de los usuarios.


5. ¿Tu implementación afecta en algo la propiedad preemptive del calendarizador?

    R= No.