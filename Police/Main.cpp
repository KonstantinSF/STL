#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<list>

using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n--------------------------------------------------------------------\n"

const std::map<int, std::string> violation =//нарушение, константное тк это закон
{
	{0, "Проезд  на красный"},
	{1, "Превышение скорости"},
	{2, "Парковка в неположенном месте"},
	{3, "Выезд на встречную полосу"},
	{4, "Оскорбление офицера"},
	{5, "Вождение в сост алк опьянения"},
	{6, "Дрифт на прекрестке"}
};

class Crime
{
	int id; //берем из закона те из violation
	std::string place;//место правонарушения 
public:
	Crime(int violation, const std::string& place)
	{
		this->id = violation; 
		this->place = place; 
	}
	~Crime(){}
	friend std::ostream& operator << (std::ostream& os, const Crime& obj); 
	//нарушили инкапсуляцию, чтобы можно было выводить без get_()
};

std::ostream& operator << (std::ostream& os, const Crime& obj)
{
	return os << violation.at(obj.id) << ", " << obj.place;
}
void main()
{
	setlocale(LC_ALL, ""); 
	std::map<std::string, std::list<Crime>> base =
	{
		{"a777bb", {Crime(0, "Улица Ленина"), Crime(6, "ул. Космонавтов"), Crime(3, "ул. Октябрьская")}}, //в конструкторе вводим ключи
		{"m123ab", {Crime(2, "площадь Революции")}}, 
		{"a234bb", {Crime (5, "ул. Ленина"), Crime(4, "ул. Ленина")}}
	}; 
	for (std::map<std::string, std::list<Crime>>::iterator it = base.begin(); it != base.end(); ++it)
	{
		cout << it->first << ":\n"; 
		for (std::list<Crime>::iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
		{
			cout << *jt << endl; 
		}
		cout << delimiter << endl; 
	}
}