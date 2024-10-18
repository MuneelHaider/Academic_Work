#include <iostream>
#include <iomanip>
#ifdef _WIN32
#include <windows.h>
#include <MMSystem.h>
#else
#include <unistd.h>
#endif
#include <conio.h> 
#include "Main.h"
using namespace std;

/*****************************************
*
*   Muneel Haider 21i-0640
*   Muhammad Abdullah 21i-0643
*   Abdullah Zahoor 21i-2481
*
*   Data Structures Project 2023 Spring
*
*    									 */

void MAINFirst() {

	bool continueProgram = false;

#ifdef _WIN32
	// Play a sound file continuously
//	PlaySound(TEXT("D:/Softwares/Visual Studio/DATA STRUCTURES/DS Project/DS Project/music.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
#else
	// Start playing the sound in a separate process
	int pid = fork();
	if (pid == 0) {
		execlp("aplay", "aplay", "-q", "sound.wav", NULL);
		exit(0);
	}
#endif

	while (true) {

#ifdef _WIN32
		system("color E4");
#endif

		cout << "                                                          *   " << endl;
		cout << "                                                         ***   " << endl;
		cout << "                                                        *****   " << endl;
		cout << "                                                       *******   " << endl;
		cout << "                                                      *********   " << endl;
		cout << "                                                     ***********   " << endl;
		cout << "                                                    *************   " << endl;
		cout << "                                                   ***************   " << endl;
		cout << "                                                  *****************   " << endl;
		cout << "                                                 *******************   " << endl;
		cout << "                                                *********************   " << endl;
		cout << "                                               ***********************   " << endl;
		cout << "                                              *************************   " << endl;
		cout << "                                             ***************************   " << endl;
		cout << "                                              *************************   " << endl;
		cout << "                                               ***********************   " << endl;
		cout << "                                                *********************   " << endl;
		cout << "                                                 *******************   " << endl;
		cout << "                                                  *****************   " << endl;
		cout << "                                                   ***************   " << endl;
		cout << "                                                    *************   " << endl;
		cout << "                                                     ***********   " << endl;
		cout << "                                                      *********   " << endl;
		cout << "                                                       *******   " << endl;
		cout << "                                                        *****   " << endl;
		cout << "                                                         ***   " << endl;
		cout << "                                                          *   " << endl << endl;
		cout << "                                       ** THE QUEST FOR THE CRYSTAL KINGDOM **" << endl;
		cout << "                                          ** PRESS ENTER KEY TO CONTINUE **" << endl;

		if (continueProgram) {

			system("cls");
			MainOfProject();
			break;
		}
		if (_kbhit()) {

			int key = _getch();
			if (key == 13) { // Enter key has ASCII value of 13
				continueProgram = true;
			}
		}


		Sleep(300);
		system("cls"); // Clear console (Windows)


	}
#ifdef _WIN32
	// Stop playing the sound
	PlaySound(NULL, NULL, 0);
#else
	// Stop the sound process
	system("killall aplay");
#endif
}

int main() {

	MAINFirst();

	return 0;
}