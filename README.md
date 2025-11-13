🌳 Árbol Binario de Búsqueda Persistente en C

El programa implementa un árbol binario de búsqueda (ABB) en lenguaje C con la capacidad de guardar los datos en un archivo (arbol.txt) para que no se pierdan al cerrar el programa.
Permite insertar números, mostrar los distintos recorridos del árbol y borrar completamente su contenido.

🧩 Características principales

✅ Inserción de números uno por uno (controlada por el usuario).
✅ Visualización de los recorridos:

Inorder (ascendente)

Inorder (descendente)

Preorder

Postorder
✅ Opción para borrar todo el árbol y eliminar el archivo.
✅ Guardado automático de los datos en arbol.txt.
✅ Carga automática del árbol al iniciar el programa.

🖥️ Funcionamiento del menú

Cuando ejecutas el programa, aparece el siguiente menú:

=== MENÚ ÁRBOL BINARIO DE BÚSQUEDA ===
1. Agregar número
2. Recorridos del árbol
3. Borrar árbol completo
4. Salir
Seleccione una opción:

1️⃣ Agregar número

Permite ingresar números uno por uno.
Para terminar el ingreso, escribe una letra y presiona Enter.
Ejemplo:

Ingrese números. Para detener el ingreso, escriba una letra: 5
Ingrese números. Para detener el ingreso, escriba una letra: 3
Ingrese números. Para detener el ingreso, escriba una letra: 8
Ingrese números. Para detener el ingreso, escriba una letra: x
Datos guardados correctamente.


Los números se guardan automáticamente en el archivo arbol.txt.

2️⃣ Recorridos del árbol

Muestra los distintos recorridos del árbol actual:

Recorridos del árbol:
Inorder (ascendente): 3 5 8
Inorder (descendente): 8 5 3
Preorder: 5 3 8
Postorder: 3 8 5

3️⃣ Borrar árbol completo

Elimina todos los nodos del árbol y borra el archivo arbol.txt del disco.
Muestra:

Árbol borrado correctamente.

4️⃣ Salir

Guarda automáticamente los datos actuales y libera la memoria antes de cerrar el programa.

💾 Archivos generados

arbol.txt → Archivo donde se guardan los datos del árbol en orden ascendente (inorder).
Ejemplo de contenido:

3 5 8 10 15


Este archivo se usa para reconstruir el árbol automáticamente cuando el programa se vuelve a ejecutar.

⚙️ Compilación y ejecución

Compila el programa con gcc:

gcc Tree.c -o Tree


Luego ejecútalo:

./Tree

🧠 Estructura del código

El programa está dividido en las siguientes secciones:

Sección	Función
struct Nodo	Define la estructura del nodo del árbol.
crearNodo()	Crea un nuevo nodo.
insertar()	Inserta un número en el árbol respetando las reglas del ABB.
inorderAsc(), inorderDesc(), preorder(), postorder()	Realizan los distintos recorridos.
liberar()	Libera la memoria del árbol.
guardarArchivo() / guardarCambios()	Guardan el árbol en el archivo arbol.txt.
cargarArchivo()	Carga el árbol guardado al iniciar el programa.
main()	Controla el menú principal e interacción con el usuario.
🧹 Limpieza automática

Al elegir la opción “Salir”, el programa:

Guarda el estado actual del árbol.

Libera la memoria asignada.

Termina correctamente la ejecución.