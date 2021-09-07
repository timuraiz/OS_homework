#include <stdio.h>
#include <stdlib.h>


struct node {
    int value;
    struct node* next;
}typedef node;
struct LinkedLsit{
    node* head;
    int lenght;

}typedef LinkedList;
void add_begin(int data,struct LinkedLsit* list){
    node* new_node;
    new_node->value = data;
    new_node->next = list->head;
    list->head = new_node;
    list->lenght++;

}

void  insert_element(int data,struct LinkedLsit* list, int index){
    if (index > list->lenght || index < 0){
        return;
    }
    node* new_node = malloc(sizeof(new_node));
    if (index == 0){
       new_node->next = list->head;
       new_node->value = data;
       list->head = new_node;
        return;

    }
    int count = 0;
    node *itr = list->head;
    while (itr->next!= NULL){
        if (count == index - 1){
            new_node->value = data;
            new_node->next = itr->next;
            itr->next = new_node;
            list->lenght++;
            return;
        }
        itr = itr->next;
        count++;
    }
    if(index == list->lenght){
        new_node->value = data;
        new_node->next = NULL;
        itr->next = new_node;
        list->lenght++;
        return;
    }



}
void delete_node(int index, struct LinkedLsit* list){
    if (index < 0 || index >= list->lenght){
        return;
    }
    if (index == 0){
        list->head = list->head->next;
        list->lenght--;
        return;
    }
    int count = 0;
    node *itr = list->head;
    while (itr->next!= NULL){
        if (count == index - 1){
            itr->next = itr->next->next;
            list->lenght--;
            return;
        }
        itr = itr->next;
        count++;
    }
}

void print_list(struct LinkedLsit* list){
    node* itr = list->head;

    for(int i = 0; i < list->lenght;++i){
        printf("%d --> ", itr->value);
        itr = itr->next;
    }
}


int main() {

    struct LinkedLsit list;
    list.lenght = 0;
    node head;
    head.next = NULL;
    head.value = 7;
    list.head = &head;
    list.lenght++;

    insert_element(3,&list,1);// also possible to put nodes with index == list.length. They will be added to the tail
    insert_element(4,&list,2);
    insert_element(5,&list,3);
    insert_element(23,&list,2);




    print_list(&list);
    printf("\n");

    delete_node(0,&list);
    delete_node(3,&list);

    print_list(&list);






    return 0;
}
#include <stdio.h>
#include <stdlib.h>


struct node {
    int value;
    struct node* next;
}typedef node;
struct LinkedLsit{
    node* head;
    int lenght;

}typedef LinkedList;
void add_begin(int data,struct LinkedLsit* list){
    node* new_node;
    new_node->value = data;
    new_node->next = list->head;
    list->head = new_node;
    list->lenght++;

}

void  insert_element(int data,struct LinkedLsit* list, int index){
    if (index > list->lenght || index < 0){
        return;
    }
    node* new_node = malloc(sizeof(new_node));
    if (index == 0){
       new_node->next = list->head;
       new_node->value = data;
       list->head = new_node;
        return;

    }
    int count = 0;
    node *itr = list->head;
    while (itr->next!= NULL){
        if (count == index - 1){
            new_node->value = data;
            new_node->next = itr->next;
            itr->next = new_node;
            list->lenght++;
            return;
        }
        itr = itr->next;
        count++;
    }
    if(index == list->lenght){
        new_node->value = data;
        new_node->next = NULL;
        itr->next = new_node;
        list->lenght++;
        return;
    }



}
void delete_node(int index, struct LinkedLsit* list){
    if (index < 0 || index >= list->lenght){
        return;
    }
    if (index == 0){
        list->head = list->head->next;
        list->lenght--;
        return;
    }
    int count = 0;
    node *itr = list->head;
    while (itr->next!= NULL){
        if (count == index - 1){
            itr->next = itr->next->next;
            list->lenght--;
            return;
        }
        itr = itr->next;
        count++;
    }
}

void print_list(struct LinkedLsit* list){
    node* itr = list->head;

    for(int i = 0; i < list->lenght;++i){
        printf("%d --> ", itr->value);
        itr = itr->next;
    }
}


int main() {

    struct LinkedLsit list;
    list.lenght = 0;
    node head;
    head.next = NULL;
    head.value = 7;
    list.head = &head;
    list.lenght++;

    insert_element(3,&list,1);// also possible to put nodes with index == list.length. They will be added to the tail
    insert_element(4,&list,2);
    insert_element(5,&list,3);
    insert_element(23,&list,2);




    print_list(&list);
    printf("\n");

    delete_node(0,&list);
    delete_node(3,&list);

    print_list(&list);






    return 0;
}
