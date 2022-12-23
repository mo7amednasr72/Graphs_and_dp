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
vector < vector < int > >adjacency_list(Size); // to represent the graph
// vector <  list<int> > adjacency_list(Size); // same complexity as the line above


int parent[Size], comp_size[Size];

void make_set(int n){
    for( int i = 1; i <= n; i++){
        parent[i] = i, comp_size[i] = 1;
    }
}

int find_parent(int node){
    if( parent[node] == node) return node;
    return parent[node] = find_parent(parent[node]);
}

bool connected_already(int x, int y){
    return (find_parent(x) == find_parent(y));
}

void connect_components(int x, int y){
    x = find_parent(x);
    y = find_parent(y);

    if(x == y) return;

    if( comp_size[x] < comp_size[y]) swap(x, y);
    parent[y] = x;
    comp_size[x] += comp_size[y];
}



void burn(){
    int n, m, k; cin >> n >> m >> k;
    make_set(n); // disjoint union set

    int x, y, w;
    vector < pair < int, pair < int, int > > > edge_list1, edge_list2;
    int mim_cost = INT_MAX;

    FORI(0, m){

        cin >> x >> y >> w;
        if(w <= k)
            edge_list1.push_back({w, {x, y}});
        else
            edge_list2.push_back({w, {x, y}});

        mim_cost = min(mim_cost, abs(k - w));
    }



    sort(edge_list2.begin(), edge_list2.end());
    // u only need to sort the second edge list bc their cost is above k, so you need the edges that are the closest to the k

    // we will iterate on the first edge_list to make a spinning tree from the graph

    for ( auto &edge : edge_list1){
        int x = edge.second.first, y = edge.second.second, w = edge.first;
        if( !connected_already(x, y) ) connect_components(x, y);
    }

    ll ans = 0;
    bool ok = true;
    // we will iterate on the second edge_list to check if there still some nodes weren't  connected yet on the tree to connect them and their difference cost will be the new answer
    for( auto &edge : edge_list2){
        int x = edge.second.first, y = edge.second.second, w = edge.first;
        if( !connected_already(x, y) ) {
            ok = false;
            connect_components(x, y);
            ans += w - k;
        }
    }

    cout << ( ok  ? mim_cost : ans ) << '\n';

}




int main()
{
    // freopen("contest.in","rt",stdin); g++ tempans -o tempans
    Mo7amed_Nasr
    // preprocessing
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t;
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