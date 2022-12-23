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

const int Size = 1e2 + 5;
vector <  vector<int> > adjacency_list(Size); // to represent the graph
// vector <  list<int> > adjacency_list(Size); // same complexity as the line above


bool visited[Size];

int dfs (int curr_node){
    visited[curr_node] = true;
    int cnt = 1;

    for(auto child : adjacency_list[curr_node]){
        if(!visited[child]) cnt += dfs(child);
    }

    return cnt ;
}


void burn(){

    int nodes, edges, x, y; cin >> nodes >> edges;
    FORI(0, edges){
        cin >> x >> y;
        adjacency_list[x].push_back(y);
        adjacency_list[y].push_back(x);
    }

    int one_component = dfs(1);
    // graph would have simple cycle if it was connected (one_component) && no. of nodes == no. of edges
    if(nodes == one_component && nodes == edges) cout<<"FHTAGN!";
    else cout<<"NO";


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
