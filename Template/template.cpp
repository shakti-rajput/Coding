#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define out cout<<endl
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin();i != (c).end(); i++)
#define fastIO	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main() {
    fastIO;
    int n=5;
    vi a_list={0,1,2,3,4,5};
    sort(all(a_list));
    FOR(i,0,a_list.size())
    {
        cout<<a_list[i]<<endl;
    }
    out;
    FOR(i,0,10) a_list.push_back(i*i);  // for (int i = (0); i < (100); i++) a_list.push_back(i*i);
    sort((a_list).begin(), (a_list).end());
    FOR(i,0,a_list.size())
    {
        cout<<a_list[i];
        out;
    }
    out;
    FORIT(i,a_list) cout << *i << endl;
    out;
    vector<int> list1;
    list1.clear();
    FOR(i,0,n) {
        int a=i+13;
        list1.push_back(a);
    }
    sort(all(list1));

    FORIT(i,list1) cout << *i << endl;
    set<int> s;
    FOR(i,0,n) {
        int a=i+234;
        s.insert(a);
    }
    FORIT(i,s) cout << *i << endl;
    map<int,int> m;
    m.clear();
    FOR(i,0,n) {
        int x=i,y=i+10;
        m[y] = x;
    }
    FOR(i,0,n) {
        int z=i+34;
        cout << m[z] << endl;
    }
}
