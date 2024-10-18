#include "pch.h"
#include "Q2.h"

TEST(Question2, Part_A_1) {
	DoubleLinkedList operator_stack; // Operator stack
	char output_stack[30] = {}; // Output stack
	string infix = "(A*(B/C-D)^E)+(E/F/(G+H))"; // Equation to convert from infix to postfix
	int pos = infix_to_postfix_A(infix, output_stack, operator_stack);
	// This is to empty stack contents and append it to the output string one by one
	while (!operator_stack.is_empty()) {
		string temp = operator_stack.pop();
		output_stack[pos++] = temp[0];
	}
	char expected_output[] = "ABC/D-*E^EF/GH+/+";
	for (int i = 0; output_stack[i]; i++) {
		EXPECT_EQ(output_stack[i], expected_output[i]);
	}
}

TEST(Question2, Part_A_2) {
	DoubleLinkedList operator_stack; // Operator stack
	char output_stack[30] = {}; // Output stack
	string infix = "HABCE/F/G-(H^J^K)ABCD"; // Equation to convert from infix to postfix
	int pos = infix_to_postfix_A(infix, output_stack, operator_stack);
	// First, compare the remaining operators left in the operator stack
	string expected_operators[] = { "ABC", "-" };
	for (int i = 0; !operator_stack.is_empty(); i++) {
		EXPECT_EQ(operator_stack.top(), expected_operators[i]);
		string op = operator_stack.pop();
		if (op == "ABC") {
			output_stack[pos++] = op[0];
			output_stack[pos++] = op[1];
			output_stack[pos++] = op[2];
		}
		else {
			output_stack[pos++] = op[0];
		}
	}
	// Then, compare the output string after popping the operator stack into the output stack
	char expected_output[] = "HEABCF/G/HJ^K^DABC-";
	for (int i = 0; expected_output[i]; i++) {
		EXPECT_EQ(output_stack[i], expected_output[i]);
	}
}