#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<functional>
using namespace std;
struct node {
	int val;
	char ch;
	float fl;
	node(int v, char c, float f) : val(v), ch(c), fl(f) {}
	void print() const {
		std::cout << "val: " << val << " ch: " << ch << " fl: " << fl;
		printf("\n");
	}
};

struct comparator {
	bool operator()(const node& a, const node& b) const {
		if (a.val != b.val)
			return a.val < b.val;
		if (a.ch != b.ch)
			return a.ch < b.ch;
		return a.fl < b.fl;
	}
};
class person {
public:
	int age;
	string name;
public:
	person(int a, string n) :age(a), name(n) {
		cout << "constructor " << endl;

	}
	bool operator < (const person& other) const{
		return age < other.age;
	}
	bool operator > (const person& other)const {
		return age > other.age;
	}
};
int main() {
	//different ways to initialise
	set<int> s;
	set<int, greater<>> s2{ 2,3,56,7,90,12,30 };
	s.insert(10);
	s.insert(17);
	s.insert(13);
	s.insert(18);
	s.insert(1);
	set<int> s3(s);

	vector<int> v{ 1,23,4,6,8 };
	cout << v.size() << endl;
	cout << v.max_size() << endl;
	cout << v.capacity() << endl;
	//set<int> s5{ v.begin(),v.end() };
	//auto itr=s.find(13);
	//if (itr == s.end()) {
	//	cout << "not found" << endl;
	//}
	//else {
	//	cout << "found" << endl;
	//}
	//s.erase(itr);
	//s.erase(18);
	//for (auto it : s) {
	//	cout << it << endl;
	//}
	//cout << s.count(13) << endl;
	////cout << (s.contains(13) ? "yes" : "no") << endl; in c++20
	//set<int> nums{ 2,3,56,7,90,12,30,23,78,90,32 };
	//auto rb = nums.rbegin();
	//auto re = nums.rend();
	//for (auto i = rb;i != re;++i) {
	//	std::cout << *i << " ";
	//}
	//auto crb = nums.cbegin();
	//auto cre = nums.cend();
	//for (auto i = crb;i != cre;++i) {
	//	std::cout << *i << " ";
	//}
	//set<person>sp;
	//sp.insert(person{21,"bob"});
	//sp.emplace(32, "mansi");
	////person p1;
	//sp.insert({ 22, "shivam" });
	//for (auto i = sp.begin(); i != sp.end();++i) {
	//	cout << i->name << " " << i->age << endl;
	//}
	//multiset<int> ms = { 2,4,4,8,90,12,34,2,87,92,87,35,90 };
	//ms.erase(2);//delete all instances
	//auto it = ms.find(90);
	//ms.erase(it);//delete the first instance
	//for (auto it : ms) {
	//	cout << it<<endl;
	//}
	std::multiset<node, comparator>msn;
	msn.insert({ 26, 'z', 14.5 });
	msn.insert({ 6, 'w', 4.45f });
	msn.insert({ 20, 's', 1.5f });
	msn.emplace(10, 's', 34.5);
	for (auto& it : msn) {
		it.print();
	}
   return 0;
}
