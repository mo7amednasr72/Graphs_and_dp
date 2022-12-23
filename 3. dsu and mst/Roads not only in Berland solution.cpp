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

const int Size = 1e3 + 5;
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

    if( comp_size[x] < comp_size[y] ) swap(x, y);
    comp_size[x] += comp_size[y];
    parent[y] = x;

}


void burn() {

    int n, x, y; cin >> n;
    make_set(n);

    deque<pair<int, int> > edge_list;
    FORI(0, n -1){
        cin >> x >> y;
        if( already_connected(x, y) ) { edge_list.push_back({x, y});
            continue;
        }
        connect_components(x, y);

    }

    vector < int > parent_vec;
    for(int i = 1; i <= n ; i++){
        if(find_parent(i) == i) parent_vec.push_back(i);
    }

    int siz = int(edge_list.size());
    cout << siz << '\n';
    for(int i = 0; i < siz; i++){
        cout << edge_list[i].first << ' ' << edge_list[i].second << ' ' << parent_vec[0] << ' ' << parent_vec[i + 1] << '\n';
    }


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
