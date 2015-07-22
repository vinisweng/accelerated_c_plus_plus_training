#include <iostream>
#include <string>
#include <ios>
#include <iomanip>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;
using std::vector;
using std::sort;

int main()
{
	cout << "Type your text:" << endl;

	string x;
	string::size_type len = 0;
	string::size_type max = 0, min = 0;

	while (cin >> x) {

		if ((len = x.length()) > max)
			max = len;
		else if ((len < min) || (min == 0))
			min = len;
	}

	cout << "Max: " << max << endl;
	cout << "Min: " << min << endl;

	return 0;
}
