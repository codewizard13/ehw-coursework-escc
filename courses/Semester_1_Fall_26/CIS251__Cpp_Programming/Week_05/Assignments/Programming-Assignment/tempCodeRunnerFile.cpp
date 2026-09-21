#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{

    // Declare Variables
    double score = 0;
    char grade_ltr;

    // FUNCTION PROTOTYPES
    double readScore(double score);
    char calcGradeLetter(double score);
    void displayGrade(char grade_ltr);


    int main() {

        readScore(score);
        calcGradeLetter(score);
        displayGrade(grade_ltr);

        return 0;
    }


    /*** CUSTOM FUNCTIONS  ***/


    double readScore(double score) {

        return score;
    };
    
    char calcGradeLetter(double score) {

        return grade_ltr;
    };

    void displayGrade(char grade_ltr) {

        
    };

    cout << "*******************\n\n";
    return 0;
}