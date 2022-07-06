#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include <locale.h>
#define ESPACO ' '
#define TAB '\t'
#define MAX 50
void push(long int operador);
long int pop();
void infixa_posfixa();
long int calcula_posfixa();
int prioridade(char operador);
int estaVazio();
int espaco(char );
char infixa[MAX], posfixa[MAX];
long int stack[MAX];
int top;

int main()
{
long int value;
top=-1;
setlocale(LC_ALL, "Portuguese");
printf("Entre com sua expressão Infixa : ");
gets(infixa);
infixa_posfixa();
value=calcula_posfixa();
printf("Expressão convertida em Posfixa : %s\n",posfixa);
printf("Resultado do calculo da expressão Posfixa : %ld\n",value);
return 0;
}

void infixa_posfixa()
{
unsigned int i,p=0;
char proximo;
char operador;
for(i=0;i<strlen(infixa);i++)
{
operador=infixa[i];
if(!espaco(operador))
{
switch(operador)
{

case '(':
push(operador);
break;
case ')':
while((proximo=pop())!='(')
posfixa[p++] = proximo;
break;
case '+':
case '-':
case '*':
case '/':
case '%':
case '^':
while( !estaVazio( ) && prioridade(stack[top])>= prioridade(operador) )
posfixa[p++]=pop();
push(operador);
break;
default:
posfixa[p++]=operador;
}
}
}
while(!estaVazio( ))
posfixa[p++]=pop();
posfixa[p]='\0';
}

int prioridade(char operador)
{
switch(operador)
{
case '(':
return 0;
case '+':
case '-':
return 1;
case '*':
case '/':
case '%':
return 2;
case '^':
return 3;
default :
return 0;
}
}
void push(long int operador)
{
if(top>MAX)
{

printf("Erro!\n");
exit(1);
}
stack[++top]=operador;
}
long int pop()
{
if( estaVazio() )
{
printf("Erro!");
exit(1);
}
return (stack[top--]);
}
int estaVazio()
{
if(top==-1)
return 1;
else
return 0;
}
int espaco(char operador)
{
if( operador == ESPACO || operador == TAB )
return 1;
else
return 0;
}
long int calcula_posfixa()
{
long int a,b,temp,resultado;
unsigned int i;
for(i=0;i<strlen(posfixa);i++)
{
if(posfixa[i]<='9' && posfixa[i]>='0')
push(posfixa[i]-'0');
else
{
a=pop();
b=pop();
switch(posfixa[i])
{
case '+':
temp=b+a; break;
case '-':
temp=b-a;break;
case '*':
temp=b*a;break;
case '/':

temp=b/a;break;
case '%':
temp=b%a;break;
case '^':
temp=pow(b,a);
}
push(temp);
}
}
resultado=pop();
return resultado;
}
