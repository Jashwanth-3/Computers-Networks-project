#include<iostream>
#include<stdlib.h>
using namespace std;
#define maxlength 10
#define maxmessages 10
int crr[50][10];
void initialize(int arr[][10],int m,int n)
{
for(int i =0;i<m;i++)
for(int j=0;j<n;j++)
{
cin>>arr[i][j];
arr[i][j] = arr[i][j]%2;
}
}
void print(int arr[][10],int m,int n)
{
for(int i =0;i<m;i++)

{  
    for(int j=0;j<n;j++)
{
cout<<arr[i][j]<<" ";
}
cout<<endl;
}
}
void addparbitrow(int arr[][10],int m,int n)  // Even Parity
{
for(int i=0;i<m;i++)
{

int count = 0;

for(int j=0;j<n;j++)

{

if(arr[i][j] == 1)

count++;

}

if(count%2 == 0)

arr[i][n] = 0;

else

arr[i][n] = 1;



}
}

void addparbitcol(int arr[][10],int m,int n) 

{
int i;
for(int j=0;j<n+1;j++)

{

int count = 0;

for(i=0;i<m;i++)

{

if(arr[i][j] == 1)

count++;

}

if(count%2 == 0)

arr[m][j] = 0;

else

arr[m][j] = 1;

}

}

void checkerror(int arr[][10],int crr[][10],int m,int n)
{
cout<<"Enter received bits"<<endl;
for(int i=0;i<m;i++)
for(int j=0;j<n;j++)

{

cin>>crr[i][j];
}


for(int i=0;i<m;i++)
{
for(int j=0;j<n;j++)
{
    if(crr[i][j]!=arr[i][j])
    {
        cout<<"Error at:"<<i<<","<<j<<endl;
    }
    
    else
    {
        cout<<"NO ERROR AT:"<<i<<","<<j<<endl;
        
       
    }
}
}   



 

}

int main()

{   int m,n,arr[maxmessages][maxlength];

cout<<"Enter total number of messages :";

cin>>m;

cout<<"Enter length of each message :";

cin>>n;

cout<<"Enter the message line by line"<<endl;

initialize(arr,m,n);
cout<<"The matrix format of the message is as follows:"<<endl;
print(arr,m,n);
addparbitrow(arr,m,n);
addparbitcol(arr,m,n);


cout<<"The Generated 2D PARITY matrix is as follows:"<<endl;

print(arr,m+1,n+1);
checkerror(arr,crr,m+1,n+1);




return 0;

}