#include<bits/stdc++.h>
using namespace std;
//std is a space where c++ standards names are present. For example --> cout is in the space named as std by c++.
//** If we dont use std we will have to use std::cout instead of cout. **
// #pragma warning( push )
// #pragma warning( disable : 4705 )
// #pragma warning( disable : 4706 )
// #pragma warning( disable : 4707 )


struct Person {
	string name;
	int age;
	double income;
	int sex;
	Person()
	{

	} // If we define our own constructor in the struct, we have to declare this default constructor also
	Person(string name_,int age_,double income_,int sex_)
	{
		name = name_;
		age = age_;
		income = income_;
		sex = sex_;
	}
};

	//	array<int, 3> arrGlobal; // -> {0, 0, 0}

	// max size of 10^7 -> int, double, char
	//	int arr_global[10000000];

	// max size of 10^8 -> bool
	//	bool arr_bool[100000000];

namespace shakti {
	int val = 50;
	int getVal(){
		return val*10;
	}
}
int namespaceExample()
{
// Commented as it will throw error
//	int val = 50;
	double val = 10.0;
	cout<<val<<endl;  // value will be 10 as default we are using std by this line ---> using namespace std;
	cout<<shakti::val<<endl;  // value will be 50 as default we are using is std.
	cout<<shakti::getVal()<<endl;
	// Error if both declare in the same namespace.
}
int StructExample(){
	Person shakti; // At this moment the random values will be there in all the variables(age, name, income) of person shakti. It is the wrong way of declaring this.
	shakti.age = 25;
	shakti.income = 0.0;
	shakti.name = "Shakti";
	shakti.sex = 'M';

//  The alternative way is to define is to create a constuctor in struct.
	Person harshil("Harshil Gandhi", 26, 100000.0, 1);
}
void arrayExample()
{
	// ************************** arrays ***********************************
	//	int arr[1000000]; // max size of 10^6 -> int, double, char
	//	bool arr[10000000]; // max size of 10^7 -> bool

	//	array<int, 3> arr1;  // -> {?, ?, ?} // ? --> random
	//	array<int, 5> arr2 = {1}; // -> {1, 0, 0, 0, 0}
	//	array<int, 5> arr;
	//	arr.fill(10); -> /// {10, 10, 10, 10, 10}

	//	for(int i = 0;i<5;i++) {
	//		cout << arr.at(i) << " ";
	//	}


// ************************ iterators ********************************
	//	// begin(), end(), rbegin(), rend()
	//
	//	array<int, 5> arr = {1, 3, 4, 5, 6};
	//	cout<<"1st   ----->   "<<endl;
	//	for(auto it =  arr.begin(); it!=arr.end();it++) {
	//		cout << *it << " ";
	//	}
	//	cout<<endl;
	//	cout<<"2nd   ----->   "<<endl;
	//	for(auto it= arr.rbegin(); it!=arr.rend();it++) {
	//		cout << *it << " ";
	//	}
	//	cout<<endl;
	//	cout<<"3rd   ----->   "<<endl;
	//	for(auto it= arr.end() - 1; it>=arr.begin();it--) {
	//		cout << *it << " ";
	//	}
	//	cout<<endl;
	//	cout<<"4th   ----->   "<<endl;
	//	for(auto it: arr) {
	//		cout << it << " ";
	//	}
	//	cout<<endl;

	// cout<<"5th"<<endl;
	//	string s = "xhegcwe";
	//	// x h e g c w e
	//	for(auto c:s) {
	//		cout << c << " ";
	//	}
	//	cout<<endl;



	//	// size
	//	cout << arr.size();
	//
	//	// front
	//	cout << arr.front(); // arr.at(0);
	//
	//	// back
	//	cout << arr.back(); // arr.at(arr.size() - 1);


}
void vectorExample()
{
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

//	// copy the entire vec2 into vec3
	vector<int> vec3(vec2.begin(), vec2.end()); // -> [)
	vector<int> vec4(vec2);
//
//
//
	vector<int> raj;
	raj.push_back(1); // raj.emplace_back(1); // emplace_back takes lesser time than push back
	raj.push_back(3);
	raj.push_back(2);
	raj.push_back(5); // -> {1, 3, 2, 5}
//
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


	for(int i = 0;i<vec.size();i++) {
		for(int j = 0;j<vec[i].size();j++) {
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
void setExample()
{
	// given n elements, tell me the number of unique elements
	int arr[] = {2, 5, 2, 1, 5}; // 3 unique elements -> {1. 2. 5}

    set<int> asdasdasds = {1, 5, 7, 8};

	// int n;
	// cin >> n;
	// for(int i = 0;i<n;i++) {
	// 	int x;
	// 	cin >> x;
	// 	st.insert(x);
	// }

	// cout << st.size();

	// // st -> {1, 2, 5}
	// // erase functionality
	// // log n
	// st.erase(st.begin()); // st.erase(iterator) // st -> {2, 5}

	// // log n
	// // 77777777777
	// st.erase(st.begin(), st.begin() + 2); // -> [)
	// // st.erase(startIterator, endIterator)

	// st.erase(5) // st.erase(key) // delete the 5 -> {1, 2}


	// set<int> st = {1, 5, 7, 8};

	// auto it = st.find(7); // log n // it will be iterator to 7

	// auto it = st.find(9); // it = st.end();

	// st.emplace(6); // st.insert(6)

	// cout << st.size() << endl;


	// set<int> st;
	// st.insert(5); // -> {5}
	// st.insert(5); // -> {5}

	// for(auto it=st.begin(); it!=st.end();it++) {
	// 	cout << *it << " ";
	// }

	// for(auto it : st) {
	// 	cout << it << endl;
	// }

	// // delete the entire set
	// st.erase(st.begin(), st.end()); // makes sure the entire set is deleted
	// 	unordered_set<int> st;

	// st.insert(2);
	// st.insert(3);
	// st.insert(1);

	// // average time complexity is O(1)
	// // tle -> switch to set
	// // but the worst case is linear in nature, O(set size)

	// multiset<int> ms;

	// ms.insert(1);
	// ms.insert(1);
	// ms.insert(2);
	// ms.insert(2);
	// ms.insert(3); // ms.emplace(3)
	// // st -> {1, 1, 2, 2, 3}

	// ms.erase(2); // all the instances will be erased

	// auto it = ms.find(2); // returns an iterator pointing to the first element of 2
	// ms.clear(); // deleted the entire set
	// ms.erase(ms.begin(), ms.end()); // deletes the entire set
	// // log n in size


	// for(auto it=st.begin(); it!=st.end();it++) {
	// 	cout << *it << " ";
	// }

	// for(auto it : st) {
	// 	cout << it << endl;
	// }
	// // finds how many times 2 occurs
	// st.count(2);


	// ms.erase(ms.find(2));
	// ms.erase(ms.find(2), ms.find(2) + 2);

}
int main() {

//  Use of namespace
// 	namespaceExample();

// //	Standard DataTypes are --> int, double, float, char ....
// //  Create your own DataType... ----> struct
// 	StructExample();


// ************************** VECTOR **********************************

// #pragma warning( pop )

}
