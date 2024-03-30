#include<iostream>
using namespace std;
float Add()
{
	float a,b;
	cout<< "\n Enter your first number : ";
	cin>>a;
	cout<<"\n Enter your second number : ";
	cin>>b; 
	cout<<a<<" + "<<b<<" = "<<a+b<<endl;
	return a+b;
}
 float sub(){
	float c,d;
	cout<<"\n Enter your first number : ";
	cin>>c;
	cout<<" \n Enter your second number : ";
	cin>>d;
	cout<<c<<" - "<<d<<" = "<<c-d<<endl;
	return c-d;	
}
void  div(){
    double e,f ;
    cout<<"\n Enter first number : ";
    cin>>e;
    cout<<"\n Enter second number : ";
    cin>>f;
    cout<<"\n the division is : "<<e/f<<endl;
}
float multi(){
	float g,h;
	cout<<"\n Enter your first number : ";
	cin>>g;
	cout<<"\n Enter your second number : ";
	cin>>h;
	cout<<g<<" * "<<h<<" = "<<g*h<<endl;
	return g*h;		
} 
void  evenodd(){
	int i;
	cout<<" \nEnter an integer : ";
	cin>>i;
	(i%2==0)?cout<<i<<" is even ":cout<<i<<" is odd "<<endl;
	
}

int main(){
    while ( 1 ){
        cout<<"welcome to my calculator - RABIA ANWAR\n"<<endl;
        cout<<" \t\t\t\t1. For Addition\n\t\t\t\t2. For substraction\n \t\t\t\t3. For division\n \t\t\t\t4. For multiplication\n \t\t\t\t5. For even/odd\n ";
        cout<<endl;
        cout<<endl;
        cout<<endl;

        int input;
        cout<<" press 1 to continue :";
        cin>>input;

        if(input != 1)
        {
        break;
        }
        int n;
        cout<<"\n Enter your choice : ";
        cin>>n;

        switch( n ){ 
            case 1:
                Add();
                break;
            case 2:
                sub();
                break;
            case 3:
                div();
                break;
            case 4:
                multi();
                break;
            case 5:
                evenodd();
                break;			
        }
	}
}