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

int parent1[Size], comp_size1[Size], parent2[Size], comp_size2[Size];

void make_set(int n, int parent[], int comp_size[]){
    for(int i = 1; i <= n; i++){
        parent[i] = i, comp_size[i] = 1;
    }
}

int find_parent(int node, int parent[]){
    if(parent[node] == node) return node;
    return parent[node] = find_parent(parent[node], parent);
}
bool already_connected(int x, int y, int parent[]){
    return (find_parent(x, parent) == find_parent(y, parent));
}
void connect_components(int x, int y, int parent[], int comp_size[]){
    x = find_parent(x, parent);
    y = find_parent(y, parent);
    if(x == y) return;
    if(comp_size[x] < comp_size[y]) swap(x, y);
    comp_size[x] += comp_size[y];
    parent[y] = parent[x];
}

void burn() { // solution is 2 dsu

    int n, m1, m2, x, y; cin >> n >> m1 >> m2;
    make_set(n, parent1, comp_size1);
    make_set(n, parent2, comp_size2);

    FORI(0, m1){
        cin >> x >> y;
        connect_components(x, y, parent1, comp_size1);
    }

    FORI(0, m2){
        cin >> x >> y;
        connect_components(x, y, parent2, comp_size2);
    }


    vector< pair<int, int> > res;
    for(int a = 1; a <= n; a++) {
        for (int b = a + 1; b <= n; b++) {
            if (!already_connected(a, b, parent1) && !already_connected(a, b, parent2)) {
                res.push_back({a, b});
                connect_components(a, b, parent1, comp_size1);
                connect_components(a, b, parent2, comp_size2);
            }
        }
    }

    cout << int(res.size()) << '\n';
    for( auto i : res) {
        cout << i.first << ' ' << i.second << '\n';
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
