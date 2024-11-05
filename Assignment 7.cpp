/*
Name : Prachi Mehetre
Roll no. : 47
Class : TY-B2
Assignment 7 : 8-Queen matrix is stored having first queen placed use backtracking to place remaining queens to generate the final 8-queen matrix using C++.
*/
#include<iostream>
using namespace std;
const int MAX=20;
int x[MAX];
int solutionpossible=0;
void printsol(int n)
{
    solutionpossible++;
    cout<<"Solution : "<<solutionpossible<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<"Row ---> "<<i<<" column ---> "<<x[i]<<endl;
    }
    cout<<"\n";
}
bool place(int k,int i)
{
    for(int j=1;j<k;j++)
    {
        if(x[j]==i || abs(x[j]-i)==abs(j-k))
        {
            return false;
        }
    }
    return true;
}
void nqueen(int k,int n)
{
    for(int i=1;i<=n;i++)
    {
        if(place(k,i))
        {
            x[k]=i;
            if(k==n)
            {
                printsol(n);
            }
            else
            {
                nqueen(k+1,n);
            }
        }
        
    }
}
int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    nqueen(1,n);
    cout<<"Total no. of possible solutions : "<<solutionpossible<<endl;
    return 0;
}
/*
OUTPUT :
/tmp/2Wjq9GIs7y.o
Enter n : 8
Solution : 1
Row ---> 1 column ---> 1
Row ---> 2 column ---> 5
Row ---> 3 column ---> 8
Row ---> 4 column ---> 6
Row ---> 5 column ---> 3
Row ---> 6 column ---> 7
Row ---> 7 column ---> 2
Row ---> 8 column ---> 4

Solution : 2
Row ---> 1 column ---> 1
Row ---> 2 column ---> 6
Row ---> 3 column ---> 8
Row ---> 4 column ---> 3
Row ---> 5 column ---> 7
Row ---> 6 column ---> 4
Row ---> 7 column ---> 2
Row ---> 8 column ---> 5

Solution : 3
Row ---> 1 column ---> 1
Row ---> 2 column ---> 7
Row ---> 3 column ---> 4
Row ---> 4 column ---> 6
Row ---> 5 column ---> 8
Row ---> 6 column ---> 2
Row ---> 7 column ---> 5
Row ---> 8 column ---> 3

Solution : 4
Row ---> 1 column ---> 1
Row ---> 2 column ---> 7
Row ---> 3 column ---> 5
Row ---> 4 column ---> 8
Row ---> 5 column ---> 2
Row ---> 6 column ---> 4
Row ---> 7 column ---> 6
Row ---> 8 column ---> 3

Solution : 5
Row ---> 1 column ---> 2
Row ---> 2 column ---> 4
Row ---> 3 column ---> 6
Row ---> 4 column ---> 8
Row ---> 5 column ---> 3
Row ---> 6 column ---> 1
Row ---> 7 column ---> 7
Row ---> 8 column ---> 5

Solution : 6
Row ---> 1 column ---> 2
Row ---> 2 column ---> 5
Row ---> 3 column ---> 7
Row ---> 4 column ---> 1
Row ---> 5 column ---> 3
Row ---> 6 column ---> 8
Row ---> 7 column ---> 6
Row ---> 8 column ---> 4

Solution : 7
Row ---> 1 column ---> 2
Row ---> 2 column ---> 5
Row ---> 3 column ---> 7
Row ---> 4 column ---> 4
Row ---> 5 column ---> 1
Row ---> 6 column ---> 8
Row ---> 7 column ---> 6
Row ---> 8 column ---> 3

Solution : 8
Row ---> 1 column ---> 2
Row ---> 2 column ---> 6
Row ---> 3 column ---> 1
Row ---> 4 column ---> 7
Row ---> 5 column ---> 4
Row ---> 6 column ---> 8
Row ---> 7 column ---> 3
Row ---> 8 column ---> 5

Solution : 9
Row ---> 1 column ---> 2
Row ---> 2 column ---> 6
Row ---> 3 column ---> 8
Row ---> 4 column ---> 3
Row ---> 5 column ---> 1
Row ---> 6 column ---> 4
Row ---> 7 column ---> 7
Row ---> 8 column ---> 5

Solution : 10
Row ---> 1 column ---> 2
Row ---> 2 column ---> 7
Row ---> 3 column ---> 3
Row ---> 4 column ---> 6
Row ---> 5 column ---> 8
Row ---> 6 column ---> 5
Row ---> 7 column ---> 1
Row ---> 8 column ---> 4

Solution : 11
Row ---> 1 column ---> 2
Row ---> 2 column ---> 7
Row ---> 3 column ---> 5
Row ---> 4 column ---> 8
Row ---> 5 column ---> 1
Row ---> 6 column ---> 4
Row ---> 7 column ---> 6
Row ---> 8 column ---> 3

Solution : 12
Row ---> 1 column ---> 2
Row ---> 2 column ---> 8
Row ---> 3 column ---> 6
Row ---> 4 column ---> 1
Row ---> 5 column ---> 3
Row ---> 6 column ---> 5
Row ---> 7 column ---> 7
Row ---> 8 column ---> 4

Solution : 13
Row ---> 1 column ---> 3
Row ---> 2 column ---> 1
Row ---> 3 column ---> 7
Row ---> 4 column ---> 5
Row ---> 5 column ---> 8
Row ---> 6 column ---> 2
Row ---> 7 column ---> 4
Row ---> 8 column ---> 6

Solution : 14
Row ---> 1 column ---> 3
Row ---> 2 column ---> 5
Row ---> 3 column ---> 2
Row ---> 4 column ---> 8
Row ---> 5 column ---> 1
Row ---> 6 column ---> 7
Row ---> 7 column ---> 4
Row ---> 8 column ---> 6

Solution : 15
Row ---> 1 column ---> 3
Row ---> 2 column ---> 5
Row ---> 3 column ---> 2
Row ---> 4 column ---> 8
Row ---> 5 column ---> 6
Row ---> 6 column ---> 4
Row ---> 7 column ---> 7
Row ---> 8 column ---> 1

Solution : 16
Row ---> 1 column ---> 3
Row ---> 2 column ---> 5
Row ---> 3 column ---> 7
Row ---> 4 column ---> 1
Row ---> 5 column ---> 4
Row ---> 6 column ---> 2
Row ---> 7 column ---> 8
Row ---> 8 column ---> 6

Solution : 17
Row ---> 1 column ---> 3
Row ---> 2 column ---> 5
Row ---> 3 column ---> 8
Row ---> 4 column ---> 4
Row ---> 5 column ---> 1
Row ---> 6 column ---> 7
Row ---> 7 column ---> 2
Row ---> 8 column ---> 6

Solution : 18
Row ---> 1 column ---> 3
Row ---> 2 column ---> 6
Row ---> 3 column ---> 2
Row ---> 4 column ---> 5
Row ---> 5 column ---> 8
Row ---> 6 column ---> 1
Row ---> 7 column ---> 7
Row ---> 8 column ---> 4

Solution : 19
Row ---> 1 column ---> 3
Row ---> 2 column ---> 6
Row ---> 3 column ---> 2
Row ---> 4 column ---> 7
Row ---> 5 column ---> 1
Row ---> 6 column ---> 4
Row ---> 7 column ---> 8
Row ---> 8 column ---> 5

Solution : 20
Row ---> 1 column ---> 3
Row ---> 2 column ---> 6
Row ---> 3 column ---> 2
Row ---> 4 column ---> 7
Row ---> 5 column ---> 5
Row ---> 6 column ---> 1
Row ---> 7 column ---> 8
Row ---> 8 column ---> 4

Solution : 21
Row ---> 1 column ---> 3
Row ---> 2 column ---> 6
Row ---> 3 column ---> 4
Row ---> 4 column ---> 1
Row ---> 5 column ---> 8
Row ---> 6 column ---> 5
Row ---> 7 column ---> 7
Row ---> 8 column ---> 2

Solution : 22
Row ---> 1 column ---> 3
Row ---> 2 column ---> 6
Row ---> 3 column ---> 4
Row ---> 4 column ---> 2
Row ---> 5 column ---> 8
Row ---> 6 column ---> 5
Row ---> 7 column ---> 7
Row ---> 8 column ---> 1

Solution : 23
Row ---> 1 column ---> 3
Row ---> 2 column ---> 6
Row ---> 3 column ---> 8
Row ---> 4 column ---> 1
Row ---> 5 column ---> 4
Row ---> 6 column ---> 7
Row ---> 7 column ---> 5
Row ---> 8 column ---> 2

Solution : 24
Row ---> 1 column ---> 3
Row ---> 2 column ---> 6
Row ---> 3 column ---> 8
Row ---> 4 column ---> 1
Row ---> 5 column ---> 5
Row ---> 6 column ---> 7
Row ---> 7 column ---> 2
Row ---> 8 column ---> 4

Solution : 25
Row ---> 1 column ---> 3
Row ---> 2 column ---> 6
Row ---> 3 column ---> 8
Row ---> 4 column ---> 2
Row ---> 5 column ---> 4
Row ---> 6 column ---> 1
Row ---> 7 column ---> 7
Row ---> 8 column ---> 5

Solution : 26
Row ---> 1 column ---> 3
Row ---> 2 column ---> 7
Row ---> 3 column ---> 2
Row ---> 4 column ---> 8
Row ---> 5 column ---> 5
Row ---> 6 column ---> 1
Row ---> 7 column ---> 4
Row ---> 8 column ---> 6

Solution : 27
Row ---> 1 column ---> 3
Row ---> 2 column ---> 7
Row ---> 3 column ---> 2
Row ---> 4 column ---> 8
Row ---> 5 column ---> 6
Row ---> 6 column ---> 4
Row ---> 7 column ---> 1
Row ---> 8 column ---> 5

Solution : 28
Row ---> 1 column ---> 3
Row ---> 2 column ---> 8
Row ---> 3 column ---> 4
Row ---> 4 column ---> 7
Row ---> 5 column ---> 1
Row ---> 6 column ---> 6
Row ---> 7 column ---> 2
Row ---> 8 column ---> 5

Solution : 29
Row ---> 1 column ---> 4
Row ---> 2 column ---> 1
Row ---> 3 column ---> 5
Row ---> 4 column ---> 8
Row ---> 5 column ---> 2
Row ---> 6 column ---> 7
Row ---> 7 column ---> 3
Row ---> 8 column ---> 6

Solution : 30
Row ---> 1 column ---> 4
Row ---> 2 column ---> 1
Row ---> 3 column ---> 5
Row ---> 4 column ---> 8
Row ---> 5 column ---> 6
Row ---> 6 column ---> 3
Row ---> 7 column ---> 7
Row ---> 8 column ---> 2

Solution : 31
Row ---> 1 column ---> 4
Row ---> 2 column ---> 2
Row ---> 3 column ---> 5
Row ---> 4 column ---> 8
Row ---> 5 column ---> 6
Row ---> 6 column ---> 1
Row ---> 7 column ---> 3
Row ---> 8 column ---> 7

Solution : 32
Row ---> 1 column ---> 4
Row ---> 2 column ---> 2
Row ---> 3 column ---> 7
Row ---> 4 column ---> 3
Row ---> 5 column ---> 6
Row ---> 6 column ---> 8
Row ---> 7 column ---> 1
Row ---> 8 column ---> 5

Solution : 33
Row ---> 1 column ---> 4
Row ---> 2 column ---> 2
Row ---> 3 column ---> 7
Row ---> 4 column ---> 3
Row ---> 5 column ---> 6
Row ---> 6 column ---> 8
Row ---> 7 column ---> 5
Row ---> 8 column ---> 1

Solution : 34
Row ---> 1 column ---> 4
Row ---> 2 column ---> 2
Row ---> 3 column ---> 7
Row ---> 4 column ---> 5
Row ---> 5 column ---> 1
Row ---> 6 column ---> 8
Row ---> 7 column ---> 6
Row ---> 8 column ---> 3

Solution : 35
Row ---> 1 column ---> 4
Row ---> 2 column ---> 2
Row ---> 3 column ---> 8
Row ---> 4 column ---> 5
Row ---> 5 column ---> 7
Row ---> 6 column ---> 1
Row ---> 7 column ---> 3
Row ---> 8 column ---> 6

Solution : 36
Row ---> 1 column ---> 4
Row ---> 2 column ---> 2
Row ---> 3 column ---> 8
Row ---> 4 column ---> 6
Row ---> 5 column ---> 1
Row ---> 6 column ---> 3
Row ---> 7 column ---> 5
Row ---> 8 column ---> 7

Solution : 37
Row ---> 1 column ---> 4
Row ---> 2 column ---> 6
Row ---> 3 column ---> 1
Row ---> 4 column ---> 5
Row ---> 5 column ---> 2
Row ---> 6 column ---> 8
Row ---> 7 column ---> 3
Row ---> 8 column ---> 7

Solution : 38
Row ---> 1 column ---> 4
Row ---> 2 column ---> 6
Row ---> 3 column ---> 8
Row ---> 4 column ---> 2
Row ---> 5 column ---> 7
Row ---> 6 column ---> 1
Row ---> 7 column ---> 3
Row ---> 8 column ---> 5

Solution : 39
Row ---> 1 column ---> 4
Row ---> 2 column ---> 6
Row ---> 3 column ---> 8
Row ---> 4 column ---> 3
Row ---> 5 column ---> 1
Row ---> 6 column ---> 7
Row ---> 7 column ---> 5
Row ---> 8 column ---> 2

Solution : 40
Row ---> 1 column ---> 4
Row ---> 2 column ---> 7
Row ---> 3 column ---> 1
Row ---> 4 column ---> 8
Row ---> 5 column ---> 5
Row ---> 6 column ---> 2
Row ---> 7 column ---> 6
Row ---> 8 column ---> 3

Solution : 41
Row ---> 1 column ---> 4
Row ---> 2 column ---> 7
Row ---> 3 column ---> 3
Row ---> 4 column ---> 8
Row ---> 5 column ---> 2
Row ---> 6 column ---> 5
Row ---> 7 column ---> 1
Row ---> 8 column ---> 6

Solution : 42
Row ---> 1 column ---> 4
Row ---> 2 column ---> 7
Row ---> 3 column ---> 5
Row ---> 4 column ---> 2
Row ---> 5 column ---> 6
Row ---> 6 column ---> 1
Row ---> 7 column ---> 3
Row ---> 8 column ---> 8

Solution : 43
Row ---> 1 column ---> 4
Row ---> 2 column ---> 7
Row ---> 3 column ---> 5
Row ---> 4 column ---> 3
Row ---> 5 column ---> 1
Row ---> 6 column ---> 6
Row ---> 7 column ---> 8
Row ---> 8 column ---> 2

Solution : 44
Row ---> 1 column ---> 4
Row ---> 2 column ---> 8
Row ---> 3 column ---> 1
Row ---> 4 column ---> 3
Row ---> 5 column ---> 6
Row ---> 6 column ---> 2
Row ---> 7 column ---> 7
Row ---> 8 column ---> 5

Solution : 45
Row ---> 1 column ---> 4
Row ---> 2 column ---> 8
Row ---> 3 column ---> 1
Row ---> 4 column ---> 5
Row ---> 5 column ---> 7
Row ---> 6 column ---> 2
Row ---> 7 column ---> 6
Row ---> 8 column ---> 3

Solution : 46
Row ---> 1 column ---> 4
Row ---> 2 column ---> 8
Row ---> 3 column ---> 5
Row ---> 4 column ---> 3
Row ---> 5 column ---> 1
Row ---> 6 column ---> 7
Row ---> 7 column ---> 2
Row ---> 8 column ---> 6

Solution : 47
Row ---> 1 column ---> 5
Row ---> 2 column ---> 1
Row ---> 3 column ---> 4
Row ---> 4 column ---> 6
Row ---> 5 column ---> 8
Row ---> 6 column ---> 2
Row ---> 7 column ---> 7
Row ---> 8 column ---> 3

Solution : 48
Row ---> 1 column ---> 5
Row ---> 2 column ---> 1
Row ---> 3 column ---> 8
Row ---> 4 column ---> 4
Row ---> 5 column ---> 2
Row ---> 6 column ---> 7
Row ---> 7 column ---> 3
Row ---> 8 column ---> 6

Solution : 49
Row ---> 1 column ---> 5
Row ---> 2 column ---> 1
Row ---> 3 column ---> 8
Row ---> 4 column ---> 6
Row ---> 5 column ---> 3
Row ---> 6 column ---> 7
Row ---> 7 column ---> 2
Row ---> 8 column ---> 4

Solution : 50
Row ---> 1 column ---> 5
Row ---> 2 column ---> 2
Row ---> 3 column ---> 4
Row ---> 4 column ---> 6
Row ---> 5 column ---> 8
Row ---> 6 column ---> 3
Row ---> 7 column ---> 1
Row ---> 8 column ---> 7

Solution : 51
Row ---> 1 column ---> 5
Row ---> 2 column ---> 2
Row ---> 3 column ---> 4
Row ---> 4 column ---> 7
Row ---> 5 column ---> 3
Row ---> 6 column ---> 8
Row ---> 7 column ---> 6
Row ---> 8 column ---> 1

Solution : 52
Row ---> 1 column ---> 5
Row ---> 2 column ---> 2
Row ---> 3 column ---> 6
Row ---> 4 column ---> 1
Row ---> 5 column ---> 7
Row ---> 6 column ---> 4
Row ---> 7 column ---> 8
Row ---> 8 column ---> 3

Solution : 53
Row ---> 1 column ---> 5
Row ---> 2 column ---> 2
Row ---> 3 column ---> 8
Row ---> 4 column ---> 1
Row ---> 5 column ---> 4
Row ---> 6 column ---> 7
Row ---> 7 column ---> 3
Row ---> 8 column ---> 6

Solution : 54
Row ---> 1 column ---> 5
Row ---> 2 column ---> 3
Row ---> 3 column ---> 1
Row ---> 4 column ---> 6
Row ---> 5 column ---> 8
Row ---> 6 column ---> 2
Row ---> 7 column ---> 4
Row ---> 8 column ---> 7

Solution : 55
Row ---> 1 column ---> 5
Row ---> 2 column ---> 3
Row ---> 3 column ---> 1
Row ---> 4 column ---> 7
Row ---> 5 column ---> 2
Row ---> 6 column ---> 8
Row ---> 7 column ---> 6
Row ---> 8 column ---> 4

Solution : 56
Row ---> 1 column ---> 5
Row ---> 2 column ---> 3
Row ---> 3 column ---> 8
Row ---> 4 column ---> 4
Row ---> 5 column ---> 7
Row ---> 6 column ---> 1
Row ---> 7 column ---> 6
Row ---> 8 column ---> 2

Solution : 57
Row ---> 1 column ---> 5
Row ---> 2 column ---> 7
Row ---> 3 column ---> 1
Row ---> 4 column ---> 3
Row ---> 5 column ---> 8
Row ---> 6 column ---> 6
Row ---> 7 column ---> 4
Row ---> 8 column ---> 2

Solution : 58
Row ---> 1 column ---> 5
Row ---> 2 column ---> 7
Row ---> 3 column ---> 1
Row ---> 4 column ---> 4
Row ---> 5 column ---> 2
Row ---> 6 column ---> 8
Row ---> 7 column ---> 6
Row ---> 8 column ---> 3

Solution : 59
Row ---> 1 column ---> 5
Row ---> 2 column ---> 7
Row ---> 3 column ---> 2
Row ---> 4 column ---> 4
Row ---> 5 column ---> 8
Row ---> 6 column ---> 1
Row ---> 7 column ---> 3
Row ---> 8 column ---> 6

Solution : 60
Row ---> 1 column ---> 5
Row ---> 2 column ---> 7
Row ---> 3 column ---> 2
Row ---> 4 column ---> 6
Row ---> 5 column ---> 3
Row ---> 6 column ---> 1
Row ---> 7 column ---> 4
Row ---> 8 column ---> 8

Solution : 61
Row ---> 1 column ---> 5
Row ---> 2 column ---> 7
Row ---> 3 column ---> 2
Row ---> 4 column ---> 6
Row ---> 5 column ---> 3
Row ---> 6 column ---> 1
Row ---> 7 column ---> 8
Row ---> 8 column ---> 4

Solution : 62
Row ---> 1 column ---> 5
Row ---> 2 column ---> 7
Row ---> 3 column ---> 4
Row ---> 4 column ---> 1
Row ---> 5 column ---> 3
Row ---> 6 column ---> 8
Row ---> 7 column ---> 6
Row ---> 8 column ---> 2

Solution : 63
Row ---> 1 column ---> 5
Row ---> 2 column ---> 8
Row ---> 3 column ---> 4
Row ---> 4 column ---> 1
Row ---> 5 column ---> 3
Row ---> 6 column ---> 6
Row ---> 7 column ---> 2
Row ---> 8 column ---> 7

Solution : 64
Row ---> 1 column ---> 5
Row ---> 2 column ---> 8
Row ---> 3 column ---> 4
Row ---> 4 column ---> 1
Row ---> 5 column ---> 7
Row ---> 6 column ---> 2
Row ---> 7 column ---> 6
Row ---> 8 column ---> 3

Solution : 65
Row ---> 1 column ---> 6
Row ---> 2 column ---> 1
Row ---> 3 column ---> 5
Row ---> 4 column ---> 2
Row ---> 5 column ---> 8
Row ---> 6 column ---> 3
Row ---> 7 column ---> 7
Row ---> 8 column ---> 4

Solution : 66
Row ---> 1 column ---> 6
Row ---> 2 column ---> 2
Row ---> 3 column ---> 7
Row ---> 4 column ---> 1
Row ---> 5 column ---> 3
Row ---> 6 column ---> 5
Row ---> 7 column ---> 8
Row ---> 8 column ---> 4

Solution : 67
Row ---> 1 column ---> 6
Row ---> 2 column ---> 2
Row ---> 3 column ---> 7
Row ---> 4 column ---> 1
Row ---> 5 column ---> 4
Row ---> 6 column ---> 8
Row ---> 7 column ---> 5
Row ---> 8 column ---> 3

Solution : 68
Row ---> 1 column ---> 6
Row ---> 2 column ---> 3
Row ---> 3 column ---> 1
Row ---> 4 column ---> 7
Row ---> 5 column ---> 5
Row ---> 6 column ---> 8
Row ---> 7 column ---> 2
Row ---> 8 column ---> 4

Solution : 69
Row ---> 1 column ---> 6
Row ---> 2 column ---> 3
Row ---> 3 column ---> 1
Row ---> 4 column ---> 8
Row ---> 5 column ---> 4
Row ---> 6 column ---> 2
Row ---> 7 column ---> 7
Row ---> 8 column ---> 5

Solution : 70
Row ---> 1 column ---> 6
Row ---> 2 column ---> 3
Row ---> 3 column ---> 1
Row ---> 4 column ---> 8
Row ---> 5 column ---> 5
Row ---> 6 column ---> 2
Row ---> 7 column ---> 4
Row ---> 8 column ---> 7

Solution : 71
Row ---> 1 column ---> 6
Row ---> 2 column ---> 3
Row ---> 3 column ---> 5
Row ---> 4 column ---> 7
Row ---> 5 column ---> 1
Row ---> 6 column ---> 4
Row ---> 7 column ---> 2
Row ---> 8 column ---> 8

Solution : 72
Row ---> 1 column ---> 6
Row ---> 2 column ---> 3
Row ---> 3 column ---> 5
Row ---> 4 column ---> 8
Row ---> 5 column ---> 1
Row ---> 6 column ---> 4
Row ---> 7 column ---> 2
Row ---> 8 column ---> 7

Solution : 73
Row ---> 1 column ---> 6
Row ---> 2 column ---> 3
Row ---> 3 column ---> 7
Row ---> 4 column ---> 2
Row ---> 5 column ---> 4
Row ---> 6 column ---> 8
Row ---> 7 column ---> 1
Row ---> 8 column ---> 5

Solution : 74
Row ---> 1 column ---> 6
Row ---> 2 column ---> 3
Row ---> 3 column ---> 7
Row ---> 4 column ---> 2
Row ---> 5 column ---> 8
Row ---> 6 column ---> 5
Row ---> 7 column ---> 1
Row ---> 8 column ---> 4

Solution : 75
Row ---> 1 column ---> 6
Row ---> 2 column ---> 3
Row ---> 3 column ---> 7
Row ---> 4 column ---> 4
Row ---> 5 column ---> 1
Row ---> 6 column ---> 8
Row ---> 7 column ---> 2
Row ---> 8 column ---> 5

Solution : 76
Row ---> 1 column ---> 6
Row ---> 2 column ---> 4
Row ---> 3 column ---> 1
Row ---> 4 column ---> 5
Row ---> 5 column ---> 8
Row ---> 6 column ---> 2
Row ---> 7 column ---> 7
Row ---> 8 column ---> 3

Solution : 77
Row ---> 1 column ---> 6
Row ---> 2 column ---> 4
Row ---> 3 column ---> 2
Row ---> 4 column ---> 8
Row ---> 5 column ---> 5
Row ---> 6 column ---> 7
Row ---> 7 column ---> 1
Row ---> 8 column ---> 3

Solution : 78
Row ---> 1 column ---> 6
Row ---> 2 column ---> 4
Row ---> 3 column ---> 7
Row ---> 4 column ---> 1
Row ---> 5 column ---> 3
Row ---> 6 column ---> 5
Row ---> 7 column ---> 2
Row ---> 8 column ---> 8

Solution : 79
Row ---> 1 column ---> 6
Row ---> 2 column ---> 4
Row ---> 3 column ---> 7
Row ---> 4 column ---> 1
Row ---> 5 column ---> 8
Row ---> 6 column ---> 2
Row ---> 7 column ---> 5
Row ---> 8 column ---> 3

Solution : 80
Row ---> 1 column ---> 6
Row ---> 2 column ---> 8
Row ---> 3 column ---> 2
Row ---> 4 column ---> 4
Row ---> 5 column ---> 1
Row ---> 6 column ---> 7
Row ---> 7 column ---> 5
Row ---> 8 column ---> 3

Solution : 81
Row ---> 1 column ---> 7
Row ---> 2 column ---> 1
Row ---> 3 column ---> 3
Row ---> 4 column ---> 8
Row ---> 5 column ---> 6
Row ---> 6 column ---> 4
Row ---> 7 column ---> 2
Row ---> 8 column ---> 5

Solution : 82
Row ---> 1 column ---> 7
Row ---> 2 column ---> 2
Row ---> 3 column ---> 4
Row ---> 4 column ---> 1
Row ---> 5 column ---> 8
Row ---> 6 column ---> 5
Row ---> 7 column ---> 3
Row ---> 8 column ---> 6

Solution : 83
Row ---> 1 column ---> 7
Row ---> 2 column ---> 2
Row ---> 3 column ---> 6
Row ---> 4 column ---> 3
Row ---> 5 column ---> 1
Row ---> 6 column ---> 4
Row ---> 7 column ---> 8
Row ---> 8 column ---> 5

Solution : 84
Row ---> 1 column ---> 7
Row ---> 2 column ---> 3
Row ---> 3 column ---> 1
Row ---> 4 column ---> 6
Row ---> 5 column ---> 8
Row ---> 6 column ---> 5
Row ---> 7 column ---> 2
Row ---> 8 column ---> 4

Solution : 85
Row ---> 1 column ---> 7
Row ---> 2 column ---> 3
Row ---> 3 column ---> 8
Row ---> 4 column ---> 2
Row ---> 5 column ---> 5
Row ---> 6 column ---> 1
Row ---> 7 column ---> 6
Row ---> 8 column ---> 4

Solution : 86
Row ---> 1 column ---> 7
Row ---> 2 column ---> 4
Row ---> 3 column ---> 2
Row ---> 4 column ---> 5
Row ---> 5 column ---> 8
Row ---> 6 column ---> 1
Row ---> 7 column ---> 3
Row ---> 8 column ---> 6

Solution : 87
Row ---> 1 column ---> 7
Row ---> 2 column ---> 4
Row ---> 3 column ---> 2
Row ---> 4 column ---> 8
Row ---> 5 column ---> 6
Row ---> 6 column ---> 1
Row ---> 7 column ---> 3
Row ---> 8 column ---> 5

Solution : 88
Row ---> 1 column ---> 7
Row ---> 2 column ---> 5
Row ---> 3 column ---> 3
Row ---> 4 column ---> 1
Row ---> 5 column ---> 6
Row ---> 6 column ---> 8
Row ---> 7 column ---> 2
Row ---> 8 column ---> 4

Solution : 89
Row ---> 1 column ---> 8
Row ---> 2 column ---> 2
Row ---> 3 column ---> 4
Row ---> 4 column ---> 1
Row ---> 5 column ---> 7
Row ---> 6 column ---> 5
Row ---> 7 column ---> 3
Row ---> 8 column ---> 6

Solution : 90
Row ---> 1 column ---> 8
Row ---> 2 column ---> 2
Row ---> 3 column ---> 5
Row ---> 4 column ---> 3
Row ---> 5 column ---> 1
Row ---> 6 column ---> 7
Row ---> 7 column ---> 4
Row ---> 8 column ---> 6

Solution : 91
Row ---> 1 column ---> 8
Row ---> 2 column ---> 3
Row ---> 3 column ---> 1
Row ---> 4 column ---> 6
Row ---> 5 column ---> 2
Row ---> 6 column ---> 5
Row ---> 7 column ---> 7
Row ---> 8 column ---> 4

Solution : 92
Row ---> 1 column ---> 8
Row ---> 2 column ---> 4
Row ---> 3 column ---> 1
Row ---> 4 column ---> 3
Row ---> 5 column ---> 6
Row ---> 6 column ---> 2
Row ---> 7 column ---> 7
Row ---> 8 column ---> 5

Total no. of possible solutions : 92


=== Code Execution Successful ===*/
