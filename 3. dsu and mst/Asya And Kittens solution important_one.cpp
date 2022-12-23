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
vector<int> order[Size];

void make_set(int n){
    for(int i = 1; i <= n; i++){
        parent[i] = i, comp_size[i] = 1, order[i].push_back(i);
    }
}

int find_parent(int node){
    if(parent[node] == node) return node;
    return parent[node] = find_parent(parent[node]);
}

void connect(int x, int y){

    x = find_parent(x);
    y = find_parent(y);
    if(x == y) return;

    if(comp_size[x] < comp_size[y]) swap(x, y);
    comp_size[x] += comp_size[y];
    int siz = int(order[y].size());

    for(auto &i : order[y]){ // by adding this part time complexity over all instead of being o(n) will be o(n * log2(n)) bc you would iterate to push the smaller vector at most only log2(n) and over all would be n * log2(n)
        order[x].push_back(i);
    }
    parent[y] = x;

    order[y].clear(); // just to reduce memory you may get time limit in other problems if you don't do it and this complexity won't increase still o(n * log2(n))
}




void burn() {

    int n, x, y; cin >> n;
    make_set(n);

    for(int i = 0; i < n - 1; i++){
        cin >> x >> y;
        connect(x, y);
    }

    int mxm_index = find_parent(1); // find the maximum component by finding its parent

    for( auto &i : order[mxm_index]) cout << i << ' ';
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
