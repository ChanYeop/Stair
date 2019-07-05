#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	int stair;
	cin >> stair;
	int p;
	for (int i = 0; i <= stair; i++) {
		if (i == 0)
			v.push_back(0);
		else {
			cin >> p;
			v.push_back(p);
		}
	}
	int count = 1;
	int sum = v[stair];
	int location = stair;
	int price = v[stair];
	while (v[location] != v[0]) {
		if (v[location - 1] == v[0]) {
			v[location] == v[0];
			break;
		}
		if (count == 2) {
			location = location - 2;
			price = v[location - 2];
			sum += price;
			count = 1;
		}
		else {
			if (max(v[location - 1], v[location - 2]) == v[location - 1])
				count++;
			price = max(v[location - 1], v[location - 2]);
			location = max(v[location - 1], v[location - 2]) == v[location - 1] ? location - 1 : location - 2;
			sum += price;
		}
	}

	cout << sum;
	return 0;
}