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
			cout << "Двигатель не заводится" << endl;
		if (!engine) {
			cout << "Включаю зажигание..." << endl;
			engine = true;
			fuel -= 0.0003;
			cout << "Двигатель заведён" << endl;
		}
		else {
			cout << "Глушу двигатель..." << endl;
			engine = false;
			cout << "Двигатель выключен" << endl;
		}
	}
	void print() {
		del;
		if (engine)
			fuel -= 0.0003;
		cout << "Количество топлива в баке: " << fuel << " литров\n"
			<< "Двигатель "; if (engine) cout << "заведён" << endl;
			else     cout << "не заведён" << endl;
		if (speed > 0)
			cout << "В данный момент машина движется со скоростью " << speed << " км/ч" << endl;
		else if (speed < 0)
			cout << "В данный момент машина движется назад со скоростью " << speed << " км/ч" << endl;
		else cout << "В данный момент машина стоит на месте" << endl;
		del;
	}
	void ai() {
		system("CLS");
		del;
		cout << "Вас приветствует продвинутый ИИ автомобиля Tesla Cybertruck v.2077\n"
			<< "Вы можете управлять автомобилем через интерфейс бортового компьютера\n"
			<< "Для того, чтобы осуществить необходимое действие, нажмите соответствующую кнопку\n\n"
			<< "1) Показать информацию о Tesla Cybertruck\n"
			<< "2) Завести/заглушить двигатель\n"
			<< "3) Завершить процесс ИИ Tesla Cybertruck v.2077\n";
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
		cout << "Вы пытаетесь добиться скорости в  " << accelerate << " км/ч" << endl;
		if (fuel <= 0)
			cout << "В машине кончилось топливо" << endl;
		if (!engine)
			cout << "Для начала стоит завести двигатель" << endl;
		else {
			int start_speed = speed;
			if (accelerate > 251)
				speed = 250;
			else if (accelerate < -31)
				speed = 30;
			else speed = accelerate;
			cout << "Машина ускорилась на " << speed - start_speed  << " км/ч, текущая скорость " << speed << " км/ч" << endl;

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

			cout << "Вы пытаетесь затормозить до " << brake << " км/ч" << endl;
			if (fuel <= 0)
				cout << "В машине кончилось топливо" << endl;
			else {
				int start_speed = speed;
				speed -= brake;
				cout << "Машина замедлилась на " << start_speed - speed << " км/ч, текущая скорость " << speed << "км/ч" << endl;
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