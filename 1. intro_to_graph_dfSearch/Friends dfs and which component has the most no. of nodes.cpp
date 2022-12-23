#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef bitset<70> Mask; // for bit mask operations

#define FORI(s, e) for(int i = s; i < e; i++)

#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N = 2e6 + 7; // means 1 million + 1 == 1000001;
const ll prime_mod = 1e9 + 7;

// set < vector<int>, greater<vector<int>> > res;
// note that when the set is a vector of values the vector will be sorted and the values

const int Size = 5e5 + 1;
vector < vector<int> > adjacency_list(Size); // to represent the graph
vector<int> visited(Size);


void init(int nodes){
    
    for(int node = 0; node <= nodes; node++){
        adjacency_list[node].clear(); 
        visited[node] = 0;
    }

}

int dfs(int curr_node){
    visited[curr_node] = 1;
    int ret = 1;
    for( auto child : adjacency_list[curr_node]){
        if(!visited[child]) ret += dfs(child); // recurse
    }

    return ret;
}


void burn(){

    int nodes, edges , x, y; cin>>nodes>>edges;
    init(nodes);

    FORI(0, edges){
        cin>>x>>y;
        adjacency_list[x].push_back(y);
        adjacency_list[y].push_back(x); // because it's an undirected graph
    }

    int ans = 0;
    for(int node = 1; node <= nodes; node++){
        if(!visited[node])
            ans = max(ans, dfs(node)); // see what component is the biggest // if it was one component then it will do this step only one time
    }

    cout<<ans<<'\n';
    
}




int main()
{
    // freopen("contest.in","rt",stdin);
    FAST
    // preprocessing

    int t, n, e; 
    cin>>t;
    while(t--)        
        burn();
    









    // Mask mask = 4747;
    // cout<<mask<<'\n';
    // Mask mask2 = 7474;
    // printing is from right to left in the binary representation
    // cout<<mask2<<'\n';

    return 0;

}
