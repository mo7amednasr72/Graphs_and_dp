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

const int Size = 1e5 + 5;
vector < vector < int > >adjacency_list(Size); // to represent the graph
// vector <  list<int> > adjacency_list(Size); // same complexity as the line above

ll parent[Size], comp_size[2 * Size], comp_sum[2 * Size];


void make_set(int n){ // in this problem we will do arbitrary parents if the node is i then its parent will be n + i
    for(int i = 1; i <= n; i++){
        parent[i] = n + i, comp_size[n + i] = 1, comp_sum[n + i] = i;
        parent[n + i] = n + i; // to avoid running forever
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
    comp_sum[x] += comp_sum[y];
    parent[y] = x; 

}

void move_element(int x, int y){

    int par_x = find_parent(x); // here you will move one element from the component so you  have to create temp parent in order to avoid moving the whole component
    int par_y = find_parent(y);
    if(par_x == par_y) return;

    comp_size[par_y]++; // since you're moving one element
    comp_size[par_x]--;

    comp_sum[par_y] += x;
    comp_sum[par_x] -= x;

    parent[x] = par_y; // only the parent of x will change

}


void burn() {

    int n, m, op, x, y;
    while (cin >> n && cin >> m) {
        make_set(n);

        while (m--) {
            cin >> op;

            if (op != 3) {

                cin >> x >> y;

                if (op == 1) connect_components(x, y);
                else move_element(x, y);

                continue;

            }

            cin >> x;
            int par_x = find_parent(x);
            cout << comp_size[par_x] << ' ' << comp_sum[par_x] << '\n';
        }
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
