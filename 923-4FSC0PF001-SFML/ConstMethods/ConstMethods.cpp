// ConstMethods.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

class Truc
{
	int member_;

public:
	Truc(int value) { member_ = value; }

	void setMember(int value) { member_ = value; }
	int getMember() const { return member_; }

};

class Machin
{
	Truc truc_;

public:
	Machin(int value) : truc_(value){}

	void SetBValue(int value)
	{
		truc_.setMember(value);
	}

};


int main()
{
	std::vector<Truc> trucs;

	Machin m;
	m.SetBValue(10);

	//for (const auto& t : trucs)
	//{
	//	t.getB();
	//	t.setB(3);
	//}


}
