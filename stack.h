#ifndef __stack_h__
#define __stack_h__

#ifndef NULL
#define NULL 0x00
#endif

class Node
{
    private:
        Node* next;
        long data;

    public:
        Node(long d);
        ~Node();


        friend class Stack;
};

class Stack
{
    private:
        Node* head;
        Node* tail;
        unsigned int n_elem;
        //int top; //idk what I'll be neding this for but better safe than sorry

    public:

        Stack();
        ~Stack(); //need to work on the deconstructor

        long int pop(); //remove first
        void push(long val); //void prepend(int d);
        bool isEmpty();
        long peek(); //return the top element
        int getSize(); //Return the size of the Stack
};
#endif /* stack_h */
