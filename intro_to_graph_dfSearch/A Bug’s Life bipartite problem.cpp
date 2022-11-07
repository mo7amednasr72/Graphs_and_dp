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
const int S = 2e3 + 2;
vector < vector<int> > adjacency_list(S);

vector < int > color(S);
bool is_bipartite = true;

void init(int n){
    is_bipartite = true;
    FORI(0, n){
        adjacency_list[i].clear();
        color[i] = 0;
    }
}
void set_color(int current_node, int node_color){ // dfs tranverse
    color[current_node] = node_color;
    for(auto child : adjacency_list[current_node]){
        if(color[child] == 0){
        set_color(child, 3 - node_color); // recurse
        }
        else if(color[child] == color[current_node]){
        is_bipartite = false; return;}
    }
}
void burn(int u){

    // we will do adjacency list

    int nodes, edges, x, y;
    cin>>nodes>>edges;

    init(nodes);
    
    FORI(0, edges){
        cin>>x>>y;
        adjacency_list[x].push_back(y);
        adjacency_list[y].push_back(x);
    }

    // do dfs depth first search
    FORI(1, nodes + 1){
        if(color[i] == 0){
            set_color(i, 1);
        }
    }
    cout<<"Scenario "<<"#"<<u<<":\n";
    if(is_bipartite) cout<<"No suspicious bugs found!\n";
    else cout<<"Suspicious bugs found!\n";
}
// 3 2 1 2 2 3




int main()
{
    // freopen("contest.in","rt",stdin);
    FAST
    // preprocessing

    int t; cin>>t;
    FORI(1, t + 1)
        burn( i);









    // Mask mask = 4747;
    // cout<<mask<<'\n';
    // Mask mask2 = 7474;
    // printing is from right to left in the binary representation
    // cout<<mask2<<'\n';

    return 0;

}
