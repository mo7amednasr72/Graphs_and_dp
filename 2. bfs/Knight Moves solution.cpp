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



int cost[9][9];
int dir_x[] = {-2, 2, -1, 1, -2, 2, -1, 1};
int dir_y[] = {-1, -1, -2, -2, 1, 1, 2, 2};

unordered_map < char, int > mp;

void init (){
    int j = 0;
    for(char i = 'a'; i <= 'h' ; i++){
       mp[i] = ++j;
    }
}

bool check_validation(int new_x, int new_y){
    return (new_x > 0 && new_x <= 8 && new_y > 0 && new_y <= 8 );
}

int bfs (pair<int, int> starting_point, pair<int, int> target_point){

    for(int i = 1; i <= 8; i++){
        for(int j = 1; j <= 8; j++) cost[i][j] = INT_MAX;
    }

    queue< pair<int, int> > qe;
    qe.push(starting_point);
    cost[starting_point.first][starting_point.second] = 0;

    while(!qe.empty()){

        auto curr_node = qe.front();
        qe.pop();
        int curr_cost = cost[curr_node.first][curr_node.second];
        if(curr_node == target_point) break;

        for(int i = 0; i < 8; i++){
            int new_x = curr_node.first + dir_x[i];
            int new_y = curr_node.second + dir_y[i];
            if(check_validation(new_x, new_y) && curr_cost + 1 < cost[new_x][new_y]){
                qe.push({new_x, new_y});
                cost[new_x][new_y] = curr_cost + 1;
            }
        }

    }

    return cost[target_point.first][target_point.second];

}


void burn(){

    init();
    string str;
    while(getline(cin, str) && str.length()){
        pair <int, int > starting_point = {mp[str[0]], str[1] - '0'};
        pair <int, int > target_point = {mp[str[3]], str[4] - '0'};
        int ans = bfs(starting_point, target_point);
        cout<< "To get from "<< str[0] << str[1] << " to " << str[3] << str[4] <<" takes "<< ans <<" knight moves.\n";
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
