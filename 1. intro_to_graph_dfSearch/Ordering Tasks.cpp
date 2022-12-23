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

const int Size = 100 + 2;
vector <  vector<int> > adjacency_list(Size); // to represent the graph
// vector <  list<int> > adjacency_list(Size); // same complexity as the line above
vector < int> visited(Size);
stack <int> st;


void init(int n){ // used to initilize if there is test cases
    
    for(int i = 1; i <= n; i++){
        adjacency_list[i].clear();
        visited[i] = 0;
    }
    while(!st.empty()) st.pop();
}

void top_sort(int curr_node){ // we did put a default value for the root so because is has no parent so we will give it 0  as a parent
    visited[curr_node] = 1;
    for(auto child : adjacency_list[curr_node]){
        if(visited[child] == 0 ) top_sort(child);
    }
    st.push(curr_node);
}


void burn(int n, int m){
    int nodes = n, edges = m, x, y;
   
    init(nodes);
    FORI(0, edges){ // it's guaranteed that this graph is DAG directed acyclic graph you don't have to check if it was cyclic or not
        cin>>x>>y;
        adjacency_list[x].emplace_back(y);
    }
    


    for(int node = 1; node <= nodes; node++){
        if(!visited[node]) top_sort(node);
    }
    while(!st.empty()){
        cout<<st.top()<<' ';
        st.pop();
    }
    cout<<'\n';
}




int main()
{
    // freopen("contest.in","rt",stdin);
    Mo7amed_Nasr
    // preprocessing

    int t, n, m; 
       
    // cin>>t;
    while(true) {
        cin>>n>>m;
        if(n == m && m == 0) break;
        burn(n, m);
    }  // note that space wouldnot be consider as an input so it will be handled by default

    









    // Mask mask = 4747;
    // cout<<mask<<'\n';
    // Mask mask2 = 7474;
    // printing is from right to left in the binary representation
    // cout<<mask2<<'\n';

    return 0;

}
