#include <iostream>
#include<string>
#include<set>
#include<map>
#include<list>

using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

void main()
{
	setlocale(LC_ALL, ""); 
//#define STL_SET
//#define STL_MAP

#ifdef STL_SET
	std::set<int> set = { 50,25,75,16,32,64,128,8,32,64,50,8,8,8 };
	for (std::set<int>::iterator it = set.begin(); it != set.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;

	int value;
	cout << "Enter significent element: "; cin >> value;
	set.insert(value);
	for (int i : set) cout << i << tab; cout << endl;
	std::set<int>::iterator position = set.find(75);
	set.insert(position, 1024);
	for (int i : set) cout << i << tab; cout << endl;
	for (std::set<int>::iterator it = set.lower_bound(20); it != set.upper_bound(80); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
#endif // STL_SET

#ifdef STL_MAP
	std::map<int, std::string> week =
	{
		std::pair <int, std::string>(0, "Sunday"),
		std::pair <int, std::string>(1, "Monday"),
		std::pair <int, std::string>(2, "Tuesday"),
		{3, "Wednesday"},
	{4, "Thursday"},
	{5, "Friday"},
	{6, "Saturday"}
	}; 
	for (std::map <int, std::string>::iterator it = week.begin(); 
		it != week.end(); ++it)
	{
		cout << it->first << tab << it->second << endl; 
	}

#endif

	std:: map<std::string, std::list<std::string>> dictionary=
	{
		std::pair<std::string, std::list<std::string>>("squad", {"������", "�������", "���������"}),
		std::pair<std::string, std::list<std::string>>("flock", {"����", "�����"}),
		{"plural", {"�������������", "������������", "��������������"}},
		{"space", {"������", "������", "������������"}}
	};
	for (std::map<std::string, std::list<std::string>>::iterator it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		cout << it->first << ":\t"; 
		for (std::list<std::string> ::iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
		{
			cout << *jt << ", "; 
		}
		cout << "\b\b;"; //this is backspace
		cout << endl; 
	}
	cout << "\n-------------------------------------------\n"; 
	for (std::pair<std::string, std::list<std::string>> i : dictionary)
	{
		cout << i.first << ":t"; 
		for (std::string j: i.second)//������ ���� ����������, ������ ��������� � i.second
		{
			cout << j << ", "; 
		}
		cout << "\b\b;"; 
		cout << endl; 
	}
}