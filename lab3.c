#include<stdio.h>
#include<string.h>
int main(){
 char str[100];
 printf("Enter Expression: ");
 gets(str);
 int len = strlen(str), top = -1, flag = 0;
 char stack[len];
 for(int i=0; i<len; i++){
  char ch = str[i];
  if(ch=='(' || ch=='[' || ch=='{')
   stack[++top] = ch;
  else if(ch==')' || ch==']' || ch=='}'){
   if(ch==')' && stack[top]=='(')
    top--;
   else if(ch==']' && stack[top]=='[')
    top--;
   else if(ch=='}' && stack[top]=='{')
    top--;
   else{
    flag = 1;
    break;
   }
  }
 }
 if(flag == 0 && top == -1)
  printf("Balanced !!!");
 else
  printf("Not Balanced!!!!");
 return 0;
}