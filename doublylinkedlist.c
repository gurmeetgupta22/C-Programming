#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
};
struct Node* head = NULL;
struct Node* tail = NULL;
struct Node* createnode(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data= data;
    temp->prev=temp->next = NULL;  
    return temp;
};
void insertNodeInBeg(int data){
    struct Node* newnode = createnode(data);
    if(head==NULL && tail==NULL){                    
        head = tail = newnode;
    }
    else{
        newnode->next=head;      
        head->prev=newnode;
        head=newnode;          
    }
    printf("\nNode inserted....\n");
}
void insertNodeAtEnd(int data){
    struct Node* newnode = createnode(data);
    if(head==NULL && tail == NULL){
        head = tail = newnode;
    }
    else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
     printf("\nNode inserted....\n");
}
void insertNodeAtAnyPos(int data, int pos){
    struct Node* newnode = createnode(data);
    if(head == NULL && pos == 0){
        struct Node* newnode = createnode(data);
        head=tail=newnode;                                              
        printf("\nNode inserted at position %d...\n",pos);
    }
    else if(pos == 0){
        struct Node* newnode = createnode(data);
        newnode->next = head;
        head = newnode;
        printf("\nNode inserted at position %d...\n",pos);
    }
    else{
        struct Node* temp = head;
        int i=0;
        while(temp != NULL){
            if(i==pos){
               break;
            }
            temp=temp->next;
            i++;
        }
        if(temp == NULL && i!= pos){                    
            printf("\n....Invalid Position....\n");    
        }
        else if(i==pos){
            insertNodeAtEnd(data);                              
            printf("\nNode inserted at position %d...\n",pos);
        }
        else{
            struct Node* newnode = createnode(data);
            temp->prev->next=newnode;
            newnode->prev=temp->prev;
            newnode->next=temp;
            temp->prev=newnode;
            printf("\nNode inserted at position %d...\n,pos");
        }
    }
}
void deleteNodeFromBeg(){
    if(head==NULL && tail == NULL){
        printf("\nList is empty....\n");
    }
    else if(head==tail){      
        head=tail=NULL;
        printf("\nNode deleted...\n");
    }
    else{            
        head = head-> next;
        printf("\nNode deleted...\n");
    }
}
void deleteNodeFromEnd(){
    if(head==NULL && tail == NULL){
        printf("\nList is empty....\n");
    }
    else if(head==tail){       //or we can use condition head->next=NULL
        struct Node* delnode = head;
        head=tail=NULL;
        free(delnode);
        printf("\nNode deleted...\n");
    }
    else{
        tail->prev->next = NULL;
        tail = tail-> prev;
        printf("\nNode deleted...\n");
    }
}
void deleteNodeFromAnyPos(int pos){
    if(head==NULL && tail==NULL)
      printf("\nlist is empty...\n");
    else if(pos==0)
        deleteNodeFromBeg();
    else{
        struct Node* temp = head;
        int i=0;
        while(temp != NULL && i!=pos){
            temp=temp->next;                          
            i++;
        }
        if(temp==NULL && i!=pos){
            printf("\nInvalid Position...\n");
        }
        else if(i==pos){                                      
            deleteNodeFromEnd();                              
            printf("\nNode deleted from position %d...\n",pos);
        }
        else{                                                  
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            free(temp);
        }
    }
}
void search(int val){
    if(head==NULL && tail ==NULL){
        printf("List is Empty.\n");
    }
    else{
         struct Node* temp = head;
        while(temp != NULL){
            if(temp->data == val){
                printf("Found.\n");
                return;
            }
            temp = temp->next;
        }
        printf("Not Found.\n");
    }
}
void display(){                      
     if(head==NULL && tail ==NULL){
        printf("List is Empty.\n");
    }
    else{
         struct Node* temp = head;
        while(temp != NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main(){
    while(1){
        printf("\n-_____Doubly Linked list _____-\n");
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
                scanf("%d",&pos);
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
                printf("Enter position : ");
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


