#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef bitset<70> Mask; // for bit mask operations

#define FORI(s, e) for(int i = s; i < e; i++)

#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N = 2e6 + 7; // means 1 million + 1 == 1000001;
const ll prime_mod = 1e9 + 7;

// set < vector<int>, greater<vector<int>> > res;
// note that when the set is a vector of values the vector will be sorted and the values
const int Size = 1e6 + 1;
vector < vector<int> > adjacency_list(Size);
vector<int> visited(Size);
stack<int> st;
bool valid = true;

void init(int n){
    while(!st.empty()) st.pop();
    valid = true;
    FORI(0, n + 1) visited[i] = 0;
    for(int i = 0; i < n + 1; i++){
        adjacency_list[i].clear();
    }
}

void top_sort(int curr_node){ // using dfs
    visited[curr_node] = 1; // 1 means discovered and 2 means finished and 0 means not visited yet
    for(auto child : adjacency_list[curr_node]){
        if(!visited[child]) top_sort(child); // recurse do dfs on this child
        else if(visited[child] == 1) {valid = false; return;} // means this graph is a cyclic graph not an acylic graph
        // and this bc there is a parent is a child for its child and this not vaild with the directed acyclic graph
    }
    visited[curr_node] = 2; // means finished
    st.push(curr_node);
}


void burn(int n, int e){

    // we will do adjacency list to represent a graph

    int nodes = n, edges = e,  x, y;
    
    
    init(nodes); // initilize
    
    FORI(0, edges){
        cin>>x>>y;
        adjacency_list[x].push_back(y); // because it supposes to be a directed graph (DAG)
    }

    // do dfs depth first search
    FORI(1, nodes + 1){
        if(visited[i] == 0){
            top_sort(i);
        }
    }

    if(!valid) cout<<"IMPOSSIBLE\n";
    else{
        while(!st.empty()) {
            cout<<st.top()<<'\n';
            st.pop();
        }
    }
    
}
// 3 2 1 2 2 3




int main()
{
    // freopen("contest.in","rt",stdin);
    FAST
    // preprocessing

    int t, n, e; 
    // cin>>t;
    while(true){
        cin>>n>>e;
        if(!n && !e) break;
        burn(n, e);
    }









    // Mask mask = 4747;
    // cout<<mask<<'\n';
    // Mask mask2 = 7474;
    // printing is from right to left in the binary representation
    // cout<<mask2<<'\n';

    return 0;

}
