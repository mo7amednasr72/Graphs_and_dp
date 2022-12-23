#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef bitset<70> Mask; // for bit mask operations

#define FORI(s, e) for(int i = s; i < e; i++)

#define Mo7amed_Nasr ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N = 2e6 + 7; // means 1 million + 1 == 1000001;
const ll prime_mod = 1e9 + 7;

// set < vector<int>, greater<vector<int>> > res;
// note that when the set is a vector of values the vector will be sorted and the values

const int Size = 1e5 + 2 ;
// map < int, vector<int> > adjacency_list; // to represent the graph
// vector <  vector<int> > adjacency_list(Size); // same complexity as the line above



map <int, vector<int> > adjacency_list;
map < int, int> degree; // degree means no. of edges connected to each node


void dfs(int curr_node, int par = 0 ){
    cout<< curr_node<<' ';
    for( auto child : adjacency_list[curr_node]){
      if(child != par) dfs(child, curr_node);
    }
}


void burn(){

    int nodes, x, y; cin>>nodes; // since it's a tree then no. of edges is nodes - 1

    FORI(0, nodes ){ // note that this problem will be undirected chain
      cin>>x>>y;
      adjacency_list[x].push_back(y);
      adjacency_list[y].push_back(x); // undirected tree
      degree[x]++;
      degree[y]++;
    }

    for( auto node : adjacency_list){ // u just need to know the start point for the graph or the end point bc both has only one degree (one connected edge) and that's way there's only 2 solutions
      if(degree[node.first] == 1) { dfs(node.first); break;} // so you just need to dfs one time
    }
}




int main()
{
    // freopen("contest.in","rt",stdin);
    Mo7amed_Nasr
    // preprocessing

    int t, n, m;

    // cin>>t;
    // while(true)

        burn();












    // Mask mask = 4747;
    // cout<<mask<<'\n';
    // Mask mask2 = 7474;
    // printing is from right to left in the binary representation
    // cout<<mask2<<'\n';

    return 0;

}
