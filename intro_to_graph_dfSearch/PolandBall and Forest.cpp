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

const int Size = 1e4 + 2 ;
// map < int, vector<int> > adjacency_list; // to represent the graph
vector <  vector<int> > adjacency_list(Size); // same complexity as the line above
// map < int, bool > visited;
std::vector<int> visited(Size);



// void init(int n){ // used to initilize if there is test cases

//     for(int i = 1; i <= n; i++){
//         adjacency_list[i].clear();
//         visited[i] = 0;
//     }
//     while(!st.empty()) st.pop();
// }

void dfs(int curr_node){ // we did put a default value for the root so because is has no parent so we will give it 0  as a parent
    visited[curr_node] = 1;
    for(auto child : adjacency_list[curr_node]){
        if(!visited[child]) {  dfs(child); };
    }

}


void burn(){
    int nodes, x; cin>>nodes;
    for(int i = 1; i <= nodes; i++){
      cin>>x; // parent
      adjacency_list[i].push_back(x);
      adjacency_list[x].push_back(i); // and bc it's undirected tree
    }
    int cnt_component = 0;
    for(int node = 1; node <= nodes; node++){
      if(!visited[node]){
        dfs(node); cnt_component++;
      }
    }
    cout<<cnt_component;
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
