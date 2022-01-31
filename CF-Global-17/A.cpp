#include <iostream> // For Basic Input/Output Operations
#include <list> // For using List (STL)
using namespace std;
class Student
{

private:
    string name;
    int roll_no;

public:
    Student() // Empty Constructor
    {
        name = "";
        roll_no = 0;
    }

    Student(string myname, int roll) // Parameterized Constructor
    {
        name = myname; // Name is assigned
        roll_no = roll; // Roll Number is assigned
    }

    // Access Modifiers

    // Getter for name of the student
    string get_name() const
    {
        return name;
    }

    // Getter for roll number of the student
    int get_roll() const
    {
        return roll_no;
    }
};
int main()
{
    list<Student> phone_list; // Created a list, which will store 5 objects of type Student
    for (int i = 0; i < 5; ++i)
    {
        cout << "For " << (i + 1) << "th student :";
        string temp_name;
        cout << "\nEnter name of the student\n";
        cin >> temp_name;

        int temp_roll;
        cout << "\nEnter Roll Number of the student\n";
        cin >> temp_roll;
        Student tt = Student(temp_name, temp_roll);
        
        phone_list.push_back(tt);
        cout << endl;
    }
    
    // Now list has 5 objects of type student
    cout << "\n\n\t ...... Interaction is Starting ...... \n\n";
    while (1)
    {
        cout << "\nEnter : \n\t 1. To exit the Interaction. \n\t 2. To find roll number using name. \n\t 3. To find name using roll number\n";
        int query; cin >> query;
        if(query == 1)
        {
            cout << "\n\n\t .... Stopping Interaction .... \n\n";
            break;
        }
        else if(query == 2)
        {
            cout << "\n Enter name of the Student\n";
            string find_name;
            cin >> find_name;

            bool got_it = false;
            for(auto it = phone_list.begin(); it != phone_list.end(); ++it)
            {
                string what_we_want = (*it).get_name();
                if(what_we_want == find_name)
                {
                    cout << "\nRoll No of " << find_name << " is " << ((*it).get_roll()) << endl;
                    got_it = true;
                    break;
                }
            }
            if(!got_it)
            {
                cout << "\nStudent with name " << find_name << " not found!\n";
            }
        }
        else
        {
            cout << "\n Enter Roll Number of the student\n";
            int find_roll;
            cin >> find_roll;

            bool got_it = false;
            for(auto it = phone_list.begin(); it != phone_list.end(); ++it)
            {
                int what_we_want = (*it).get_roll();
                if (what_we_want == find_roll)
                {
                    cout << "\n Name of student with roll number " << find_roll << " is " << (*it).get_name() << endl;
                    got_it = true;
                    break;
                }
            }

            if(!got_it)
            {
                cout << "\nStudent with Roll number " << find_roll << " not found\n";
            }
        }
    }
    return 0;
}