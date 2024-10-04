#include "linked_list.h"

int nrOfNodes = 0;

void list_init(Node** head, size_t size){
    mem_init(size);
    *head = NULL;
}

void list_insert(Node** head, uint16_t data){
  Node* theNode = mem_alloc(sizeof(Node));
  theNode->data = data;
  theNode->next = NULL;
  if(theNode==NULL){printf("ERROR");}

  if(*head == NULL){
    *head = theNode;
  }
  else{
    Node* walkerNode = *head;
    while(walkerNode->next != NULL){
      walkerNode = walkerNode->next;
    }
    walkerNode->next = theNode;
  }
}

void list_insert_after(Node* prev_node, uint16_t data){
  Node* theNode = mem_alloc(sizeof(Node));
  theNode->data = data;
  theNode->next = prev_node->next;
  prev_node->next = theNode;
}

void list_insert_before(Node** head, Node* next_node, uint16_t data){
  Node* theNode = mem_alloc(sizeof(Node));
  theNode->data = data;
  
  if(*head == next_node){
    theNode->next = *head;
    *head = theNode;
  }
  else{
    Node* walkerNode = *head;
    while(walkerNode->next != NULL && walkerNode->next != next_node){
      walkerNode = walkerNode->next;
    }
    walkerNode->next = theNode;
    theNode->next = next_node;
  }
}

void list_delete(Node** head, uint16_t data){
  if(*head == NULL){
    printf("det finns inga nodes");
    return NULL;
  }
  else if((*head)->data == data){
    Node* nexthead = (*head)->next;
    mem_free((*head));
    *head = nexthead;
  }
  else{
    Node* walkerNode = *head;
    Node* prevNode;
    while(walkerNode->next != NULL && walkerNode->data != data){
      prevNode = walkerNode;
      walkerNode = walkerNode->next;
    }
    if(walkerNode->next == NULL && walkerNode->data != data){
      printf("the node you look for does not exist");
      return NULL;
    }
    else{
      prevNode->next = walkerNode->next;
      mem_free(walkerNode);
    }
  }
}

Node* list_search(Node** head, uint16_t data){
  Node* walkerNode = *head;
  while(walkerNode->next != NULL && walkerNode->data != data){
    walkerNode = walkerNode->next;
  }
  if(walkerNode->next == NULL && walkerNode->data != data){
      printf("the node you look for does not exist");
      return NULL;
    }
  else{
    return walkerNode;
  }
}

void list_display(Node** head){
  list_display_range(*head, NULL, NULL);
}

void list_display_range(Node** head, Node* start_node, Node* end_node){
  Node* walkerNode = *head;
  bool inRange = false;

  printf("[");
  if(start_node == NULL){
    start_node = *head;
  }

  while(walkerNode->next != NULL){

    walkerNode = walkerNode->next;

    if(walkerNode->data == start_node->data){
      inRange = true;
      printf("%d", walkerNode->data);
    }
    if(walkerNode->data == end_node->data){
      inRange = false;
    }
    if(inRange == true && walkerNode->data != start_node->data){
      printf(", %d", walkerNode->data);
    }
  }
  printf("]");
}

int list_count_nodes(Node** head){
  int amount = 0;
  Node* walkerNode = *head;
  while(walkerNode->next != NULL){
    amount++;
    walkerNode = walkerNode->next;
  }
  return amount;
}

void list_cleanup(Node** head){
  mem_deinit();
  *head = NULL;
}
