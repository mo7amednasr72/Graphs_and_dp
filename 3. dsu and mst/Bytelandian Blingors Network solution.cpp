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
    for(int i = 1; i <= n; i++){
        parent[i] = i, comp_size[i] = 1;
    }
}

int find_parent(int node){
    if(parent[node] == node) return node;
    return parent[node] = find_parent(parent[node]);
}
bool already_connected(int x, int y){
    return (find_parent(x) == find_parent(y));
}
void connect_components(int x, int y){
    x = find_parent(x);
    y = find_parent(y);
    if(x == y) return;
    if(comp_size[x] < comp_size[y]) swap(x, y);
    comp_size[x] += comp_size[y];
    parent[y] = parent[x];
}

void burn() { // solution is minimum spanning tree

    int n; cin >> n;
    make_set(n);
    vector< pair <int, pair<int, int> > > edge_list;

    for(int edge1 = 1; edge1 <= n; edge1++){
        string str ; cin >> str;
        int temp_no_edges, edge2, cost; cin >> temp_no_edges;

        while(temp_no_edges--){
            cin >> edge2 >> cost;
            edge_list.push_back({cost, {edge1, edge2}});
        }
    }

    sort(edge_list.begin(), edge_list.end());

    int siz = int(edge_list.size());


    ll ans = 0;
    for( auto i : edge_list){
        int x = i.second.first, y = i.second.second, c = i.first;
        if(!already_connected(x, y)){
            connect_components(x, y);
            ans += c;
        }
    }

    cout << ans << '\n';

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
