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

const int Size = 2e3 + 5;
vector <  vector<int> > adjacency_list(Size); // to represent the graph
// vector <  list<int> > adjacency_list(Size); // same complexity as the line above

int dis[Size][Size];
queue< pair<int, int> > qe;

int dir_x[] = {0, 0, 1, -1};
int dir_y[] = {1, -1, 0, 0};

bool check_coordinates (int x, int y, int n, int m){
    if(x > 0 && x <= n && y > 0 && y <= m) return true;
    return false;
}

void bfs (int n, int m) {

    while(!qe.empty()){

        int curr_node_x = qe.front().first;
        int curr_node_y = qe.front().second;
        qe.pop();
        int curr_cost = dis[curr_node_x][curr_node_y];

        FORI(0, 4){
            int new_x = curr_node_x + dir_x[i];
            int new_y = curr_node_y + dir_y[i];

            if(check_coordinates(new_x, new_y, n, m) && curr_cost + 1 < dis[new_x][new_y]){
                qe.push({new_x, new_y});
                dis[new_x][new_y] = curr_cost + 1;
            }
        }

    }

}


void burn(){

    int n, m, x, y; cin>>n>>m;
    // we will do multi source here for the bfs means more than one root (multi bfs)
    int k; cin>>k;

    for(int i = 1; i <= n; i++){ // initilize the cost
      for(int j = 1; j <= m; j++){
        dis[i][j] = INT_MAX;
      }
    }

    FORI(0, k){
        cin>>x>>y;
        // we here don't need adjacency_list bc we already know the adjacents
        qe.push({x, y});
        dis[x][y] = 0; // those are teh sources

    }

    bfs(n, m);

    int mxm = -1;
    int ans_x = -1;
    int ans_y = -1;


    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(dis[i][j] > mxm){
                mxm = dis[i][j];
                ans_x = i, ans_y = j;
            }
        }
    }

    cout<< ans_x <<' '<< ans_y ;
}




int main()
{
    // freopen("contest.in","rt",stdin); g++ tempans -o tempans
    Mo7amed_Nasr
    // preprocessing
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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
