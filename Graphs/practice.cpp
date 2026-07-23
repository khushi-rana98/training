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
    // NO. OF PROVINCES PROBLEM
     void dfs(vector<int>&visited,int node, vector<vector<int>>&isConnected){
        visited[node]=1;
        for(int neigh=0;neigh<isConnected.size();neigh++){
            if(isConnected[node][neigh]==1 && !visited[neigh])
            dfs(visited,neigh, isConnected);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
       int v=isConnected.size(); //n_vertices
       vector<int>visited(v,0);
       int provinces=0;
       for(int i=0;i<v;i++){
        if(!visited[i]){
            provinces++;
            dfs(visited,i,isConnected);
        }
        
       }
       return provinces;
    }
    // flood fill problem--important interview question
    void dfs(int r, int c, vector<vector<bool>>&visited,vector<vector<int>>& image, int o_color, int color){
        int t_rows=image.size();
        int t_cols=image[0].size();
        visited[r][c]=true;
        image[r][c]=color;
        // up down left right
        int x[4]={-1,1,0,0};
        int y[4]={0,0,-1,1};
        for(int k=0;k<4;k++){
            int row=r+x[k];
            int col=c+y[k];
            if(row>=0 && row<t_rows && col>=0 && col<t_cols && image[row][col]==o_color && !visited[row][col])
            dfs(row,col,visited, image,o_color, color);
        }

            }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int r=image.size(); //no_vertices
        int c=image[0].size();
        vector<vector<bool>>visited(r,vector<bool>(c,false)); //visited
        if(sr>=0 && sr<r && sc>=0 && sc<c){
            int og_color=image[sr][sc];
            dfs(sr,sc,visited,image,og_color,color);
        }
        return image;
    }
// rotting oranges problem--leetcode--important interview question
// whenever they ask min. time required, spread or anything like this--use BFS
     int orangesRotting(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        queue<pair<int,int>>q;
        int fresh=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==2)
                q.push(make_pair(i,j));
                else if(grid[i][j]==1)
                fresh++;
            }
        }
        int time=0;
        // up down left right
        int dr[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        while(!q.empty() && fresh>0){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto curr=q.front();
                q.pop();
                int r=curr.first;
                int c=curr.second;
                for(int k=0;k<4;k++){
                    int nr=r+dr[k];
                    int nc=c+dy[k];
                if(nr>=0 && nr<rows && nc>=0 && 
                    nc<cols &&
                    grid[nr][nc]==1){
                    grid[nr][nc]=2;
                    fresh--;
                    q.push(make_pair(nr,nc));
                    }
                }

            }//size
            time++;
        }
        return (fresh==0)?time:-1;
    }
// DETECT CYCLE IN AN UNDIRECTED GRAPH--
// USING BFS AND DFS--
   bool dfs(int start, int parent, vector<bool>&visited, unordered_map<int,list<int>>&adjList){
    visited[start]=true;
    for(auto neigh:adjList[start]){
        if(!visited[neigh]){
            if(dfs(neigh, start,visited,adjList)) return true;
        }
        else if(visited[neigh] && parent!=neigh) return true;
    }
    return false;
}
   bool isCycle(int V, vector<vector<int>>&edges){
       unordered_map<int,list<int>>adjList;
       for(auto &edge:edges){
           int u=edge[0];
           int v=edge[1];
           adjList[u].push_back(v);
           adjList[v].push_back(u);
       }
       vector<bool>visited(V,false);
       for(int i=0;i<V;i++){
           if(!visited[i]){
               if(dfs(i,-1,visited,adjList))
               return true;
           }
       }
       return false;
   }
    // detect cycle in a directed graph:
    
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

