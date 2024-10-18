#include <iostream>
using namespace std;

char* convertToString(char* ptr) {

		char* word = new char[20];
	
		int dots_one = 0, dots_two = 0, ascii = 0, counter = 0;
	
		for (int i = 0; *(ptr + i - 2) != NULL; counter++) {
	
			for(; *(ptr + i) == '.' ;i++) {
	
				dots_one++;
			}
	
			i++;
	
			for(; *(ptr + i) == '.' ;i++) {
	
				dots_two++;
			}
	
			i += 2;
	
			(	THIS IS THE PART WHERE I FUCK UP 
 
			if (dots_one == 5) {
	
				TF I WRITE HERE?
			}
	
			else if (dots_two == 5) {
	
				ascii = 96 + (dots_one * dots_two);
				cout << ascii << "  2  " << endl;
			}
 
			)	FUCKERY TILL HERE
	
			word[counter] = char(ascii);
	
			dots_one = 0;
			dots_two = 0;
		}
	
		*(word + counter) = NULL;
	
		return word;
}





		
		THIS IS SHUJAAN, THE MAIN CODE IS ABOVE THIS 
 
//	char arr[5][5] = { {'a','b','c','d','e'},
//					  {'f','g','h','i','j'},
//					  {'l','m','n','o','p'},
//					  {'q','r','s','t','u'},
//					  {'v','w','x','y','z'} };
//	char* decypher_code = new char[20];
//	int row = 0, column = 0, i = 0, counter = 0;
//
//	for (int i = 0; i < 20; i++)
//	{
//		*(decypher_code + i) = ' ';
//	}
//
//	while ((*(ptr + i) != '\0'))
//	{
//
//		while (*(ptr + i) == '.')
//		{
//			row++;
//			column = 0;
//			i++;
//		}
//		i++;
//
//		while (*(ptr + i) == '.')
//		{
//			column++;
//			i++;
//		}
//
//		*(decypher_code + counter) = arr[row - 1][column - 1];
//		counter++;
//
//		row = 0;
//		column = 0;
//
//		/*if ((*(ptr + i + 1) != '\0')) {
//			i += 2;
//		}*/
//
//		*(decypher_code + counter) = arr[row - 1][column - 1];
//		counter++;
//		i += 2;
//	}
//	counter--;
//	*(decypher_code + counter) = '\0';
//
//	return decypher_code;
//}




char* convertToTapCode(char* ptr) {

	int row = 0, column = 0, counter = 0;

	char array[5][5] = { {'a', 'b', 'c', 'd', 'e'},
						{'f', 'g', 'h', 'i', 'j'},
						{'l', 'm', 'n', 'o', 'p'},
						{'q', 'r', 's', 't', 'u'},
						{'v', 'w', 'x', 'y', 'z'} };

	char* code = new char[100];

	for (int i = 0; i < 100; i++) {

		*(code + i) = ' ';
	}

	for (int i = 0; *(ptr+i) != '\0'; i++) {

		if (*(ptr + i) == 'k') {

			column = 3;
			row = 1;
		}

		for (int j = 0; j <= 4; j++) {

			for (int m = 0; m <= 4; m++) {

				if (*(ptr + i) == array[j][m]) {

					column = m + 1;
					row = j + 1;
				}
			}
		}

		for (int j = 0; j < row; j++) {

			*(code + counter++) = '.';
		}

		*(code + counter++) = ' ';

		for (int j = 0; j < column; j++) {

			*(code + counter++) = '.';
		}

		for (int j = 0; j < 2; j++) {

			*(code + counter++) = ' ';
		}
	}

	*(code + (counter - 2)) = NULL;
	return code;
}
