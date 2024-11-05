/*
Name : Prachi Mehetre
Roll no. : 47
Class : TY-B2
Assignment 4 : Develop a program to solve a fractional Knapsack problem using a greedy method. 
*/
#include<iostream>
using namespace std;
class knapsack
{
    public :
            int p[20],w[20],i,j,n,m;
            float x[20],divi[20];
    public :
            void sortitems()
            {
                for(i=0;i<n;i++)
                {
                    for(j=0;j<n-1;j++)
                    {
                        if(divi[j]<divi[j+1])
                        {
                            swap(p[j],p[j+1]);
                            swap(w[j],w[j+1]);
                            swap(divi[j],divi[j+1]);
                        }
                    }
                }
                cout<<"\nStep 2 : Arranging in descending order\n";
                cout<<"----------------------------------\n";
                cout<<"Obj\t\t|\t";
                for(i=0;i<n;i++)
                {
                    cout<<i+1<<"\t|\t";
                }
                cout<<"\n";
                cout<<"Pi\t\t|\t";
                for(i=0;i<n;i++)
                {
                    cout<<p[i]<<"\t|\t";
                }
                cout<<"\n";
                cout<<"Wi\t\t|\t";
                for(i=0;i<n;i++)
                {
                    cout<<w[i]<<"\t|\t";
                }
                cout<<"\n";
                cout<<"Pi/Wi\t|\t";
                for(i=0;i<n;i++)
                {
                    cout<<divi[i]<<"\t|\t";
                }
                cout<<"\n----------------------------------\n";
                cout<<"\n";
            }
            void knap()
            {
                sortitems();
                for(i=0;i<n;i++)
                {
                    x[i]=0.0;
                }
                int u=m;
                for(i=0;i<n;i++)
                {
                    if(w[i]>u)
                    {
                        break;
                    }
                    x[i]=1.0;
                    u=u-w[i];
                }
                if(u>0 && i<n)
                {
                    x[i]=(float)u/w[i];
                }
                display();
            }
            void display()
            {
                float total=0.0;
                cout<<"Step 3 : Computing the profit \n";
                cout<<"--------------------------------\n";
                cout<<"Obj\tPi\tWi\tXi\tWiXi\t\tPiWi\n";
                cout<<"--------------------------------\n";
                for(i=0;i<n;i++)
                {
                    cout<<i+1<<"\t"<<p[i]<<"\t"<<w[i]<<"\t"<<x[i]<<"\t"<<w[i]*x[i]<<"\t\t"<<p[i]*x[i]<<"\n";
                    total+=(p[i]*x[i]);
                }
                cout<<"--------------------------------\n\n";
                cout<<"Total Profit : "<<total;
            }
};
int main()
{
    knapsack k;
    int i,j;
    cout<<"Enter n : ";
    cin>>k.n;
    cout<<"Enter capacity : ";
    cin>>k.m;
    cout<<"Enter profit : ";
    for(i=0;i<k.n;i++)
    {
        cin>>k.p[i];
    }
    cout<<"Enter weight : ";
    for(i=0;i<k.n;i++)
    {
        cin>>k.w[i];
    }
    for(i=0;i<k.n;i++)
    {
        k.divi[i]=(float)k.p[i]/k.w[i];
    }
    cout<<"Step 1 : Initial State \n";
    cout<<"---------------------------------\n";
    cout<<"Obj\t\t|\t";
    for(i=0;i<k.n;i++)
    {
        cout<<i+1<<"\t|\t";
    }
    cout<<"\n";
    cout<<"Pi\t\t|\t";
    for(i=0;i<k.n;i++)
    {
        cout<<k.p[i]<<"\t|\t";
    }
    cout<<"\n";
    cout<<"Wi\t\t|\t";
    for(i=0;i<k.n;i++)
    {
        cout<<k.w[i]<<"\t|\t";
    }
    cout<<"\n";
    cout<<"Pi/Wi\t|\t";
    for(i=0;i<k.n;i++)
    {
        cout<<k.divi[i]<<"\t|\t";
    }
    cout<<"\n";
    k.knap();
    return 0;
}
/*
OUTPUT : 
Enter n : 3
Enter capacity : 20
Enter profit : 
30
21
18
Enter weight : 18
15
10
Step 1 : Initial State 
---------------------------------
Obj		|	1	|	2	|	3	|	
Pi		|	30	|	21	|	18	|	
Wi		|	18	|	15	|	10	|	
Pi/Wi	|	1.66667	|	1.4	|	1.8	|	

Step 2 : Arranging in descending order
----------------------------------
Obj		|	1	|	2	|	3	|	
Pi		|	18	|	30	|	21	|	
Wi		|	10	|	18	|	15	|	
Pi/Wi	|	1.8	|	1.66667	|	1.4	|	
----------------------------------

Step 3 : Computing the profit 
--------------------------------
Obj	Pi	Wi	Xi	WiXi		PiWi
--------------------------------
1	18	10	1	10		18
2	30	18	0.555556	10		16.6667
3	21	15	0	0		0
--------------------------------

Total Profit : 34.6667
*/