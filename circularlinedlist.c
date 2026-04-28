#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* head=NULL;
struct Node* createNode(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = data;
    temp -> next = NULL;
    return temp;
}
void insertNodeInBeg(int data){
    struct Node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        newNode->next = head;
    }
    else{
        struct Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    printf("Node inserted !!!\n");
}
void insertNodeAtEnd(int data){
    struct Node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        newNode->next = head;
    }
    else{
        struct Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    printf("Node inserted !!!\n");
}
void insertNodeAtAnyPos(int data , int pos){
    if(head == NULL){
        if(pos==0)
            insertNodeInBeg(data);
        else
            printf("Invalid position !!!\n");
    }
    else if(pos == 0)
        insertNodeInBeg(data);
    else{
        struct Node* temp = head;
        int i = 0;
        while(i != pos-1 ){
            temp = temp->next;
            i++;
            if(temp == head){
                printf("Invalid position !!!\n");
                return;
            }
        }
        struct Node* newNode = createNode(data);
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Node Inserted !!!\n");
    }
}
void deleteNodeFromBeg(){
    if(head == NULL)
        printf("List is empty !!!\n");
    else if(head->next == head){
        head = NULL;
        printf("Node deleted!!!\n");
    }
    else{
        struct Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = head->next;
        head = head->next;
        printf("Node deleted !!!\n");
    }
}
void deleteNodeFromEnd(){
    if(head == NULL)
        printf("List is empty !!!\n");
    else if(head->next == head){
        head = NULL;
        printf("Node deleted!!!\n");
    }
    else{
        struct Node* temp = head;
        while(temp->next->next != head){
            temp = temp->next;
        }
        temp->next = head;
        printf("Node deleted !!!\n");
    }
}


void deleteNodeFromAnyPos(int pos){           // 0 based.
    if(head == NULL)
        printf("List is empty !!\n");
    else if(pos == 0)
        deleteNodeFromBeg();
    else{
        struct Node* temp = head;
        int i = 0;
        while(i != pos-1 && temp->next != head){
            i++;
            temp = temp->next;
        }
        if(temp->next == head)
            printf("Invalid position !!!\n");
        else{
            temp->next = temp->next->next;
            printf("Node deleted !!!\n");
        }
    }
}
void search(int val){
    if(head == NULL){
        printf("List is empty !!\n");
    }
    else{
        struct Node* temp = head;
        do{
            if(temp->data == val){
                printf("Found !!!\n");
                return;
            }
            temp = temp->next;
        }while(temp != head);
        printf("Not Found !!!\n");
    }
}
void display(){
    if(head == NULL){
        printf("List is empty !!\n");
    }
    else{
        struct Node* temp = head;
        do{
            printf("%d ", temp->data);
            temp = temp->next;
        }while(temp != head);
        printf("\n");
    }
}
int main(){
    while(1){
        printf("\n-_____Circular Singly Linked list _____-\n");
        printf("1. Insert In Beginning\n");
        printf("2. Insert In end\n");
        printf("3. Insert At Specific Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete from any position\n");
        printf("7. Display List\n");
        printf("8. Search element in list\n");
        printf("9. Exit\n");
        int choice, data, pos;
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data : ");
               scanf("%d",&data);
               insertNodeInBeg(data);
               break;
            case 2:
               printf("Enter data : ");
               scanf("%d",&data);
               insertNodeAtEnd(data);
               break;
            case 3:
                printf("Enter position : ");
                scanf("%d", &pos);
                printf("Enter data : ");
                scanf("%d",&data);
                insertNodeAtAnyPos(data,pos);  
                break;
            case 4:
                deleteNodeFromBeg();
                break;
            case 5:
                deleteNodeFromEnd();
                break;
            case 6:
                printf("Enter Position : ");
                scanf("%d",&pos);
                deleteNodeFromAnyPos(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Enter value to search : ");
                scanf("%d",&data);
                search(data);
                break;
            case 9:
                exit(0);
                break;
        }
    }
    return 0;
}


