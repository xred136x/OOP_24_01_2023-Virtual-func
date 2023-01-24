#pragma once
#include<string>
class IPerson
{
public:
	virtual const std::string getName() = 0;
	virtual void fight() = 0;
	virtual ~IPerson(){}
};

class Person : public IPerson {
public:
	Person(const std::string& name) : _name(name) {}
	void fight()override;
private:
	std::string _name;
};
