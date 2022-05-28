#ifndef ARRAYLIST_H
#define ARRAYLIST_H
using std::ostream;

class ArrayList
{
public:
    ArrayList() : capacity{ 1 }, used{ 0 }, pArray{ new int[1] } {} // default ctor
    ArrayList(const ArrayList& source); // copy ctor
    ArrayList(ArrayList&& source) noexcept; // move ctor
    ArrayList& operator=(const ArrayList& rhs); // copy assignment
    ArrayList& operator=(ArrayList&& rhs) noexcept; // move assignment
    virtual ~ArrayList(); // virtual dtor

    bool empty() const;
    bool full() const;
    int size() const;
    void pushBack(int x);
    bool contains(int x) const;
    bool get(int position, int& value) const;
    int getCapacity() const;
    void print(ostream& sout) const;

private:
    void resize();
    int capacity;
    int used;
    int* pArray;
};

ostream& operator<<(ostream& sout, const ArrayList& source);

#endif