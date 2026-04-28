#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    struct Node* left;
    int data;
    struct Node* right;
} Node;
Node* createNode(int data){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
Node* insert(Node* root, int data){
    if(root == NULL)
        return createNode(data);
    else{
        Node* queue[100];
        int front = -1, rear = -1;
        queue[++rear] = root;
        front++;
        while(front<=rear){
            Node* temp = queue[front++];
            if(temp->left == NULL){
                temp->left = createNode(data);
                break;
            }
            else if(temp->right == NULL){
                temp->right = createNode(data);
                break;
            }
            else{
                queue[++rear] = temp->left;
                queue[++rear] = temp->right;
            }
        }
        return root;
    }
}
Node* search(Node* root, int val){
    if(root== NULL)
        return NULL;
    Node* queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;
        front++;
    while(front<=rear){
        Node* temp = queue[front++];
        if(temp->data == val)
            return temp;
        if(temp->left != NULL)
            queue[++rear] = temp->left;
        if(temp->right != NULL)
            queue[++rear] = temp->right;
    }
    return NULL;
}
void delete(Node* root, int val){
    if(root== NULL)
        return NULL;
    Node* queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;
    front++;
    Node *t1=NULL, *t2=NULL, *temp=NULL;
    while(front<=rear){
        temp = queue[front++];
        if(temp->data == val)
            t1 = temp;
        if(temp->left != NULL)
            queue[++rear] = temp->left;
        if(temp->right != NULL)
            queue[++rear] = temp->right;
    }
    t2 = temp;
    if(t1 == NULL)
        printf("Element not found !!!\n");
    else{
        t1->data = t2->data;
        front = rear = -1;
        queue[++rear] = root;
        front++;
        while(front<=rear){
            Node* temp = queue[front++];
            if(temp->left == t2){
                temp->left = NULL;
                break;
            }
            if(temp->right == t2){
                temp->right = NULL;
                break;
            }
            if(temp->left != NULL)
                queue[++rear] = temp->left;
            if(temp->right != NULL)
                queue[++rear] = temp->right;
        }
        printf("Node deleted !!!\n");
    }
}
void preOrder(Node* root){
    if(root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node* root){
    if(root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}
void postOrder(Node* root){
    if(root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}
int main(){
    int choice, val;
    Node* root = NULL;
    while (1){
        printf("\n ***** Binary Tree Menu *****\n");
        printf("1. Insert\n");
        printf("2. Pre-Order Traversal\n");
        printf("3. In-Order Traversal\n");
        printf("4. Post-Order Traversal\n");
        printf("5. Search\n");
        printf("6. Delete\n");
        printf("7. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter Value: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                preOrder(root);
                break;
            case 3:
                inOrder(root);
                break;
            case 4:
                postOrder(root);
                break;
            case 5:
                printf("Enter Seaching Element: ");
                scanf("%d", &val);
                if(search(root, val) == NULL)
                    printf("Not Found !!\n");
                else
                    printf("Found!!!\n");
                break;
            case 6:
                printf("Enter Deleting Element: ");
                scanf("%d", &val);
                delete(root, val);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice !!!!\n");
        }
    }
   
}


