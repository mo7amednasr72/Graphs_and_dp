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


/* Minimum Spanning Tree topic && */
int parent[Size], com_size[Size];

void init (int n){

    for( int i = 1; i <= n; i++){
        parent[i] = i, com_size[i] = 1;
    }

}

int find_parent( int node ){

    if(parent[node] == node) return node;

    return parent[node] = find_parent(parent[node]); // recurse // and to make this function more efficient to amortized o(1) we will update each parent node when we are coming back form recursion just we will add this parent[node] =
    // adding parent[node] = to return each recursion call ---> this step called (pass compression)
}

bool conn_already(int x, int y){
    return (find_parent(x) == find_parent(y));
}

bool is_cyclic = false;

void connect_components(int x, int y){

    x = find_parent(x);
    y = find_parent(y);
    if(x == y) { is_cyclic = true; return ;} // return bc disjoint set union only works on undirected tree and there is no cycles in trees
    if( com_size[x] < com_size[y] ) parent[x] = y, com_size[y] += com_size[x]; // doing union by size which will make the complexity of find_parent log(n) for each call and this is the first optimization and after optimization above we will make it amortized o(1) bc some time the algorithm have to take log(n) steps
    else parent[y] = x, com_size[x] += com_size[y];

}



void burn(){

    int n = 26; // no. of characters
    init(n);

    int len ; cin >> len;
    string str1,str2;
    cin >> str1 >> str2;

    vector < pair < char, char > > edges; // edge list
    int x, y;

    FORI(0, len){
        x = str1[i] - 'a', y = str2[i] - 'a';
        if( !conn_already(x, y) ){
            edges.push_back({str1[i], str2[i]}); // keep the edge between them if they aren't connected already
            connect_components(x, y);
        }
    }

    int siz = int(edges.size());
    cout << siz << '\n';
    FORI(0, siz){
        cout << edges[i].first << ' ' << edges[i].second << '\n';
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
