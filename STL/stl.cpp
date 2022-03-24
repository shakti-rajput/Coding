#include<bits/stdc++.h>
using namespace std;

////std is a space where c++ standards names are present. For example --> cout is in the space named as std by c++.
////** If we dont use std we will have to use std::cout instead of cout. **

struct Person {
    string name;
    int age;
    double income;
    int sex;
    Person() {

    } // If we define our own constructor in the struct, we have to declare this default constructor also
    Person(string name_,int age_,double income_,int sex_) {
        name = name_;
        age = age_;
        income = income_;
        sex = sex_;
    }
};

array<int, 3> arrGlobal; // -> {0, 0, 0}
int arr_global[10000000]; //max size of 10^7 -> int, double, char
bool arr_bool[100000000]; //max size of 10^8 -> bool

namespace shakti {
    int val = 50;
    int getVal() {
        return val*10;
    }
}
int namespaceExample() {

    // int val = 50; // Commented as it will throw error
    double val = 10.0;
    cout<<val<<endl;  // value will be 10 as default we are using std by this line ---> using namespace std;
    cout<<shakti::val<<endl;  // value will be 50 as default we are using is std. // Error if both declare in the same namespace.
    cout<<shakti::getVal()<<endl;

}
int StructExample() {
    Person shakti; // At this moment the random values will be there in all the variables(age, name, income) of person shakti. It is the wrong way of declaring this.
    shakti.age = 25;
    shakti.income = 0.0;
    shakti.name = "Shakti";
    shakti.sex = 'M';

    //  The alternative way is to define is to create a constuctor in struct.
    Person harshil("Harshil Gandhi", 26, 100000.0, 1);
    Person *vaibhav = new Person("Vaibhav", 26, 100000.0, 1);
    Person umakant = Person("Umakant", 26, 100000.0, 1);

}
void arrayExample() {
    //************************** arrays ***********************************
    int arrInteger[100000]; // max size of 10^6 -> int, double, char
    bool arrBool[1000000]; // max size of 10^7 -> bool

    array<int, 3> arr1;  // -> {?, ?, ?} // ? --> random
    //    array<int, 5> arr2 = {1}; // -> {1, 0, 0, 0, 0}
    array<int, 16> arr3;
    arr3.fill(10);  //    -> /// {10, 10, 10, 10, 10}

    for(int i = 0; i<5; i++) {
        cout << arr3.at(i) << " ";
    }

    //************************ iterators ********************************
    // begin(), end(), rbegin(), rend()

    array<int, 5> arr = {1, 3, 4, 5, 6};
    cout<<"1st   ----->   "<<endl;
    for(auto it =  arr.begin(); it!=arr.end(); it++) {
        cout << *it << " ";
    }
    cout<<endl;
    cout<<"2nd   ----->   "<<endl;
    for(auto it= arr.rbegin(); it!=arr.rend(); it++) {
        cout << *it << " ";
    }
    cout<<endl;
    cout<<"3rd   ----->   "<<endl;
    for(auto it= arr.end() - 1; it>=arr.begin(); it--) {
        cout << *it << " ";
    }
    cout<<endl;
    cout<<"4th   ----->   "<<endl;
    for(auto it: arr) {
        cout << it << " ";
    }
    cout<<endl;

    cout<<"5th"<<endl;
    string s = "xhegcwe";
    // x h e g c w e
    for(auto c:s) {
        cout << c << " ";
    }
    cout<<endl;

    // size
    cout << arr.size();

    // front
    cout << arr.front(); // arr.at(0);

    // back
    cout << arr.back(); // arr.at(arr.size() - 1);
}
void vectorExample() {
    // segmentation fault if you push_back 10^7 times

    vector<int> arr; // -> {}
    cout << arr.size() << endl; // -> print 0
    arr.push_back(0); // {0}
    arr.push_back(2); // {0,2}
    cout << arr.size() << endl; // -> print 2
    arr.pop_back(); // {0}
    cout << arr.size() << endl; // print 1

    arr.push_back(0); // {0,0}
    arr.push_back(2); // {0,0,2}
    arr.clear(); // --> erase all elements at once {}


    vector<int> vec1(4, 0); // -> {0,0,0,0}
    vector<int> vec2(4, 10); // -> {10,10,10,10}

    // copy the entire vec2 into vec3
    vector<int> vec3(vec2.begin(), vec2.end()); // -> [)
    vector<int> vec4(vec2);
    vector<int> raj;
    raj.push_back(1); // raj.emplace_back(1); // emplace_back takes lesser time than push back
    raj.push_back(3);
    raj.push_back(2);
    raj.push_back(5); // -> {1, 3, 2, 5}

    vector<int> shakti(raj.begin(), raj.begin() + 2);  // -> {1, 3}

    // lower bound , upper bound
    // swap(v1, v2)
    // begin(), end(), rbegin(), rend()
    // to defining 2d vectors

    vector<vector<int> > vec;

    vector<int> raj1;
    raj1.push_back(1);
    raj1.push_back(2);

    vector<int> raj2;
    raj2.push_back(10);
    raj2.push_back(20);

    vector<int> raj3;
    raj3.push_back(19);
    raj3.push_back(24);
    raj3.push_back(27);

    vec.push_back(raj1);
    vec.push_back(raj2);
    vec.push_back(raj3);

    // it is vector itself
    for(auto vctr: vec) {
        for(auto it: vctr) {
            cout << it << " ";
        }
        cout << endl;
    }


    for(int i = 0; i<vec.size(); i++) {
        for(int j = 0; j<vec[i].size(); j++) {
            cout <<  vec[i][j] << " ";
        }
        cout << endl;
    }

    // define 10 x 20
    vector<vector<int>> vec2D(10, vector<int> (20, 0));
    vec2D.push_back(vector<int>(20, 0));
    cout << vec2D.size() << endl; // 11 prints
    vec2D[2].push_back(1);

    // 10 x 20 x 30 // int arr[10][20][30]
    vector<vector<vector<int>>> vec3d(10, vector<vector<int>> (20, vector<int> (30, 0)));
}
void setExample() {
    // given n elements, tell me the number of unique elements
    int arr[] = {2, 5, 2, 1, 5}; // 3 unique elements -> {1. 2. 5}

    set<int> st = {1, 5, 7, 8, 5, 2, 1};

    int n=5;
    for(int i = 0; i<n; i++) {
        st.insert(i);
    }

    cout << st.size();

    // st -> {1, 2, 5}
    // erase functionality
    // log n
    st.erase(st.begin()); // st.erase(iterator) // st -> {2, 5}

    // log n
    // 77777777777
    st.erase(st.begin(), st.end()); // -> [)
    // st.erase(startIterator, endIterator)

    st.erase(5); // st.erase(key) // delete the 5 -> {1, 2}


    set<int> st2 = {1, 5, 7, 8};

    auto it_7 = st2.find(7); // log n // it will be iterator to 7

    auto it_9 = st2.find(9); // it = st.end();

    st2.emplace(6); // st.insert(6)

    cout << st.size() << endl;


    set<int> st3;
    st3.insert(5); // -> {5}
    st3.insert(5); // -> {5}

    for(auto it=st3.begin(); it!=st3.end(); it++) {
        cout << *it << " ";
    }

    for(auto it : st3) {
        cout << it << endl;
    }

    // delete the entire set
    st3.erase(st3.begin(), st3.end()); // makes sure the entire set is deleted
    unordered_set<int> st4;

    st4.insert(2);
    st4.insert(3);
    st4.insert(1);

    // average time complexity is O(1)
    // tle -> switch to set
    // but the worst case is linear in nature, O(set size)

    multiset<int> ms;

    ms.insert(1);
    ms.insert(1);
    ms.insert(2);
    ms.insert(2);
    ms.insert(3); // ms.emplace(3)
    // st -> {1, 1, 2, 2, 3}

    ms.erase(2); // all the instances will be erased

    auto it = ms.find(2); // returns an iterator pointing to the first element of 2
    ms.clear(); // deleted the entire set
    ms.erase(ms.begin(), ms.end()); // deletes the entire set
    // log n in size


    for(auto it=st.begin(); it!=st.end(); it++) {
        cout << *it << " ";
    }

    for(auto it : st) {
        cout << it << endl;
    }
    // finds how many times 2 occurs
    st.count(2);

    auto itr = ms.find(2);
    if(itr!=ms.end()) {
        ms.erase(itr);
    }
    ms.erase(ms.find(2), ms.end());

}
void mapAndPairExample() {
    // Key Value
    // raj -> 27
    // hima -> 31
    // sandeep -> 67
    // tank -> 89
    // map only stores unique keys
    // log n is the tc of map
    map<string, int> mpp;
    mpp["raj"] = 27;
    mpp["hima"] = 31;
    mpp["praveer"] = 31;
    mpp["sandeep"] = 67;
    mpp["tank"] = 89;
    mpp["raj"] = 29;
    mpp.emplace("raj", 45);
    mpp.erase("raj"); // mpp.erase(key)
    mpp.erase(mpp.begin()); // mpp.erase(iterator)
    mpp.clear(); // entire map is cleaned up
    //	mpp.erase(mpp.begin(), mpp.begin()+2); // cleans up a given range
    auto it = mpp.find("raj"); // points to where raj lies
    auto it2 = mpp.find("simran"); // points to end since she does not exists

    if(mpp.empty()) {
        cout << "Yes it is empty";
    }
    mpp.count("raj"); // always returns 1 as it stores only 1
    // instance of raj

    // printing map
    for(auto it: mpp) {
        cout << it.first << " " << it.second << endl;
    }

    for(auto it = mpp.begin(); it!=mpp.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    // does not stores in any order
    unordered_map<int,int> Umpp;
    //    unordered_map<pair< int ,int > ,int > Umpp2D; //xxxxxx

    //    // o(1) in almost all cases
    //    // o(n) in the worst case, where n is the container size
    //
    //
    multimap<string, int> MUmpp;
    mpp.emplace("raj", 2);
    mpp.emplace("raj", 5);
}
void pairExample() {
    // Pair class
    pair<int,int> pr1;
    pr1.first = 1;
    pr1.second = 10;
    pair<int,int> pr2 = {1,2};
    pair< pair<int,int>, int> pr3 = {{1,2}, 2};
    cout << pr3.first.second << endl;
    pair<pair<int,int>,  pair<int,int>> pr4 = {{1,2},{2, 4}};
    cout << pr4.first.first; //-> 1
    cout << pr4.second.second;// -> 4
    vector<pair<int,int>> vec;
    set<pair<int,int>> st;
    map< pair<int,int>, int> mpp;
}
void stackExample() {
    stack<int> st; // lifo ds
    // pop
    // top
    // size
    // empty
    // push and emplace

    st.push(2);
    st.push(4);
    st.push(3);
    st.push(1);


    cout << st.top(); // prints 2
    st.pop(); // deletes the last entered element
    cout << st.top(); // prints 3
    st.pop();
    cout << st.top();

    bool flag = st.empty(); // returns true if stack is empty, or false

    // deleted the entire stack
    while(!st.empty()) {
        st.pop();
    }

    cout << st.size() << endl; // number of elements in the stack

    if(!st.empty()) {
        cout << st.top() << endl; // throw error
    }
}
void queueExample() {
    // queue // fifo operation ds
    // push
    // front
    // pop
    // size
    // empty

    queue<int> q;
    q.push(1);
    q.push(5);
    q.push(3);
    q.push(6);

    cout << q.front();; // prints 1
    q.pop();
    cout << q.front(); // prints 5

    // linear time
    while(!q.empty()) {
        q.pop();
    }
    for(int i = 0; i<10; i++) q.push(i);

}

void priorityQueueExample() {

    // priority_queue
    // push
    // size
    // top pop empty
    priority_queue<int> pq;
    pq.push(1);
    pq.push(5);
    pq.push(2);
    pq.push(6);

    cout << pq.top(); // print 6
    pq.pop();
    cout << pq.top(); // print 5

    priority_queue<pair<int,int>> pqPair;
    pqPair.push(make_pair(1, 5));
    pqPair.push(make_pair(1, 6));
    pqPair.push(make_pair(1, 7));

    priority_queue<int> pq1;
    pq1.push(-1); // pq.push(-1 * el);
    pq1.push(-5);
    pq1.push(-2);
    pq1.push(-6);

    cout << -1 * pq1.top() << endl; // prints 1

    // min priority queue is
    priority_queue<int, vector<int>, greater<int>> pq2;
    pq2.push(1);
    pq2.push(5);
    pq2.push(2);
    pq2.push(6);

    cout << pq2.top() << endl; // prints 1



    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq3;


    deque<int> dq;
    // push_front()
    // push_back()
    // pop_front()
    // pop_back()
    // begin, end, rbegin, rend
    // size
    // clear
    // empty
    // at
}

void listExample() {

    list<int> ls;
    // push_front()
    // push_back()
    // pop_front()
    // pop_back()
    // begin, end, rbegin, rend
    // size
    // clear
    // empty
    // at
    // remove -> O(1)
    ls.push_front(1);
    ls.push_front(2);
    ls.push_front(3);
    ls.remove(2);
    //-> // o(1) operation
}

void Question1() {

    // given N elements, print the elements that occurs maximum
    // number of times
    // input
    // 5
    // 1 3 3 3 2

    // output
    // 3
    int n=5;
    map<int,int> mpp;
    int maxi = 0;
    int x=3;
    for(int i = 0; i<n; i++) {
        mpp[x]++;
        if(mpp[x] > mpp[maxi]) {
            maxi = x;
        }
    }
    cout << x << endl;
}
void Question2() {

    // given N elements, print all elements in sorted order
    // input
    // n = 6
    /// 6 6 3 2 3 5

    // output
    // 2 3 3 5 6 6

    int n=5;
    multiset<int> ms;
    for(int i=0; i<n; i++) {
        ms.insert(i);
    }

    for(auto it : ms) {
        cout << it << endl;
    }

}
void BitSetExample() {

    // Bitset
    // int -> 16 bits
    // char -> 8 bits
    int a[100];
    char a2[100];

    // bitset -> 1 bit

    bitset<15> bt; // stores 1 or 0
    bt= 10111; // 10111

    // all
    // true // false
    cout << bt.all(); // returns a true or a false

    // any
    // true
    cout << bt.any(); // bt -> 10011

    // false
    cout << bt.any(); // bt -> 00000

    // count
    // for bt -> 10100
    // prints 2
    cout << bt.count(); // print the number of set bits

    // flip
    // bt -> 10100
    bt.flip(2); // bt will become 10000

    bt.flip();

    // none
    // if none is set, then true, else false
    // bt -> 10000
    cout << bt.none(); // false

    // bt -> 00000
    cout << bt.none(); //true

    // set
    bt.set(); // 11111

    bt.set(2); // sets the 2nd index

    bt.set(2, 0);


    // reset
    bt.reset(); // turn all indexes to 0

    bt.reset(2); // turn the 2nd index to 0

    // size
    cout << bt.size(); // prints 5

    // test

    cout << bt.test(1); // check if the bit is set or not at index  1

}

bool comp1(int el1, int el2) {
    if(el1 <= el2) {
        return true;
    }
    return false;
}

bool comp2(pair<int,int> el1, pair<int,int> el2) {
    if(el1.first < el2.first) {
        return true;
    }
    if(el1.first == el2.first) {
        if(el1.second > el2.second) {
            return true;
        }
    }
    return false;
}

void sortingExample() {

    // sorting
    // array, vector
    int n=5;
    int arr[n];
    for(int i = 0; i<n; i++) arr[i]=i;
    // takes n log n
    sort(arr, arr+n); // in increasing order
    // sort from 1 to 3
    sort(arr + 1, arr + 4);

    vector<int> vec(5, 0);
    for(int i = 0; i<n; i++) {
        vec[i]=i;
    }

    sort(vec.begin(), vec.end()); // [)

    // vec -> {1, 6, 2, 7, 4}
    //         0  1  2  3  4
    // sort it so that only indexes from 1 to 3
    // final vec -> {1, 2, 6, 7, 4}
    sort(vec.begin() + 1, vec.begin() + 4); // [1, 4);



    // COMPARATOR
    sort(arr, arr+n); // sorts everything in ascending order
    sort(arr, arr+n, comp1);
    //

    // descending
    sort(arr, arr+n, comp1);
    // greater<int> is an inbuilt comparator
    // which works only if you wanna do this in descending
    sort(arr, arr+n, greater<int>());

}

void reverseExample() {
    // If I wanna reverse
    // reverse(startIterator, endIterator) -> [)
    int n=5;
    int arr[n];
    for(int i = 0; i<n; i++) arr[i]=i;

    reverse(arr, arr+n);

    reverse(arr + 1, arr + 4);

    vector<int> vec(5, 0);
    for(int i = 0; i<n; i++) {
        vec[i]=i;
    }

    reverse(vec.begin(), vec.end());

    reverse(vec.begin() + 1, vec.begin() + 4);
}

void maximumElementExample() {
    // If i want to fine the maximum elements in any index range
    // i to j give me the maximum

    // *max_element(firstIterator, lastIterator);
    int maxi = INT_MIN;
    int i=0,j=3,k=5,a[10]= {0};
    for(int k = i; k<=j; k++) {
        if(a[k] > maxi) {
            maxi = a[k];
        }
    }

    int n=5;
    int arr[n];
    for(int i = 0; i<n; i++) arr[i]=i;

    int el = *max_element(arr, arr+n);
    int el1 = *min_element(arr, arr+n);

    vector<int> vec(5, 0);
    for(int i = 0; i<n; i++) {
        vec[i]=i;
    }

    int el2 = *max_element(vec.begin(), vec.end());
    int el3 = *min_element(vec.begin(), vec.end());

}

void sumExample() {
    // I give you a range and I want you to find the sum in that range
    // i - j, tell me the sum in that range i to j
    int sum = 0;
    int i=0,j=5;

    int n=5;
    int arr[n];
    for(int i = 0; i<n; i++) arr[i]=i;

    for(int k = i; k<=j; k++) {
        sum += arr[k];
    }

    vector<int> vec(5, 0);
    for(int i = 0; i<n; i++) {
        vec[i]=i;
    }

    // accumulate(startIterator, endIterator, initialSum);
    int sum3 = accumulate(arr, arr+n, 0);
    int sum2 = accumulate(vec.begin(), vec.end(), 0);

}

void countOccuranceExample() {
    // arr[] -> [1, 6, 7, 1, 2, 1, 3]
    // x = 1
    // tell me how many times the element 1 occurs in the array
    int cnt = 0;
    // O(N)
    int n=5;
    int arr[n];
    int x=3;
    for(int i = 0; i<n; i++) arr[i]=i;
    vector<int> vec(5, 0);
    for(int i = 0; i<n; i++) {
        vec[i]=i;
    }


    for(int i = 0; i<n; i++) {
        if(arr[i] == x) {
            cnt++;
        }
    }
    cout << cnt;

    /// count(firstIterator, lastIterator, x)
    int cnt1 = count(arr, arr+n, 1);
    int cnt2 = count(vec.begin(), vec.end(), 1);

}

void firstOccuranceExample() {
    // i want you to find the first occurrence of 2
    // it is in the index 1

    int ind = -1;
    int x=3;
    int n=5;
    int arr[n];
    for(int i = 0; i<n; i++) arr[i]=i;
    vector<int> vec(5, 0);
    for(int i = 0; i<n; i++) {
        vec[i]=i;
    }

    for(int i = 0; i<n; i++) {
        if(arr[i] == x) {
            ind = i;
            break;
        }
    }
    cout << ind;


    // arr[] -> {1, 2, 5, 1, 2, 4, 4}
    auto it1 = find(arr, arr+n, 2); // return an iterator
    // pointing to the first instance of it, or else it
    // returns pointing to the end() if it is not there

    int ind1 = it1 - arr;


    auto it2 = find(vec.begin(), vec.end(), 2);
    int ind2 = it2 - vec.begin();


    // arr[] -> {1, 5, 6, 2, 3, 5, 6}
    // x = 4
    auto it = find(vec.begin(), vec.end(), 4);
    if(it == vec.end()) {
        cout << "element is not present";
    } else {
        cout << "Element is first present at: " << it - vec.begin();
    }

}

void binarySearchExample() {
    // binary search
    // this stl only works on SORTED arrrays
    // arr[] -> {1, 5, 7, 9, 10}
    // x = 9
    // true -> 9 exists in my arr
    // x = 8
    // false -> 8 does not exist in my arr


    // binary_search(firstIterator, lastIterator, x)
    // returns a true or returns a false
    // works in log n complexity
    int x=3;
    int n=5;
    int arr[n];
    for(int i = 0; i<n; i++) arr[i]=i;
    vector<int> vec(5, 0);
    for(int i = 0; i<n; i++) {
        vec[i]=i;
    }


    bool res1 = binary_search(arr, arr+n, 8);
    bool res2 = binary_search(vec.begin(), vec.end(), 8);


    // lower_bound function
    // returns an iterator pointing to the first
    // element which is not less than x
    // arr[] -> {1, 5, 7, 7, 8, 10, 10, 10, 11, 11, 12}
    // x = 10
    // x = 6
    // x = 13
    // this works in log N

    auto it = lower_bound(arr, arr+n, x);
    int ind;
    ind = it - arr;

    auto it2 = lower_bound(vec.begin(), vec.end(), x);
    ind = it2 - vec.begin();

    int ind2=  lower_bound(vec.begin(), vec.end(), x) - vec.begin();



    // upper bound
    // returns an iterator which points to an element which is
    // just greater than x
    // arr[] -> {1, 5, 7, 7, 8, 10, 10, 10, 11, 11, 12}
    // x = 7
    // x = 6
    // x = 12 -> end() iterator
    // x = 15 -> end() iterator

    auto it3 = upper_bound(arr, arr+n, x);
    ind = it3 - arr;

    auto it4 = upper_bound(vec.begin(), vec.end(), x);
    int ind3 = it4 - vec.begin();

    int ind4 =  upper_bound(vec.begin(), vec.end(), x) - vec.begin();



    // Q1. find me the first index where the element X lies
    // find function can be used but that takes O(N) times
    // the array is sorted..


    // arr[] -> {1, 5, 7, 7, 8, 10, 10, 10, 11, 11, 12}
    // find x = 7
    int ind5 = lower_bound(arr, arr+n, x) - arr;

    // find x = 6
    int ind6 = lower_bound(arr, arr+n, x) - arr;



    // There are couple of ways to do it
    // 1st way
    if(binary_search(arr, arr+n, x) == true) {
        cout << lower_bound(arr, arr+n, x) - arr;
    } else cout << "does not exists";


    // 2nd way
    int ind7 = lower_bound(arr, arr+n, x) - arr;
    // arr[] -> {1, 5, 7, 7, 8, 10, 10, 10, 11, 11, 12}
    /////////////0  1  2  3  4  5   6   7   8   9   10
    // find x = 13 -> ind = 11, which is out of bound
    // hence arr[11] will give you runtime error
    if(ind7 != n && arr[ind7] == x) {
        cout << "Found at: " << ind;
    } else {
        cout << "Not found";
    }

    // Find me the last occurrence of x in an arr
    // arr[] -> {1, 5, 7, 7, 8, 10, 10, 10, 11, 11, 12}
    ///index/////0  1  2  3  4  5   6   7   8   9   10

    // last occurrence of x = 10, ans = 7th index
    // last occurrence of x = 6, ans = does not exists
    // last occurrence of x = 0,
    // last occurence of x = 13
    int ind8 = upper_bound(arr, arr+n, x) - arr;
    ind8 -= 1;
    if(ind8>=0 && arr[ind8] == x) {
        cout << "last occurrence: " << ind8;
    } else {
        cout << "Does not exists";
    }
}

void nextPermutationExample() {
    // Q3. tell me the number of times the x appears in arr
    // arr[] -> {1, 5, 7, 7, 8, 10, 10, 10, 11, 11, 12}
    ///index/////0  1  2  3  4  5   6   7   8   9   10

    // x = 10, ans = 3
    // x = 7, ans = 2


    // Next Permutation
    // string s = "abc"
    // all permutations are as follows:

    // abc
    // acb
    // bac
    // bca
    // cab
    // cba



    // s = "bca"
    string s = "bca";
    bool res = next_permutation(s.begin(), s.end());

    // s = "cba"
    bool res2 = next_permutation(s.begin(), s.end());

    // if I give you any random string s = "bca"
    // i want you to print all the permutations


    sort(s.begin(), s.end()); // this makes the string as "abc"
    do {
        cout << s << endl;
    } while(next_permutation(s.begin(), s.end()));


    int arr[] = {1, 6, 5};
    int n = 3;
    sort(arr, arr + n); // this makes the array as {1, 5, 6}
    do {
        for(int i = 0; i<n; i++) cout << arr[i] << " ";
        cout << endl;
    } while(next_permutation(arr, arr+n)) ;


    // prev permutation
    bool res3 = prev_permutation(s.begin(), s.end());
}

int main() {

    //  Use of namespace
    cout<<endl;
    namespaceExample();

    // //	Standard DataTypes are --> int, double, float, char ....
    // //  Create your own DataType... ----> struct
    cout<<endl;
    StructExample();


    // ************************** VECTOR **********************************
    cout<<endl;
    arrayExample();
    cout<<endl;
    vectorExample();
    cout<<endl;
    setExample();
    cout<<endl;
    mapAndPairExample();
    cout<<endl;
    pairExample();
    cout<<endl;
    stackExample();
    cout<<endl;
    queueExample();
    cout<<endl;
    priorityQueueExample();
    cout<<endl;
    listExample();
    cout<<endl;
    Question1();
    cout<<endl;
    Question2() ;
    cout<<endl;
    BitSetExample();
    cout<<endl;
    sortingExample();
    cout<<endl;
    reverseExample();
    cout<<endl;
    maximumElementExample();
    cout<<endl;
    sumExample();
    cout<<endl;
    countOccuranceExample();
    cout<<endl;
    firstOccuranceExample();
    cout<<endl;
    binarySearchExample();
    cout<<endl;
    nextPermutationExample();
    cout<<endl;
}
