/**
 * @brief Employee child classes — Week 9 C++ programming assignment:
 *        Inheritance, Overriding, and Polymorphism.
 *
 * @course ESCC, CIS-251 - C++ Programming
 * @assignment Week 9 Programming Assignment
 * @lesson_focus OOP: Inheritance, Overriding, and Polymorphism.
 *
 * @instructions Employee Hierarchy: create an Employee base class and
 *   two derived employee types that override a virtual display/pay-description
 *   method. Demonstrate polymorphic calls using the exact pattern practiced in
 *   the readings/videos. Include one has-a/composition relationship only if
 *   demonstrated in your study examples.
 *
 * @status Fully Working
 *
 * @author Eric L. Hepperle
 * @date 2026-10-16
 * @updated 2026-10-18
 * @version 1.0
 *
 * @see https://github.com/codewizard13
 */

#include <iostream>
#include <string>
using namespace std;

/*
    @class Employee - parent class
*/
class Employee
{
public:
  string name;
  string employeePayType;

  // Use the normal automatic cleanup, but make destruction polymorphic.
  virtual ~Employee() = default;

  virtual void displayPayDescription() const
  {
    cout << "Hi, I'm " << name << " and I'm a " << employeePayType << " employee.\n";
  }
};

class Intern : public Employee
{
public:
  void displayPayDescription() const override
  {
    cout << "Hi, I'm " << name << " and I'm an intern. My pay type is " << employeePayType << ".\n";    
  }
};

class Manager : public Employee {
public:
  void displayPayDescription() const override {
    cout << "Hi, I'm " << name << " and I'm a manager. My pay type is " << employeePayType << ".\n";        
  }

};

int main()
{

  cout << "\n***************** TEST 1 ******************\n";
  // Create pointer to an Employee object
  Employee *employee1 = new Employee;

  // Populate employee1 values
  employee1->name = "Michael";
  employee1->employeePayType = "salaried";
  employee1->displayPayDescription();

  // Create intern
  cout << "\n***************** TEST 2 ******************\n";
  Intern *intern1 = new Intern;
  Employee *pIntern1 = intern1;
  intern1->name = "Fiona";
  intern1->employeePayType = "W-2 minimum wage";
  pIntern1->displayPayDescription();

  // Create Manager
  cout << "\n***************** TEST 3 ******************\n";
  Manager *manager1 = new Manager;
  Employee *pManager1 = manager1;
  manager1->name = "Chuck";
  manager1->employeePayType = "salaried with stock options";
  pManager1->displayPayDescription();

  // TEST 4: 
  cout << "\n***************** TEST 4 ******************\n";
  pIntern1->displayPayDescription();

  // TEST 5: 
  cout << "\n***************** TEST 5 ******************\n";
  pManager1->displayPayDescription();


  // Cleanup Employee objects
  delete employee1;
  employee1 = nullptr;

  delete intern1;
  intern1 = nullptr;

  delete manager1;
  manager1 = nullptr;


  cout << "\n******** END PROGRAM *******************************************\n";

  return 0;
}
