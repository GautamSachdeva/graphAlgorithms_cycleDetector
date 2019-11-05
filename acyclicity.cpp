#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void recur(vector<vector<int> > &adj,vector<bool> &visited,vector<bool> &in_stack,bool &cycle_detected,int vertex){
	visited[vertex] = true;
	in_stack[vertex] = true;
	for(int i = 0; i < adj[vertex].size();i++){
		if(!visited[adj[vertex][i]]){
			recur(adj,visited,in_stack,cycle_detected,adj[vertex][i]);
		}
		if(visited[adj[vertex][i]] && in_stack[adj[vertex][i]]){
			cycle_detected = true;
		}
	}
	in_stack[vertex] = false;
}


int acyclic(vector<vector<int> > &adj) {
	vector<bool> visited(adj.size(),false);
	vector<bool> in_stack(adj.size(),false);
	bool cycle_detected = false;
	for(int i = 0 ; i < adj.size() ; i++){
		recur(adj,visited,in_stack,cycle_detected,i);
	}
	//recur(adj,visited,in_stack,cycle_detected,0);
	if(cycle_detected){
		return 1;
	}	
  	return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
