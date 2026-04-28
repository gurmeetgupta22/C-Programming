#include<stdio.h>
#include<stdlib.h>
#define max 100
int tree[max];
void initTree(){
    for(int i=0; i<max; i++){
        tree[i] = -1;
    }
}
void insert(int index, int val){
    if(tree[index]==-1)
        tree[index] = val;
    else if(val < tree[index])
        insert(2*index+1, val);
    else
        insert(2*index+2, val);
}
int search(int index, int val){
    if(index >= max || tree[index] == -1)
        return -1;
    else if(val == tree[index])
        return index;
    else if(val < tree[index])
        return search(2*index+1, val);
    else
        return search(2*index+2, val);
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
    int choice, val;
    initTree();
    while (1){
        printf("\n ***** Binary Search Tree Menu *****\n");
        printf("1. Insert\n");
        printf("2. Pre-Order Traversal\n");
        printf("3. In-Order Traversal\n");
        printf("4. Post-Order Traversal\n");
        printf("5. Search\n");
        printf("6. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter Value: ");
                scanf("%d", &val);
                insert(0, val);
                break;
            case 2:
                preOrder(0);
                break;
            case 3:
                inOrder(0);
                break;
            case 4:
                postOrder(0);
                break;
            case 5:
                printf("Enter Seaching Element: ");
                scanf("%d", &val);
                if(search(0, val) == -1)
                    printf("Not Found !!\n");
                else
                    printf("Found!!!\n");
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice !!!!\n");
        }
    }
   
}

