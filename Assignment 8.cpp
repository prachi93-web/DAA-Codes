/*Name : Prachi Mehetre
Roll no. : 47
Class : TY-B2
Assignment 8 : Develop a program to implement Graph Coloring using backtracking method.
*/
#include<iostream>
using namespace std;
int count=0;
bool safe(int graph[20][20],int color[20],int cv,int c,int V)
{
    for(int i=0;i<V;i++)
    {
        if(graph[cv][i]==1 && color[i]==c)      //cv is current vertex and c is current color
        {
            return false;
        }
    }
    return true;
}
bool Coloring(int graph[20][20],int color[20],int cv,int V,int m)
{
    if(cv==V)          //cv is current vertex
    {
        count++;
        cout<<"Solution "<<count<<" : \n";
        for(int i=0;i<V;i++)
        {
            cout<<"Vertex : "<<i+1<<" ---> Color : "<<color[i]<<endl;
        }
        cout<<endl;
        return true;
    }
    bool found=false;
    //trying diff colors for cv vertex
    for(int c=1;c<=m;c++)     //c is current color
    {
        if(safe(graph,color,cv,c,V))
        {
            color[cv]=c;
            if(Coloring(graph,color,cv+1,V,m))
            {
                found=true;
            }
        }
        color[cv]=0;  //backtracking if neighbouring colors are same.
    }
    return true;
}
bool graphcolor(int graph[20][20],int V,int m)
{
    int color[20]={0};
    if(!Coloring(graph,color,0,V,m))
    {
        cout<<"No solution exist.\n";
        return false;
    }
    return true;
}
int main()
{
    int graph[20][20],i,j,V,m;
    cout<<"Enter the no. of vertices : ";
    cin>>V;
    cout<<"Enter the adjacency matrix for it : \n";
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            cin>>graph[i][j];
        }
    }
    cout<<"Enter the no. of colors : ";
    cin>>m;
    graphcolor(graph,V,m);
    cout<<"Total possible solutions : "<<count<<endl;
    return 0;
}
/*
OUTPUT :
/tmp/9euPqY7RnQ.o
Enter the no. of vertices : 4
Enter the adjacency matrix for it : 
0 1 0 1
1 0 1 0
0 1 0 1
1 0 1 0
Enter the no. of colors : 3
Solution 1 : 
Vertex : 1 ---> Color : 1
Vertex : 2 ---> Color : 2
Vertex : 3 ---> Color : 1
Vertex : 4 ---> Color : 2

Solution 2 : 
Vertex : 1 ---> Color : 1
Vertex : 2 ---> Color : 2
Vertex : 3 ---> Color : 1
Vertex : 4 ---> Color : 3

Solution 3 : 
Vertex : 1 ---> Color : 1
Vertex : 2 ---> Color : 2
Vertex : 3 ---> Color : 3
Vertex : 4 ---> Color : 2

Solution 4 : 
Vertex : 1 ---> Color : 1
Vertex : 2 ---> Color : 3
Vertex : 3 ---> Color : 1
Vertex : 4 ---> Color : 2

Solution 5 : 
Vertex : 1 ---> Color : 1
Vertex : 2 ---> Color : 3
Vertex : 3 ---> Color : 1
Vertex : 4 ---> Color : 3

Solution 6 : 
Vertex : 1 ---> Color : 1
Vertex : 2 ---> Color : 3
Vertex : 3 ---> Color : 2
Vertex : 4 ---> Color : 3

Solution 7 : 
Vertex : 1 ---> Color : 2
Vertex : 2 ---> Color : 1
Vertex : 3 ---> Color : 2
Vertex : 4 ---> Color : 1

Solution 8 : 
Vertex : 1 ---> Color : 2
Vertex : 2 ---> Color : 1
Vertex : 3 ---> Color : 2
Vertex : 4 ---> Color : 3

Solution 9 : 
Vertex : 1 ---> Color : 2
Vertex : 2 ---> Color : 1
Vertex : 3 ---> Color : 3
Vertex : 4 ---> Color : 1

Solution 10 : 
Vertex : 1 ---> Color : 2
Vertex : 2 ---> Color : 3
Vertex : 3 ---> Color : 1
Vertex : 4 ---> Color : 3

Solution 11 : 
Vertex : 1 ---> Color : 2
Vertex : 2 ---> Color : 3
Vertex : 3 ---> Color : 2
Vertex : 4 ---> Color : 1

Solution 12 : 
Vertex : 1 ---> Color : 2
Vertex : 2 ---> Color : 3
Vertex : 3 ---> Color : 2
Vertex : 4 ---> Color : 3

Solution 13 : 
Vertex : 1 ---> Color : 3
Vertex : 2 ---> Color : 1
Vertex : 3 ---> Color : 2
Vertex : 4 ---> Color : 1

Solution 14 : 
Vertex : 1 ---> Color : 3
Vertex : 2 ---> Color : 1
Vertex : 3 ---> Color : 3
Vertex : 4 ---> Color : 1

Solution 15 : 
Vertex : 1 ---> Color : 3
Vertex : 2 ---> Color : 1
Vertex : 3 ---> Color : 3
Vertex : 4 ---> Color : 2

Solution 16 : 
Vertex : 1 ---> Color : 3
Vertex : 2 ---> Color : 2
Vertex : 3 ---> Color : 1
Vertex : 4 ---> Color : 2

Solution 17 : 
Vertex : 1 ---> Color : 3
Vertex : 2 ---> Color : 2
Vertex : 3 ---> Color : 3
Vertex : 4 ---> Color : 1

Solution 18 : 
Vertex : 1 ---> Color : 3
Vertex : 2 ---> Color : 2
Vertex : 3 ---> Color : 3
Vertex : 4 ---> Color : 2

Total possible solutions : 18
*/