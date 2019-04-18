#ifndef DESIGN_CLASS_H_
#define DESIGN_CLASS_H_

#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<shlobj.h>
#include<shellapi.h>
#include<iomanip>
#include<mysql.h>
#include<Windows.h>
#include<fstream>
#include<sstream>

using namespace std;

const string STARS = "*****************";
list<class student> con;
list<class student>::iterator it;
typedef list<class student> list_stu;

class student
{
private:
	string student_id;
	string student_name;
	int course_computer_vision;
	int course_machine_learning;
	int course_algorithm;
	double course_average;
	bool input_test;
public:
	student(string a, string b, int c, int d, int e) :student_id(a), student_name(b), course_computer_vision(c), course_machine_learning(d), course_algorithm(e), course_average((c + d + e) / 3.0) {}
	student()
	{
		cout << "       ";
		cin >> student_id;
		cout << "     ";
		cin >> student_name;
		cout << "      ";
		cin >> course_computer_vision;
		cout << " ";
		cin >> course_machine_learning;
		cout << "      ";
		cin >> course_algorithm;
		course_average = (course_computer_vision + course_machine_learning + course_algorithm) / 3.0;
		input_test = course_computer_vision >= 0 && course_computer_vision <= 100 &&
			course_machine_learning >= 0 && course_machine_learning <= 100 &&
			course_computer_vision >= 0 && course_computer_vision <= 100;
		if (!input_test)
		{
			cout << STARS << STARS << endl;
			cout << "     " << endl;
		}
	}
	const string return_student_id() { return student_id; }
	const string return_student_name() { return student_name; }
	const int return_course_computer_vision() { return course_computer_vision; }
	const int return_course_machine_learning() { return course_machine_learning; }
	const int return_course_algorithm() { return course_algorithm; }
	const double return_course_average() { return course_average; }
	const bool return_input_test() { return input_test; }
	bool operator<(student &stu) { return course_average < stu.return_course_average(); }
	bool operator==(string find) { return student_id == find; }
	friend ostream& operator<<(ostream& out, const student& stu)
	{
		out <<  << setw(11) << stu.student_id << " " << setw(13) << stu.student_name
			<<  << setw(9) << stu.course_computer_vision << " " << setw(9) << stu.course_machine_learning
			<<  << setw(9) << stu.course_algorithm << " " << setw(14) << fixed << setprecision(2) << stu.course_average << " ";
		return out;
	
	}
};
void student_message_add() {
	student *transmit = new student;
	if (transmit->return_input_test() == true)
	{
		for (it = con.begin(); it != con.end(); it++)
		{
			if (it->return_student_id() == transmit->return_student_id())
			{
				cout <<  << endl;
				return;
			}
		}
		con.push_back(*transmit);
	}
}
void student_message_print() {
	if (!con.empty())
	{
		
		for (it = con.begin(); it != con.end(); it++)
		{
			cout << *it << endl;
		}
		
	}
	else { cout <<  << endl; }
}
void student_message_add_mysql()
{
	const char user[] = ;
	const char pswd[] = ;
	const char host[] = ;
	const char table[] = ;
	unsigned int port = 3306;
	string mysql_command;
	MYSQL myCont;
	MYSQL_RES *result;
	MYSQL_ROW sql_row;
	MYSQL_FIELD *fd;
	string table_field[10];
	int res;
	mysql_init(&myCont);
	if (mysql_real_connect(&myCont, host, user, pswd, table, port, NULL, 0))
	{
		cout <<  << endl;
		mysql_query(&myCont, ); 
		res = mysql_query(&myCont, );
		if (!res)
		{
			result = mysql_store_result(&myCont);
			if (result)
			{
				cout <<  << result->row_count <<  << endl;
				for (int i = 0; fd = mysql_fetch_field(result); i++)
				{
					table_field[i] = fd->name;
				}
				for (unsigned int i = 0; i < result->field_count; i++)
				{
					cout<<table_field[i];
				}
			
				while (sql_row = mysql_fetch_row(result))
				{
					for (unsigned int i = 0; i < result->field_count; i++)
					{
						printf("%s\n", sql_row[i]);
					}
				
					string id = sql_row[0];
					string name = sql_row[1];
					int c1 = atoi(sql_row[2]); 
					int c2 = atoi(sql_row[3]);
					int c3 = atoi(sql_row[4]);
					student *transmit = new student(id, name, c1, c2, c3);
					con.push_back(*transmit);
				}
				cout <<  << endl;
			}
			if (result != NULL)
				mysql_free_result(result);
		}
		else { cout <<  << endl; }
	}
	else { cout <<  << endl; }
	mysql_close(&myCont);
}
void student_message_edit()
{
	string test_number;
	bool check_find = false;
	cout << ;
	cin >> test_number;
	for (it = con.begin(); it != con.end(); it++)
	{
		if (it->return_student_id() == test_number)
		{
			cout << endl <<  << endl;
			check_find = true;
			student *transmit = new student;
			if (transmit->return_input_test() == true)
			{
				for (list<class student>::iterator test = con.begin(); test != con.end(); test++)
				{
					if (test->return_student_id() == transmit->return_student_id())
					{
						cout <<  << endl;
						return;
					}
				}
			}
			*it = *transmit;
		}
	}
	if (check_find == false)
	{
		cout <<  << endl;
		return;
	}
}
void student_message_delete()
{
	string test_number;
	cout << ;
	cin >> test_number;
	list<class student>::iterator it_delete;
	it_delete = find(con.begin(), con.end(), test_number);
	if (it_delete != con.end())
	{
		cout <<  << endl;
		con.erase(it_delete);
		cout <<  << endl;
	}
	else
	{
		cout <<  << endl;
		return;
	}
}
void 	student_message_sort()
{
	con.sort();

}
void student_message_search()
{
	string test_number;
	bool check_find = false;
	cout << ;
	cin >> test_number;
	list<class student>::iterator it_find;
	it_find = find(con.begin(), con.end(), test_number);
	if (it_find != con.end())
	{
		cout <<  << endl;
		cout << *it_find << endl;
		cout <<  << endl;
	}
	else
	{
		cout <<  << endl;
		return;
	}
}
void student_message_sort_add()
{
	student_message_sort();
	double course_average;
	bool state = false;
	cout << ;
	cin >> course_average;
	list<class student>::iterator it_course = con.begin();
	list<class student>::iterator next_student = con.begin();
	for (; it_course != con.end(); it_course++)
	{
		next_student++;
		if (next_student != con.end())
		{
			if (it_course->return_course_average() <= course_average && next_student->return_course_average() >= course_average)
			{
				student *transmit = new student;
				if (transmit->return_input_test() == true)
				{
					for (list<class student>::iterator test = con.begin(); test != con.end(); test++)
					{
						if (test->return_student_id() == transmit->return_student_id())
						{
							cout <<  << endl;
							state = true;
							return;
						}
					}
				}
				con.insert(next_student, *transmit);
				return;
			}
		}
	}
	if (state == false)
	{
		cout <<  << endl;
	}
}
void student_message_export()
{
	ofstream outFile;
	outFile.open(, ios::out);
	if (outFile)
	{
		
		for (it = con.begin(); it != con.end(); it++)
		{
			outFile << it->return_student_id() << ',' << it->return_student_name() << ',' << it->return_course_computer_vision() << ','
				<< it->return_course_machine_learning() << ',' << it->return_course_algorithm() << ',' << it->return_course_average() << endl;
		}
		cout <<  << endl;
	}
	else { cout <<  << endl; }
	outFile.close();
}
#endif
