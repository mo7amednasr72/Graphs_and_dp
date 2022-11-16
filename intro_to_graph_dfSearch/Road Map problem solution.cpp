#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef bitset<70> Mask; // for bit mask operations

#define FORI(s, e) for(int i = s; i < e; i++)

#define Mo7amed_Nasr ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N = 2e6 + 7; // means 1 million + 1 == 1000001;
const ll prime_mod = 1e9 + 7;

// set < vector<int>, greater<vector<int>> > res;
// note that when the set is a vector of values the vector will be sorted and the values

const int Size = 5e4 + 1;
vector <  vector<int> > adjacency_list(Size); // to represent the graph
// vector <  list<int> > adjacency_list(Size); // same complexity as the line above

vector<int> parent(Size);

// void init(int n){ // used to initilize if there is test cases

//     for(int i = 1; i <= n; i++){
//         adjacency_list[i].clear();
//         visited[i] = false;
//     }

// }

void dfs(int curr_node, int parnt = 0){ // we did put a default value in case if the graph wasn't connected the parent node its danger is always one otherwise the danger will multiplied by 2
    parent[curr_node] = parnt;
    for( auto child : adjacency_list[curr_node]){
        if(child != parent[curr_node]) // since it's a tree u don't need to go for the parent again && you don't need to allocate a visited vector for it
          dfs(child, curr_node); // recurse
    }
}


void burn(){
    int nodes , r1, r2, x;
    cin>>nodes>>r1>>r2;
    for(int i = 1; i <= nodes ; i++){ // n - 1 because it's a tree
        if(i != r1){
            cin>>x;
            adjacency_list[i].emplace_back(x);
            adjacency_list[x].emplace_back(i); // undirected tree;
        }
    }



    dfs(r2);

    for(int node = 1; node <= nodes; node++){
        if(parent[node] != 0)
            cout<<parent[node]<<' ';
    }

}




int main()
{
    // freopen("contest.in","rt",stdin);
    Mo7amed_Nasr
    // preprocessing

    // int t;

    // cin>>t;
    // while(true)   // note that space wouldnot be consider as an input so it will be handled by default

        burn();










    // Mask mask = 4747;
    // cout<<mask<<'\n';
    // Mask mask2 = 7474;
    // printing is from right to left in the binary representation
    // cout<<mask2<<'\n';

    return 0;

}
