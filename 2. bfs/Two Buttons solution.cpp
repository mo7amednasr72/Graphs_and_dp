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

const int Size = 1e4 + 1;
vector <  vector<int> > adjacency_list(Size); // to represent the graph
// vector <  list<int> > adjacency_list(Size); // same complexity as the line above

std::vector<int> dis(Size);
queue<int> qe;


void bfs(int src, int des){

    FORI(1, Size){ // we initilize the cost (dis) of every node by inf
      dis[i] = INT_MAX;
    }

    dis[src] = 0;
    qe.push(src);

    while(!qe.empty()){
      
        int curr_node = qe.front();
        qe.pop();
        int curr_cost = dis[curr_node];

        int child_one = curr_node * 2;
        int child_two = curr_node - 1;

        if( child_one < Size && curr_cost + 1 < dis[child_one]){
            qe.push(child_one);
            dis[child_one] = curr_cost + 1;
        }

        if( child_two > 0 && curr_cost + 1 < dis[child_two]){
            qe.push(child_two);
            dis[child_two] = curr_cost + 1;
        }

    }

    cout<< dis[des] <<'\n';
}


void burn(){

    int nodes, edges; cin>>nodes>>edges; // in this problem nodes represent the source and edges represent the destination


    bfs(nodes, edges);


}




int main()
{
    // freopen("contest.in","rt",stdin); g++ tempans -o tempans
    Mo7amed_Nasr
    // preprocessing

    // int t;

    // cin>>t;
    // while(true)

        burn();










    // Mask mask = 4747;
    // cout<<mask<<'\n';
    // Mask mask2 = 7474;
    // printing is from right to left in the binary representation
    // cout<<mask2<<'\n';

    return 0;

}
