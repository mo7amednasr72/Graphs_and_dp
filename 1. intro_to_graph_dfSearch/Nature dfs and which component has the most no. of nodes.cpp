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

const int Size = 5e3 + 1;
vector <  vector<int> > adjacency_list(Size); // to represent the graph
// vector <  list<int> > adjacency_list(Size); // same complexity as the line above
vector< bool> visited(Size);


void init(int n){
    
    for(int i = 1; i <= n; i++){
        adjacency_list[i].clear();
        visited[i] = false;
    }

}

int dfs(int curr_node){
    visited[curr_node] = 1;
    int ret = 1;
    for( auto child : adjacency_list[curr_node]){
        if(!visited[child]) ret += dfs(child); // recurse
    }

    return ret;
}


void burn(int n, int e){

    int nodes = n, edges = e, x, y;
    init(nodes);
    map <string,int> indx; // to handle the string and encode it into integer 
    string str;
    FORI(1, nodes + 1){
        cin>>str;
        indx[str] = i;
    }
    string str1, str2;
    FORI(0, edges){
        cin>>str1>>str2;
        x = indx[str1], y = indx[str2];
        adjacency_list[x].push_back(y);
        adjacency_list[y].push_back(x); // because it's an undirected graph
    }

    int ans = 0;
    for(int node = 1; node <= nodes; node++){
        if(!visited[node])
            ans = max(ans, dfs(node)); // see what component is the biggest // if it was one component then it will do this step only one time
    }

    cout<<ans<<'\n';
    
}




int main()
{
    // freopen("contest.in","rt",stdin);
    Mo7amed_Nasr
    // preprocessing

    int t, n, e; 
    // cin>>t;
    while(true) {   // note that space wouldnot be consider as an input so it will be handled by default
        cin>>n>>e;    
        if(n == e && e == 0) break;

        burn(n, e);}
    









    // Mask mask = 4747;
    // cout<<mask<<'\n';
    // Mask mask2 = 7474;
    // printing is from right to left in the binary representation
    // cout<<mask2<<'\n';

    return 0;

}
