#include <iostream>
#define del cout << "-----------------------------------------------------------------------------------\n"
using namespace std;
class car {
private:
	double fuel;
	bool engine;
	double speed = 0;
public:
	car(double fuel = 20, bool engine = false) {
		if (fuel > 60)
			this->fuel = 60;
		else this->fuel = fuel;
		this->engine = engine;
	}

	void ignition() {
		if (fuel <= 0)
			cout << "��������� �� ���������" << endl;
		if (!engine) {
			cout << "������� ���������..." << endl;
			engine = true;
			fuel -= 0.0003;
			cout << "��������� ������" << endl;
		}
		else {
			cout << "����� ���������..." << endl;
			engine = false;
			cout << "��������� ��������" << endl;
		}
	}
	void print() {
		del;
		if (engine)
			fuel -= 0.0003;
		cout << "���������� ������� � ����: " << fuel << " ������\n"
			<< "��������� "; if (engine) cout << "������" << endl;
			else     cout << "�� ������" << endl;
		if (speed > 0)
			cout << "� ������ ������ ������ �������� �� ��������� " << speed << " ��/�" << endl;
		else if (speed < 0)
			cout << "� ������ ������ ������ �������� ����� �� ��������� " << speed << " ��/�" << endl;
		else cout << "� ������ ������ ������ ����� �� �����" << endl;
		del;
	}
	void ai() {
		system("CLS");
		del;
		cout << "��� ������������ ����������� �� ���������� Tesla Cybertruck v.2077\n"
			<< "�� ������ ��������� ����������� ����� ��������� ��������� ����������\n"
			<< "��� ����, ����� ����������� ����������� ��������, ������� ��������������� ������\n\n"
			<< "1) �������� ���������� � Tesla Cybertruck\n"
			<< "2) �������/��������� ���������\n"
			<< "3) ��������� ������� �� Tesla Cybertruck v.2077\n";
		del;
		int input;
		cin >> input;
		if (input == 1) {

			print();
			system("PAUSE");
			ai();
		}
		else if (input == 2) {
			ignition();
			system("PAUSE");
			ai();
		}
		
	}
	void accelerate(int accelerate) {
		if (accelerate < speed)
			brake(accelerate);
		cout << "�� ��������� �������� �������� �  " << accelerate << " ��/�" << endl;
		if (fuel <= 0)
			cout << "� ������ ��������� �������" << endl;
		if (!engine)
			cout << "��� ������ ����� ������� ���������" << endl;
		else {
			int start_speed = speed;
			if (accelerate > 251)
				speed = 250;
			else if (accelerate < -31)
				speed = 30;
			else speed = accelerate;
			cout << "������ ���������� �� " << speed - start_speed  << " ��/�, ������� �������� " << speed << " ��/�" << endl;

			////////FUEL///////////
			if (speed <= 60 && speed >= -30)
				fuel -= 0.0020;
			else if (speed >= 61 && speed <= 100)
				fuel -= 0.0014;
			else if (speed >= 101 && speed <= 140)
				fuel -= 0.0020;
			else if (speed >= 141 && speed <= 200)
				fuel -= 0.0025;
			else if (speed >= 201 && speed <= 250)
				fuel -= 0.0030;
			////////FUEL///////////


		}
	}
	void brake(int brake) {
		if (brake > speed)
			accelerate(brake);
		else if (brake < 0)
			brake = 0;
		else {

			cout << "�� ��������� ����������� �� " << brake << " ��/�" << endl;
			if (fuel <= 0)
				cout << "� ������ ��������� �������" << endl;
			else {
				int start_speed = speed;
				speed -= brake;
				cout << "������ ����������� �� " << start_speed - speed << " ��/�, ������� �������� " << speed << "��/�" << endl;
			}
			if(engine)
				fuel -= 0.0020;
		}
	}
};

void main() {
	setlocale(LC_ALL, "");
	car tesla;
	double fuel = 20;
	tesla.ignition();
	tesla.accelerate(666);
	tesla.accelerate(50);
	tesla.brake(10);
	tesla.print();
}