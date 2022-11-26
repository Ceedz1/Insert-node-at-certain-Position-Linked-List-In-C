#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct node{
    int data;
    struct node *next;
}node, *Dlist;

Dlist insertFirst(Dlist *head);
Dlist inputList(Dlist temp);
Dlist displayList(Dlist head);
Dlist insertAtPos(Dlist *head);

int main(){
    int choose = 0;
    Dlist head;
    head = NULL;

    do{
        printf("\n\nMenu Operation\n");
        printf("----------------\n");
        printf("[1] Insert First\n");
        printf("[2] Display List\n");
        printf("[3] Insert at Position\n");
        printf("----------------\n");

        printf("\nEnter Operation: ");
        scanf("%d", &choose);

        switch(choose){
            case 1:
                insertFirst(&head);
                getch();
                system("cls");
                break;
            case 2:
                displayList(head);      
                getch();
                system("cls");
                break;
            case 3:
                insertAtPos(&head);
                getch();
                system("cls");
                break;
            default:
                break;
        }
    }while(choose);
    return 0;
}

//Populate list function----------------------------------------------
Dlist insertFirst(Dlist *head){
    Dlist temp;                     //we declare temp var here
    temp = inputList(temp);         //we call inputList and pass temp
    temp->next = *head;
    *head = temp;
}

//Input function (Data)-----------------------------------------------
Dlist inputList(Dlist temp){
    temp = malloc(sizeof(node));
    
    if(temp != NULL){
        printf("\nEnter Data: ");
        scanf("%d", &temp->data);
        temp->next = NULL;
    }else{
        printf("error");
    }
    return temp;
}

//Display the list function-------------------------------------------
Dlist displayList(Dlist head){
    Dlist current;                //current will traverse the list by node

    if(head == NULL){
        printf("\nList is Empty");
    }else{
        printf("\nList:");           
        for(current = head; current!=NULL; current = current->next){
            printf("\n%d", current->data);
        }
    }
}

Dlist insertAtPos(Dlist *head){
    Dlist current = *head;
    Dlist temp;
    int pos = 0;

    printf("\nEnter Position: ");
    scanf("%d", &pos);

    temp = inputList(temp);

    pos--;
    while(pos!=1){
        current=current->next;
        pos--;
    }
    temp->next = current->next;
    current->next = temp;
}