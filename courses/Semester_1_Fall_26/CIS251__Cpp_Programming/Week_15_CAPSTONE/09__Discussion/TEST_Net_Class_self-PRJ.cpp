#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Net
{
public:
    double amount;

    Net(double gross, double tax_percent)
        : amount(gross * (1.0 - tax_percent / 100.0)) {}

    Net operator+(const Net &other) const
    {
        return Net(amount + other.amount, 0.0);
    }

    void display() {
        cout << this->amount;
    }
};

int main()
{

    Net Jan_Net(5000, 20);
    Net Feb_Net(6000, 20);
    Net Mar_Net(5500, 20);

    Net First_Quarter_Net = Jan_Net + Feb_Net + Mar_Net;

    First_Quarter_Net.display();

    return 0;
}
