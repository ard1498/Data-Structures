#include<iostream>
#include<string>
#include<cctype>
#include<cmath>

using namespace std;

void push(char item,char *stack,int &top,int size){
	if(top==size-1)
		cout<<"\noverflow";
	else{
		top+=1;
		stack[top]=item;
		cout<<"\nitem added to stack:"<<stack[top];
	}
	
}


char pop(int &top,char *stack){
	char item;
	if(top==-1)
		cout<<"\nunderflow";
	else{
		item=stack[top];
		top=top-1;
		return item;
	}
	return '0';
}


void pushint(int item,int* stack,int& top){
	top+=1;
	stack[top]=item;
}

int popint(int* stack,int& top){
	int item =stack[top];
	top-=1;
	return item;
}

int precedence(char ch){
	switch(ch){
		case '^' : return 4;
					break;
		case '*' : return 3;
					break;
		case '/' : return 3;
					break;
		case '-' : return 2;
					break;
		case '+' : return 2;
					break;
		case '=' : return 1;
					break;
		
		default :  return 0;
					break;
	}
}	


int number(char ch){
	switch(ch){
		case '1' : return 1;
					break;
		case '2' : return 2;
					break;
		case '3' : return 3;
					break;
		case '4' : return 4;
					break;
		case '5' : return 5;
					break;
		case '6' : return 6;
					break;
		case '7' : return 7;
					break;
		case '8' : return 8;
					break;
		case '9' : return 9;
					break;	
		default :  return 0;
					break;
	}
}

int operate(char b,char a,char op){
	switch(op){
		case '*' : return (b*a);
					break;
		case '+' : return (b+a);
					break;
		case '-' : return (b-a);
					break;
		case '/' : return (b/a);
					break;
		case '^' : return pow(b,a);
					break;		
		default : return 0;
					break;
	}
}	


void evaluate(string infix){
	int stack1[10];
	char stack2[10];
	int top1=-1;
	int top2=-1;
	int a,b,c;
	char op,k;
	
	
	for (int i=0;i<infix.length();i++){
		if(isdigit(infix[i])){
			top1+=1;
			pushint(number(infix[i]),stack1,top1);
		}	
		else {
		
			if(infix[i]!='(' &&infix[i]!=')'){
				if(precedence(stack2[top2])>=precedence(infix[i]) && top2!=-1){
					op=pop(top2,stack2);
					push(infix[i],stack2,top2,10);
					a=popint(stack1,top1);
					b=popint(stack1,top1);
					c=operate(b,a,op);
					pushint(c,stack1,top1);
				}
				else
					push(infix[i],stack2,top2,10);
			}	
			else if(infix[i]==')'){
				while(stack2[top2]!='('){
					op=pop(top2,stack2);
					a=popint(stack1,top1);
					b=popint(stack1,top1);
					c=operate(b,a,op);
					pushint(c,stack1,top1);
				}
				k=pop(top2,stack2);
			}
		
			else
				push(infix[i],stack2,top2,10);
		}
	}
	if(top2!=-1){
			while(top2!=-1){
				op=pop(top2,stack2);
				a=popint(stack1,top1);
				b=popint(stack1,top1);
				c=operate(b,a,op);
				pushint(c,stack1,top1);
			}
		}
	cout<<"\nevaluated answer is:"<<stack1[top1];
}		
	

int main(){
	string input;
	cout<<"\nenter the infix expressioin to be evaluated:";
	cin>>input;
	evaluate(input);
	return 0;
}	