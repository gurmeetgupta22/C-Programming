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
void reverse(char *str){
    int len = strlen(str);
    int i = 0, j = len - 1;

    while(i < j){
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;

        i++;
        j--;
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
char* infixtoprefix(char* infix){
    int len = strlen(infix),top=-1,x=0;
    char operator[len];
    char* prefix = (char*)malloc(len+1);
    for(int i=len-1;i>=0;i--){
        char ch = infix[i];
        if(isalnum(ch)){
            prefix[x++] = ch;
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'){
    while(top!=-1 &&(precedence(ch) < precedence(operator[top]) || (precedence(ch) == precedence(operator[top]) && ch == '^')))
    {
        prefix[x++] = operator[top--];
    }
    operator[++top] = ch;
}
        else if(ch == ')'){
            operator[++top] = ch;
        }
        else if(ch == '('){
            while(operator[top] != ')'){
                prefix[x++] = operator[top--];
            }
            top--;
        }
    }
    while(top!=-1){
        prefix[x++] = operator[top--];
    }
    prefix[x] = '\0';
    reverse(prefix);
    return prefix;
}
int main(){
    char exp[50];
    scanf("%s",exp);
    printf("%s\n",infixtopostfix(exp));
    printf("%s\n",infixtoprefix(exp));
}