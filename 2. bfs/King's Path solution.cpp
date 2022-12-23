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

const int Size = 1e2 + 5;
vector <  vector<int> > adjacency_list(Size); // to represent the graph
// vector <  list<int> > adjacency_list(Size); // same complexity as the line above

int sX, sY, eX, eY;

map < pair<int, int>, bool > exist, visited;
queue < pair < pair<int, int>, int > > qe;
int dir_x[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dir_y[] = {1, -1, 0, 0, 1, -1, -1, 1};

void bfs (){
    qe.push({ {sX, sY}, 0 }); // 0 is the cost;
    visited[{sX, sY}] = true;

    while(! qe.empty()){

        auto curr_node = qe.front();
        qe.pop();

        if(curr_node.first.first == eX && curr_node.first.second == eY){
            cout<<curr_node.second; return; }

        FORI(0, 8){ // to go for all directions
            int new_x = curr_node.first.first + dir_x[i];
            int new_y = curr_node.first.second + dir_y[i];
            if( exist[{new_x, new_y}] && !visited[{new_x, new_y}] ){
                qe.push({{new_x, new_y}, curr_node.second + 1}); // curr_node.second + 1 is the cost for this new cell
                visited[{new_x, new_y}] = true;
            }
        }
    }

    cout<< -1;
}


void burn(){

    cin>>sX>> sY>> eX>> eY;
    int no_segments; cin>>no_segments;

    int s_column, e_column, row;
    FORI(0, no_segments){
        cin>>row>>s_column>>e_column;
        for(int j = s_column; j <= e_column; j++){
            exist[{row, j}] = true;
        }
    }

    bfs();


}




int main()
{
    // freopen("contest.in","rt",stdin); g++ tempans -o tempans
    Mo7amed_Nasr
    // preprocessing
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
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
