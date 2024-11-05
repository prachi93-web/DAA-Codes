/*
Name : Prachi Mehetre
Roll no. : 47
Class : TY-B2
Assignment 2 : Develop a program to design a class for Concurrent Quick Sort Using Divide and Conquer Strategies. Also Compute it's time complexity.
*/
#include<iostream>
using namespace std;
class sort
{
    public :
    void quicksort(int arr[],int p,int q,int n);
    void interchange(int arr[],int i,int j);
    int partition(int arr[],int start,int end,int n);
    void printarray(int arr[],int n);
};
void sort :: quicksort(int arr[],int p,int q,int n)
{
    if(p<q)
    {
        int j=partition(arr,p,q,n);
        cout<<"After partition with pivot index "<<j<<" : ";
        printarray(arr,n);
        quicksort(arr,p,j-1,n);
        quicksort(arr,j+1,q,n);
    }
}
void sort :: interchange(int arr[],int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
void sort :: printarray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int sort :: partition(int arr[],int start,int end,int n)
{
    int pivot=arr[start];
    int i=start;
    int j=end;
    while(i<j)
    {
        while(i<j && arr[j]>=pivot)  //check jth element first
        {
            j--;
        }
        while(i<j && arr[i]<=pivot)
        {
            i++;
        }
        if(i<j)
        {
            interchange(arr,i,j);
            cout<<"Swapped "<<arr[i]<<" "<<arr[j]<<" : ";
            printarray(arr,n);
        }
    }
    interchange(arr,start,j);
    //printarray(arr,n);
    return j;
}
int main()
{
    sort s;
    int arr[25],i,j,n;
    cout<<"Enter n : ";
    cin>>n;
    cout<<"Enter the elements : ";
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Initial array : ";
    s.printarray(arr,n);
    s.quicksort(arr,0,n-1,n);
    cout<<"Sorted Array : ";
    s.printarray(arr,n);
    return 0;
}
/*
OUTPUT :
Enter n : 8
Enter the elements : 5 3 1 9 8 2 4 7
Initial array : 5 3 1 9 8 2 4 7 
Swapped 4 9 : 5 3 1 4 8 2 9 7 
Swapped 2 8 : 5 3 1 4 2 8 9 7 
After partition with pivot index 4 : 2 3 1 4 5 8 9 7 
Swapped 1 3 : 2 1 3 4 5 8 9 7 
After partition with pivot index 1 : 1 2 3 4 5 8 9 7 
After partition with pivot index 2 : 1 2 3 4 5 8 9 7 
Swapped 7 9 : 1 2 3 4 5 8 7 9 
After partition with pivot index 6 : 1 2 3 4 5 7 8 9 
Sorted Array : 1 2 3 4 5 7 8 9 
*/