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
vector <  vector<int> > adjacency_list(Size); // to represent the graph
// vector <  list<int> > adjacency_list(Size); // same complexity as the line above

int cost[Size];
void init (int n){
    FORI(1, n + 1){
        cost[i] = INT_MAX;
        adjacency_list[i].clear();
    }
}
void bfs (int sP){


    queue <int> qe;
    cost[sP] = 0;
    qe.push(sP);

    while( !qe.empty()){
        int curr_node = qe.front();
        qe.pop();
        int curr_cost = cost[curr_node];

        for(auto child : adjacency_list[curr_node]){
            if(curr_cost + 1 < cost[child]){
                cost[child] = curr_cost + 1;
                qe.push(child);
            }
        }
    }

}











void burn(){

    int n, m, x, y; cin >> n >> m;
    init(n);
    FORI(0, m){
        cin >> x >> y;
        adjacency_list[x].push_back(y);
        adjacency_list[y].push_back(x);
    }
    int start_point; cin>> start_point;

    bfs( start_point);
    for(int i = 1; i <= n; i++){
        if(cost[i] == INT_MAX) cout << -1 << ' ';
        else if( i != start_point ) cout << cost[i] * 6 << ' ';
    }


}




int main()
{
    // freopen("contest.in","rt",stdin); g++ tempans -o tempans
    Mo7amed_Nasr
    // preprocessing
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t;
    cin>>t;
//    cin.ignore();
////    cin.ignore();
    while(t--) {
        burn();
        if(t) cout << '\n';
    }











    // Mask mask = 4747;
    // cout<<mask<<'\n';
    // Mask mask2 = 7474;
    // printing is from right to left in the binary representation
    // cout<<mask2<<'\n';

    return 0;

}
