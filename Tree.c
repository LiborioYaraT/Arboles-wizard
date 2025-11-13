#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Nodo {
    int dato;
    struct Nodo *izq, *der;
};

// Crear nodo
struct Nodo* crearNodo(int dato) {
    struct Nodo* nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo->dato = dato;
    nuevo->izq = nuevo->der = NULL;
    return nuevo;
}

// Insertar en árbol binario de búsqueda
struct Nodo* insertar(struct Nodo* raiz, int dato) {
    if (raiz == NULL) return crearNodo(dato);
    if (dato < raiz->dato)
        raiz->izq = insertar(raiz->izq, dato);
    else
        raiz->der = insertar(raiz->der, dato);
    return raiz;
}

// Recorridos
void inorderAsc(struct Nodo* raiz) {
    if (raiz) {
        inorderAsc(raiz->izq);
        printf("%d ", raiz->dato);
        inorderAsc(raiz->der);
    }
}

void inorderDesc(struct Nodo* raiz) {
    if (raiz) {
        inorderDesc(raiz->der);
        printf("%d ", raiz->dato);
        inorderDesc(raiz->izq);
    }
}

void preorder(struct Nodo* raiz) {
    if (raiz) {
        printf("%d ", raiz->dato);
        preorder(raiz->izq);
        preorder(raiz->der);
    }
}

void postorder(struct Nodo* raiz) {
    if (raiz) {
        postorder(raiz->izq);
        postorder(raiz->der);
        printf("%d ", raiz->dato);
    }
}

// Liberar memoria
void liberar(struct Nodo* raiz) {
    if (raiz) {
        liberar(raiz->izq);
        liberar(raiz->der);
        free(raiz);
    }
}

// Guardar árbol en archivo (inorder)
void guardarArchivo(struct Nodo* raiz, FILE *archivo) {
    if (raiz) {
        guardarArchivo(raiz->izq, archivo);
        fprintf(archivo, "%d ", raiz->dato);
        guardarArchivo(raiz->der, archivo);
    }
}

// Cargar árbol desde archivo
struct Nodo* cargarArchivo(struct Nodo* raiz) {
    FILE *archivo = fopen("arbol.txt", "r");
    if (!archivo) return NULL;
    int dato;
    while (fscanf(archivo, "%d", &dato) == 1) {
        raiz = insertar(raiz, dato);
    }
    fclose(archivo);
    return raiz;
}

// Guardar cambios
void guardarCambios(struct Nodo* raiz) {
    FILE *archivo = fopen("arbol.txt", "w");
    if (archivo) {
        guardarArchivo(raiz, archivo);
        fclose(archivo);
    }
}

int main() {
    struct Nodo* raiz = NULL;
    int opcion, num;
    char entrada[100];

    // Cargar árbol guardado
    raiz = cargarArchivo(raiz);

    do {
        printf("\n=== MENÚ ÁRBOL BINARIO DE BÚSQUEDA ===\n");
        printf("1. Agregar número\n");
        printf("2. Recorridos del árbol\n");
        printf("3. Borrar árbol completo\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar();

        switch(opcion) {
            case 1:
                while (1) {
                    printf("Ingrese números. Para detener el ingreso, escriba una letra: ");
                    if (scanf("%s", entrada) != 1) break;
                    if (!isdigit(entrada[0])) break;
                    num = atoi(entrada);
                    raiz = insertar(raiz, num);
                }
                getchar();
                guardarCambios(raiz);
                printf("Datos guardados correctamente.\n");
                break;

            case 2:
                if (raiz == NULL) {
                    printf("El árbol está vacío.\n");
                } else {
                    printf("\nRecorridos del árbol:\n");
                    printf("Inorder (ascendente): ");
                    inorderAsc(raiz);
                    printf("\nInorder (descendente): ");
                    inorderDesc(raiz);
                    printf("\nPreorder: ");
                    preorder(raiz);
                    printf("\nPostorder: ");
                    postorder(raiz);
                    printf("\n");
                }
                break;

            case 3:
                liberar(raiz);
                raiz = NULL;
                remove("arbol.txt");
                printf("Árbol borrado correctamente.\n");
                break;

            case 4:
                guardarCambios(raiz);
                liberar(raiz);
                printf("Saliendo...\n");
                break;

            default:
                printf("Opción no válida.\n");
        }
    } while (opcion != 4);

    return 0;
}
