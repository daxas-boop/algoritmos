# Problema de conectividad
Se quiere implementar un programa que permita determinar si dos elementos, p y q, están conectados.
Puede suponerse que estos dos elementos son números enteros. 
También podemos ponerle un límite a este conjunto de números enteros: los números enteros del 0 al 7.

El programa recibirá por entrada estándar dos enteros y los procesa de la siguiente manera:
- Si no estaban unidos los vuelve a imprimir a los dos por pantalla y los une
- Si ya estaban unidos no realiza ninguna acción
- El programa termina cuando el usuario deja de ingresar valores.

Ejemplo de una ejecución del programa.

| Ingreso  | Salida esperada  | Explicacion  |   
|---|---|---|
| (2,3)  | 2-3  | 2 y 3 no estaban conectados, ahora están conectados  |
| (3,2)  |  -   | No hay salida porque 3 y 2 están conectados, ya que las relaciones son conmutativas |
| (3,1)  | 3-1  | No estaban conectados, ahora están conectados |
| (1,2)  |  -   | Están conectados del siguiente modo: 1-3-2. Las conecciones son transitivas |
| (6,7)  | 6-7  | No estaban conectados, ahora están conectados |
| (5,5)  |  -   | El 5 ya está conectado consigo mismo. Las conexiones son reflexivas |
