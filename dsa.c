//Implement List using array
#include<stdio.h>

#define MAX 100
int List[MAX];
int size=0;
void Insertinbegin(int List[size]){
    if(size>=MAX){
        printf("List is full!!\n");
    }
    else{
        printf("Enter value to be inserted in the beginning : ");
                int Insert;
                scanf("%d",&Insert);
                for(int i=size;i>0;i--){
                    List[i]=List[i-1];
                }
                List[0]=Insert;
                size++;
                printf("Value Inserted!!\n");
        }
        
}
void Insertinend(int List[size]){
    if(size>=MAX){
        printf("List is Full!!\n");
     }
     else{
        printf("Enter value to be inserted in the end : ");
                int Insert;
                scanf("%d",&Insert);     
                List[size]=Insert;
                size++;
                printf("Value Inserted!!\n");
}}
void Insertatspec(int List[size]){
    if(size>=MAX){
        printf("List is full!!\n");
    }
    else{
        printf("Enter value to be inserted : ");
                int Insert;
                scanf("%d",&Insert);
        printf("Enter position to enter the value: ");
                int pos;
                scanf("%d",&pos);
                if(pos<0 || pos>size){
                    printf("Invalid position!!\n");
                }
                for(int i=size;i>pos-1;i--){
                    List[i]=List[i-1];
                }
                List[pos-1]=Insert;
                size++;
                printf("Value Inserted!!\n");
}}
void DelinBeginning(int List[size]){
    if(size==0){
        printf("List is empty!!\n");
        return;
    }
    else{
    for(int i=0;i<size;i++){
        List[i]=List[i+1];
    }
    size--;
    printf("Element Deleted from Beginning\n");
}
}
void Delatend(int List[size]){
    if(size==0){
        printf("List is empty\n");
        return;
    }
    size--;
    printf("Element deleted from the end\n");
}
void Delatspec(int List[size]){
    if(size==0){
        printf("List is empty!!\n");
        return;
    }
    int pos;
    printf("Enter position to be deleted: ");
    scanf("%d",&pos);
    if(pos<0 || pos>=size){
        printf("Invalid Postition!!\n");
        return;
    }
    else{
        for(int i=pos-1;i<size;i++){
            List[i]=List[i+1];
        }
        size--;
    }
    printf("Element Deleted successfully!!\n");
}
int Search(int List[size]){
    if(size==0){
        printf("List is empty!!\n");
    }
    else{
    int value,found=0,index=-1;
    printf("Enter value to be searched: ");
    scanf("%d",&value);
    for(int i=0;i<size;i++){
        if(value==List[i]){
            found=1;
            index=i;
        }
    }
    if(found==0){
        printf("Element not found!!\n");
    }
    else{
        return index+1;
    }

}}
void update(int List[size]){
    if(size==0){
        printf("List is empty!!\n");
    }
    else{
    printf("Enter position to be updated: ");
    int pos;
    scanf("%d",&pos);
    if(pos<0 || pos>size){
        printf("Invalid Position!!\n");
    }
    else{
        printf("Enter Value you want to input: ");
        int value;
        scanf("%d",&value);
        List[pos-1]=value;
    }
    printf("List updated successfully!!\n");
}
}
void sort(int List[size]){
    if(size==0){
        printf("List is empty!!\n");
    }
    else{
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(List[i]>List[j]){
                int temp=List[i];
                List[i]=List[j];
                List[j]=temp;
            }
        }
    }}
    printf("List Sorted!!\n");
}
int main(){
    while(1){
        printf("1. Insert in Begining\n");
        printf("2. Insert in End\n");
        printf("3. Insert in Specific Position\n");
        printf("4. Delete from Begining\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Specific Position\n");
        printf("7. Display List\n");
        printf("8. Search Element In List\n");
        printf("9. Update List Element\n");
        printf("10. Sort Elemeny of List\n");
        printf("11. Exit\n");
        int choice;
        printf("Enter your Choice (1-11) : ");
        scanf("%d",&choice);
        switch(choice){
            
            case 1:
                Insertinbegin(List);
                
                break;
            case 2:
                Insertinend(List);
                break;
            case 3:
                Insertatspec(List);
                break;
            case 4:
                DelinBeginning(List);
                break;
            case 5:
                Delatend(List);
                break;
            case 6:
                Delatspec(List);
                break;
            case 7:
            if(size==0){
                printf("List is Empty!!\n");
            }
            else{
                for(int i=0;i<size;i++){
                    printf("%d ",List[i]);
                    
                }
                printf("\n");
            }
                break;
            case 8:
                printf("Element found at position %d\n",Search(List));
                break;
            case 9:
                update(List);
                break;
            case 10:
                sort(List);
                break;
            case 11:
            printf("Thank You for using our Program!!\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}