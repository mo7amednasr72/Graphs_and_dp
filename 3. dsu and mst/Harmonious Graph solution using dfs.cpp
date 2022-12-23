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
bool visited[Size];
int mim = INT_MAX, mxm = -1;

void dfs(int curr_node){
    visited[curr_node] = true;
    mim = min(curr_node, mim);
    mxm = max(curr_node, mxm);
    for( auto child : adjacency_list[curr_node]){
        if(!visited[child]) dfs(child);
    }
}

void burn() {
    int n, m, x, y; cin >> n >> m;
    FORI(0, m){
        cin >> x >> y;
        adjacency_list[x].push_back(y);
        adjacency_list[y].push_back(x);
    }


    int ans = 0;
    for(int i = 1; i <= n; i++){
        if( !visited[i] ){
            mim = INT_MAX, mxm = -1;
            dfs(i);
            for(int j = mim; j <= mxm; j++){
                if(!visited[j]){
                    ans++;
                    dfs(j);
                }
            }
        }
    }

    cout << ans << '\n';
}




int main()
{
    // freopen("contest.in","rt",stdin); g++ tempans -o tempans
    Mo7amed_Nasr
    // preprocessing
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t;
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
