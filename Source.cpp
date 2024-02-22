#include "iostream"
#include "string"
#include "vector"
#include "fstream"

using namespace std;

class Autobus
{
public:
	string license_number;
	string driver_name;
	string route_beginning;
	string route_end;
	int length_route;

	Autobus(string ln, string dn, string rb, string re, int lr)
	{
		license_number = ln; driver_name = dn; route_beginning = rb; route_end = re; length_route = lr;
	}
};
class Autobus_1
{
public:
	std::vector<Autobus> autobus;

	void addAutobus_1(string ln1, string dn1, string rb1, string re1, int lr1)
	{
		autobus.push_back(Autobus(ln1, dn1, rb1, re1, lr1));
	}
	void printAutobus_1(int pos)
	{
		cout << "License plate: " << autobus.at(pos).license_number << endl;
		cout << "Driver name: " << autobus.at(pos).driver_name << endl;
		cout << "Route beginning: " << autobus.at(pos).route_beginning << endl;
		cout << "Route end: " << autobus.at(pos).route_end << endl;
		cout << "Length of route: " << autobus.at(pos).length_route << endl;
	}
	void changeAutobus_1(int pos, string ln1, string dn1, string rb1, string re1, int lr1)
	{
		autobus.at(pos).license_number = ln1;
		autobus.at(pos).driver_name = dn1;
		autobus.at(pos).route_beginning = rb1;
		autobus.at(pos).route_end = re1;
		autobus.at(pos).length_route = lr1;
	}
	void remove(int pos) 
	{
		autobus.erase(autobus.begin() + pos);

	}
	void printAutobuss()
	{
		for (int pos = 0; pos < autobus.size(); pos++)
		{
			cout << "Autobus" << pos + 1 << endl;
			cout << "License plate: " << autobus.at(pos).license_number << endl;
			cout << "Driver name: " << autobus.at(pos).driver_name << endl;
			cout << "Route beginning: " << autobus.at(pos).route_beginning << endl;
			cout << "Route end: " << autobus.at(pos).route_end << endl;
			cout << "Length of route: " << autobus.at(pos).length_route << "\n\n\n";
		}
	}
	void showlength()
	{
		for (int pos = 0; pos < autobus.size(); pos++)
		{
			if (autobus.at(pos).length_route < 1000)
			{
				cout << "For bus " << autobus.at(pos).license_number << " route length is " << autobus.at(pos).length_route << "KM" << endl << endl;
			}
			else {
				cout << "For bus " << autobus.at(pos).license_number << " length of route is more than 1000KM" << endl << endl;
			}
		}
	}
	void writeToFile()
	{
		ofstream myfile;
		myfile.open("LibFile.txt");
		for (int pos = 0; pos < autobus.size(); pos++)
		{
			myfile << "Autobus" << pos + 1 << endl;
			myfile << "License plate: " << autobus.at(pos).license_number << endl;
			myfile << "Driver name: " << autobus.at(pos).driver_name << endl;
			myfile << "Route beginning: " << autobus.at(pos).route_beginning << endl;
			myfile << "Route end: " << autobus.at(pos).route_end << endl;
			myfile << "Length of route: " << autobus.at(pos).length_route << "\n\n\n";
		}
		myfile.close();
	}
};
void addAutobusToAutobus_1(Autobus_1* a)
{
	string license_number;
	string driver_name;
	string route_beginning;
	string route_end;
	int length_route;
	cout << "License plate: ";
	cin >> license_number;
	do
	{
		cout << "Driver name (no more than 35 chars): ";
		cin >> driver_name;
	} while (driver_name.length() > 35);
	cout << "Route beginning: ";
	cin >> route_beginning;
	cout << "Route end: ";
	cin >> route_end;
	cout << "Length of the route (no more than 20 chars): ";
	cin >> length_route;
	a->addAutobus_1(license_number, driver_name, route_beginning, route_end, length_route);
	cout << endl;
}
void changeAutobusFromAutobus_1(Autobus_1* a, int pos)
{
	a->printAutobus_1(pos);
	string license_number;
	string driver_name;
	string route_beginning;
	string route_end;
	int length_route;
	cout << "License plate: ";
	cin >> license_number;
	do
	{
		cout << "Driver name (no more than 35 chars): ";
		cin >> driver_name;
	} while (driver_name.length() > 35);
	cout << "Route beginning: ";
	cin >> route_beginning;
	cout << "Route end: ";
	cin >> route_end;
	cout << "Length of the route (no more than 20 chars): ";
	cin >> length_route;
	a->changeAutobus_1(pos, license_number, driver_name, route_beginning, route_end, length_route);
	cout << endl;
}
void menu(Autobus_1* a)
{
	while (1)
	{
		int menuint;
		cout << "To add information for a new autobus press 1\n" <<
			"To change information about a single autbous press 2\n" <<
			"To delete autobus press 3\n" <<
			"To print all autobuses press 4\n" <<
			"To print autobuses with length of route below 1000KM press 5\n" <<
			"To exit press 6\n";
		cin >> menuint;
		int autobusPos;
		string stringIn;
		switch (menuint)
		{
		case 1:
			addAutobusToAutobus_1(a);
			break;
		case 2:
			cout << "\nautobuspos: ";
			cin >> autobusPos;
			changeAutobusFromAutobus_1(a, autobusPos);
			break;
		case 3:
			cout << "\nautobuspos: ";
			cin >> autobusPos;
			a->remove(autobusPos);
			break;
		case 4:
			a->printAutobuss();
			break;
		case 5:
			a->showlength();
			break;
		case 6:
			return;
		}
	}
}
int main()
{
	Autobus_1 autobus;
	Autobus_1* a = &autobus;
	a->addAutobus_1("SA0405SV", "Ivan", "Varna", "Burgas", 150);
	a->addAutobus_1("SA0405SV", "Georgi", "Sofia", "Burgas", 250);
	a->addAutobus_1("SA0405SV", "Petko", "Plovdiv", "Atina", 1500);
	a->addAutobus_1("SA0405SV", "Cvetan", "Plovdiv", "Munich", 2500);
	a->addAutobus_1("SA0405SV", "Joro", "Sofia", "Plovdiv", 110);
	a->printAutobuss();
	menu(a);
	a->writeToFile();



	system("pause");
	return 0;
}



