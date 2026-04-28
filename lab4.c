#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
int operand[100];
char operator[100];
int top1 = -1, top2 = -1;


void doProcess(){
    int x = operand[top1--];
    int y = operand[top1--];
    char op = operator[top2--];
    int z;
    switch(op){
        case '+':
            z = y + x;
            break;
        case '-':
            z = y - x;
            break;
        case '*':
            z = y * x;
            break;
        case '/':
            z = y / x;
            break;
        case '^':
            z = (int)round(pow(y, x));
            break;
    }
    operand[++top1] = z;
}


int precedence(char op){
    switch(op){
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


int evalInfixExpression(char* exp){
    for(int i=0; i<strlen(exp); i++){
        char ch = exp[i];
        if(isdigit(ch)){
            int num = 0;
            while(isdigit(exp[i])){
                num = num * 10 + exp[i]-'0';
                i++;
            }
            i--;
            operand[++top1] = num;
        }
        else if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^'){
            if(top2 == -1)
                operator[++top2] = ch;
            else{
                while(top2 != -1 && precedence(ch) < precedence(operator[top2])){
                        doProcess();
                }
                operator[++top2] = ch;
            }
        }
        else if(ch=='('){
            operator[++top2] = ch;
        }
        else if(ch==')'){
            while(operator[top2] != '('){
                doProcess();
            }
            top2--;
        }
    }
    while(top2 != -1){
        doProcess();
    }
    return operand[top1--];
}
int evalPostfixExpression(char* exp){
    for(int i=0; i<strlen(exp); i++){
        if(isdigit(exp[i])){
            int num = 0;
            while(isdigit(exp[i])){
                num = num*10 + exp[i]-'0';
                i++;
            }
            i--;
            operand[++top1] = num;
        }
        else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/' || exp[i]=='^'){
            int x = operand[top1--];
            int y = operand[top1--];
            int z;
            switch(exp[i]){
                case '+':
                    z = y + x;
                    break;
                case '-':

                
                    z = y - x;
                    break;
                case '*':
                    z = y * x;
                    break;
                case '/':
                    z = y / x;
                    break;
                case '^':
                    z = (int)round(pow(y, x));
                    break;
            }
            operand[++top1] = z;
        }
    }
    return operand[top1--];
}
int evalPrefixExpression(char* exp){
    for(int i=strlen(exp)-1; i>=0; i--){
        if(isdigit(exp[i])){
            int num = 0, p = 1;
            while(isdigit(exp[i])){
                num = num + (exp[i]-'0') * p;
                p = p * 10;
                i--;
            }
            i++;
            operand[++top1] = num;
        }
        else if(exp[i] == '+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/' || exp[i]=='^'){
            int x = operand[top1--];
            int y = operand[top1--];
            int z;
            switch(exp[i]){
                case '+':
                    z = x + y;
                    break;
                case '-':
                    z = x - y;
                    break;
                case '*':
                    z = x * y;
                    break;
                case '/':
                    z = x / y;
                    break;
                case '^':
                    z = (int)round(pow(x, y));
                    break;
            }
            operand[++top1] = z;
        }
    }
    return operand[top1--];
}
int main(){
    char expr[100];
    printf("Enter Infix Expression: ");
    gets(expr);
    int result = evalInfixExpression(expr);
    printf("Result of expression %s = %d\n", expr, result);


    printf("Enter Postfix Expression: ");
    gets(expr);
    result = evalPostfixExpression(expr);
    printf("Result of expression %s = %d\n", expr, result);


    printf("Enter Prefix Expression: ");
    gets(expr);
    result = evalPrefixExpression(expr);
    printf("Result of expression %s = %d\n", expr, result);
    return 0;
}
