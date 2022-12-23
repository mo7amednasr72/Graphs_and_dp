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

const int Size = 5e4 + 1;
vector <  vector<int> > adjacency_list(Size); // to represent the graph
// vector <  list<int> > adjacency_list(Size); // same complexity as the line above

std::vector<int> dis(Size);
queue<int> qe;


int bfs(int src, int n){
    int cnt = 0;
    FORI(1, n + 1){ // we initilize the cost (dis) of every node by inf
      dis[i] = INT_MAX;
    }

    dis[src] = 0;
    qe.push(src);

    while(!qe.empty()){
        int curr_node = qe.front();
        qe.pop(); cnt++;
        int curr_cost = dis[curr_node];

        for( auto child : adjacency_list[curr_node]){
            if(curr_cost + 1 < dis[child]){
                dis[child] = curr_cost + 1;
                qe.push(child);
            }
        }
    }

    return cnt;
}


void burn(){

    int nodes, edges, x, y; cin>>nodes>>edges;

    FORI(0, edges){
      cin>>x>>y;
      adjacency_list[x].push_back(y);
      adjacency_list[y].push_back(x);
    }

    int no_nodes_in_one_component = bfs(1, nodes);

    if(edges == nodes - 1 && no_nodes_in_one_component == nodes) cout<<"YES\n";
    else cout<<"NO\n";


}




int main()
{
    // freopen("contest.in","rt",stdin); g++ tempans -o tempans
    Mo7amed_Nasr
    // preprocessing

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
