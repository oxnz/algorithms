class Heap {
public:
    Heap(); // constructor
    Heap(const Heap& t);
    ~Heap(); // destructor

    bool empty() const;
    double root(); // access functions
    Heap& left();
    Heap& right();

    Heap& parent(double x);

    // ... update ...
    void insert(const double x);
    void deleteMin(); // decompose x from a heap

private:
    double* array;
    int array_size;
    int heap_size;
    
