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

const int Size = 1e5 + 5;
vector <  vector<int> > adjacency_list(Size); // to represent the graph
// vector <  list<int> > adjacency_list(Size); // same complexity as the line above

queue <int> qe;
int cost[Size];


void dfs (int src, int curr_cost = 0, int parent = 0){ // we add parent bc cost of the root is 0
    cost[src] = curr_cost;
    for(auto child : adjacency_list[src]){
        if(!cost[child] && child != parent) dfs(child, curr_cost + 1, src);
    }
}



// solution using dfs this time but the safe side use bfs when you need to get the shortest path or the longest path when the graph is cyclic
void burn(){ // you'll do dfs two times to get the deepest node node first then do dfs from it again to get the longest path

    int nodes, edges, x, y; cin >> nodes >> edges;

    FORI(0, edges){
        cin >> x >> y ;
        adjacency_list[x].push_back(y);
        adjacency_list[y].push_back(x);
    }

    dfs(1);

    int deepest_node = -1, mxm_cost = -1;

    FORI(1, nodes + 1){
        if( cost[i] > mxm_cost) {
            deepest_node = i, mxm_cost = cost[i];
        }
    }

    FORI(1, nodes + 1) cost[i] = 0;
    dfs(deepest_node);

    cout<< *max_element(cost, cost + nodes + 1);


}




int main()
{
    // freopen("contest.in","rt",stdin); g++ tempans -o tempans
    Mo7amed_Nasr
    // preprocessing
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // int t;

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
