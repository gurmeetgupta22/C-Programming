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
    else if(data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}
Node* search(Node* root, int val){
    if(root == NULL)
        return NULL;
    else if(root->data == val)
        return root;
    else if(val < root->data)
        return search(root->left, val);
    else
        return search(root->right, val);
}
Node* findMin(Node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}
Node* delete(Node* root, int val){
    if(root == NULL)
        return NULL;
    else if(val < root->data)
        root->left = delete(root->left, val);
    else if(val > root->data)
        root->right = delete(root->right, val);
    else{
        //Having zero-child
        if(root->left == NULL && root->right == NULL)
            return NULL;
        //Having one-child
        else if(root->left == NULL)
            return root->right;
        else if(root->right == NULL)
            return root->left;
        //having two child
        else{
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
        return root;
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
        printf("\n ***** Binary Search Tree Menu *****\n");
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
            case 7:
                exit(0);
            default:
                printf("Invalid choice !!!!\n");
        }
    }
   
}

