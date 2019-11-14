#include <iostream>
#include "string.h"
#include "stack.h"
#include <cmath>

using namespace std;

/*
 * Convert infix mathematical equations/expression in a String to
 * Postfix mathematical equation/expression in String format
 *
 */
void infix2postfix(const char *infix, char *postfix)
{
    //Local Variable
    
    // The new Stack
    Stack *i2fStack = new Stack();
    
    //Define the operator characters
    char mult = '*';
    char div  = '/';
    char carr = '^';
    char add  = '+';
    char sub  = '-';
    char left = '(';
    char right= ')';
    
    int infixSize = (int)strlen(infix); //need the size of the array
    int pFCount = 0; // postfix (array) counter
    
    for(int i = 0; i < infixSize; i++) 
    {
        //Check for negative numbers, if negative, append '-' to the postfix String
        if((infix[i] == '-') && (infix[i + 1] != ' ')) 
        {
            postfix[pFCount] = '-';
            pFCount++;
        }
        
        //Check if numbers have a leading '+', if so, append '+' to the postfix String
        if((infix[i] == '+') && (infix[i + 1] != ' ')) 
        {
            postfix[pFCount] = '+';
            pFCount++;
        }
        
        //Check for the digits (regular numbers, not operators)
        if((infix[i] != mult) && (infix[i] != div) && (infix[i] != carr) &&
            (infix[i] != add ) && (infix[i] != sub) && (infix[i] != left) &&
            (infix[i] != right) && (infix[i] != ' '))
        {
            postfix[pFCount] = infix[i];
            pFCount++;
            
            //Append a space, after the whole number is appended to the postfix String
            //Check to see if the number is more than 1 digit
            if((infix[i + 1] == ' ') || (infix[i + 1] == '\0'))
            {
                postfix[pFCount] = ' ';
                pFCount++;
            }
            
        }
        
        else if (infix[i] == ' ') //Nothing to do when its a space
        {
            //Do nothing 
        }
        else if(infix[i] == left) //Left Paranthesis 
        {
            i2fStack -> push(left - '0'); //push character to the stack
        }
        
        else if((infix[i] == carr) && (infix[i + 1] == ' ')) //Carrot
        {
            i2fStack -> push(carr - '0'); //push character to the stack
        }
        
        else if((infix[i] == mult) && (infix[i + 1] == ' '))// Multiplication
        {
            //Check for precedence of operator. if so, pop the value from the stack and append to the postfix String
            while(!i2fStack -> isEmpty() && ((i2fStack -> peek() == div - '0') || (i2fStack -> peek() == carr - '0') 
                                             || (i2fStack -> peek() == mult - '0')))
            {
                long value = i2fStack -> pop();
                postfix[pFCount] = value + '0';
                pFCount++;
                postfix[pFCount] = ' '; //tailing space 
                pFCount++;
                
            }
            
            i2fStack -> push(mult - '0'); //push character to the stack
        }
        
        else if((infix[i] == div) && (infix[i + 1] == ' ')) //Division
        {
            //Check for precedence of operator. if so, pop the value from the stack and append to the postfix String
            while(!i2fStack -> isEmpty() && ((i2fStack -> peek() == mult - '0') || (i2fStack -> peek() == carr - '0') 
                                            || (i2fStack -> peek() == div -'0')))
            {
                long value = i2fStack -> pop();
                postfix[pFCount] = value + '0';
                pFCount++;
                postfix[pFCount] = ' '; //tailing space
                pFCount++;
                
            }
            
            i2fStack -> push(div - '0'); //push character to the stack
        }
        
        else if((infix[i] == add) && (infix[i + 1] == ' ')) // Addition
        {
            //Check for precedence of operator. if so, pop the value from the stack and append to the postfix String
            while(!i2fStack -> isEmpty() && i2fStack -> peek() != left - '0') 
            {
                long value = i2fStack -> pop();
                postfix[pFCount] = value + '0';
                pFCount++;
                postfix[pFCount] = ' '; //tailing space
                pFCount++;
            }
            i2fStack -> push(add - '0'); //push chacter to the stack
        }
        
        else if ((infix[i] == sub) && (infix[i + 1] == ' ')) //Substraction
        {
            //Check for precedence of operator. if so, pop the value from the stack and append to the postfix String
            while(!i2fStack -> isEmpty() && i2fStack -> peek() != left - '0')
            {
                long value = i2fStack -> pop();
                postfix[pFCount] = value + '0';
                pFCount++;
                postfix[pFCount] = ' '; //tailing space
                pFCount++;
            }
            
            i2fStack -> push(sub - '0'); //push character to the stack
        }
        
        else if(infix[i] == right) //Right Parathesis
        {
            long value;
            while(i2fStack -> peek() != left - '0') // Add the operator to the end of the String when the Right Parathesis 
            {
                value = i2fStack -> pop();
                postfix[pFCount] = value + '0';
                pFCount++;
                postfix[pFCount] = ' '; // tailing space
                pFCount++;
            }
            
            if(i2fStack -> peek() == left - '0') // Make sure the left Paranthesis is removed from the Stack
            {
                value = i2fStack -> pop();
            }
        }
    }
    
    int size = i2fStack -> getSize();
    for(int j = 0; j < size; j++) //Pop and Add the rest of the operators on the stack to the string
    {           
            long value = i2fStack -> pop();
            char remains = value + '0';
            postfix[pFCount] = remains;
            pFCount++;
            postfix[pFCount] = ' '; //tailing space
            pFCount++;
    }
    
    postfix[pFCount - 1] = '\0'; //Ending the String right after the last character(not space)

} // #end infix2postfix

/*
 * Solve a postfix expression and return the answer
 *
 */
long int eval_postfix(const char *postfix)
{
    //local variables
    Stack* postFixEval = new  Stack(); // New Stack
    int postFixSize = (int)strlen(postfix); // Size/length of the postfix expression
    bool isNeg = false; // should be false by default
    long int number = 0;
    int j;
    int digit;
    long left, right;
    
    for(int i = 0; i < postFixSize; i++) //Loop through the string
    {
        j = i;
        //Check to see if the Number is Negative
        if((postfix[i] == '-') && (postfix[i + 1] != ' '))  
        {
            isNeg = true;
        }
        
        while((postfix[j] > '/') && (postfix[j] < ':')) //Calculate numbers (one's more than 1 digit)
        {
            digit = postfix[i] - '0';
            number = (number * 10) + digit;
            j++;
            i = j;
            //cout<<number<<endl;
        }
        
        if(isNeg) //If Negaitve, make sure the number is negative 
        {
            number = number * -1;
        }
        
        
        if(((postfix[i] == ' ') || (postfix[i] == '\0')) && 
           (postfix[i - 1] > '/') && (postfix[i - 1] < ':')) //Add the number to the Stack and reset to default
        {
            postFixEval -> push(number);
            isNeg = false;
            number = 0;
        }
        
        // when the character is multiply 
        // pop the top two numbers from the stack and multiply the numbers and push the result to the stack 
        else if((postfix[i] == '*') && ((postfix[i + 1] == ' ') || postfix[i + 1] == '\0')) 
        {
            right = postFixEval -> pop();
            left  = postFixEval -> pop();
            number = left * right;
            postFixEval -> push(number);
            number = 0;
        }
        
        // when the character is the carrot 
        // pop the top two numbers from the stack and find left to the right power and push the result to the stack
        else if ((postfix[i] == '^') && ((postfix[i + 1] == ' ') || postfix[i + 1] == '\0')) 
        {
            right = postFixEval -> pop();
            left  = postFixEval -> pop();
            number = pow(left, right);
            postFixEval -> push(number);
            number = 0;
        }
        
        // when the character is the division 
        // pop the top two numbers from the stack and find left divide by right power and push the result to the stack
        else if ((postfix[i] == '/') && ((postfix[i + 1] == ' ') || postfix[i + 1] == '\0'))
        {
            right = postFixEval -> pop();
            left  = postFixEval -> pop();
            number = floor(double (left) / right);
            postFixEval -> push(number);
            number = 0;
        }
        
        // when the character is the plus 
        // pop the top two numbers from the stack and left plus right and push the result to the stack
        else if ((postfix[i] == '+') && ((postfix[i + 1] == ' ') || postfix[i + 1] == '\0'))
        {
            right = postFixEval -> pop();
            left  = postFixEval -> pop();
            number = left + right;
            postFixEval -> push(number);
            number = 0;
            
        }
        
        // when the character is the minus  
        // pop the top two numbers from the stack and find left minus right power and push the result to the stack
        else if ((postfix[i] == '-') && ((postfix[i + 1] == ' ') || postfix[i + 1] == '\0'))
        {
            right = postFixEval -> pop();
            left  = postFixEval -> pop();
            number = left - right;
            postFixEval -> push(number);
            number = 0;
        }
             
    }
    number = postFixEval -> pop(); //Get the final answer of the Evaluation 
    return number;
} // #eval_postfix
