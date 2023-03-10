// 2. (1,0 pt) A lista duplamente encadeada é composta por nós que possuem
// referências para o próximo nó e o nó anterior. A figura abaixo mostra como
// funciona a lista:
// Implemente as seguintes operações na linguagem C:
// a) remoção de um dado valor da lista
// b) impressão da lista do fim para o início

// 3. (1,5 pt) Implemente um método inverteOrdem, na linguagem C, que reverta a
// ordem dos elementos de uma lista simplesmente encadeada. Para implementar
// essa função, você não pode usar estruturas de dados auxiliares ou trocar os
// valores dos nós, isto é, só pode manipular os ponteiros de cada nó.

#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>

// definição da estrutura do nó da lista duplamente encadeada
struct node {
  int data;
  struct node *prev;
  struct node *next;
};

// função para remover um nó com um determinado valor da lista
void remove_node(struct node **head, int value) {
  // verifica se a lista está vazia
  if (*head == NULL) {
    printf("Lista vazia.\n");
    return;
  }

  struct node *current = *head;

  // percorre a lista até encontrar o nó com o valor desejado
  while (current != NULL && current->data != value) {
    current = current->next;
  }

  // verifica se o valor não foi encontrado na lista
  if (current == NULL) {
    printf("Valor não encontrado na lista.\n");
    return;
  }

  // atualiza as referências dos nós adjacentes ao nó removido
  if (current->prev != NULL) {
    current->prev->next = current->next;
  } else {
    // o nó removido era o primeiro da lista
    *head = current->next;
  }

  if (current->next != NULL) {
    current->next->prev = current->prev;
  }

  // libera a memória do nó removido
  free(current);
}

// função para imprimir os valores da lista
void print_list(struct node *head) {
  printf("Lista: ");
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

int main(void) {
  // Letra a)

  // cria a lista: 1 <-> 2 <-> 3 <-> 4
  struct node *n1 = malloc(sizeof(struct node));
  struct node *n2 = malloc(sizeof(struct node));
  struct node *n3 = malloc(sizeof(struct node));
  struct node *n4 = malloc(sizeof(struct node));

  n1->data = 1;
  n1->prev = NULL;
  n1->next = n2;

  n2->data = 2;
  n2->prev = n1;
  n2->next = n3;

  n3->data = 3;
  n3->prev = n2;
  n3->next = n4;

  n4->data = 4;
  n4->prev = n3;
  n4->next = NULL;

  struct node *head = n1;

  // imprime a lista original
  print_list(head);

  // remove o valor 3 da lista
  remove_node(&head, 3);

  // imprime a lista após a remoção
  print_list(head);

  // libera a memória dos nós da lista
  free(n1);
  free(n2);
  free(n3);
  free(n4);

  return 0;
}