
#include <iostream>
#include<stdlib.h>
using namespace std;
int i,j,k,frame[25],framesize,generator[25],generatorsize,temp[25],remaindersize,recievedrem[25],transmitedframe[25],recievedframe[25],crc[25],flag=0;
void xorfun(int i, int g[], int temp[], int j)
{

		if (temp[k]>=g[j])
		{
			for(j=0,k=i;j<generatorsize;j++,k++)
			{
				if((temp[k]==1 && g[j]==1) || (temp[k]==0 && g[j]==0))
					temp[k]=0;
				else
					temp[k]=1;
			}
		}
}

int main()
{
	//Get Frame
	cout<<"\n Enter Frame size: ";
	cin>>framesize;
	
	cout<<"\n Enter Frame:"<<endl;
	for(i=0;i<framesize;i++)
	 cin>>frame[i];
	//Get Generator
	cout<<"\n Enter Generator size: ";
	cin>>generatorsize;
	if(generatorsize>25||generatorsize>framesize)
    {
        cout<<"not possible";
        return 0;
    }
	cout<<"\n Enter Generator:"<<endl;
	for(i=0;i<generatorsize;i++)
	 cin>>generator[i];
	cout<<"\n Sender Side:";
	cout<<"\n Frame: ";
	for(i=0;i<framesize;i++)
	 cout<<frame[i];
	cout<<"\n Generator :";
	for(i=0;i<generatorsize;i++)
	 cout<<generator[i];
	//Append 0's
	remaindersize=generatorsize-1;
	cout<<"\n Number of 0's to be appended: "<<remaindersize;
	for (i=framesize;i<framesize+remaindersize;i++)
	 frame[i]=0;

	for(i=0;i<framesize+remaindersize;i++)
	 temp[i]=frame[i];
	cout<<"\n Message after appending 0's :";
	for(i=0; i<framesize+remaindersize;i++)
	 cout<<temp[i];
          //Division
	for(i=0;i<framesize;i++)
	{
		j=0;
		k=i;
                xorfun( i,generator,temp,j);
        }
	//CRC
	for(i=0,k=framesize;i<remaindersize,k<framesize+remaindersize;i++,k++)
	 crc[i]=temp[k];
	cout<<"\n CRC bits: ";
	for(i=0;i<remaindersize;i++)
	 cout<<crc[i];
	cout<<"\n Transmitted Frame: ";
	for(i=0;i<framesize;i++)
	 transmitedframe[i]=frame[i];
	for(i=framesize;i<framesize+remaindersize;i++)
	 transmitedframe[i]=crc[i-framesize];
	for(i=0;i<framesize+remaindersize;i++)
    {
	 cout<<transmitedframe[i];
    }
    cout<<endl;
	
    cout<<"\n------- Receiver side :--------- ";
	cout<<"\n Enter the Received Frame: "<<endl;
	
    for(i=0;i<framesize+remaindersize;i++)
{
	 cin>>recievedframe[i];
	 }
	for(i=0;i<framesize+remaindersize;i++)
    {
	 temp[i]=recievedframe[i];
    }
        for(i=0;i<framesize;i++)
	{
		j=0;
		k=i;
	        xorfun( i,generator,temp,j);
        }
	cout<<"\n Remainder: ";
	for(i=0,k=framesize;i<remaindersize,k<framesize+remaindersize;i++,k++)
	 recievedrem[i]=temp[k];
	for(i=0;i<remaindersize;i++)
	 cout<<recievedrem[i];
	for(i=0;i<remaindersize;i++)
	{
		if(recievedrem[i]!=0)
		cout<<"Error at:"<<i<<endl;
		 flag=1;
	}
	if(flag==0)
		cout<<"\nRemainder Is 0 the  Message Transmitted From Sender To Receriver Is Correct ";
	else
		cout<<"\nRemainder Is Not 0 the Message Transmitted From Sender To Receriver Contains Error";
	return 0;
}