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

int dfs(int curr_node, int lvl ){ // we did put a default value for the root so because is has no parent so we will give it 0  as a parent
    visited[curr_node] = 1;
    int mxm = lvl;

    for(auto child : adjacency_list[curr_node]){

        if(visited[child] == 0) { mxm = max(dfs(child, lvl + 1), mxm);   }

    }
    return mxm;
}


void burn(){
    int nodes, x; cin>>nodes;
    std::vector<int> has_no_parent;
    for(int i = 1; i <= nodes; i++){
      cin>>x; // parent
      if(x == -1) has_no_parent.push_back(i); // means i has no parent
      else adjacency_list[x].push_back(i);
       // and bc it's undirected tree
    }
    int ans = 1;
    for(auto node : has_no_parent){
       ans = max(ans, dfs(node, 1));
    }

    cout<<ans; // solution is the level of the deepest leaf
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
