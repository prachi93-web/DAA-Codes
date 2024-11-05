/*
Name : Prachi Mehetre
Roll no. : 47
Class : TY-B2
Assignment 10 : Develop a program for Travelling Salesman Problem using Branch and Bound.  
*/
#include<iostream>
#include<climits>
using namespace std;

const int MAX = 100; 
int N;
int final_res = INT_MAX;
int final_path[MAX + 1];
bool visited[MAX];

// Function to copy temporary solution to the final solution
void copyToFinal(int curr_path[])
{
    for (int i = 0; i < N; i++)
        final_path[i] = curr_path[i];
    final_path[N] = curr_path[0];
}

// Function to find the minimum edge cost having an end at the vertex i
int firstMin(int adj[MAX][MAX], int i)
{
    int min = INT_MAX;
    for (int k = 0; k < N; k++)
        if (adj[i][k] < min && i != k)
            min = adj[i][k];
    return min;
}

// Function to find the second minimum edge cost having an end at the vertex i
int secondMin(int adj[MAX][MAX], int i)
{
    int first = INT_MAX, second = INT_MAX;
    for (int j = 0; j < N; j++)
    {
        if (i == j)
            continue;

        if (adj[i][j] <= first)
        {
            second = first;
            first = adj[i][j];
        }
        else if (adj[i][j] <= second && adj[i][j] != first)
            second = adj[i][j];
    }
    return second;
}

// Recursive function for TSP
void TSPRec(int adj[MAX][MAX], int curr_bound, int curr_weight, int level, int curr_path[])
{
    if (level == N)
    {
        if (adj[curr_path[level - 1]][curr_path[0]] != 0)
        {
            int curr_res = curr_weight + adj[curr_path[level - 1]][curr_path[0]];
            if (curr_res < final_res)
            {
                copyToFinal(curr_path);
                final_res = curr_res;
            }
        }
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (adj[curr_path[level - 1]][i] != 0 && !visited[i])
        {
            int temp = curr_bound;
            curr_weight += adj[curr_path[level - 1]][i];

            if (level == 1)
                curr_bound -= ((firstMin(adj, curr_path[level - 1]) + firstMin(adj, i)) / 2);
            else
                curr_bound -= ((secondMin(adj, curr_path[level - 1]) + firstMin(adj, i)) / 2);

            if (curr_bound + curr_weight < final_res)
            {
                curr_path[level] = i;
                visited[i] = true;
                TSPRec(adj, curr_bound, curr_weight, level + 1, curr_path);
            }

            curr_weight -= adj[curr_path[level - 1]][i];
            curr_bound = temp;

            // Reset the visited array
            for (int j = 0; j < N; j++)
                visited[j] = false;
            for (int j = 0; j <= level - 1; j++)
                visited[curr_path[j]] = true;
        }
    }
}

// This function sets up final_path[]
void TSP(int adj[MAX][MAX])
{
    int curr_path[MAX + 1];
    for (int i = 0; i <= MAX; i++)
        curr_path[i] = -1;

    int curr_bound = 0;

    for (int i = 0; i < N; i++)
        visited[i] = false;

    for (int i = 0; i < N; i++)
        curr_bound += (firstMin(adj, i) + secondMin(adj, i));

    curr_bound = (curr_bound & 1) ? curr_bound / 2 + 1 : curr_bound / 2;

    visited[0] = true;
    curr_path[0] = 0;

    TSPRec(adj, curr_bound, 0, 1, curr_path);
}

// Driver code
int main()
{
    cout << "Enter the number of cities: ";
    cin >> N;

    int adj[MAX][MAX];
    cout << "Enter the adjacency matrix (use 0 for no direct path between cities):\n";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> adj[i][j];

    TSP(adj);

    cout << "Minimum cost : " << final_res << endl;
    cout << "Path Taken : ";
    for (int i = 0; i <= N; i++)
        cout << final_path[i] << " ";

    return 0;
}
/*
Enter the number of cities: 4
Enter the adjacency matrix (use 0 for no direct path between cities):
0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0
Minimum cost : 80
Path Taken : 0 1 3 2 0 
*/
