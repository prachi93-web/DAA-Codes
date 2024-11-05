/*
Name : Prachi Mehetre
Roll no. : 47
Class : TY-B2
Assignment 1 : Develop a program to design a function for Binary Search using Divide and Conquer Strategies. Also compute it's time complexity.
*/
#include<iostream>
using namespace std;
class binary
{
    public :
            int iterative(int a[],int n,int key)
            {
                int low=0,high=n;
                while(low<=high)
                {
                    int mid=(low+high)/2;
                    cout<<low<<"\t"<<mid<<"\t"<<high<<endl;
                    if(key>a[mid])
                    {
                        low=mid+1;
                    }
                    else if(key<a[mid])
                    {
                        high=mid-1;
                    }
                    else
                    {
                        return mid;
                    }
                }
                return 0;
            }
            int recursive(int a[],int low,int high,int key)
            {
                int mid=(low+high)/2;
                cout<<low<<"\t"<<mid<<"\t"<<high<<endl;
                if(low==high)
                {
                    if(key==a[low])
                    {
                        return low;
                    }
                }
                else
                {
                    mid=(low+high)/2;
                    if(key>a[mid])
                    {
                        recursive(a,mid+1,high,key);
                    }
                    else if(key<a[mid])
                    {
                        recursive(a,low,mid-1,key);
                    }
                    else
                    {
                        return mid;
                    }
                }
                return 0;
            }
};
int main()
{
    int a[25],n,i,j,temp,key,result,ch;
    binary b;
    cout<<"Enter n: ";
    cin>>n;
    cout<<"Enter the elements : ";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter the key to be searched : ";
    cin>>key;
    cout<<"Sorted Array : \n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n1.Recursive\n2.Iterative\nEnter your choice : ";
    cin>>ch;
    cout<<"\nLOW\tMID\tHIGH\n";
    if(ch==1)
    {
        result=b.recursive(a,0,n-1,key);
    }
    else if(ch==2)
    {
        result=b.iterative(a,n-1,key);
    }
    else
    {
        cout<<"Invalid choice....\nExiting the program\n";
        return 0;
    }
    return 0;
}
/*
OUTPUT :
Enter n: 14
Enter the elements : -6
0
9
7
82
54
23
-15
151
125
101
142
131
112
Enter the key to be searched : 23
Sorted Array : 
-15 -6 0 7 9 23 54 82 101 112 125 131 142 151 
1.Recursive
2.Iterative
Enter your choice : 1

LOW	MID	HIGH
0	6	13
0	2	5
3	4	5
5	5	5
*/