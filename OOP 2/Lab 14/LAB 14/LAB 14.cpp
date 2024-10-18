#include <iostream>
#include "Publication.h"
#include "Person.h"
#include "Date.h"
using namespace std;

int main() {

	//DateTime* obj = new DateTime;
	//obj->setDay(4);
	//obj->setHours(2);
	//obj->setMin(12);
	//obj->setMonth(5);
	//obj->setSec(56);
	//obj->setYear(2022);
	//obj->display();

	/*Person p1("Mr Monroe", 40, "I-8");
	p1.display();
	Employee e1("MUNEEL", 23, "LALAMUSA", 5, 4, 20);
	e1.display();
	productionWorker p2("fafa", 21, "I-8", 30, 4, 50, 5, 25);
	p2.display();*/

	book b1(20);
	b1.display();
	tape t1(5);
	t1.display();


	return 0;
}