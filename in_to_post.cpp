//we have isdigit() here by using <cctype>.
//push_back() function valid for string.
//this code is only for single digit numbers..................



#include<iostream>
#include<string>
#include<cctype>		//for isdigit
#include<cmath>

using namespace std;


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



void display(char* stack,int &top){
	cout<<"\nstack is:";
	while(top!=-1){
		cout<<stack[top];
		top-=1;
	}
}

string rev(string input){
	string preinput;
	for(int i=input.length()-1;i>=0;i--){
		if(input[i]=='(')
			preinput.push_back(')');
		else if(input[i]==')')
			preinput.push_back('(');
		else 
			preinput.push_back(input[i]);
	}
	return preinput;
}

string postfix(string input){
	input.push_back('$');
	cout<<"\ninput string after  push back:"<<input<<"\n";
	string post_exp;
	char stack[input.length()],k;
	int top=0;
	stack[top]='$';
	cout<<"\nstack[top]:"<<stack[top]<<"\n";
	 
	
	for(int i=0;input[i]!='$';i++){
		if(isdigit(input[i])){
			cout<<"\nisdigit(input["<<i<<"]):"<<isdigit(input[i])<<"\n";
			post_exp.push_back(input[i]);
		}	
		
		//checkfrom here;
		else if(input[i]==')'){
			while(stack[top]!='('){
				post_exp.push_back(stack[top]);
				cout<<"\npost_fix expressioin:"<<post_exp<<"\n";
				k=pop(top,stack);
				cout<<"\nitem popped out:"<<k;
			}
			k=pop(top,stack);
			cout<<"\nitem popped out:"<<k;
		}
		else if(input[i]!='(' && stack[top]!='('){ 
				if(precedence(input[i])<=precedence(stack[top])){
					post_exp.push_back(stack[top]);
					cout<<"\npost_fix expressioin:"<<post_exp<<"\n";
					k=pop(top,stack);
					cout<<"\nitem popped out:"<<k;
					push(input[i],stack,top,input.length());
				}
				else
					push(input[i],stack,top,input.length());
			}	
		else 
			push(input[i],stack,top,input.length());	
	}
	while(stack[top]!='$'){
		post_exp.push_back(stack[top]);
		k=pop(top,stack);
		cout<<"\nitem popped out:"<<k;
	}
	k=pop(top,stack);
	cout<<"\nitem popped out:"<<k;
	display(stack,top);
	cout<<"\ntop is:"<<top;
	return post_exp;
}

string prefix(string input){
	string prefixstr;
	prefixstr=rev(postfix(rev(input)));
	return prefixstr;
}


//for evaluation
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
		

void pushint(int item,int* stack,int& top){
	top+=1;
	stack[top]=item;
}



int popint(int& top,int* stack){
	int item =stack[top];
	top-=1;
	return item;
}	
	

void evaluate(string postexp){
	int stack[postexp.length()];
	int top=-1;
	int a,b,c;
	for(int i=0;i<postexp.length();i++){
		if(isdigit(postexp[i]))
			pushint(number(postexp[i]),stack,top);
		else{
			cout<<"\nstack's top is:"<<stack[top];
			a=(popint(top,stack));
			cout<<"\na is:"<<a;
			cout<<"\nstack's top is:"<<stack[top];
			b=(popint(top,stack));
			cout<<"\nb is:"<<b;
			c=(operate(b,a,postexp[i]));
			cout<<"\nc is:"<<c;
			pushint(c,stack,top);
		}	
	}
	cout<<"\nevaluated answer is:"<<stack[top];
}	

void evaluate_pre(string postexp){
	int stack[postexp.length()];
	int top=-1;
	int a,b,c;
	for(int i=postexp.length()-1;i>=0;i--){
		if(isdigit(postexp[i]))
			pushint(number(postexp[i]),stack,top);
		else{
			cout<<"\nstack's top is:"<<stack[top];
			a=(popint(top,stack));
			cout<<"\na is:"<<a;
			cout<<"\nstack's top is:"<<stack[top];
			b=(popint(top,stack));
			cout<<"\nb is:"<<b;
			c=(operate(a,b,postexp[i]));
			cout<<"\nc is:"<<c;
			pushint(c,stack,top);
		}	
	}
	cout<<"\nevaluated answer is:"<<stack[top];
}	
	
int main(){
	string post_str,input_str;
	cout<<"\nenter the input expression:";
	cin>>input_str;
	//post_str=postfix(input_str);
	//cout<<"\n"<<"postfix:"<<post_str;
	//evaluate(post_str);
	
	cout<<"\n"<<prefix(input_str);
	evaluate_pre(prefix(input_str));
	return 0;
}	
	