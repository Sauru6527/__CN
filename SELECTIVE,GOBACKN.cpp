#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

void success(int f,int w)
{
 int send[10],rec[10];
 cout<<"Enter the data frames:";
 for(int i=0;i<f;i++)
 {
  cin>>send[i];
  cout<<"Sent Frame: "<<send[i]<<endl;
 }
  
 cout<<"Enter the data frames recieved:";
  for(int i=0;i<f;i++)
  {
  cin>>rec[i];
  cout<<"Acknowledgement for "<<rec[i]<<" received!"<<endl;
}
}

void goback_n(int f,int w)
{
 int i=1;
 while(i<=f)
 {
     int x=0;
     for(int j=i;j<i+w && j<=f;j++)
     {
         cout<<"Sent Frame "<<j<<endl;
     }
     for(int j=i;j<i+w && j<=f;j++)
     {
         int flag = rand()%2;
         if(!flag)
             {
                 cout<<"Acknowledgment for Frame "<<j<<endl;
                 x++;
             }
         else
             {   cout<<"Frame "<<j<<" Not Received"<<endl;
                 cout<<"Retransmitting Window"<<endl;
                 break;
             }
     }
     cout<<endl;
     i+=x;
 }
}

void repeat(int x)
{
  cout<<"Retransmitting Frame "<< x <<" ..."<< endl;
}

void selective_repeat(int f,int w)
{
 int i=1;
 while(i<=f)
    {
     int x=0;
     for(int j=i;j<i+w && j<=f;j++)
     {
         cout<<"Sent Frame "<<j<<endl;
     }
     for(int j=i;j<i+w && j<=f;j++)
    {
         int flag = rand()%2;
         if(!flag)
            {
                 cout<<"Acknowledgment for Frame "<<j<<endl;
                 x++;
            }
         else
            {  
                cout<<"Frame "<<j<<" Not Received"<<endl;
                cout<<"Time out!!\nAcknowledgment for Frame "<<j<<" Not received or NEGATIVE ACKNOWLEDGEMENT!"<<endl;
                repeat(j);
                cout<<"Acknowledgment for Frame "<<j<<" received."<<endl;
            }
    }
     cout<<endl;
     i+=x;
    }
}

int main()
{
 int f,w,ch,send[10],rec[10],ans;
 srand(time(NULL));
 cout<<"Enter the Window Size : ";
 cin>>w;
 cout<<"Enter the number of frames : ";
 cin>>f;
 do
 {
 cout<<"\nOptions to perform over loss of frame:-";
 cout<<"\n1.Success case\n2.GoBack N\n3.Selective repeat"<<endl;
 cout<<"Enter your choice:";
 cin>>ch;
 switch(ch)
 {
  case 1: success(f,w);
          break;
          
  case 2: goback_n(f,w);
          break;
   
  case 3: selective_repeat(f,w);
          break;
 }
 cout<<"\nDo you want to continue?(0/1):";
 cin>>ans; 
 }while(ans!=0);
 return 0;
}

