//#include<iostream>
//#include<string>
//#include<cstring>
//
//using namespace std;
//
//
//char additionOfBigInteger(char* Num1, char Num2) {
//    int len1 = strlen(Num1);
//    int len2 = strlen(Num2);
//    // max and min by mength
//    int max = (len1 > len2) ? len1 : len2;
//    int min = (len1 > len2) ? len2 : len1;
//
//    // reverse both array
//    for (int i = 0; i < len1 / 2; i++) {
//        char tmp = Num1[i];
//        Num1[i] = Num1[len1 - 1 - i];
//        Num1[len1 - 1 - i] = tmp;
//    }
//    for (int i = 0; i < len2 / 2; i++) {
//        char tmp = Num2[i];
//        Num2[i] = Num2[len2 - 1 - i];
//        Num2[len2 - 1 - i] = tmp;
//    }
//
//
//
//    char* num3 = new char[max + 2];
//
//    int sum = 0;
//    // add each digits
//    for (int i = 0; i < min; i++) {
//        sum = sum + (Num1[i] - '0') + (Num2[i] - '0');
//        if (sum >= 10) {
//            num3[i] = (char)((sum % 10) + '0');
//        }
//        else {
//            num3[i] = (char)((sum)+'0');
//        }
//        sum = sum / 10;
//    }
//
//    // add remaining digits
//    for (int i = min; i < max; i++) {
//        if (len1 > min) {
//            sum = sum + (Num1[i] - '0');
//            num3[i] = (char)((sum % 10) + '0');
//        }
//        if (len2 > min) {
//            sum = sum + (Num2[i] - '0');
//            num3[i] = (char)((sum % 10) + '0');
//        }
//        sum = sum / 10;
//    }
//
//
//    // adding extra sum value [carry]
//    int size = max;
//    if (sum != 0) {
//        num3[max] = sum;
//        size = max + 1;
//    }
//    // end string
//    num3[size] = '\0';
//
//    // reverse them
//    for (int i = 0; i < size / 2; i++) {
//        char tmp = num3[i];
//        num3[i] = num3[size - 1 - i];
//        num3[size - 1 - i] = tmp;
//    }
//    for (int i = 0; i < len1 / 2; i++) {
//        char tmp = Num1[i];
//        Num1[i] = Num1[len1 - 1 - i];
//        Num1[len1 - 1 - i] = tmp;
//    }
//    for (int i = 0; i < len2 / 2; i++) {
//        char tmp = Num2[i];
//        Num2[i] = Num2[len2 - 1 - i];
//        Num2[len2 - 1 - i] = tmp;
//    }
//
//    return num3;
//}
//
//char subtractionOfBigInteger(char* Num1, char Num2) {
//    int len1 = strlen(Num1);
//    int len2 = strlen(Num2);
//
//    char* num1, * num2;
//
//    // getting big value
//    // and small value
//    // num1 for big number
//    // num2 for small number
//    if (len1 > len2) {
//        num1 = Num1;
//        num2 = Num2;
//    }
//    else {
//
//        if (len1 == len2) {
//            int i = 0;
//            while (i < len1 && Num1[i] == Num2[i]) {
//                i++;
//            }
//            if (Num1[i] < Num2[i]) {
//                num1 = Num2;
//                num2 = Num1;
//            }
//            else {
//                num1 = Num1;
//                num2 = Num2;
//            }
//        }
//        else {
//            num1 = Num2;
//            num2 = Num1;
//        }
//    }
//
//    int max = (len1 > len2) ? len1 : len2;
//    int min = (len1 > len2) ? len2 : len1;
//
//    for (int i = 0; i < len1 / 2; i++) {
//        char tmp = num1[i];
//        num1[i] = num1[len1 - 1 - i];
//        num1[len1 - 1 - i] = tmp;
//    }
//    for (int i = 0; i < len2 / 2; i++) {
//        char tmp = num2[i];
//        num2[i] = num2[len2 - 1 - i];
//        num2[len2 - 1 - i] = tmp;
//    }
//
//
//
//    char* num3 = new char[max + 2];
//    // subtraction
//    int sum = 0;
//    for (int i = 0; i < min; i++) {
//        sum = sum + (num1[i] - '0') - (num2[i] - '0');
//        if (sum < 0) {
//            num3[i] = (char)((10 + sum) + '0');
//            sum = -1;
//        }
//        else {
//            num3[i] = (char)((sum)+'0');
//            sum = 0;
//        }
//    }
//    // subtraction for remaining digits
//    for (int i = min; i < max; i++) {
//        if (len1 > min) {
//            sum = sum + (num1[i] - '0');
//            num3[i] = (char)((sum)+'0');
//        }
//        if (len2 > min) {
//            sum = sum + (num2[i] - '0');
//            num3[i] = (char)((sum)+'0');
//        }
//        sum = 0;
//    }
//
//    // reverse string
//    for (int i = 0; i < len1 / 2; i++) {
//        char tmp = Num1[i];
//        Num1[i] = Num1[len1 - 1 - i];
//        Num1[len1 - 1 - i] = tmp;
//    }
//    for (int i = 0; i < len2 / 2; i++) {
//        char tmp = Num2[i];
//        Num2[i] = Num2[len2 - 1 - i];
//        Num2[len2 - 1 - i] = tmp;
//    }
//
//    // remove leading
//    int size = max;
//    while (num3[size - 1] == '0') {
//        size--;
//    }
//
//    if (len1 < len2) {
//        num3[size] = '-';
//        size++;
//    }
//    else if (len1 == len2) {
//        int i = 0;
//        while (i < len1 && Num1[i] == Num2[i]) {
//            i++;
//        }
//        if (Num1[i] < Num2[i]) {
//            num3[size] = '-';
//            size++;
//        }
//    }
//
//    num3[size] = '\0';
//
//    for (int i = 0; i < size / 2; i++) {
//        char tmp = num3[i];
//        num3[i] = num3[size - 1 - i];
//        num3[size - 1 - i] = tmp;
//    }
//
//
//    return num3;
//
//
//}
//
//char multiplicationOfBigInteger(char* Num1, char Num2) {
//    int len1 = strlen(Num1);
//    int len2 = strlen(Num2);
//
//    char* num3 = new char[len1 + len2 + 2];
//    char* mul = new char[(len1 + len2) + 2];
//    // initialize num3 to "0"
//    num3[0] = '0';
//    num3[1] = '\0';
//
//    for (int i = 0; i < len1; i++) {
//        // getting each digits
//        int digit = (Num1[i] - '0');
//
//        // adding Num2
//        for (int j = 0; j <= len2; j++) {
//            mul[j] = Num2[j];
//        }
//        // adding extra 0 according to the number of digits
//        for (int j = len2; j < (len2 + len1 - i - 1); j++) {
//            mul[j] = '0';
//        }
//
//        mul[len2 + len1 - i - 1] = '\0';
//
//        // perform addition operation
//        for (int j = 0; j < digit; j++) {
//            num3 = additionOfBigInteger(num3, mul);
//        }
//    }
//    return num3;
//}
//
//
//int main() {
//    char num1[20];
//    char num2[20];
//
//    strcpy(num1, "12346353");
//    strcpy(num2, "746456");//56757
//
//    char num3[20];
//    strcpy(num3, additionOfBigInteger(num1, num2));
//
//    cout << num1 << "+" << num2 << "=" << num3 << endl;
//
//
//    strcpy(num3, subtractionOfBigInteger(num1, num2));
//    cout << num1 << "-" << num2 << "=" << num3 << endl;
//
//
//    strcpy(num3, multiplicationOfBigInteger(num1, num2));
//    cout << num1 << "*" << num2 << "=" << num3 << endl;
//
//    system("pause");
//    return 0;
//}