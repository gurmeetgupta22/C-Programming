#include<stdio.h>
#include<stdlib.h>
#define max 100
int tree[max], idx = 13;
void initTree(){
    for(int i=0; i<max; i++){
        tree[i] = -1;
    }
}
void insert(int val){   // Here we are inserting data in BT using level order
    if(idx == max)
        printf("Tree is full !!!\n");
    else{
        tree[idx++] = val;
    }
}
void levelOrder(){
    if(idx == 0)
        printf("Tree is empty!!!\n");
    else{
        for(int i=0; i<idx; i++){
            if(tree[i] != -1)
                printf("%d ", tree[i]);
        }
    }
}
void preOrder(int index){
    if(index >= max || tree[index] == -1)
        return;
    printf("%d ", tree[index]);
    preOrder(2*index+1);
    preOrder(2*index+2);
}
void inOrder(int index){
    if(index >= max || tree[index] == -1)
        return;
    inOrder(2*index+1);
    printf("%d ", tree[index]);
    inOrder(2*index+2);
}
void postOrder(int index){
    if(index >= max || tree[index] == -1)
        return;
    postOrder(2*index+1);
    postOrder(2*index+2);
    printf("%d ", tree[index]);
}
int main(){
    int choice, value;
    initTree();
    while(1){
        printf("\n***** Binary Tree Menu *****\n");
        printf("1. Insert\n");
        printf("2. Level Order Traversal\n");
        printf("3. Pre-Order Traversal\n");
        printf("4. In-Order Traversal\n");
        printf("5. Post-Order Traversal\n");
        printf("6. Exit\n");
        printf("Enter Choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter Value: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                levelOrder();
                break;
            case 3:
                preOrder(0);
                break;
            case 4:
                inOrder(0);
                break;
            case 5:
                postOrder(0);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid Choice !!!\n");
        }
    }
    return 0;
}

