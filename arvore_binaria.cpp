/*  Falta o método para desenhar a árvore
    Falta o método de inserção
    Criado após uma noite estudando python e desistindo
    ~By: L.M 02/04/2020 ~ 03/04/2020
*/

#include <array>
#include <vector>
#include <iostream>
#include <locale.h>
using namespace std;

struct Node {
    int data; //valor do nó
    struct Node *left, *right;
};

Node* newNode(int value) {
    Node* node = new Node;

    node->data = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

//Apaga a árvore
void deleteTree(Node* root) {
    if (root != NULL) {
        deleteTree(root->left);//chama recursivamente o nó a esquerda
        deleteTree(root->right); //chama recursivamente o nó a direita
        delete root;
    }
}

//Mostra o nó em ordem
void showInOrder(Node* root) {
    if (root != NULL) {
        showInOrder(root->left);//chama recursivamente o nó a esquerda
        cout<<" | "<<root->data<<" | "; //printa o conteúdo do nó
        showInOrder(root->right); //chama recursivamente o nó a direita
    }
}

//Mostra em pós-ordem
void showPostOrder(Node* root) {
    if (root != NULL) {
        showPostOrder(root->left);//chama recursivamente o nó a esquerda
        showPostOrder(root->right); //chama recursivamente o nó a direita
        cout<<" | "<<root->data<<" | ";; //printa o conteúdo do nó
    }
}
//Mostra em pós-ordem
void showPreOrder(Node* root) {
    if (root != NULL) {
        cout<<" | "<<root->data<<" | ";; //printa o conteúdo do nó
        showPreOrder(root->left);//chama recursivamente o nó a esquerda
        showPreOrder(root->right); //chama recursivamente o nó a direita
    }
}

//Mostra o percurso em extensao
void showExtensionOrder(Node* root, vector <Node*> nodeArr, int index = -1) {
    //index do vetor, onde deve iniciar... padrão = -1
    if (root != NULL) {
        cout<<"|"<<root->data<<"|  ";
        if(root->left != NULL)//verifica se há elementos a esquerda
            nodeArr.push_back(root->left); //se sim, adiciona ao array de nós
        if(root->right != NULL)//verifica se há elementos a direita
            nodeArr.push_back(root->right); //se sim, adiciona ao array de nós
        index = index+1;
        showExtensionOrder(nodeArr[index], nodeArr,index);
        
    }
}

Node* insertBinTree (Node* root,  int value,  Node* ant = NULL) {
    if(root == NULL) {
        if(ant == NULL) {
            root = newNode(value);
            return root;
        } else
            if(ant->data > value)
                ant->left = newNode(value);
            else
                ant->right = newNode(value);
    } else { 
        Node* ant = root;
        if(root->data > value)
            insertBinTree(root->left, value, ant);
        else
            insertBinTree(root->right, value, ant);
    }
    return NULL;
}

int buscaArvore(Node *node, int value, int altura = 0) {
    if(node == NULL)
        return -1;
    else
        if(node->data < value) {
            if(node->left != NULL)
                altura = altura + 1;
           buscaArvore(node->left, value);
        } else if(node->data > value) {
            if(node->right != NULL)
                altura = altura + 1;
           buscaArvore(node->right, value);
        } else {
            cout<<"ALtura"<<altura;
        }
    
    
}


int main() {
    setlocale(LC_ALL, "Portuguese");
    std::vector <Node*> nodeArr; 
    int opcao;
    int value;
    int numeros[4] = {1,2,4,5};
    Node* tree = NULL;

    //menu de opcões da árvore
    cout<<"Programa de execucao de arvore binaria de busca!"<<endl;
    do {
        cout<<"\n------------Opcoes--------------------"<<endl;
        cout<<"\n\t1-Inserir"<<endl;
        cout<<"\n\t2-Exclusao"<<endl;
        cout<<"\n\t3-Balanceamento"<<endl;
        cout<<"\n\t4-Mostrar altura"<<endl;
        cout<<"\n\t5-Busca"<<endl;
        cout<<"\n------------Mostrar arvore--------------------"<<endl;
        cout<<"\n\t6-Em ordem | 7 - Pos ordem | 8 - Pre-ordem | 9 - Em extensao"<<endl;
        cout<<"\n\t0-Sair"<<endl;
        cin>>opcao;

        switch(opcao) {
            case 1 :
                cout<<"Insira o valor:"<<endl;
                cin>>value;
                if(tree == NULL)
                    tree = insertBinTree(tree, value);
                else
                    insertBinTree(tree, value);
                break;
            case 6:
            cout<<"\n------------Mostrar arvore em ordem--------------------"<<endl;
                showInOrder(tree);
                break;
            case 7:
            cout<<"\n------------Mostrar arvore em pos ordem--------------------"<<endl;
                showPostOrder(tree);
                break;
            case 8:
            cout<<"\n------------Mostrar arvore em pre ordem--------------------"<<endl;
                showPreOrder(tree);
                break;
            case 9:
            cout<<"\n------------Mostrar arvore em extensao--------------------"<<endl;
                showExtensionOrder(tree, nodeArr);
                break;
            default:
                break;
        }

        cout<<"\n\tContinuar executando?\n\t 1 - sim | 0 - nao"<<endl;
        cin>>opcao;


    } while(opcao != 0);
    
    deleteTree(tree); //desaloca os elementos na memória
    nodeArr.clear();
    
    //para o uso do percurso em largura
    //monta a árvore:
    /*
            5
          /   \
         3     7
        / \     \
       1   4      9
    */
    /* Node* tree = newNode('5');
     tree->left = newNode('3');
     tree->right = newNode('7');
     tree->left->left = newNode('1');
     tree->left->right = newNode('4');
     tree->right->right = newNode('9');
     */
    //arvore - alfabeto
    /*Node* tree = newNode('F');
    esquerda
    tree->left = newNode('B');
    tree->left->left = newNode('A');
    tree->left->right = newNode('D');
    tree->left->right->left = newNode('C');
    tree->left->right->right = newNode('E');
    //direita
    tree->right = newNode('G');
    tree->right->right = newNode('I');
    tree->right->right->left = newNode('H');
    
    cout<<"Em ordem:"<<endl;
    showInOrder(tree);

    cout<<"\nPós ordem:"<<endl;
    showPostOrder(tree);

    cout<<"\nPré ordem:"<<endl;
    showPreOrder(tree);

    cout<<"\nPercurso em extensão:"<<endl;
    showExtensionOrder(tree, nodeArr, -1);
*/


    // for(int i = 0; i < 4; i++)
    //     insertBinTree(tree, numeros[i]);

/*    
    tree->left = newNode(2);
    tree->right = newNode(10);
    tree->left = newNode(4);
    tree->right = newNode(8);
    tree->left = newNode(81);
*/
    return 0;
}



