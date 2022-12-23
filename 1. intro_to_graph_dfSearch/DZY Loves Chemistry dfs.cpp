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

const int Size = 51;
vector <  vector<int> > adjacency_list(Size); // to represent the graph
// vector <  list<int> > adjacency_list(Size); // same complexity as the line above
vector< bool> visited(Size);


// void init(int n){ // used to initilize if there is test cases
    
//     for(int i = 1; i <= n; i++){
//         adjacency_list[i].clear();
//         visited[i] = false;
//     }

// }

ll dfs(int curr_node, int multiply = 1){ // we did put a default value in case if the graph wasn't connected the parent node its danger is always one otherwise the danger will multiplied by 2
    visited[curr_node] = true;
    ll ret = multiply ;
    for( auto child : adjacency_list[curr_node]){
        if(!visited[child]) ret *= dfs(child, 2); // recurse
    }

    return ret;
}


void burn(){
    int nodes , edges, x, y;
    cin>>nodes>>edges;
    FORI(0, edges){
        cin>>x>>y;
        adjacency_list[x].emplace_back(y);
        adjacency_list[y].emplace_back(x); // undirected graph
    }
    ll ans = 1;
    for(int node = 1; node <= nodes; node++){
        if(!visited[node]){
            ans *= dfs(node);
        }
    }

    cout<<ans<<'\n';
    
}




int main()
{
    // freopen("contest.in","rt",stdin);
    Mo7amed_Nasr
    // preprocessing

    // int t; 
       
    // cin>>t;
    // while(true)   // note that space wouldnot be consider as an input so it will be handled by default

        burn();
    









    // Mask mask = 4747;
    // cout<<mask<<'\n';
    // Mask mask2 = 7474;
    // printing is from right to left in the binary representation
    // cout<<mask2<<'\n';

    return 0;

}
