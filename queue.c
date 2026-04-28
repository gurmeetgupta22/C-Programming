#include<stdio.h>
#define Max 100
int queue[Max],front=-1,rear=-1;

int isFull(){
    return (rear+1)==Max-1;
}

int isEmpty(){
    return  front == -1;
}

void enqueue(int data){
    if(isFull()){
        printf("Queue Overflow!!\n");
    }
    else if(isEmpty()){
        front = rear = 0;
    }
    else if(rear == Max-1 && front !=0){

    }
    
}

int dequeue(){
    if(isEmpty()){
        printf("Queue Underflow!!\n");
        return -1;
    }
    int val=queue[front];
    if(front == rear)
    front = rear =-1;
    else if(front == Max -1)
    front =0;
    else 
    front++;
    return val;
}

int peek(){

}

void display(){
    if(isEmpty()){
        printf("Queue is Empty!!\n");
        return ;
    }
    int i = front;
    while(1){
        printf("%d ",queue[i]);
        if(i==rear)
            break;
        i =(i+1)%Max;
    }
    printf("\n");
}

int main(){

    return 0;
}
