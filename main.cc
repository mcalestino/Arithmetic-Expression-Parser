
#include<iostream>
#include "stack.h"
#include "math.h"

using namespace std;

void infix2postfix(const char *infix, char *postfix);
long int eval_postfix(const char *postfix);//suppose to be eval_postfix


int main(int argc, const char * argv[])
{
    //const char A[] = "( 4 + 8 ) * ( 6 - 5 ) / ( ( 3 - 2 ) * ( 2 + 2 ) )";
    //const char A[] = "( -300 + 23 ) * ( 43 - -21 ) / ( 84 + 7 )";
    const char A[] = //"1 + 2 - 3 * 4 / 5 ^ 6 ";
        //"1 + 2";
        //"-10 + 20 * ( 30 / 2 )";
        //"( 5 + 3 ) * 12 / 3";
        "33 + 12 - 12 / ( 4 * -9 )";
        //"1 + 2 - +3 * 4 / 5 ^ 6";
        //"4 ^ 2 * 3 - 3 + 8 / 4 / ( 1 + 1 ) * ( 1 + -2 - -3 * 4 ^ 2 ^ 1 ^ 3 ) + 2";
        //"200";
    int capacity = (int)strlen(A);
    char B[capacity+1];
    infix2postfix(A, B);
    cout<<B<<endl;
    
    //int size = (int)strlen(B);
    //cout<<size<<endl;
    //const char check[] = "33 12 + 12 4 -9 * / - ";
    
    long int chec = eval_postfix(B);
    cout<<chec<<endl;
    return 0;
}

/*
#include "stack.h"
#include <string>
#include <string.h>
#include <assert.h>

void infix2postfix(const char *infix, char *postfix);
long int eval_postfix(const char *postfix);

int main() {
    Stack st;

    // testing stack works (QUESTION 1)
    for (int j = 10 ; j <= 1000000 ; j *= 10) {
        assert(st.isEmpty());
        for (int i = 0 ; i < j ; i++) {
            st.push(i);
            st.push(i * 2);
            st.pop();
            assert(st.pop() == i);
        }
    }

    // create 5 test cases
    int n_cases = 5;
    std::string infix_cases[] = 
    {
        "1 + 2",
        "-10 + 20 * ( 30 / 2 )",
        "( 5 + 3 ) * 12 / 3",
        "33 + 12 - 12 / ( 4 * -9 )",
        "1 + 2 - 3 * 4 / 5 ^ 6"
    };
    
    std::string postfix_cases[] = 
    {
        "1 2 +",
        "-10 20 30 2 / * +",
        "5 3 + 12 * 3 /",
        "33 12 + 12 4 -9 * / -",
        "1 2 + 3 4 * 5 6 ^ / -"
    };
    
    long int values[] = {3, 290, 32, 46, 3};

    // iterate over all test cases
    for (int i = 0 ; i < n_cases ; i++) 
    {
	// allocate memory
        char *postfix = new char [infix_cases[i].size() + 1];

	// testing QUESTION 2
        infix2postfix(infix_cases[i].c_str(), postfix);
        assert(strcmp(postfix_cases[i].c_str(), postfix) == 0);

	// testing QUESTION 3
        //assert(eval_postfix(postfix_cases[i].c_str()) == values[i]);

	// release memory
        delete [] postfix;
    }
}*/
