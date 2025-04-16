class A
{
public:
	int i;
	A(int val) : i(val) {}
};
class B
{
public:
	int j;
	string ch;
};
int main() {
	A obj(10);

	B* ptr = reinterpret_cast<B*>(&obj);
	ptr->j = 94;
	cout << "obj.i = " << obj.i << std::endl;
	return 0;
}
