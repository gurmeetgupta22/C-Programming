#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int precedence(char opr){
    switch(opr){
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
char* covertInfixToPostfix(char* infixExp){
    int len=strlen(infixExp),top=-1,x=0;
    char *postfix = (char*) malloc(len+1);
    char operator[len];
    for(int i=0;i<len;i++){
        char ch= infixExp[i];
        if(isalnum(ch)){
            postfix[x++]=ch;
        }
        else if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^'){
            while(top!=-1 && precedence(ch)<=precedence(operator[top])&& ch!='^'){
                    postfix[x++]=operator[top--];
                }
                operator[++top]=ch;
        }
        else if(ch=='('){
            operator[++top]=ch;
        }
        else if(ch==')'){
            while(operator[top]!='('){
                postfix[x++]=operator[top--];
            }
            top--;
        }
    }
    while(top!=-1){
        postfix[x++]=operator[top--];
    }
    postfix[x]='\0';
    return postfix;

}
int main(){
    char expr[100];
    printf("Enter Infix Expression: ");
    gets(expr);
    printf("Postfix expression = %s\n",covertInfixToPostfix(expr));
    return 0;
}