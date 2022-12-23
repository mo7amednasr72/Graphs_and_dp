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
vector < vector < pair<int, int> > >adjacency_list(Size); // to represent the graph
// vector <  list<int> > adjacency_list(Size); // same complexity as the line above
bool visited[Size];
int in[Size];
int out[Size];


pair <int, int> bfs(int src, int diameter = INT_MAX){
    
    int mim_diameter = INT_MAX, last_node = -1;
    queue <  pair<int, int>  > qe;
    qe.push({src, diameter});
    visited[src] = true;

    while( !qe.empty() ){
        
        auto curr_node = qe.front();
        qe.pop();
        mim_diameter = min(mim_diameter, curr_node.second);
        if( in[curr_node.first] && !out[curr_node.first]) last_node = curr_node.first;

        for( auto child : adjacency_list[curr_node.first]){
            if( !visited[child.first]){
                qe.push(child);
                visited[child.first] = true;
            }
        }
    }

    return {last_node, mim_diameter};
}




void burn(){

    int nodes, edges, x, y, d; cin >> nodes >> edges;
    
    FORI(0, edges){ // this is directed tree
        cin >> x >> y >> d;
        adjacency_list[x].push_back({y, d});
        out[x]++;
        in[y]++;
    }


    vector < pair < pair <int, int>, int > >  ans;
    for(int i = 1; i <= nodes; i++){
        if(  !in[i] && out[i] ){ // ! in means you have to put tank here bc this house would be the source && ! out means this the end so you have to put tape here to make the water flow
            pair< int, int> temp_ans = bfs(i);
            ans.push_back({{i, temp_ans.first}, temp_ans.second});
        }
    }

    int sz = int(ans.size());
    cout << sz << '\n';
    for(int i = 0; i < sz; i++){
        cout << ans[i].first.first << ' ' << ans[i].first.second << ' ' << ans[i].second <<'\n';
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
