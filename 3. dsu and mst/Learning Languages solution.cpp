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

const int Size = 1e2 + 5;
//vector < vector < int > >adjacency_list(Size); // to represent the graph
// vector <  list<int> > adjacency_list(Size); // same complexity as the line above


int par[Size], com_size[Size];

void make_set(int n){
    for(int i = 1; i <= n; i++){
        par[i] = i, com_size[i] = 1;
    }
}

int find_parent(int node){
    if(par[node] == node) return  node;
    return par[node] = find_parent(par[node]);
}

bool already_connected(int x, int y){
    return (find_parent(x) == find_parent(y));
}

void connect(int x, int y){
    x = find_parent(x);
    y = find_parent(y);
    if(x == y) return;
    if(com_size[x] < com_size[y]) swap(x, y);
    par[y] = x;
    com_size[x] += com_size[y];
}

bool spoken_lang[Size];

void burn(){
    int n, m, k; cin >> n >> m;
    make_set(n);

    int ans = 0;

    for(int i = 0; i < n; i++){

        cin >> k; if( k == 0) ans++;
        int temp_arr[k];

        for(int j = 0; j < k ; j++){
            cin >> temp_arr[j];
            spoken_lang[temp_arr[j]] = true;
            if(j > 0){
                connect(temp_arr[j], temp_arr[j - 1]);
            }
        }

    }

    int no_component = 0;
    for(int i = 1; i <= m; i++){
        if(find_parent(i) == i && spoken_lang[i]) no_component++;
    }

    ans += ((no_component > 0) ? no_component - 1 : 0);

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
