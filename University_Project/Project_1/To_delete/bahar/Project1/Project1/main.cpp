#include<iostream>
#include<string>
using namespace std;

class Patient {
public:
	Patient() {
		id = 0;
		fullname = "";
		age = 0;
		numOfVisits = 1;
		visitsPerYear = 0;
	}
	Patient(string fullname, int age, int numOfV, int id) {
		this->id = id;
		this->fullname = fullname;
		this->age = age;
		this->numOfVisits = numOfV;
		visitsPerYear = float(numOfVisits) / float(age);
	}

	~Patient() = default;
	int getId() {
		return id;
	}
	int getAge() {
		return age;
	}
	int getNumOfVisits() {
		return numOfVisits;
	}
	string getFullname() {
		return fullname;
	}
	float getVisitsPerYear() {
		visitsPerYear = calcVisits();
		return visitsPerYear;
	}
	float calcVisits() {
		return float(numOfVisits) / float(age);
	}
	void setName(string name) {
		fullname = name;
	}
	void setAge(int age) {
		this->age = age;
	}
	void setNumOfVisits(int num) {
		numOfVisits = num;
	}

	void increaseVisits() {
		numOfVisits++;
	}

	friend ostream& operator << ( ostream& os,const  Patient& other);
	friend istream& operator>> (istream& is, Patient& other);
private:
	int id;
	string fullname;
	int age;
	int numOfVisits;
	float visitsPerYear;
};



ostream& operator<<(ostream& os,const Patient& other)
{
	os << "Patient fullname: " << other.fullname << "\nAge: " << other.age;
	os << "\nNumber of viists: " << other.numOfVisits<<"\nVisit per year "<< other.visitsPerYear<<endl;
	return os;
}

istream& operator>>(istream& is, Patient& other)
{
	cout << "Patient name: ";
	is >> other.fullname;
	cout << "Patient age: ";
	is >> other.age;
	cout << "Patient id: ";
	is >> other.id;
	return is;
}

class Hospital {
public:
	Hospital() {
		patients = nullptr;
		number = 0;
	}
	void setNewPatiend(const Patient& p) {
		Patient *temp = new Patient[number+1];
		for (int i = 0; i < number; i++)
		{
			temp[i] = patients[i];
		}
		temp[number] = p;
		temp[number].getVisitsPerYear();
		number++;
		delete[] patients;
		patients = temp;
	}
	int getPatientId(int index) {
		if (index > number)
		{
			cout << "Wrong value" << endl;
		}
		else {
			return patients[index].getId();
		}
	}
	Patient getPatient(int index) {
		if (index > number)
		{
			cout << "Wrong value" << endl;
		}
		else {
			patients[index].getVisitsPerYear();
			patients[index].increaseVisits();
			return patients[index];
		}
	}
	friend ostream& operator<<(ostream& os, const Hospital& other);
	int getPatientsCount() {
		return number;
	}
private:
	Patient* patients;
	int number;
};

ostream& operator <<(ostream& os, const Hospital &other) {
	os << "Number of patients: " << other.number << endl;
	for (int i = 0; i < other.number; i++)
	{
		other.patients[i].getVisitsPerYear();
		os << "Patient number " << i + 1 << "   Patient information\n"<<other.patients[i];
		cout << endl;
	}
	return os;
}

void options() {
	cout << "For a new patient recotd, press 1." << endl;
	cout << "If you already have a record, press 2." << endl;
	cout << "For all patients in the hospital, press 3." << endl;
	
}


int main() {

	cout << "Welcome to the \"Princeton – Plainsboro Teaching Hospital \"\n";
	Patient a;
	Hospital b;
	int id, number;
	bool switcher = true;
	options();
	cin >> number;
	while (switcher)
	{
		switch (number)
		{
		case 1:
			cin >> a;
			b.setNewPatiend(a);
			break;
		case 2:
			cout << "enter your patient id:";
			cin >> id;
			for (int i = 0; i < b.getPatientsCount(); i++)
			{
				if (b.getPatientId(i) == id) {
					b.getPatient(i);
					cout << b.getPatient(i);
				}
			}
			break;
		case 3:
			cout << b << endl;
		default:
			cout << "Wong value" << endl;
			break;
		}
		cout << "Do you have any other request?(-1 to quit)" << endl;
		cin >> number;
		switch (number)
		{
		case -1:
			cout << "Bye!" << endl;
			switcher = false;
			break;
		default:
			break;
		}
	}
	

	return 0;
}
