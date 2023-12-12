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
	void palindrome();
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


void stack_class :: reverse()
{
	char s[10],s2[10];int j=0;
	printf("\nEnter the String\n");
        scanf("%s", s);
        for (int i = 0;s[i] != '\0';i++)
        {
                char b = s[i];
                push(b);
        }
        for(int i= st.top;i>=0;i--)
        {
        	
        	char c=pop();
        	s2[j]=c;
        	j++;
        }
       s2[j]='\0';
        cout<<"\nReversed String is: "<<s2;
}   

void stack_class:: palindrome()
{
	int flag=0;char s[10],s2[10];int j=0;
	printf("\nEnter the String: \n");
        scanf("%s", s);
        for (int i = 0;s[i] != '\0';i++)
        {
                char b = s[i];
                push(b);
        }
        for(int i= st.top;i>=0;i--)
        {
        	
        	char c=pop();
        	s2[j]=c;
        	j++;
        }
       s2[j]='\0';
       cout<<"\nOriginal String is:"<<s;
       cout<<"\nReversed String is:"<<s2;
       for(int i= 0;s[i]!='\0';i++)
        {
        	if(s[i]==s2[i])
        	flag=1;
        	else 
        	{
        	flag=0;
        	break;
        	}
        }
        if(flag==1)      
        cout<<"\nString is Palindrome.";
        else
        cout<<"\nString is not Palindrome.";
}

int main()
{
	stack_class obj;
	int ch;
	char ans;
	
	do
	{
	    cout<<"--------";
		cout<<"\nMenu";
        cout<<"\n--------";
		cout<<"\n\n1.Reverse the String\n2.Check Palindrome";
		cout<<"\n\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: 
				obj.reverse();
				break;
			case 2: 
				obj.palindrome();
			        break;
               	}
               	cout<<"\nDo you want to continue?(Y or N)";
		cin>>ans;
	}while(ans=='Y' or ans=='y');
}


***************OUTPUT********************


--------
Menu
--------

1.Reverse the String
2.Check Palindrome

Enter your choice: 1
Enter the String
ADITYA
Reversed String is: AYTIDA
Do you want to continue?(Y or N)Y
--------
Menu
--------

1.Reverse the String
2.Check Palindrome

Enter your choice: 2
Enter the String: 
MALAYALAM
Original String is:MALAYALAM
Reversed String is:MALAYALAM
String is Palindrome.
Do you want to continue?(Y or N)Y
--------
Menu
--------

1.Reverse the String
2.Check Palindrome

Enter your choice: 2
Enter the String: 
ADITYA
Original String is:ADITYA
Reversed String is:AYTIDA
String is not Palindrome.
Do you want to continue?(Y or N)N
