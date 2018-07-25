


### Listas

#### Inserción por la cabeza

1. Crear el nuevo nodo (reservar memoria).
2. Almacenar el dato en el campor correspondiente
3. Como este nuevo nodo va a ser el primero, su campo enlace deberá apuntar
al hasta ahora primer nodo (nodo cabesa).
4. Por último el enlace externo (lista), no perteneciente a ningún nodo
y que apunta al primer nodo de la lista, debera apuntar ahora al nuevo nodo.

#### Inserción por detrás
##### Con elementos en la lista

Para insertar por detrás debemos de llegar hasta el final y hacer la
inserción.
+ Se crea un nuevo nodo
+ Se introducen los nuevos datos en el campo *datos* del nodo
+ Se asigna NULL al campo enlace, ya que se posicionará al final.
+ Se recorre la lista hasta que el enlace de *actual* sea NULL (implica
que es el último).
+ En este momento, se quedaría  el nodo actual apuntando a NULL.

Por último se realiza el enlace entre el elemento de la lista y el nuevo nodo

##### Lista vacia

En el caso de que la lista esté vacía, se debe de comprobar realizando una
llamada al método correspondiente y en caso de que esté vacía, el nodo
actual se colocaría como nodo inicial (con el enlace a NULL) y a volar

##### Suprimir por cabeza

1. Se almacena la dirección de este primer elemento, apuntado por la
variable lista, en un puntero *auxiliar*.
2. Se asigna al parametro formal dato, el valor almacenado en el elemento a
eliminar.
3. Se realiza la asignación de la lista al nuevo primer elemento.
4. Se libera memoria del nodo que ya no pertenece a la lista.
