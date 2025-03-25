#include <iostream>
#include <vector>
#include <typeinfo>
#include<algorithm>
#include"lambda.h"
//syntax[capture](arg)<mutable><exception specification>-><return type>{body}
using namespace std;
//implementation of lambda internally 
template<typename t>
struct test {
	t operator()(t a, t b) {
		return a + b;
	}
};
int main() {
	/*[]() {
		cout << "one way to call lambda" << endl;
		}();->this parathesis at the end is to call lambda*/
	/*auto fn=[]() {
		cout << "another way to call lambda" << endl;
		};
	fn();*///class `int __cdecl main(void)'::`2'::<lambda_1> type is class
	/*cout << typeid(fn).name() << endl;*/
	auto sum = [](auto a, auto b)noexcept { //noexcept is used to tell that the expression does 
		                                     //not generate any exception use noexcept(false)indicate function
		return a + b;                        //throws exception
		};

	cout << "using lambda " << sum(5.6,7)<<endl;//so that it can accept any type of data
	test<int> t;
	cout << "using function pointer" << t(2, 3) << endl;

	Unnamed<int> n(3);
	int x = 5;
	n(x);
	int arr[]{ 1,6,8,4,0 };
	ForEach(arr, [](auto x) {
		std::cout << x << " ";
		});
	std::cout << std::endl;
	int offset = 0;
	/*ForEach(arr, [offset](auto &x) {
		x += offset;
	});*/

	//ForEach(arr, [offset](auto &x)mutable {
	//	x += offset;
	//	++offset;
	//});

	int sum{};
	ForEach(arr, [&, offset](auto& x) {
		sum += x;
		});
	//cout <<  sum << std::endl;
	ForEach(arr, [](auto x) {
		std::cout << x << " ";
		});
	std::cout << std::endl;

	return 0;
}
