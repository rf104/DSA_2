//MCM


#include<iostream>
#include<cstring>
using namespace std;

const int N = 102, M = 1e9+7;
int a[N];
int dp[N][N];

int mcm(int i,int j){
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = M;

    for(int k=i;k<j;k++){
        ans = min(ans, mcm(i,k)+mcm(k+1,j)+a[i-1]*a[k]*a[j]);
    }

    return dp[i][j] = ans;
}

signed main(){
    memset(dp, -1, sizeof(dp));
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<mcm(1,n-1)<<endl;
    return 0;
}





//TOPOLOGICAL SORT


#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<char,vector<char>> adj;
    map<char,int> deg;
    set<char>edges;
    for(int i = 0; i < n; i++){
        char x, y;
        cin >> x >> y;
        edges.insert(x);
        edges.insert(y);
        adj[x].push_back(y);
        deg[y]++;
    }
    queue<char> q;
    for(auto i : edges){
        if(deg[i] == 0)
            q.push(i);
    }
    vector<char> ans;
    while(q.size()){
        char tp = q.front();
        q.pop();
        ans.push_back(tp);
        for(auto i : adj[tp]){
            deg[i]--;
            if(deg[i] == 0){
                q.push(i);
            }
        }
    }
    if(ans.size() != edges.size()){
        cout << "Cycle Exist !!!\n";
        return 0;
    }
    for(auto i : ans){
        cout << i << " ";
    }
    cout << endl;
}





//job sequencing



#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    string jobId;
    int deadline, profit;
    Node(string jobId, int deadline, int profit) {
        this->jobId = jobId;
        this->deadline = deadline;
        this->profit = profit;
    }
};

bool cmp(Node a, Node b) {
    if (a.profit > b.profit)
        return true;
    return false;
}

int main() {
    int n;
    cin >> n;
    int max_deadline = 0;
    vector<Node> v;
    for (int i = 1; i <= n; i++) {
        string s;
        int deadline, profit;
        cin >> s >> deadline >> profit;
        v.push_back(Node(s, deadline, profit));
        max_deadline = max(max_deadline, deadline);
    }
    sort(v.begin(), v.end(), cmp);
    vector<int> slot(max_deadline, -1);
    vector<string> ans;
    int max_profit = 0;
    for (int i = 0; i < n; i++) {
        int deadline = v[i].deadline;
        for (int j = deadline - 1; j >= 0; j--) {
            if (slot[j] == -1) {
                ans.push_back(v[i].jobId);
                max_profit += v[i].profit;
                slot[j] = 1;
                break;
            }
        }
    }
    cout << max_profit << endl;
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
}

/*
input:
5
a 2 100
b 1 19
c 2 27
d񁦤5
e񂍻5

*/



//GRAPH COLOURING


#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100; // Maximum number of vertices

int graph[MAX][MAX];
int numVertices;
int countSolutions = 0; // Track the number of solutions

bool isSafe(int v, int colors[], int c) {
    for (int i = 0; i < numVertices; ++i) {
        if (graph[v][i] && c == colors[i])
            return false;
    }
    return true;
}

void graphColoringUtil(int colors[], int m, int v) {
    if (v == numVertices) {
        cout << "Solution " << ++countSolutions << ":\n";
        for (int i = 0; i < numVertices; ++i)
            cout << "Vertex " << i << " --> Color " << colors[i] << "\n";
        cout << "\n";
        return;
    }

    for (int c = 1; c <= m; ++c) {
        if (isSafe(v, colors, c)) {
            colors[v] = c;
            graphColoringUtil(colors, m, v + 1);
            colors[v] = 0; // Backtrack
        }
    }
}

void graphColoring(int m) {
    int colors[MAX] = {0};
    countSolutions = 0; // Reset the count for each run

    graphColoringUtil(colors, m, 0);

    if (countSolutions == 0) {
        cout << "No solution exists\n";
    } else {
        cout << "Total number of solutions: " << countSolutions << "\n";
    }
}

int main() {
    int numEdges, u, v;

    // Input the number of vertices and edges
    cin >> numVertices >> numEdges;

    // Initialize graph with 0
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            graph[i][j] = 0;
        }
    }

    // Input edges
    for (int i = 0; i < numEdges; ++i) {
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1; // For undirected graphs
    }

    int m; // Number of colors
    cin >> m;

    graphColoring(m);

    return 0;
}




//SUM_SUBSET


#include <iostream>
using namespace std;

void subsetSumUtil(int set[], int target, int temp[], int size, int start, int sum) {
    if (sum == target) {
        // If the current sum matches the target, print the subset
        cout << "Subset found: ";
        for (int i = 0; i < size; ++i) {
            if (temp[i] == 1) {
                cout << set[i] << " ";
            }
        }
        cout << endl;
    }

    for (int i = start; i < size; ++i) {
        // Add the current element to the temporary subset
        temp[i] = 1;
        sum += set[i];

        // Recursively check the subset sum with the added element
        if (sum <= target) {
            subsetSumUtil(set, target, temp, size, i + 1, sum);
        }

        // Backtrack: Remove the last element to explore other possibilities
        sum -= set[i];
        temp[i] = 0;
    }
}

void subsetSum(int set[], int size, int target) {
    int *temp = new int[size];
    for (int i = 0; i < size; ++i) {
        temp[i] = 0;
    }

    subsetSumUtil(set, target, temp, size, 0, 0);

    delete[] temp; // Free dynamically allocated memory
}

int main() {
    int inputSet[] = {2, 4, 6, 8, 10};
    int targetSum = 10;
    int setSize = sizeof(inputSet) / sizeof(inputSet[0]);

    subsetSum(inputSet, setSize, targetSum);

    return 0;
}





//N_QUEEN


#include <bits/stdc++.h>
    using namespace std;

    const int MAX = 10;
    int cnt;

    // Assuming a maximum size for the chessboard

    // x is == row no, y is == column no. In the given code, x and y represent the row and column indices, respectively.
    // The isSafe function is checking whether it is safe to place a queen at position (x, y) on the chessboard
    // x: It represents the current row where the algorithm is trying to place a queen
    // y: It represents the current column where the algorithm is trying to place a queen.
    bool isSafe(int arr[MAX][MAX], int x, int y, int n) {
        for (int row = 0; row < x; row++) {
            if (arr[row][y] == 1) {
                return false;
            }
        }

        int row = x;
        int col = y;
        while (row >= 0 && col >= 0) {
            if (arr[row][col] == 1) {
                return false;
            }
            row--;
            col--;
        }

        row = x;
        col = y;
        while (row >= 0 && col < n) {
            if (arr[row][col] == 1) {
                return false;
            }
            row--;
            col++;
        }
        return true;
    }

    bool nQueen(int arr[MAX][MAX], int x, int n) {
        if (x >= n) {
            // Print the current solution
            cout << ++cnt << endl<<endl;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl; // Add a newline to separate solutions
            return false;
        }
        for (int col = 0; col < n; col++) {
            if (isSafe(arr, x, col, n)) {
                arr[x][col] = 1;
                if (nQueen(arr, x + 1, n)) {
                    return true;
                }
                arr[x][col] = 0; // backtracking
            }
        }
        return false;
    }

    int main() {
        cnt = 0; // Reset count for each run
        int n;
        cin >> n;

        int arr[MAX][MAX] = {0};

        nQueen(arr, 0, n);

        return 0;
    }




    //0-1 KNAPSACK


    #include <bits/stdc++.h>
    using namespace std;

    const int MAX = 10;
    int cnt;

    // Assuming a maximum size for the chessboard

    // x is == row no, y is == column no. In the given code, x and y represent the row and column indices, respectively.
    // The isSafe function is checking whether it is safe to place a queen at position (x, y) on the chessboard
    // x: It represents the current row where the algorithm is trying to place a queen
    // y: It represents the current column where the algorithm is trying to place a queen.
    bool isSafe(int arr[MAX][MAX], int x, int y, int n) {
        for (int row = 0; row < x; row++) {
            if (arr[row][y] == 1) {
                return false;
            }
        }

        int row = x;
        int col = y;
        while (row >= 0 && col >= 0) {
            if (arr[row][col] == 1) {
                return false;
            }
            row--;
            col--;
        }

        row = x;
        col = y;
        while (row >= 0 && col < n) {
            if (arr[row][col] == 1) {
                return false;
            }
            row--;
            col++;
        }
        return true;
    }

    bool nQueen(int arr[MAX][MAX], int x, int n) {
        if (x >= n) {
            // Print the current solution
            cout << ++cnt << endl<<endl;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl; // Add a newline to separate solutions
            return false;
        }
        for (int col = 0; col < n; col++) {
            if (isSafe(arr, x, col, n)) {
                arr[x][col] = 1;
                if (nQueen(arr, x + 1, n)) {
                    return true;
                }
                arr[x][col] = 0; // backtracking
            }
        }
        return false;
    }

    int main() {
        cnt = 0; // Reset count for each run
        int n;
        cin >> n;

        int arr[MAX][MAX] = {0};

        nQueen(arr, 0, n);

        return 0;
    }






