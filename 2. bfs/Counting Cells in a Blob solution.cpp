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

const int Size = 1e5 + 5;
vector <  vector<int> > adjacency_list(Size); // to represent the graph
// vector <  list<int> > adjacency_list(Size); // same complexity as the line above

int len, k , remaining, no_empty, sx, sy;
const int N = 30, M = 27;

bool exist[N][N], visited[N][N];
int dir_x[] = {0, 0, -1, 1, 1, -1, 1, -1};
int dir_y[] = {1, -1, 0, 0, 1, -1, -1, 1};

bool check_validation(int new_x, int new_y){
    return (new_x > 0 && new_x <= k && new_y > 0 && new_y <= len && exist[new_x][new_y] && !visited[new_x][new_y]);
}

int bfs(pair<int, int> src){
    int cnt = 0;
    queue < pair<int, int> > qe;
    qe.push(src);
    visited[src.first][src.second] = true;

    while( !qe.empty()){
        auto curr_node = qe.front();
        qe.pop();
        cnt++;
        FORI(0, 8){
            int new_x = curr_node.first + dir_x[i];
            int new_y = curr_node.second + dir_y[i];
            if(check_validation(new_x, new_y) ){
                visited[new_x][new_y] = true;
                qe.push({new_x, new_y});
            }
        }
    }

    return cnt;

}




void burn(){


    string str;

    int j = 0;
    int temp_len;
    while(getline(cin, str) && str.length()){

        temp_len = str.length();
        FORI(1, temp_len + 1){
            exist[j + 1][i] = str[i - 1] - '0';
        }
        j++;
    }

    k = j;
    len = temp_len;
    memset(visited, false, sizeof visited);

    int ans = 0;

    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= len ; j++){
            if(!visited[i][j] && exist[i][j]){
                pair <int, int> pair_value = {i, j};
                ans = max(ans, bfs(pair_value));
            }
        }
    }
    cout<< ans << '\n';

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
    cin.ignore();
    cin.ignore();
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
