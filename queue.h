class QueueOfInts{
    
public:
    virtual void enqueue(int x) = 0;
    virtual int dequeue() = 0;
    virtual bool isEmpty() = 0;
    virtual int peek() const = 0;
    virtual ~QueueOfInts(){}
};

class Queue : public QueueOfInts{

public:
    Queue(int length = 20);
    ~Queue();
    void enqueue(int x);
    int dequeue();
    bool isEmpty();
    int peek() const;

private:
    int* tab;
    int maxLength;
    int frontPointer;
    int backPointer;
};
