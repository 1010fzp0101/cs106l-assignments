#include <iterator>
class Circle {
public:
Circle(int radius) : data(radius) {}
Circle() : data(1) {}

int getData() const;
void setData(int radius);
    
private:
    int data;
    bool isValidRadius(int radius); 
};