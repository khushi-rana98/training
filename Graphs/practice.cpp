#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>
using namespace std;
class Graph{
public:
int n; // no of vertices
int m; // no. of edges
unordered_map<int,list<int>>adj_list;
// create a graph--
Graph(int vertices, int edges){
    n=vertices;
    m=edges;
    
}
void createGraph(){
    cout<<"Enter the edges (u,v):"<<endl;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u); //for undirectred graph
    }
}
void printGraph(){
    for(auto i:adj_list){
        cout<<i.first<<"->";
        for(auto j:i.second){
            cout<<j<<",";
        }
        cout<<endl;
    }
}
// traversal of graph using bfs--
 vector<int> bfs(vector<vector<int>> &adj) {
        int v=adj.size();
        vector<int>vis(v,0);
        vector<int>ans;
        queue<int>q;
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto neigh:adj[node]){
                if(!vis[neigh]){
                    vis[neigh]=1; //marked as visited
                    q.push(neigh);
                }
            }
        }
        return ans;
    }
    // traversal of graph using dfs--
      void soln(int node, vector<vector<int>>&adj, vector<int>&vis, vector<int>&ans){
      vis[node]=1;
      ans.push_back(node);
      for(auto neigh: adj[node]){
          if(!vis[neigh]){
              soln(neigh, adj,vis,ans);
          }
      }
  }
    vector<int> dfs(vector<vector<int>>& adj) {
        int v=adj.size();
        vector<int>vis(v,0); //visited array
        vector<int>ans;
        soln(0,adj,vis,ans);
        return ans;
        
    }
 void dfs(vector<int>&vis, int node, unordered_map<int,list<int>>&adj){
      vis[node]=1;
      for(auto neigh: adj[node]){
          if(!vis[neigh])
          dfs(vis,neigh,adj);
      }
      
     
      
  }
    int countConnected(int V, vector<vector<int>>& edges) {
       
        vector<int>vis(V,0);
        unordered_map<int,list<int>>adj;
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int count=0; //count of connected  components
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(vis,i,adj);
                count++;
            }
        }
        return count;
    }

    // no. of islands in a 2D grid problem
    // remember: dfs algorithm is used to traverse the left, right, up and down of grid
     void dfs(int r, int c, vector<vector<char>>&grid, vector<vector<int>>&visited){
        visited[r][c]=1; //mark this visited
        int t_rows=grid.size();//total rows
        int t_cols=grid[0].size(); //total cols
        // up down left right
        int x[4]={-1,1,0,0};
        int y[4]={0,0,-1,1};
        for(int k=0;k<4;k++){
            int row=r+x[k];
            int col=c+y[k];
            if(row>=0 && row<t_rows && col>=0 && col<t_cols && !visited[row][col] && 
            grid[row][col]=='1'){
                dfs(row,col,grid,visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int r=grid.size(); //n_rows
        int c=grid[0].size(); //n_col
        int count=0;
        vector<vector<int>>visited(r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    count++; //increase count if not visited
                    dfs(i,j,grid,visited);
                }
            }
        }
        return count;
    }
};

int main(){
    int n;
    cout<<"Enter the number of vertices: ";
    int m;
    cout<<"Enter the number of edges: ";
    cin>>n>>m;
    Graph g(n,m);
    g.createGraph();
    g.printGraph();
}

