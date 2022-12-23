#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef bitset<70> Mask; // for bit mask operations

#define FORI(s, e) for(int i = s; i < e; i++)

#define Mo7amed_Nasr ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int Z = 2e6 + 7; // means 1 million + 1 == 1000001;
const int prime_mod = 1e9 + 7;

// set < vector<int>, greater<vector<int>> > res;
// note that when the set is a vector of values the vector will be sorted and the values

const int Size = 1e5 + 1;
vector < vector < pair<int, int> > >adjacency_list(Size); // to represent the graph
// vector <  list<int> > adjacency_list(Size); // same complexity as the line above
int cost[Size];

void init(int n){
    FORI(1, n + 1) cost[i] = INT_MAX;
}
void dijkstra(int src){
    priority_queue < pair < int, int >, vector < pair < int, int > >, greater < pair<int, int> > > pq;
    cost[src] = 0;
    pq.push({0, src});

    while( !pq.empty() ){

        int curr_node = pq.top().second, curr_cost = pq.top().first;
        pq.pop();
        if(cost[curr_node] < curr_cost) continue;

        for( auto &child : adjacency_list[curr_node]){
            int edge_cost = child.second, child_node = child.first;
            int new_cost = curr_cost + edge_cost;

            if(new_cost < cost[child_node]){
                pq.push({new_cost, child_node});
                cost[child_node] = new_cost;
            }
        }

    }
}
void burn(){
    int n, m, x, y, w, starting_poit, end_point; cin >> n >> m >> starting_poit >> end_point;

    FORI(0, m){
        cin >> x >> y >> w;
        adjacency_list[x].push_back({y, w});
        adjacency_list[y].push_back({x, w});
    }
    init(n);

    dijkstra(starting_poit);

    if( cost[end_point] == INT_MAX) cout << "NONE\n";
    else cout << cost[end_point] << '\n';



}


int main()
{
    // freopen("contest.in","rt",stdin); g++ tempans -o tempans
    Mo7amed_Nasr
    // preprocessing
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t = 1;
    cin>>t;
//    cin.ignore();
////    cin.ignore();
    while(t--) {
        burn();
//        if(t) cout << '\n';
    }

    // Mask mask = 4747;
    // cout<<mask<<'\n';
    // Mask mask2 = 7474;
    // printing is from right to left in the binary representation
    // cout<<mask2<<'\n';

    return 0;

}
