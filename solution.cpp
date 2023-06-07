#include<bits/stdc++.h>
using namespace std;


/*
This function takes the shortcuts from the user and stores them in the shortcuts vector.
*/
void fillShortcuts(vector<int>&shortcuts, int n) {
  shortcuts.clear();
  
  int shortcut;

  for (int i = 0; i < n; i++)
   {
    cin>>shortcut;
    shortcuts.push_back(shortcut-1);
   }
}


/*
This function visits a potentially unvisited node within the bfs algorithm.
energy represents the energy required to arrive at the node from which we are visiting the new intersection.
If the node is already visited or is not within the range of intersections, it is not processed.
*/
inline void visitIntersection(vector<bool>&visited, queue<pair<int,int>>&bfs_q, int intersection, int energy) {
  if (intersection >= 0 && intersection < visited.size() && !visited[intersection]) {
    visited[intersection] = true;
    bfs_q.push({intersection, energy + 1});
  }
}


/*
This function applies the BFS algorithm on the intersections graph and returns the minimum energy to reach 
each intersection.
*/
vector<int> getMinEnergies(vector<int>&shortcuts, int n) {
  vector<int>min_energy(n,-1);

  queue<pair<int,int>>bfs_q;
  vector<bool>visited(n,false);


  bfs_q.push({0, 0});
  visited[0] = true;

  
  while(!bfs_q.empty()) {
    auto item = bfs_q.front();

    bfs_q.pop();
    
    int intersection = item.first;
    int energy = item.second;

    min_energy[intersection] = energy;

    visitIntersection(visited, bfs_q, intersection + 1, energy);
    visitIntersection(visited, bfs_q, intersection - 1, energy);
    visitIntersection(visited, bfs_q, shortcuts[intersection], energy);

    }
  
  return min_energy;
}



/*
This is a utility function used to display the final result.
*/
void displayResult(vector<int>&min_energy) {
  for (auto energy : min_energy)
    cout<<energy<<" ";
  
  cout<<endl;
} 

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin>>n;

  // Get the shortcuts from the user
  vector<int>shortcuts;
  fillShortcuts(shortcuts, n);

  // Apply BFS to get the minimum energies
  vector<int>min_energy = getMinEnergies(shortcuts, n);

  // Display the results
  displayResult(min_energy);
  
  return 0;
}
