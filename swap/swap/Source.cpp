#include<iostream>
#include<string>

template<class Type>
Type swap(Type &a, Type &b)
{
	Type c = a;
	a = b;
	b = c;
	return 0;
}


int main()
{
	std::string a = "a";
	std::string b = "b";
	swap(a, b);
	std::cout << "a = " << a << "\nb = " << b << std::endl;
	return 0;
}