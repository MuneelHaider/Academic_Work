//#include <iostream>
//using namespace std;
//
//class Time {
//
//	int days = 0;
//	int weeks = 0;
//	int months = 0;
//	int hours = 0;
//	int minutes = 0;
//	int seconds = 0;
//
//public:
//
//	Time() {
//
//		days = 0;
//		weeks = 0;
//		months = 0;
//		hours = 0;
//		minutes = 0;
//		seconds = 0;
//	}
//
//	Time(int hoursVal, int minutesVal, int secondsVal) {
//
//		hours = hoursVal;
//		minutes = minutesVal;
//		seconds = secondsVal;
//	}
//
//	int setseconds(int s) {
//
//		seconds = s;
//	}
//
//	int setminutes(int m) {
//
//		minutes = m;
//	}
//
//	int sethours(int h) {
//
//		hours = h;
//	}
//
//	int setdays(int d) {
//
//		days = d;
//	}
//
//	int setweeks(int w) {
//
//		weeks = w;
//	}
//
//	int setmonths(int m) {
//
//		months = m;
//	}
//
//	int getdays() {
//
//		return days;
//	}
//
//	int getweeks() {
//
//		return weeks;
//	}
//
//	int getmonths() {
//
//		return months;
//	}
//
//	int getHours() {
//
//		return hours;
//	}
//
//	int getMinutes() {
//
//		return minutes;
//	}
//
//	int getSeconds() {
//
//		return seconds;
//	}
//
//	int retSeconds() {
//
//		return seconds;
//	}
//
//	int retMinutes() {
//
//		return minutes;
//	}
//
//	int retHours() {
//
//		return hours;
//	}
//
//	void setData(int, int, int);
//	void getData();
//	void calculateTime(Time);
//	void calculateDays();
//};
//
//void Time::setData(int hoursVal, int minutesVal, int secondsVal) {
//
//	hours = hoursVal;
//	minutes = minutesVal;
//	seconds = secondsVal;
//}
//
//void Time::getData() {
//
//	cout << hours << ":" << minutes << ":" << seconds << endl;
//	cout << months << ":" << weeks << ":" << days << endl;
//}
//
//void Time::calculateTime(Time obj) {
//
//	seconds += obj.seconds;
//	minutes += obj.minutes;
//	hours += obj.hours;
//	int mod = 0;
//
//	if (seconds >= 60) {
//
//		mod = seconds / 60;
//		seconds = seconds % 60;
//		minutes += mod;
//	}
//
//	if (minutes >= 60) {
//
//		mod = minutes / 60;
//		minutes = minutes % 60;
//		hours += mod;
//	}
//}
//
//void Time::calculateDays() {
//
//	while (hours > 24) {
//
//		days += 1;
//		hours -= 24;
//	}
//
//	while (days > 7) {
//
//		weeks++;
//		days -= 7;
//	}
//
//	while (weeks >= 4) {
//
//		months++;
//		weeks -= 4;
//	}
//}
//
////int main() {
////
////	Time obj1(900, 900, 900), obj2(9000, 9000, 9000);
////	obj1.calculateTime(obj2);
////	obj1.calculateDays();
////	cout << obj1.getSeconds() << endl;
////	cout << obj1.getMinutes() << endl;
////	cout << obj1.getHours() << endl;
////
////	return 0;
////}