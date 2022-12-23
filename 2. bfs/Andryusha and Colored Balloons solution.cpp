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
// vector <  list<int> > adjacency_list(Size); // same complexity as the line above but the with more memory complexity


bool visited[Size];
int color[Size], degree[Size], parent[Size];




void bfs(int src){

    queue <int> qe;
    qe.push(src);
    visited[src] = true;
    parent[src] = 1; // bc the root has no parent so we will give him the same node as the root
    color[src] = 1;

    while(!qe.empty()){
        int curr_node = qe.front();
        qe.pop();
        int col = 1;

        for( auto child : adjacency_list[curr_node]){

            if( color[parent[curr_node]] == col || color[curr_node] == col) col++;
            if( color[parent[curr_node]] == col || color[curr_node] == col) col++; // we repeated the same condition bc if the parent of curr node its color was == col then the counter will increase by 1 and if the color[curr] node was equal the new counter then you have to increase it again

            if( !visited[child] ){
                visited[child] = true;
                color[child] = col;
                parent[child] = curr_node;
                qe.push(child);
                col++; // so the next child of the curr_node should have a different color
            }

        }
    }
}




void burn(){

    int nodes, x, y; cin >> nodes;

    FORI(0, nodes - 1){ // since it's a directed tree
        cin >> x >> y;
        adjacency_list[x].push_back(y);
        adjacency_list[y].push_back(x);
        degree[x]++;
        degree[y]++;
    }

    bfs(1);

    int mim_no_colors = *max_element(degree, degree + nodes + 1);
    cout << mim_no_colors + 1 << '\n'; // +1 for the node itself

    for( int i = 1; i <= nodes; i++) cout << color[i] << ' ';
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
