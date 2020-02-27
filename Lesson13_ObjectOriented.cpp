#include <iostream>
#include <ctime>

using namespace std;

//Concept: class, encapsulation, object, constructor, destructor, modifier
class Student 
{
    private:
        const int NUM_EXAMS = 5;
        string name;
        double gpa;
        int *scoreList;
    public:
        //Constructor: special member function used to initialize the attributes
        Student(string name, double gpa)
        {
            this -> name = name;
            this -> gpa = gpa;
            scoreList = new int[NUM_EXAMS];
            for ( int i = 0; i < NUM_EXAMS; i++)
            {
                scoreList[i] = rand() % 120;
            }
        }
        ~Student() //Destructor used to release the dynamic memory
        {
            delete[] scoreList;
        }
        void output()
        {
            cout << name << gpa << endl;
            for (int i = 0; i < NUM_EXAMS; i++)
            {
                cout << scoreList[i] << endl;
            }
        }
};

int main()
{
    srand(time(0));
    //Part 1: Instantiate a Student taylor using regular constructor
    Student taylor("T. Day ", 3.89);
    taylor.output();
    //Part 2: DIY antoher student
    Student jared("Jared ", 4.0);
    jared.output();
    //Part 3: Pointer to student
    Student *pstudent = new Student("Selina ", 3.97);
    pstudent -> output();

    delete[] pstudent;

    return 0;
}