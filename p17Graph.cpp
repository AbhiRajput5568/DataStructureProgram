/*
16) Design, Develop and Implement a menu driven Program for the following operations on Graph(G) of Cities
a. Create a Graph of N cities using Adjacency Matrix
b. Traverse Graph using using DFS
c. Traverse Graph using using BFS method
*/
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Graph
{
private:
    int **adjMatrix; // Adjacency matrix for the graph
    int numCities;   // Number of cities (vertices)

public:
    Graph(int n)
    {
        numCities = n;
        adjMatrix = new int *[numCities];
        for (int i = 0; i < numCities; i++)
        {
            adjMatrix[i] = new int[numCities];
        }

        // Initialize the adjacency matrix with 0
        for (int i = 0; i < numCities; i++)
        {
            for (int j = 0; j < numCities; j++)
            {
                adjMatrix[i][j] = 0;
            }
        }
    }

    // Function to add an edge between two cities (vertices)
    void addEdge(int u, int v)
    {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // Undirected graph
    }

    // Function to perform DFS traversal
    void DFS(int start)
    {
        bool *visited = new bool[numCities];
        for (int i = 0; i < numCities; i++)
        {
            visited[i] = false;
        }

        stack<int> s;
        s.push(start);
        visited[start] = true;

        cout << "DFS Traversal: ";
        while (!s.empty())
        {
            int city = s.top();
            s.pop();
            cout << city << " ";

            for (int i = 0; i < numCities; i++)
            {
                if (adjMatrix[city][i] == 1 && !visited[i])
                {
                    s.push(i);
                    visited[i] = true;
                }
            }
        }
        cout << endl;
    }

    // Function to perform BFS traversal
    void BFS(int start)
    {
        bool *visited = new bool[numCities];
        for (int i = 0; i < numCities; i++)
        {
            visited[i] = false;
        }

        queue<int> q;
        q.push(start);
        visited[start] = true;

        cout << "BFS Traversal: ";
        while (!q.empty())
        {
            int city = q.front();
            q.pop();
            cout << city << " ";

            for (int i = 0; i < numCities; i++)
            {
                if (adjMatrix[city][i] == 1 && !visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        cout << endl;
    }

    // Function to display the adjacency matrix
    void displayGraph()
    {
        cout << "Adjacency Matrix: " << endl;
        for (int i = 0; i < numCities; i++)
        {
            for (int j = 0; j < numCities; j++)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    ~Graph()
    {
        for (int i = 0; i < numCities; i++)
        {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }
};

int main()

{
    cout<<"ABHISHEK SINGH 2315272/2435222";

    int numCities, choice, u, v;

    cout << "Enter the number of cities: ";
    cin >> numCities;

    Graph g(numCities);

    while (true)
    {
        cout << "\n--- Graph Operations ---\n";
        cout << "1. Create Graph\n";
        cout << "2. DFS Traversal\n";
        cout << "3. BFS Traversal\n";
        cout << "4. Display Graph\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the number of edges: ";
            int edges;
            cin >> edges;
            for (int i = 0; i < edges; i++)
            {
                cout << "Enter the cities to connect (u, v): ";
                cin >> u >> v;
                g.addEdge(u, v);
            }
            break;

        case 2:
            cout << "Enter the starting city for DFS: ";
            cin >> u;
            g.DFS(u);
            break;

        case 3:
            cout << "Enter the starting city for BFS: ";
            cin >> u;
            g.BFS(u);
            break;

        case 4:
            g.displayGraph();
            break;

        case 5:
            cout << "Exiting program...\n";
            return 0;

        default:
            cout << "Invalid choice, please try again.\n";
        }
    }
}
