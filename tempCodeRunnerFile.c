#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
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
char* infixtopostfix(char* infix){
    int len=strlen(infix),top=-1,x=0;
    char operator[len];
    char* postfix = (char*)malloc(len+1);
    for(int i=0;i<len;i++){
        char ch = infix[i];
        if(isalnum(ch)){
            postfix[x++] = ch;
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'){
            while(top!=-1 && precedence(ch) <= precedence(operator[top]) && ch!='^'){
                postfix[x++] = operator[top--];
            }
            operator[++top] = ch;
        }
        else if(ch == '('){
            operator[++top] = ch;
        }
        else if(ch == ')'){
            while(operator[top] != '('){
                postfix[x++] = operator[top--];
            }
            top--;
        }
    }
    while(top!=-1){
        postfix[x++] = operator[top--];
    }
    postfix[x]='\0';
    return postfix;
}
int main(){
    char exp[50];
    scanf("%s",exp);
    printf("%s",infixtopostfix(exp));
}