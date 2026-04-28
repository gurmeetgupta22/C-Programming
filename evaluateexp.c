#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define M 100
int stack[M];
char operator[M];
int top1=-1,top2=-1;
int precedence(char ch){
    switch(ch){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}
void push(int value){
    stack[++top1] = value;
}
void pushop(int value){
    operator[++top2] = value;
}
int pop(){
    int val = stack[top1--];
    return val;
}
int popop(){
    int val = operator[top2--];
    return val;
}
int apply(int a,int b,char op){
    switch(op){
        case '+': 
        return a+b;
        case '-': 
        return a-b;
        case '*': 
        return a*b;
        case '/': 
        return a/b;
        case '^':{
            int res=1;
            for(int i=0;i<b;i++)
                res*=a;
            return res;
        }
    }
}
int evaluateinfix(char* exp){
    for(int i=0;exp[i]!='\0';i++){
        char ch = exp[i];
        if(isdigit(ch)){
            int num=0;
            while(isdigit(exp[i])){
                num = num*10 + (exp[i]-'0');
                i++;
            }
            push(num);
            i--;
        }
        else if(ch == ' ' || ch == '\n'){
                continue;
            }
        
        else if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^'){
            while(top2!=-1 && (precedence(ch)<=(precedence(operator[top2]) && ch!='^'))){
            int b = pop();
            int a = pop();
            char op = popop();      
            push(apply(a,b,op));
        }
        pushop(ch);
        }
        else if(ch == '('){
           pushop(ch);
        }
        else if(ch == ')'){
            while(operator[top2] != '('){
            int b = pop();
            int a = pop();
            char op = popop();
            push(apply(a,b,op));
        }
        popop();
        }
    }
    while(top2!=-1){

    int b = pop();
    int a = pop();
    char op = popop();
    push(apply(a,b,op));
}
    return pop();
}

int evaluatepostfix(char* exp){
    for(int i=0;exp[i]!='\0';i++){
        char ch = exp[i];
        if(isdigit(ch)){
            
        int num =0;
        while(isdigit(exp[i])){
            num = num*10 + (exp[i]-'0');
            i++;
            }
        push(num);
        i--;
    }
        
        else if(ch == ' ' || ch == '\n'){
                continue;
            }
        
        else{
            int a = pop();
            int b = pop();
            switch(ch){
                case '+':
                push(b+a);
                break;
                case '-':
                push(b-a);
                break;
                case '*':
                push(b*a);
                break;
                case '/':
                push(b/a);
                break;
                case '^':{
                int res = 1;
                for(int j = 0; j < a; j++)
                res *= b;
                push(res);}
                break;
            }
        }
    }
    return pop();
}
int evaluateprefix(char* exp){
    int len = strlen(exp);
    for(int i=len-1;i>=0;i--){
        char ch = exp[i];
        if(isdigit(ch)){
            int num=0,place=1;
            while(i>=0 && isdigit(exp[i])){
                num +=(exp[i]-'0')*place;
                place *= 10;
                i--;
            }
            push(num);
            i++;
        }
        else if(ch == ' ' || ch == '\n'){
            continue;
        }
        else{
            int a = pop();
            int b = pop();
            switch(ch){
                case '+':
                push(a+b);
                break;
                case '-':
                push(a-b);
                break;
                case '*':
                push(a*b);
                break;
                case '/':
                push(a/b);
                break;
                case '^':{
                int res = 1;
                for(int j = 0; j < b; j++)
                res *= a;
                push(res);}
                break;
            }
        }
    }
    return pop();
}
int main(){
    char exp[50];
    gets(exp);
    printf("%d",evaluateinfix(exp));
}
