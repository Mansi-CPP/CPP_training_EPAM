#include<iostream>
#include<map>
#include<vector>
#include<utility>
using namespace std;


class person {
public:
	int age;
	string name;
public:
	person(int a, string n) :age(a), name(n) {
		cout << "constructor " << endl;

	}
	person(const person& other) {
		age = other.age;
		name = other.name;
		cout << "copy called!" << "\n";
	}
	person() = default; // default constructor added
	person& operator=(const person& other) {
				std::cout << "copy assignment \n";
				return *this;
	}
	
};
int main() {
	//map<int, char> m1;
	//m1 = { { 1,'a' }, { 2,'b' }, { 3,'c' } };
	//m1[4] = 'd';
	//m1.insert({ 5,'e' });
	//map<int, char>mpp(m1);
	//vector<pair<int, char>> v = { {1, 'a'},
	//							{3, 'b'},
	//							{2, 'c'} };
	//map<int, char> m2(v.begin(), v.end());
	///*m1.insert(6, 'f');   not allowed cnnot const in place*/
	//m1.emplace(6, 'f');//allowed constructs in place
	//m1[1] = 'A';
	//map<int, char>m2(m1);
	//map<int, char>m3(move(m1));
	//map<int, char>m4 = m1;
	//map<int, char>m5 = move(m1);
	//for (auto& it : m1) {
	//	cout << it.first << " " << it.second << endl;
	//}
	map<int, person>pmp;
	//pmp.insert(make_pair(1, person{ 23,"Bob" }));
	pmp.insert({ 2,{32,"Alice" }});
	//1st {32,"Alice" } this copy is createrd
	//2nd  paired { 2,{32,"Alice" }}
	//pmp.insert({ 2,{32,"Alice" }}); copied in structure very expensive
	cout << "emplace" << endl;
	pmp.emplace(3, person( 42,"shivani" ));
	//directly copied 
	//incorreect
	//pmp.emplace(3, { 42, "shivani" });
	//pmp.emplace(3, 42, "shivani");
	//better
	pmp.emplace(
		piecewise_construct,
		forward_as_tuple(4),
		forward_as_tuple(56, "jhon")
	);//just once const is called  and placed here
	pmp[5] = person(12, "Radhika");//only work if default const exist
	//requieres default constructor becuase req first it creates a value 5 not in map then defualt const person
	// then assign values to person 
	//pmp.clear();
	return 0;

}
