#include<iostream>
#include<string>
#include<vector>

// Virtual func
// интерфейс это класс в котором не определены функции
class IVehicle {
public:
	virtual void printName() {
		std::cout << "IVehicle" << '\n';
	}
	virtual int getSpeed() = 0;
	virtual ~IVehicle() {
		std::cout << "IVihecle destructor was called" << '\n';
	}
};



class Car : public IVehicle {
public:
	Car(int speed) : _speed(speed){}
	void printName() override {
		std::cout << "Car" << '\n';
	}
	int getSpeed() override {
		return _speed;
	}
	~Car() {
		std::cout << "Car destructor was called" << '\n';
	}
private:
	int _speed;
};

class Motocycle : public IVehicle {
public:
	Motocycle(int speed) : _speed(speed){}
	
	int getSpeed() {
		return _speed;
	}
	~Motocycle() {
		std::cout << "Motocycle destructor was called" << '\n';
	}
private:
	int _speed;
};

void printer(IVehicle* vehicle) {
	vehicle->printName();
	std::cout << vehicle->getSpeed() << '\n';
}

class Van :public Car {
public:
	Van(int speed) : Car(speed){}	
	~Van() {
		std::cout << "Van destructor was called" << '\n';
	}
};
class HouseVan : public Van {
public:
	HouseVan(int speed) : Van(speed) {}
	~HouseVan() {
		std::cout << "HouseVan destructor was called" << '\n';
	}
};
int main() {

	//IVehicle* a = new IVehicle();
	IVehicle* b = new Car(50);
	IVehicle* c = new Motocycle(60);
	IVehicle* d = new Van(70);
	IVehicle* e = new HouseVan(80);
	std::vector<IVehicle*> vehicle;

	//vehicle.push_back(a);
	vehicle.push_back(b);
	vehicle.push_back(c);
	vehicle.push_back(d);
	vehicle.push_back(e);
	std::cout << "Traversing vehicles" << '\n';
	/*for (size_t i = 0; i < vehicle.size(); i++)
		vehicle[i]->printName();*/
	for (size_t i = 0; i < vehicle.size(); i++)
		printer(vehicle[i]);
	delete b;
	delete c;
	delete d;
	delete e;
	return 0;
}