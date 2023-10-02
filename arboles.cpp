#include <iostream>
#include <cstdlib>

using namespace std;

// Julian David Ortiz Molina
// Arbol Binario - Insertar, Buscar y Recorridos

struct Node {
    int dato;
    Node* right;
    Node* left;
};

void options(Node*& tree);
Node* createNode(int valor);
void insert(Node*& tree, int valor);
bool buscar(Node* tree, int valor);
void deleteTree(Node* tree);
void preorden(Node* tree);
void inorden(Node* tree);
void posorden(Node* tree);
void eliminarValor(Node*& tree, int valor);
void mostrarArbol(Node* tree);

int main() {
    Node* tree = NULL;
    options(tree);
    deleteTree(tree);
    return 0;
}

void options(Node*& tree) {
    int dato, lista;

    do {
        cout << "\tOpciones\n" << endl;
        cout << "1. Insertar un nodo al arbol" << endl;
        cout << "2. Buscar un valor en el arbol" << endl;
        cout << "3. Realizar recorrido en preorden" << endl;
        cout << "4. Realizar recorrido en inorden" << endl;
        cout << "5. Realizar recorrido en posorden" << endl;
        cout << "6. Eliminar un valor del arbol" <<endl; 
        cout << "7. Mostrar todo el árbol" << endl;
        cout << "8. Salir\n" << endl;
        cout << "Opcion: ";
        cin >> lista;

        switch (lista) {
            case 1:
                cout << "\nDigite un valor para insertar: ";
                cin >> dato;
                insert(tree, dato);
                cout << "\n";
                break;
            case 2:
                cout << "\nDigite el valor a buscar: ";
                cin >> dato;
                if (buscar(tree, dato)) {
                    cout << "El valor " << dato << " se encontro en el árbol." << endl;
                } else {
                    cout << "El valor " << dato << " no se encontro en el árbol." << endl;
                }
                break;
            case 3:
                cout << "\nRecorrido en preorden: ";
                preorden(tree);
                cout << "\n";
                break;
            case 4:
                cout << "\nRecorrido en inorden: ";
                inorden(tree);
                cout << "\n";
                break;
            case 5:
                cout << "\nRecorrido en posorden: ";
                posorden(tree);
                cout << "\n";
                break;
            case 6:
    			cout << "\nDigite el valor a eliminar: ";
    			cin >> dato;
    			eliminarValor(tree, dato);
    			break;
    		case 7:
    			cout << "\nMostrar todo el árbol: ";
    			mostrarArbol(tree);
    			cout << "\n";
    			break;
        }
        system("pause");
        system("cls");
    } while (lista != 8);
}

Node* createNode(int valor) {
    Node* newNode = new Node();
    newNode->dato = valor;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

void insert(Node*& tree, int valor) {
    if (tree == NULL) {
        tree = createNode(valor);
    } else {
        if (valor < tree->dato) {
            insert(tree->left, valor);
        } else {
            insert(tree->right, valor);
        }
    }
}

bool buscar(Node* tree, int valor) {
    if (tree == NULL) {
        return false;
    }
    if (valor == tree->dato) {
        return true;
    } else if (valor < tree->dato) {
        return buscar(tree->left, valor);
    } else {
        return buscar(tree->right, valor);
    }
}

void deleteTree(Node* tree) {
    if (tree == NULL) return;
    deleteTree(tree->left);
    deleteTree(tree->right);
    delete tree;
}

void preorden(Node* tree) {
    if (tree == NULL) return;
    cout << tree->dato << " ";
    preorden(tree->left);
    preorden(tree->right);
}

void inorden(Node* tree) {
    if (tree == NULL) return;
    inorden(tree->left);
    cout << tree->dato << " ";
    inorden(tree->right);
}

void posorden(Node* tree) {
    if (tree == NULL) return;
    posorden(tree->left);
    posorden(tree->right);
    cout << tree->dato << " ";
}

Node* findMin(Node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

void eliminarValor(Node*& tree, int valor) {
    if (tree == NULL) {
        cout << "El valor " << valor << " no se encontró en el árbol." << endl;
        return;
    }

    if (valor < tree->dato) {
        eliminarValor(tree->left, valor);
    } else if (valor > tree->dato) {
        eliminarValor(tree->right, valor);
    } else {
        // Encontramos el nodo a eliminar
        if (tree->left == NULL && tree->right == NULL) {
            // Caso 1: Nodo sin hijos (hoja)
            delete tree;
            tree = NULL;
        } else if (tree->left == NULL) {
            // Caso 2: Nodo con un hijo a la derecha
            Node* temp = tree;
            tree = tree->right;
            delete temp;
        } else if (tree->right == NULL) {
            // Caso 2: Nodo con un hijo a la izquierda
            Node* temp = tree;
            tree = tree->left;
            delete temp;
        } else {
            // Caso 3: Nodo con dos hijos
            Node* temp = findMin(tree->right);
            tree->dato = temp->dato;
            eliminarValor(tree->right, temp->dato);
        }
        cout << "El valor " << valor << " ha sido eliminado del árbol." << endl;
    }
}

void mostrarArbol(Node* tree) {
    if (tree == NULL) return;
    
    cout << tree->dato << " ";
    
    mostrarArbol(tree->left);
    mostrarArbol(tree->right);
}
