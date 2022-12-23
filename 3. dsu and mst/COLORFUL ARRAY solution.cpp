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

int col[Size];
void burn() {
    int n, m, x, y, c; cin >> n >> m;

    set<int> st;
    for(int i = 1; i <= n ; i++){
        st.insert(i);
    }

    vector <pair <pair <int, int>, int> > queries;
    FORI(0, m){
        cin >> x >> y >> c;
        queries.push_back({{x, y}, c});
    }


    int siz = int(queries.size());
    for(int i = siz - 1; i >= 0; i--){
        int l = queries[i].first.first, r = queries[i].first.second, c = queries[i].second;
        while(st.lower_bound(l) != st.end() && *st.lower_bound(l) <= r){
            int element = *st.lower_bound(l); // any function in the set takes only log(n) so the overall complexity is n * log(n) to solve this problem
            col[element] = c;
            st.erase(element);
        }
    }

    for(int i = 1; i <= n; i++){
        cout << col[i] << '\n';
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
//    cin.ignore();
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
