INTEGRANTES:
    Pérez Jacome David
    Rosales Jaimes Victor


Preguntas:

1. Pintos es un Kernel para un sistema con un solo núcleo, ¿Qué cambios deberían hacerse en su
proceso de inicialización (booting) para que funcione en un sistema multi nucleo?

    Como tal no hay una respuesta correcta para esta pregunta, pero podriamos tratar de responderla ya sea que agreguemos
    un calendarizador o que simplemente activemos los demás nucleos.

2. ¿Para qué sirve el stack de un proceso?

    Para alamacenar las variables locales del proceso y los estados.

3. ¿Qué diferencia hay entre el thread idle y el thread main?

    La diferencia es que el thread main es para que el proceso sea ejecutado, mientras que el idle no muere.

4. Si suponemos que solamente existe un thread en ejecución y dicho thread se bloquea (utilizando la
función thread_block). ¿De que forma se podrá despertar el thread si es el único en ejecución?

    thread_unblock lo desbloquearía para reanudarse.
