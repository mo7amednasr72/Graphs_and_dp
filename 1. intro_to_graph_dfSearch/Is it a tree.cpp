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
const int S = 2e4 + 2;
vector < vector<int> > adjacency_list(S);

vector < bool > visited(S);

int dfs (int x){ // traverse
    visited[x] = true;
    int ret = 1;
    
    for( auto child : adjacency_list[x] ){
        if(!visited[child])
            ret += dfs(child); // recurse
    }

    return ret;
}

void burn(){
    // we will do adjacency list
    int nodes, edges, x, y;
    cin>>nodes>>edges;

    FORI(0, edges){
        cin>>x>>y;
        adjacency_list[x].push_back(y);
        adjacency_list[y].push_back(x); // you did this step bc it's undirected tree
    }

    int component_size = dfs(1); // to be tree there must be one component and this component must equal to the nodes and you can chose any node to start from
    // bc this tree is undirected tree graph and the algorithm will navigate the whole graph or  tree anyway

    if(component_size == nodes && nodes - 1 == edges) cout<<"YES\n";
    else cout<<"NO\n";
}
// 3 2 1 2 2 3




int main()
{
    // freopen("contest.in","rt",stdin);
    FAST
    // preprocessing

    // int t; cin>>t;
    // while(t--)
        burn();









    // Mask mask = 4747;
    // cout<<mask<<'\n';
    // Mask mask2 = 7474;
    // printing is from right to left in the binary representation
    // cout<<mask2<<'\n';

    return 0;

}
