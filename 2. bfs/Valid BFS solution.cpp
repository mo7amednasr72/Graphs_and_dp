#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef bitset<70> Mask; // for bit mask operations

#define FORI(s, e) for(int i = s; i < e; i++)

#define Mo7amed_Nasr ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int Z = 2e6 + 7; // means 1 million + 1 == 1000001;
const ll prime_mod = 1e9 + 7;

// set < vector<int>, greater<vector<int>> > res;
// note that when the set is a vector of values the vector will be sorted and the values

const int Size = 2e5 + 5;
vector <  vector<int> > adjacency_list(Size); // to represent the graph
// vector <  list<int> > adjacency_list(Size); // same complexity as the line above

int cost[Size], parent[Size];


void bfs (int src, int n){

    FORI(1, n + 1) cost[i] = INT_MAX;

    queue < int >  qe;
    qe.push(src);
    cost[src] = 0;
    parent[src] = 1; // bc he has no parents

    while (!qe.empty()){
        int curr_node = qe.front();
        qe.pop();
        int curr_cost = cost[curr_node];
        for( auto child : adjacency_list[curr_node]){
            if( curr_cost + 1 < cost[child]){
                qe.push(child);
                cost[child] = curr_cost + 1;
                parent[child] = curr_node;
            }
        }
    }


}


void burn(){

    int nodes, x, y; cin >> nodes;
    FORI(0, nodes - 1){ // since it's a tree hence edges = nodes - 1;
        cin>> x >> y;
        adjacency_list[x].push_back(y);
        adjacency_list[y].push_back(x);
    }

    vector<int> path(nodes + 1), id(nodes + 1); // id is just to check which node enters the queue first
    FORI(1, nodes + 1) { cin >> path[i]; id[path[i]] = i; }


    bfs(1, nodes);

    for(int i = 2 ; i <= nodes ; i++){

        int x = path[i - 1], y = path[i];

        if( cost[x] > cost[y]) return void( cout << "No\n");

        if( id[parent[x]] > id[parent[y]]) return void( cout << "No\n"); // this means the parent of the node y enters the queue before the parent of node x and this is not valid
    }

    cout << "Yes\n";



}




int main()
{
    // freopen("contest.in","rt",stdin); g++ tempans -o tempans
    Mo7amed_Nasr
    // preprocessing
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

//    int t;
//    cin>>t;
//    cin.ignore();
////    cin.ignore();
//    while(t--) {
        burn();
//        if(t) cout << '\n';
//    }











    // Mask mask = 4747;
    // cout<<mask<<'\n';
    // Mask mask2 = 7474;
    // printing is from right to left in the binary representation
    // cout<<mask2<<'\n';

    return 0;

}
