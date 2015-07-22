#include <iostream>
#include <string>
#include <ios>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;
using std::vector;
using std::sort;
using std::domain_error;
using std::istream;

const int NUM_HOMEWORK = 4;

double median(vector<double> values);
double grade(double midterm, double final, const vector<double>& hw);
double grade(double midterm, double final, double hw);
istream& read_hw(istream& in, vector<double>& hw);

struct Student_info {
	string name;
	double midterm, final;
	vector<double> homework;
};

int main()
{
	int index = 0;
	string x;
	vector<string> name;
	char other = 'y';
	int n;
	vector<double> final_grades;
	streamsize prec = cout.precision();

	while (other == 'y') {
		cout << "Enter student's name " << (index + 1) << ":" << endl;
		cin >> x;

		name.push_back(x);

		cout << "Enter your midterm and final exam grades:" << endl;
		double midterm = 0, final = 0;
		cin >> midterm >> final;

		cout << endl;
		cout << "Midterm: " << midterm << endl;
		cout << "Final  : " << final;
		cout << endl;

		cout << "Enter homework grades (" << NUM_HOMEWORK << "):" << endl;

		vector<double> homework;
		read_hw(cin, homework);

		try {
			double final_grade = grade(midterm, final, homework);

			cout << setprecision(3);

			cout << "Final grade: " << final_grade << endl;

			final_grades.push_back(final_grade);

			index++;

			cout << "Other student? (y/n)" << endl;
			cin >> other;
		} catch (domain_error) {
			cout << endl << "You must enter grades" << endl;
			return (-1);
		}
	}

	for (n = 0; n < index; n++) {
		cout << name[n] << "  " << final_grades[n] << endl;
	}

	cout << setprecision(prec);

	return 0;
}

bool compare(const Student_info &student1, const Student_info &student2)
{
	return (student1.name < student2.name);
}

istream& read(istream& in, Student_info& student_info)
{
	in >> student_info.name >> student_info.midterm >> student_info.final;

	read_hw(in, student_info.homework);

	return in;
}

double grade(const Student_info& info)
{
	return grade(info.midterm, info.final, info.homework);
}

istream& read_hw(istream& in, vector<double>& hw)
{
	if (in) {
		hw.clear();

		double x;
		while (in >> x) {
			hw.push_back(x);
		}

		in.clear();
	}

	return in;
}

double median(vector<double> values)
{
	vector<double>::size_type size = values.size();

	if (size == 0)
		throw domain_error("list is empty");

	sort(values.begin(), values.end());

	vector<double>::size_type mid = size / 2;

	return (size % 2 == 0) ? ((values[mid] + values[mid-1]) / 2) :
			values[mid];
}

double grade(double midterm, double final, const vector<double>& hw)
{
	if (hw.size() == 0)
		throw domain_error("Student has done no homework");

	return grade(midterm, final, median(hw));
}

double grade(double midterm, double final, double hw)
{
	return ((0.2 * midterm) + (0.4 * final) + (0.4 * hw));
}
