#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* head=NULL;
struct Node* createNode(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
void insertNodeInBeg(int data){
    struct Node * newNode = createNode(data);
    if(head == NULL){
        head = newNode;
    }
    else{
        newNode->next = head;
        head  = newNode;
    }
    printf("Node inserted !!!\n");
}
void insertNodeAtEnd(int data){
    struct Node * newNode = createNode(data);
    if(head == NULL){
        head = newNode;
    }
    else{
        struct Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Node inserted !!!\n");
}
void insertNodeAtAnyPos(int data, int pos){ // here position is 0-base
    if(head == NULL){
        printf("List is empty !!!\n");
    }
    else if(pos == 0){
        insertNodeInBeg(data);
    }
    else{
        struct Node* temp = head;
        int i = 0;
        while(temp != NULL){
            if(i == pos-1)
                break;
            temp = temp->next;
            i++;  
        }
        if(temp == NULL || temp->next==NULL){
            printf("Invalid position!!!\n");
        }
        else{
            struct Node* newNode = createNode(data);
            newNode->next = temp->next;
            temp->next = newNode;
            printf("Node Inserted !!!\n");
        }
    }
}
void deleteNodeFromBeg(){
    if(head == NULL)
        printf("List is empty !!!\n");
    else{
        head = head->next;
        printf("Node deleted !!!\n");
    }
}
void deleteNodeFromEnd(){
    if(head == NULL)
        printf("List is empty !!!\n");
    else if(head->next == NULL){ // only single node
        head = NULL;
    }
    else{
        struct Node* temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        temp->next = NULL;
        printf("Node deleted !!!\n");
    }
}
void deleteNodeFromAnyPos(int pos){ // Here position is 0 base
    if(head == NULL)
        printf("List is empty !!!\n");
    else if(pos == 0)
        deleteNodeFromBeg();
    else{
        struct Node* temp =  head;
        int i = 0;
        while(temp != NULL){
            if(i == pos-1)
                break;
            temp = temp->next;
            i++;
        }
        if(temp == NULL || temp->next == NULL)
            printf("Invalid position !!!\n");
        else{
            temp->next = temp->next->next;
            printf("Node deleted !!!\n");
        }
    }
}
void search(int value){
    if(head == NULL)
        printf("List is empty !!!\n");
    else{
        struct Node* temp = head;
        while(temp != NULL){
            if(temp->data == value){
                printf("Found!!!\n");
                return;
            }
            temp = temp->next;
        }
        printf("Not Found !!!\n");
    }
}
void displayList(){
    if(head == NULL)
        printf("List is empty !!!\n");
    else{
        struct Node* temp = head;
        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main(){
    while(1){
        printf("\n***** Singly Linked List *****\n");
        printf("1. Insert In Begining\n");
        printf("2. Insert At End\n");
        printf("3. Insert At Specified Position\n");
        printf("4. Detele From Begining\n");
        printf("5. Delete From End\n");
        printf("6. Delete From Specified Position\n");
        printf("7. Display List\n");
        printf("8. Search Element In List\n");
        printf("9. Exit\n");
        int choice, data, pos;
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter Data: ");
                scanf("%d", &data);
                insertNodeInBeg(data);
                break;
            case 2:
                printf("Enter Data: ");
                scanf("%d", &data);
                insertNodeAtEnd(data);
                break;
            case 3:
                printf("Enter Position: ");
                scanf("%d", &pos);
                printf("Enter Data: ");
                scanf("%d", &data);
                insertNodeAtAnyPos(data, pos);
                break;
            case 4:
                deleteNodeFromBeg();
                break;
            case 5:
                deleteNodeFromEnd();
                break;
            case 6:
                printf("Enter Position: ");
                scanf("%d", &pos);
                deleteNodeFromAnyPos(pos);
                break;
            case 7:
               displayList();
               break;
            case 8:
                printf("Enter Searching Element: ");
                scanf("%d", &data);
                search(data);
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("Invalid Choice !!!!!\n");
        }
    }
    return 0;
}









