#include <iostream>

using namespace std;

template <class t1>
class arr {
	t1* p;
	size_t len;

public:
	arr(size_t size) {
		p = new t1[size];
		len = size;
	}

	~arr() {
		delete[] p;
	}

	t1& operator[](int index) {
		return p[index];
	}

	size_t size() {
		return len;
	}

	int search(const t1 key) {
		for(int i = 0; i < len; i++) {
			if(p[i] == key)
				return i;
		}

		return -1;
	}

	friend t1* operator<<(ostream& o, arr<int>& obj);
};

ostream& operator<<(ostream& o, arr<int>& obj) {
		std::cout << obj.p;
		return o;
	}

int main() {
	arr<int> var(5);

	var[0] = 5;
	var[1] = 17;
	var[2] = 15;

	int i = var.search(107);

	if(i != -1)
		std::cout << "Element founded at index " << i << std::endl;
	else
		std::cout << "Element not founded" << std::endl;

	std::cout << var << var;
}