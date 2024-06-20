#include<bits/stdc++.h>
using namespace std;

class DSU {
  vector<int>parent,size;

  public:
  DSU(int n) {
    parent.resize(n+1);
    size.resize(n+1,0);

    for(int i = 0;i<=n;++i) parent[i] = i;
  }

  int find_Ultimate_Parent(int node) {
    if(node == parent[node]) return node;

    return parent[node] = find_Ultimate_Parent(parent[node]);
  }

  void union_By_Size(int u,int v) {
    int ultimate_parent_of_u = find_Ultimate_Parent(u);
    int ultimate_parent_of_v = find_Ultimate_Parent(v);

    if(ultimate_parent_of_u == ultimate_parent_of_v) return;

    if(size[ultimate_parent_of_u] < size[ultimate_parent_of_v]) {
      parent[ultimate_parent_of_u] = ultimate_parent_of_v;
      size[ultimate_parent_of_v] += size[ultimate_parent_of_u];
    }else {
     parent[ultimate_parent_of_v] = ultimate_parent_of_u;
      size[ultimate_parent_of_u] += size[ultimate_parent_of_v]; 
    }
  }
};

int main() {
  DSU ds(7);

  ds.union_By_Size(1,2);
  ds.union_By_Size(2,3);
  ds.union_By_Size(4,5);
  ds.union_By_Size(6,7);
  ds.union_By_Size(5,6);
  ds.union_By_Size(3,7);
  if(ds.find_Ultimate_Parent(3) == ds.find_Ultimate_Parent(7)) cout << "Same";
  else cout << "Not Same";

}