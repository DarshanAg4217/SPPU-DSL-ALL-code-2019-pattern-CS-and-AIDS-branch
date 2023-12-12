#include<iostream>

using namespace std;
class stack_class
{
	struct stack
	{
		char a[10];
		int top;
	}st;
	public:
	stack_class();
	int stack_full();
	int stack_empty();
	void push(int item);
	char pop();
	void display();
	void reverse();
	void well_formed_parenthesis();
};

stack_class :: stack_class()
{
	st.top=-1;
}
int stack_class:: stack_full()
{	
	if(st.top>=9)
	return 1;
	else
	return 0;
	
}

int stack_class:: stack_empty()
{	
	if(st.top==-1)
	return 1;
	else
	return 0;
	
}

void stack_class::display()
{
	int i;
	for(i=st.top;i>=0;i--)
	cout<<st.a[i]<<"\n";
}
void stack_class:: push(int item)
{	
	st.top++;
	st.a[st.top]=item;
}

char stack_class:: pop()
{	
	char x=st.a[st.top];
	st.top--;
	return x;
}

void stack_class::well_formed_parenthesis()
{
	char exp[20];st.top=-1;
	cout<<"------------------------";
	cout<<"\nEnter an expression:\n";
	cin>>exp;
	// int i=-1;
        for (int i = 0;exp[i] != '\0';i++)
        {
        	char ch=exp[i];
            if(ch=='(' || ch=='{' || ch=='[')
                push(ch);
            else{
            		if(ch==')' || ch=='}' || ch==']')
            		ch=pop();
                }
        }
        
        for(int i=st.top;i>=0;i--)
	cout<<st.a[i]<<"\n";
        if(stack_empty()){
        cout<<"\nExpression is well formed";
        cout<<"\n--------------------------\n";}
        else
        {cout<<"Not well formed";
        cout<<"\n-----------------------------\n";
        }
}

int main()
{
	stack_class obj;
	int ch;
	char ans;
	
	do
	{
		
				obj.well_formed_parenthesis();
               	cout<<"\nDo you want to continue? (Y or N)\n";
		cin>>ans;
	}while(ans=='Y' or ans=='y');
}


**********************OUTPUT************************8


------------------------
Enter an expression:
Aditya
Expression is well formed
--------------------------

Do you want to continue? (Y or N)
Y
------------------------
Enter an expression:
Adi{t;ua
{
Not well formed
-----------------------------

Do you want to continue? (Y or N)
N
