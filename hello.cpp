#include <iostream>
#include <string>

int main()
{
	using std::cout;
	using std::endl;

	const int pad = 0;
	const int rows = pad * 2 + 3;

	cout << "Please, enter your first name: ";

	std::string name;
	std::cin >> name;

	const std::string greeting = "Hello, " + name + "!";

	cout << endl;

	const std::string::size_type cols = greeting.size() + pad * 2 + 2;

	for (int r = 0; r != rows; ++r) {
		for (int c = 0; c != cols; ++c) {
			if ((r == 0) || (r == rows -1) || (c == 0) || (c == cols -1)) {
				cout << "*";
			} else if ((r == pad + 1) && (c == pad + 1)) {
				cout << greeting + " ";
				c += greeting.size();
			} else {
				cout << " ";
			}
		}

		cout << endl;
	}

	return 0;
}
