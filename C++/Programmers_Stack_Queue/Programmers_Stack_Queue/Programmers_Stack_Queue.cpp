#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Truck {
private:
	int truck_weight;
	int needTime;

public:
	Truck(int truck, int time) {
		truck_weight = truck;
		needTime = time;
	}

	int getTruckWieght();
	int getNeedTime();
	void decTime();
};

int Truck::getTruckWieght() {
	return truck_weight;
}

int Truck::getNeedTime() {
	return needTime;
}

void Truck::decTime() {
	needTime--;
}

int solution(int bridge_length, int weight, vector<int> truck_weights);

int main() {
	vector<int> truck_weights;
	truck_weights.push_back(7);
	truck_weights.push_back(4);
	truck_weights.push_back(5);
	truck_weights.push_back(6);

	int result = solution(2, 10, truck_weights);
	
	cout << result << endl;
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int sum_weight = 0;
	int spendTime = 0;

	list<Truck> bridge;

	for (int i = 0; i < truck_weights.size();) {
		spendTime++;

		if (sum_weight + truck_weights[i] <= weight) {
			Truck truck(truck_weights[i], bridge_length);
			bridge.push_back(truck);

			sum_weight += truck_weights[i];
			i++;
		}

		for (auto iter = bridge.begin(); iter != bridge.end();) {
			iter->decTime();

			if (iter->getNeedTime() == 0) {
				sum_weight -= iter->getTruckWieght();
				iter = bridge.erase(iter);
			}

			else {
				iter++;
			}
		}
	}

	return spendTime + bridge_length;
}