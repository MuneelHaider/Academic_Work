#pragma once

/*	Muneel Haider	
	21i-0640		
	Task 1			*/

#include <iostream>
using namespace std;

class ShallowCopy {

	int *seconds = new int;
	int *minutes = new int;
	int *hours = new int;

public:

	ShallowCopy(int s = 0, int m = 0, int h = 0) {

		if (s < 0 || s > 59) {

			s = 0;
		}
		if (m < 0 || m > 59) {

			m = 0;
		}
		if (h < 0 || h > 23) {

			h = 0;
		}

		*seconds = s;
		*minutes = m;
		*hours = h;
	}

	int getSecondsShallow() {

		return *seconds;
	}
	void setSecondsShallow(int s) {

		*seconds = s;
	}

	int getMinutesShallow() {

		return *minutes;
	}
	void setMinutesShallow(int m) {

		*minutes = m;
	}

	int getHoursShallow() {

		return *hours;
	}
	void setHoursShallow(int h) {

		*hours = h;
	}

	ShallowCopy(ShallowCopy& obj) {

		this->seconds = obj.seconds;
		this->minutes = obj.minutes;
		this->hours = obj.hours;
	}

	void hoursToMinutes() {

		while (*hours > 0) {

			this->hours--;
			this->minutes += 60;
		}
	}

	void minutesToSeconds() {

		while (*minutes > 0) {

			this->minutes--;
			this->seconds += 60;
		}
	}

	void secondsToMinutes() {

		while (*seconds > 59) {

			*seconds -= 60;
			this->minutes++;
		}
	}

	void minutesToHours() {

		while(*minutes > 59) {
		
			*minutes -= 60;
			this->hours++;
		}
	}

	~ShallowCopy() {

		delete seconds;
		delete minutes;
		delete hours;
	}
};

class DeepCopy {

	int* seconds = new int;
	int* minutes = new int;
	int* hours = new int;

public:

	DeepCopy(int s = 0, int m = 0, int h = 0) {

		if (s < 0 || s > 59) {

			s = 0;
		}
		if (m < 0 || m > 59) {

			m = 0;
		}
		if (h < 0 || h > 23) {

			h = 0;
		}

		*seconds = s;
		*minutes = m;
		*hours = h;
	}

	int getSecondsDeep() {

		return *seconds;
	}
	void setSecondsDeep(int s) {

		*seconds = s;
	}

	int getMinutesDeep() {

		return *minutes;
	}
	void setMinutesDeep(int m) {

		*minutes = m;
	}

	int getHoursDeep() {

		return *hours;
	}
	void setHoursDeep(int h) {

		*hours = h;
	}

	DeepCopy(DeepCopy& obj) {

		int* s = new int;
		int* m = new int;
		int* h = new int;

		this->seconds = new int;
		this->minutes = new int;
		this->hours = new int;

		s = obj.seconds;
		m = obj.minutes;
		h = obj.hours;

		this->seconds = s;
		this->minutes = m;
		this->hours = h;
	}

	void hoursToMinutes() {

		while (*hours > 0) {

			this->hours--;
			this->minutes += 60;
		}
	}

	void minutesToSeconds() {

		while (*minutes > 0) {

			this->minutes--;
			this->seconds += 60;
		}
	}

	void secondsToMinutes() {

		while (*seconds > 59) {

			*seconds -= 60;
			this->minutes++;
		}
	}

	void minutesToHours() {

		while (*minutes > 59) {

			*minutes -= 60;
			this->hours++;
		}
	}

	~DeepCopy() {

		delete seconds;
		delete minutes;
		delete hours;
	}
};