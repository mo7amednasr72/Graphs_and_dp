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

const int Size = 2e5 + 1;
vector < vector < pair<int, ll> > >adjacency_list(Size); // to represent the graph
// vector <  list<int> > adjacency_list(Size); // same complexity as the line above
ll cost[Size];


void dijkstra(int n){
    priority_queue < pair < ll, int >, vector < pair < ll, int > >, greater < pair<ll, int> > > pq;

    FORI(1, n + 1) pq.push({cost[i], i});

    while(!pq.empty()){
        ll curr_node = pq.top().second, curr_cost = pq.top().first;
        pq.pop();

        if(cost[curr_node] < curr_cost) continue;

        for( auto &child : adjacency_list[curr_node]){
            ll edge_cost = child.second, child_node = child.first;
            ll new_cost = 2 * edge_cost + curr_cost;

            if(new_cost < cost[child_node]){
                pq.push({new_cost, child_node});
                cost[child_node] = new_cost;
            }
        }
    }
}
void burn(){
    ll n, m, x, y, w; cin >> n >> m ;

    FORI(0, m){
        cin >> x >> y >> w;
        adjacency_list[x].push_back({y, w});
        adjacency_list[y].push_back({x, w});
    }



    FORI(1, n + 1){
        cin >> cost[i];
    }

    dijkstra(n);

    FORI(1, n + 1) cout << cost[i] << ' ';




}


int main()
{
    // freopen("contest.in","rt",stdin); g++ tempans -o tempans
    Mo7amed_Nasr
    // preprocessing
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t = 1;
//    cin>>t;
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
