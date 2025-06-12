#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
class person {
	string name;
	int age;
public:
	person(string n, int a) :name(n), age(a) {
		cout << "const called" << name<<endl;
	}
	person(const person& p) {
		name = p.name;
		age = p.age;
		cout << "copy const" << name<<endl;

	}
	
};
class demo {
	int val;
public:
	demo(int x = 0) :val(x) {
		cout << "const" << val << endl;
	}
	demo(const demo& other) {
		val = other.val;
		cout << "copy const" << val << endl;
	}
	demo(demo&& other) noexcept{
		val = other.val;
		cout << "move const" << val << endl;
	}
};
int main() {
	vector<int> v1(5, 20);//single value
	vector<int> v2{ 1,2,3,4 };
	vector<int> v3 = { 12,34,56,78 };
	vector<int> v4;
	
	/*v4.push_back(9);
	cout<<v4.size()<<"    "<<v4.capacity()<<endl;
	v4.push_back(10);
	cout << v4.size() << "    " << v4.capacity()<<endl;
	v4.push_back(13);
	cout << v4.size() << "    " << v4.capacity()<<endl;
	v4.push_back(45);
	cout << v4.size() << "    " << v4.capacity()<<endl;*/
	vector<int> v5(5);
	fill(v5.begin(), v5.end(), 4);
	vector<int> v6(5);
	iota(v6.begin(), v6.end(), 11);
	//add element
	v6.insert(v6.begin() + 3, { 3,4 });
	auto pos = v6.begin();
	v6.insert(pos, 2, 300);
	pos = v6.begin();
	int arr[] = { 2,34,5 };
	v6.insert(pos, arr,arr+ size(arr));
	for (auto it : v6) {
		cout << it << endl;
	}
	vector<demo>demovec;                               
	demo d(10);                                     //const10  constructor is called
	demovec.push_back(d);                           //copy const10  d is lvalue so copy const is called
	demovec.emplace_back(d);                        //copy const10  as d is passed as l value so emplace 
	                                               //behaves as demovec.emplace_back(const demo& d)-> copy;
		                                            //move const10 now vector resizes so moved to a new location
	

	cout << "2"<<endl; //move const is called because r value is passed

	demovec.push_back(demo(31)); //temp copy created  so const31 called and then moves temp to demovec
	                              ///vector resized so move 10 is called 
	demovec.emplace_back(demo(34));  //temporary object is passed so move const is called 

	cout << "3" << endl;
	demovec.push_back(41);          //const +move const becuase rvalue is passed here
	demovec.emplace_back(42);       //const 42


	//insert vs emplace
	vector<person>employee;                                  
	person p1("alice", 23);   // const called
	employee.insert(employee.begin(),p1);//copy const
	employee.emplace(employee.end(), "Bob",32);  //const called
	//erase 
	/*vector<int> v3 = { 12,34,56,78,11,6,7,8,10,23,45,60 };
	v3.erase(v3.begin()+1);
	v3.erase(v3.begin() + 7,v3.end());
	v3.erase(find(v3.begin(), v3.end(), 11));
	for (auto val : v3) cout << val << " ";*/
	//resize
	vector<int> v(10);
	v.resize(5);
	cout<<"before capcity "<<v.capacity()<<endl;

	// Shrink capacity of vector
	v.shrink_to_fit();

	cout << v.capacity();
	//iterator invalidation
	std::vector<int> v = { 1, 2, 3 };
	int* p = &v[0];
	v.push_back(4);
	// May reallocate
    // p might now point to garbage
	//2
	auto it = v.begin() + 2;
	v.insert(v.begin() + 1, 10); // `it` becomes invalid if reallocated or shifted

	//3
	auto it = v.begin() + 1;
	v.erase(v.begin()); // `it` may now point to different element
	/*4. resize(n) (if n > capacity())
	 Invalidates all iterators because it causes reallocatio*/
	return 0;
}
