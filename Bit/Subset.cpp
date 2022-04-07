#include<bits/stdc++.h>
using namespace std;
int main() {
    int n = 5;
    for (int subset = 0; subset < (1 << n); subset++) {
        cout<<"subset "<<subset<<endl;
        for (int i = 0; i < n; i++) {
//            cout<<"i "<<i<<endl;
//            cout<<"(subset & (1 << i) "<<(subset & (1 << i))<<endl;
            if ((subset & (1 << i)) != 0) {
            printf("%d ", i+1);
            }
        }
        printf("\n");
    }
}
