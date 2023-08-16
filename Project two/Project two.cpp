#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;


struct Course {
	string Id;
	string name;
	string prereq1;
	string prereq2;
};
void loadDataStructure(vector<Course>& course, string fileName)
{

	fstream myFile;
	myFile.open(fileName);
	if (!myFile.is_open()) {
		cout << "Error: File not found" << endl;
		return;
	}
	else {
		string tempLine;
		while (getline(myFile, tempLine)) {
			stringstream cStream(tempLine);
			Course tempCourse;
			getline(cStream, tempCourse.Id, ',');
			getline(cStream, tempCourse.name, ',');
			if (!cStream.eof()) {
				getline(cStream, tempCourse.prereq1, ',');
			}
			if (!cStream.eof()) {
				getline(cStream, tempCourse.prereq2, ',');
			}
			course.push_back(tempCourse);
		}
	}

	return;
}

int main() {
	vector<Course> course;
	int userInput = 0;
	string fileName;
	string userCourse;

	while (userInput != 4) {
		cout << "Please select an option" << endl;
		cout << "1: Load Courses" << endl;
		cout << "2: Display Course List" << endl;
		cout << "3: Display Course Details" << endl;
		cout << "4: Exit" << endl;
		cin >> userInput;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Please enter new input" << endl;
			cin >> userInput;
		}
		switch (userInput) {
		case 1:
			cout << "Please enter file name." << endl;
			cin >> fileName;
			cout << fileName;
			loadDataStructure(course, fileName);
			break;

		case 2:
			for (int i = 0; i < course.size(); ++i) {
				cout << course[i].Id << "," << course[i].name << endl;
			}
			break;
		case 3:
			cout << "Please enter course ID." << endl;
			cin >> userCourse;
			for (int i = 0; i < course.size(); ++i) {
				if (userCourse.compare(course[i].Id) == 0) {
					cout << course[i].Id << " " << course[i].name << endl;
					if (course[i].prereq1 != "") {
						cout << "The course prerequisites are " << course[i].prereq1;
						if (course[i].prereq2 != "") {
							cout << " and " << course[i].prereq2 << endl;
						}
						else {
							cout << endl;
						}
					}
 				}
			
			}

		default:
			break;
		}
		cout << endl;

	}
};