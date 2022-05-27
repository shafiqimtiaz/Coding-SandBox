#ifndef ARRAYLIST_H
#define ARRAYLIST_H
using std::ostream;

class ArrayList
{
public:
    ArrayList();
    ArrayList(const ArrayList& source);
    ArrayList(ArrayList&& source) noexcept;
    ArrayList& operator=(const ArrayList& rhs);
    ArrayList& operator=(ArrayList&& rhs) noexcept;
    virtual ~ArrayList();

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