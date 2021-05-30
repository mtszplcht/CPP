class StackOfInts{
    
public:
    virtual int pop() = 0;
    virtual void push(int x) = 0;
    virtual bool isEmpty() = 0;
    virtual int size() = 0;
    virtual int peek() const = 0;
    virtual ~StackOfInts(){}
};


class Stack : public StackOfInts{
    
public:
    Stack(int length = 20);
    ~Stack();
    int pop();
    void push(int x);
    bool isEmpty();
    int size();
    int peek() const ;

private:
    int* tab;
    int top;
    int maxLength;
    int stackLength;
};
