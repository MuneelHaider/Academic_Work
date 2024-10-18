#include "Rational.cpp"
#include "String.cpp"
#include "Array.cpp"
#include "BinaryStore.cpp"
#include "CMap.cpp"

#include <gtest/gtest.h>

// Q1: Rational.cpp

TEST(Rational, Constructors) { 
    Rational a(2,8);
    Rational b(3,1);
    string expected1="1/4";
    string actual1=(string)a;
   
    ASSERT_EQ(0, actual1.compare(expected1));
    string expected2="3";
    string actual2=(string)b;
   
    ASSERT_EQ(0, actual2.compare(expected2));
    
}
TEST(Rational, Addition) { 
    Rational a(2,8);
	Rational b(3,4);
	Rational c;
	Rational d;
	Rational x(5,1);
	c=a+x;
	string expected1="21/4";
        string actual1=(string)c;
        
        ASSERT_EQ(0, actual1.compare(expected1));
	d=c+b;
	string expected2="6";
        string actual2=(string)d;
        
        ASSERT_EQ(0, actual2.compare(expected2));
    
}

TEST(Rational, Subtraction) { 
        Rational a(5,1);
	Rational b(3,4);
	Rational c;
	Rational d;
	Rational x(5,1);
	c=a-x;
	string expected1="0";
        string actual1=(string)c;
        
        ASSERT_EQ(0, actual1.compare(expected1));
	d=c-b;
	string expected2="-3/4";
        string actual2=(string)d;
        
        ASSERT_EQ(0, actual2.compare(expected2));
    
}
TEST(Rational, Mul) { 
        Rational a(5,1);
	Rational b(1,25);
	Rational c;
	Rational d;
	Rational x(5,1);
	c=a*x;
	string expected1="25";
        string actual1=(string)c;
        
        ASSERT_EQ(0, actual1.compare(expected1));
	d=a*b;
	string expected2="1/5";
        string actual2=(string)d;
        
        ASSERT_EQ(0, actual2.compare(expected2));
    
}
TEST(Rational, Div) { 
        Rational a(5,1);
	Rational b(1,5);
	Rational c;
	Rational d;
	Rational x(5,1);
	c=a/x;
	string expected1="1";
        string actual1=(string)c;
        
        ASSERT_EQ(0, actual1.compare(expected1));
	d=b/a;
	string expected2="1/25";
        string actual2=(string)d;
        
        ASSERT_EQ(0, actual2.compare(expected2));
    
}
TEST(Rational, LessthanEqualGreaterthan) { 
        Rational a(3,2);
	Rational b(9,8);
	Rational c(1,1);
	Rational d(1,5);
	Rational e(1,5);
	ASSERT_EQ(true, e==d);
	ASSERT_EQ(false, a==b);
	ASSERT_EQ(true, a>=b);
	ASSERT_EQ(false, a<c);
	ASSERT_EQ(true, d<=a);
	ASSERT_EQ(true, c<a);
	
    
}


TEST(Rational, InputOutput) { 
        Rational s1;
        cin>>s1;// input 2/4 on terminal
        Rational s2(1,2);
        cout<<s1;
        ASSERT_EQ(true,s2==s1 );
    
}

// Q2:String 
TEST(String, Constructors) { 
    String s1("abcd");
    ASSERT_EQ(4, (int)s1); // Conversion Operator should be overloaded 
    char* c = (char*)"asdfgh";
    String s2(c);
    ASSERT_EQ(6, (int)s2);
    String s3(10);
    ASSERT_EQ(10, (int)s3);
    String s4(s2);
    ASSERT_EQ(6, (int)s4);
    
    
}

TEST(String, SquareBracket) { 
    String s1("abcd");
    ASSERT_EQ('c', s1[2]);
    s1[2]='x';// assignment operator should be overloaded 
    ASSERT_EQ('x', s1[2]);
    ASSERT_EQ('d', s1[3]);
    
}
TEST(String, ArithmeticOperatorsplus) { 
        String s1("abcd");
	
	String s2;
	s2 = s1 + 'e';
	//cout << "ARRAY:" << s2 << endl ;
	ASSERT_EQ('d', s2[3]);
	ASSERT_EQ('e', s2[4]);
	char* c = (char*)"asdfgh";
	s2 = s1 + c;
	ASSERT_EQ('d', s2[3]);
	ASSERT_EQ('a', s2[4]);
	ASSERT_EQ('g', s2[8]);
	ASSERT_EQ(10, (int)s2);
	String s3 = s1 + s2;
	ASSERT_EQ(14, (int)s3);
	
	ASSERT_EQ('s', s3[9]);
    
}
TEST(String, ArithmeticOperatorsSub) { 
        String s1("ababacc");
	
	String s2("aba");
	String string2("cc");;
	s2 = s1 - s2;
	cout << "ANSWER:" << s2 << endl << "SUBSTR:aba\n" << "MAINSTR:" << s1 << endl ;
	ASSERT_EQ('b', s2[0]);
	ASSERT_EQ('a', s2[1]);
	ASSERT_EQ('c', s2[2]);
	s2=s2-string2;
	ASSERT_EQ('b', s2[0]);
	ASSERT_EQ('a', s2[1]);
    
}
TEST(String, Logical) { 
        String s1("ababacc");
        String s4("ababacc");
	String s2("aba");
	string string2="aba";
	char * chararray=(char*)"ababacc";
	ASSERT_EQ(true,s1==chararray );
	
	ASSERT_EQ(false,s2==s1 );
	ASSERT_EQ(true,s1==s4 );
	ASSERT_EQ(true,s2==string2 );
    
}

TEST(String, FunctionCall) { 
        String s1("ababacc");
        int i=s1('c');
        ASSERT_EQ(5,i );
	String s2("acc");
	i=s1(s2);
	ASSERT_EQ(4,i );
	string s3="bac";
	i=s1(s3);
	ASSERT_EQ(3,i );
	
    
}

// Q3 Array

TEST(Array, AssignmentAndEqual_A) {
    Array a1(5);
    int arr[] = {1,2,3,4,5};
    Array a2(arr,5);
    a1 = a2;
    ASSERT_EQ(true,a1==a2);
}
TEST(Array, AssignmentAndEqual_B) {
    Array a1;
    ASSERT_EQ(true,!a1);// checks for NULL
    int arr[] = {1,2,3,4,5,6,7,8,9};
    Array a2(arr,9);
    a1 = a2;
    for(int i=0;i<9;i++){
    	ASSERT_EQ(arr[i],a1[i]);
    }
}
TEST(Array, Addition_A) {
    int arr[] = {1,2,3};
    int arr2[] = {4,5,6};
    Array a1(arr,3);
    Array a2(arr2,3);
    Array a3;
    a3 = a1 + a2;
    ASSERT_EQ(5,a3[0]);
    ASSERT_EQ(7,a3[1]);
    ASSERT_EQ(9,a3[2]);
}
TEST(Array, Addition_B) {
    int arr[] = {1,2,3};
    int arr2[] = {4};
    Array a1(arr,3);
    Array a2(arr2,1);
    a1 += a2;
    ASSERT_EQ(5,a1[0]);
    ASSERT_EQ(2,a1[1]);
    ASSERT_EQ(3,a1[2]);
}

TEST(Array, Subtraction_A) {
    int arr[] = {1,2,3};
    int arr2[] = {4,5,6};
    Array a1(arr,3);
    Array a2(arr2,3);
    Array a3;
    a3 = a2 - a1;
    ASSERT_EQ(3,a3[0]);
    ASSERT_EQ(3,a3[1]);
    ASSERT_EQ(3,a3[2]);
}

TEST(Array, Subtraction_B) {
    int arr[] = {1,2,3};
    int arr2[] = {4};
    Array a1(arr,3);
    Array a2(arr2,1);
    a1 -= a2;
    ASSERT_EQ(-3,a1[0]);
    ASSERT_EQ(2,a1[1]);
    ASSERT_EQ(3,a1[2]);
}
TEST(Array, Increment) {
    int arr[] = {1,2,3};
    Array a1(arr,3);
    a1++;
    ASSERT_EQ(2,a1[0]);
    ASSERT_EQ(3,a1[1]);
    ASSERT_EQ(4,a1[2]);
}
TEST(Array, Decrement) {
    int arr[] = {1,2,3};
    Array a1(arr,3);
    a1--;
    ASSERT_EQ(0,a1[0]);
    ASSERT_EQ(1,a1[1]);
    ASSERT_EQ(2,a1[2]);
}
TEST(Array, DelAtIndex) {
    int arr[] = {1,2,3};
    Array a1(arr,3);
    int res[] ={1,3};
    Array a2(res,2); 
    a1(1,2);
    ASSERT_EQ(true,a1==a2);
}

// Q4 BinaryStore
TEST(Add_Assign_Get, One) {
    BinaryStore b1(2);
    b1 += "1001";
    b1.Add("1001", Byte("01010010"));
    EXPECT_TRUE(strcmp(b1.Get("1001").getByte(), "01010010") == 0);

    b1 += "1101";
    b1.Add("1101", Byte("01011010"));
    EXPECT_TRUE(strcmp(b1.Get("1101").getByte(), "01011010") == 0);

}


TEST(Add_Assign_Get, Two) {

    BinaryStore b1(5);
    b1 += "1111";
    b1.Add("1111", Byte("01011110"));
    EXPECT_EQ(strcmp(b1.Get("1111").getByte(), "01011110"), 0);

    b1 += "1110";
    b1.Add("1110", Byte("00011000"));
    EXPECT_FALSE(strcmp(b1.Get("1110").getByte(), "00011000") != 0);

}

TEST(Add_Assign_Get, Three) {
    BinaryStore b1;
    b1.setSize(5);
    b1 += "0000";
    b1.Add("0000", Byte("00000000"));
    EXPECT_FALSE(strcmp(b1.Get("0000").getByte(), "10000000") == 0);

}

TEST(Byte_Addition, One) {
    Byte byt("00001110");
    Byte byt2("01110000");
    EXPECT_TRUE(strcmp((byt + byt2).getByte(), "01111110") == 0);
}

TEST(Byte_Addition, Two) {
    Byte byt("00001010");
    Byte byt2("01010110");
    EXPECT_EQ(strcmp((byt + byt2 + Byte("00110001")).getByte(), "10010001"), 0);

}


TEST(Byte_Subtraction, One) {
    Byte byt ("00000011");
    Byte byt2("00000100");
    EXPECT_TRUE(strcmp((byt - byt2).getByte(), "11111111") == 0);

    EXPECT_FALSE(strcmp((byt2 - byt).getByte(), "11111111") == 0);
}

TEST(Byte_Subtraction, Two) {
    Byte byt ("00001001");
    Byte byt2("00000100");
               
    EXPECT_TRUE(strcmp((byt - byt2).getByte(), "00000101") == 0);
}


TEST(Byte_Equality, One) {
    Byte byt("10001110");
    Byte byt2("10001110");
    EXPECT_TRUE(byt == byt2);
}

TEST(Byte_Equality, Two) {
    Byte byt("10101110");
    Byte byt2("10001110");
    EXPECT_FALSE(byt == byt2);
}

TEST(Byte_OR, One) {
    Byte byt("10101110");
    Byte byt2("10001110");
    EXPECT_EQ(strcmp((byt || byt2).getByte(), "10101110"), 0);
}

TEST(Byte_AND, One) {
    Byte byt("11111110");
    Byte byt2("10001010");
    EXPECT_TRUE(strcmp((byt && byt2).getByte(), "10001010") == 0);
}

TEST(Byte_AND_OR, One) {
    Byte byt("10101110");
    Byte byt2("10001110");
    EXPECT_TRUE(strcmp(((byt && byt2) || Byte("11110000")).getByte(), "11111110") == 0);
}


// Q5 CMap

TEST(CMap, Equal_A) {
    CMap map;
    map["ENT"] = "Dr. Sibt Ul Hussain";
    map["Radiology"] = "Dr. Sana Mir";
    ASSERT_EQ("[ ENT : { Dr. Sibt Ul Hussain }, Radiology : { Dr. Sana Mir } ]",map.toString());
}
TEST(CMap, Equal_B) {
    CMap map;
    map["ENT"] = "Dr. Sibt Ul Hussain";
    map["Radiology"] = "Dr. Sana Mir";
    map["ENT"] = "Dr. Omer Beg";
    ASSERT_EQ("[ ENT : { Dr. Omer Beg }, Radiology : { Dr. Sana Mir } ]",map.toString());
}
TEST(CMap, Equal_C) {
    CMap map,map2;
    map["ENT"] = "Dr. Sibt Ul Hussain";
    map["Radiology"] = "Dr. Sana Mir";
    map2= map;
    map["ENT"] = "Dr. Omer Beg";
    ASSERT_EQ("[ ENT : { Dr. Omer Beg }, Radiology : { Dr. Sana Mir } ]",map.toString());
    ASSERT_EQ("[ ENT : { Dr. Sibt Ul Hussain }, Radiology : { Dr. Sana Mir } ]",map2.toString());
}


TEST(CMap, ADDEqual_A) {
    CMap map;
    map["ENT"] = "Dr. Sibt Ul Hussain";
    map["ENT"] += "Dr. Omer Beg";
    map["Radiology"] = "Dr. Sana Mir";
    map["Radiology"] += "Dr. Shahid Afridi";
    ASSERT_EQ("[ ENT : { Dr. Sibt Ul Hussain, Dr. Omer Beg }, Radiology : { Dr. Sana Mir, Dr. Shahid Afridi } ]",map.toString());
}
TEST(CMap, ADDEqual_B) {
    CMap map;
    map["ENT"] += "Dr. Sibt Ul Hussain";
    map["ENT"] += "Dr. Omer Beg";
    map["Radiology"] += "Dr. Sana Mir";
    map["Radiology"] += "Dr. Shahid Afridi";
    ASSERT_EQ("[ ENT : { Dr. Sibt Ul Hussain, Dr. Omer Beg }, Radiology : { Dr. Sana Mir, Dr. Shahid Afridi } ]",map.toString());
}

TEST(CMap, SUBEqual_A) {
    CMap map;
    map["ENT"] = "Dr. Sibt Ul Hussain";
    map["ENT"] += "Dr. Omer Beg";
    map["ENT"] -= "Dr. Sibt Ul Hussain";
    
    map["Cardiology"] += "Dr. Husnain Abdullah";
    map["Cardiology"] += "Dr. Omer Beg";
    map["Cardiology"] -= "Dr. Husnain Abdullah";
    
    ASSERT_EQ("[ ENT : { Dr. Omer Beg }, Cardiology : { Dr. Omer Beg } ]",map.toString());
}
TEST(CMap, SUBEqual_B) {
    CMap map;
    map["ENT"] = "Dr. Sibt Ul Hussain";
    map["ENT"] += "Dr. Omer Beg";
    map["ENT"] += "Dr. Husnain Abdullah";
    
    map["ENT"] -= "Dr. Omer Beg";
    
    map["Cardiology"] = "Dr. Shahid Afridi";
    
    ASSERT_EQ("[ ENT : { Dr. Sibt Ul Hussain, Dr. Husnain Abdullah }, Cardiology : { Dr. Shahid Afridi } ]",map.toString());    
}
TEST(CMap, SUBEqual_C) {
    CMap map;
    map["ENT"] = "Dr. Sibt Ul Hussain";
    map["ENT"] += "Dr. Omer Beg";
    map["ENT"] += "Dr. Husnain Abdullah";
    
    map["ENT"] -= "Dr. Omer Beg";
    map["ENT"] -= "Dr. Shahid Afridi";
    
    map["Cardiology"] = "Dr. Shahid Afridi";
    map["Cardiology"] -= "Dr. Omer Beg";
    
    ASSERT_EQ("[ ENT : { Dr. Sibt Ul Hussain, Dr. Husnain Abdullah }, Cardiology : { Dr. Shahid Afridi } ]",map.toString());    
}


TEST(CMap, ADDMaps_A) {
    CMap map,map2,map3;
    map["ENT"] = "Dr. Sibt Ul Hussain";
    map["Radiology"] = "Dr. Sana Mir";
    map["ENT"] += "Dr. Ehtesham Zahoor";
    map["ENT"] += "Dr. Shahid Afridi";
    
    map2["Cardiology"] = "Dr. Umer Farooq";
    map2["Cardiology"] += "Dr. Husnain Abdullah";
    map2["Cardiology"] += "Dr. Omer Beg";
    map2["Cardiology"] += "Dr. Mark Waugh";
    map2["Cardiology"] += "Dr. Saeed Anwar";
    map2["Cardiology"] += "Dr. David Warner";

    map2["Dermatology"] += "Dr. Bisma Maroof";
    map2["Dermatology"] += "Dr. Sidra Ameen";
    map2["Dermatology"] += "Dr. Wahab Riaz";
    map2["Dermatology"] += "Dr. Zahid Alam";

    map3 = map + map2;
    
    ASSERT_EQ("[ ENT : { Dr. Sibt Ul Hussain, Dr. Ehtesham Zahoor, Dr. Shahid Afridi }, Radiology : { Dr. Sana Mir }, Cardiology : { Dr. Umer Farooq, Dr. Husnain Abdullah, Dr. Omer Beg, Dr. Mark Waugh, Dr. Saeed Anwar, Dr. David Warner }, Dermatology : { Dr. Bisma Maroof, Dr. Sidra Ameen, Dr. Wahab Riaz, Dr. Zahid Alam } ]",map3.toString());
    
}

TEST(CMap, ADDMaps_B) {
    CMap map,map2,map3;
    map["ENT"] = "Dr. Sibt Ul Hussain";
    map["Radiology"] = "Dr. Sana Mir";
    map["ENT"] += "Dr. Ehtesham Zahoor";
    map["ENT"] += "Dr. Shahid Afridi";
    
    map3 = map + map2;
    ASSERT_EQ("[ ENT : { Dr. Sibt Ul Hussain, Dr. Ehtesham Zahoor, Dr. Shahid Afridi }, Radiology : { Dr. Sana Mir } ]",map3.toString());
    
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

