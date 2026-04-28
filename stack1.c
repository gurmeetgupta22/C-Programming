#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int stack[MAX], top = -1;
int isEmpty(){
     return top == -1;
}
int isFull(){
     return top == MAX-1;
}
void push(int value){
     if(isFull())
     printf("Stack overflow. Cannot push into a stack. !!\n");
     else{
     stack[++top] = value;
     printf("Pushed %d into the stack. !!\n", value);
 }
}
int pop(){
     if(isEmpty()){
     printf("Stack underflow. Cannot pop from empty stack. !!!\n");
     return -1;
 }
 else{
     int val = stack[top];
     top--;
     return val;
 }
}
int peek(){
     if(isEmpty()){

    printf("Stack underflow. Cannot peek from empty stack. !!!\n");
  return -1;
 }
  else
  return stack[top];
}
void show(){
     if(isEmpty())
     printf("Stack is empty !!!\n");
     else{
     printf("Stack elements are: \n");
     for(int i=top; i>=0; i--){
      printf("%d\n", stack[i]);
 }
 }
}
int main(){
     int choice, val, res;
     while(1){
     printf("1. Push\n");
     printf("2. Pop\n");
     printf("3. Peek\n");
     printf("4. Display\n");
     printf("5. Exit\n");
     printf("Enter Choice: ");
     scanf("%d",&choice);
     switch(choice){
      case 1:
       printf("Enter Value: ");
       scanf("%d", &val);
       push(val);
       break;

    case 2:
     res = pop();
     if(res != -1)
      printf("%d pop from stack.\n", res);
     break;
    case 3:
     res = peek();
     if(res != -1)
      printf("%d is avaiable at top of stack.\n", res);
     break;
    case 4:
     show();
     break;
    case 5:
     exit(0);
     break;
    default:
     printf("Invalid Choice...\n");
 }
   printf("\n");
 }
   return 0;
}