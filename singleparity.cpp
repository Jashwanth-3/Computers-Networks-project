#include<iostream>
#include<stdlib.h>
using namespace std;
#define maxlength 10

#define maxmessages 10
int crr[50];
void initialize(int arr[10],int m)
{
for(int i =0;i<m;i++)
{
cin>>arr[i];
arr[i] = arr[i]%2;
}
}
void print(int arr[10],int m)
{
for(int i =0;i<m;i++)
{
cout<<arr[i]<<" ";
}
cout<<endl;
}
// Even Parity
void addparbiteven(int arr[10],int m)  
{
int count=0;
for(int i=0;i<m;i++)
{
if(arr[i] == 1)
count++;
}
if(count%2 == 0)
arr[m] = 0;
else
arr[m] = 1;
print(arr,m+1);
}
//Odd parity
void addparbitodd(int arr[10],int m) 
{
int count=0;
for(int i=0;i<m;i++)
{
if(arr[i] == 1)
count++;
}
if(count%2 == 0)
arr[m] = 1;
else
arr[m] = 0;
print(arr,m+1);
}
//Error check
void checkerror(int arr[10],int crr[10],int m)
{
cout<<"Enter received bits:"<<endl;
for(int i=0;i<m;i++)
{
cin>>crr[i];
}
for(int i=0;i<m;i++)
{
    if(crr[i]!=arr[i])
	{
    cout<<"Error Detected at :"<<i<<endl;
	}
	else
	{
		cout<<"NO ERROR AT :"<<i<<endl;
}
}
}
int main()
{   
int m,arr[maxlength],data[50];
int ctr;
	char ch='y';
	do
	{
		cout<<"\n ------OPTIONS------ \n1.ENTER DATA \n2.ADD PARITY EVEN \n3.ADD PARITY ODD \n4.ERROR CHECKER\n5.EXIT ";
		cout<<"\nENTER YOUR CHOICE : ";
		cin>>ctr;
		switch(ctr)
		{
	   case 1 : cout<<"Enter length of the message :";
                     cin>>m;
                     cout<<"Enter the message line by line"<<endl;
                     initialize(arr,m);
			   break;
         case 2 : cout<<"After adding even parity bit the message is:"<<endl;
                     addparbiteven(arr,m);
					 break;
         case 3 : cout<<"After adding odd parity bit the message is:"<<endl;
	     addparbitodd(arr ,m);
	     break;
        case 4 : checkerror(arr,crr,m+1);
	     break;		 
        case 5  : exit(0);
        default : cout<<"\n WRONG CHOICE " ;
                     }
        cout<<"\n WANT TO CONTINUE? (Y/N) : ";
         cin>>ch;
	}
        while(ch=='y'||ch=='Y');
        return 0;

}
