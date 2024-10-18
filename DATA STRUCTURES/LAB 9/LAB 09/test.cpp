#include "pch.h"
#include "Q1.h"
#include "Q2.h"
#include<string>
stack<int> s1; // create object of stack class

TEST(task1, T1) {
    s1.push(1);
    s1.push(2);
    s1.push(3);
    node<int>* top = s1.Peek();
    EXPECT_EQ(3, top->val);
}

TEST(task1, T2) {
    s1.pop();
    node<int>* top = s1.Peek();
    EXPECT_EQ(2, top->val);
    s1.pop();
    top = s1.Peek();
    EXPECT_EQ(1, top->val);

}
TEST(task1, T3) {
    s1.push(3);
    s1.push(4);
    EXPECT_EQ(3, s1.size());
}

string Text1 = "#include<iostream>using namespace std;int main(){System(�Pause�);}";
string Text2 = "#include<iostream>Using namespace std; int main() {{Int arr[10];for (int i = 0; i & lt; 10; i++)cout& lt; &lt; i& lt; &lt; end;system(�pause�);";
string Text3 = "#include<iostream>using namespace std; int main() { for (int i = 0; i & lt; 10; i++) { cout & lt; &lt; i & lt; &lt; end; system(�pause�);}";
/////////Q2/////////////////////
TEST(task2, T1) {
    EXPECT_TRUE(validate(Text1));
}

TEST(task2, T2) {
    EXPECT_FALSE(validate(Text2));
}

TEST(task2, T3) {
    EXPECT_FALSE(validate(Text3));
}
