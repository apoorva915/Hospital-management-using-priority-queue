#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

struct Node
{
    char name[100];
    int age;
    char address[100];
    int phone;
    char bloodgroup[100];
    int reg;
    int priority;
    struct Node *next;
};

struct Node *start = nullptr;

struct Node *insert(struct Node *);
struct Node *deleteRecord(struct Node *);
void display(struct Node *);
void table();

int main()
{
    int option;
    do
    {
        system("COLOR 46");
        cout << "\t\t\t-------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\n";
        cout << "\t\t\t WELCOME TO ANDROIDHIRE HOSPITAL!\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\n";
        cout << "\t\t\t-------------------------------\n";
        cout << "\t\t\t1.ADD A PATIENT\n";
        cout << "\t\t\t2.DELETE A RECORD\n";
        cout << "\t\t\t3.DISPLAY ALL APPOINTMENTS\n";
        cout << "\t\t\tEnter your choice:";
        cin >> option;

        switch (option)
        {
        case 1:
            start = insert(start);
            cin.ignore();
            system("cls");
            break;
        case 2:
            start = deleteRecord(start);
            cin.ignore();
            system("cls");
            break;
        case 3:
            display(start);
            cin.ignore();
            system("cls");
            break;
        case 4:
            exit(0);
            break;
        }
    } while (option != 4);
}

struct Node *insert(struct Node *start)
{
    int val2, val4, val6, pri;
    struct Node *ptr, *p;
    ptr = new Node();

    cout << "Enter patient Name:";
    cin >> ptr->name;
    cout << "Enter the patient's age:";
    cin >> val2;
    cout << "Enter your home address:";
    cin >> ptr->address;
    cout << "Enter your phone number:";
    cin >> val4;
    cout << "Enter the blood group of Patient:";
    cin >> ptr->bloodgroup;
    cout << "Enter the reg no:";
    cin >> val6;
    cout << "Enter your disease Number:";
    table();
    cin >> pri;

    strcpy(ptr->name, name);
    ptr->age = val2;
    strcpy(ptr->address, address);
    ptr->phone = val4;
    ptr->reg = val6;
    ptr->priority = pri;

    if ((start == nullptr) || pri < start->priority)
    {
        ptr->next = start;
        start = ptr;
    }
    else
    {
        p = start;
        while (p->next != nullptr && p->next->priority <= pri)
            p = p->next;
        ptr->next = p->next;
        p->next = ptr;
    }

    return start;
}

struct Node *deleteRecord(struct Node *start)
{
    struct Node *ptr;
    if (start == nullptr)
    {
        cout << "\n NO PATIENT RECORD TO DELETE";
        return start;
    }
    else
    {
        ptr = start;
        cout << "\n Deleted Record is : " << ptr->reg;
        start = start->next;
        delete ptr;
    }
    return start;
}

void display(struct Node *start)
{
    struct Node *ptr;
    ptr = start;
    if (start == nullptr)
        cout << "\nTHERE IS NO PATIENT";
    else
    {
        cout << "\Priority wise appointments are:";
        while (ptr != nullptr)
        {
            cout << "The name of patient is:" << ptr->name << endl;
            cout << "The age of patient is:" << ptr->age << endl;
            cout << "The address of patient is : " << ptr->address << endl;
            cout << "Phone Number:" << ptr->phone << endl;
            cout << "The blood group of patient is:" << ptr->bloodgroup << endl;
            cout << "---------------------------------------------------\n";
            ptr = ptr->next;
        }
    }
    cin.ignore();
}

void table()
{
    cout << "\t\tPlease Refer this Table for your disease!\n";
    cout << "1.Heart attack\n";
    cout << "2.Severe wound/Bleeding\n";
    cout << "3.Cancer\n";
    cout << "4.Chest pain\n";
    cout << "5.Fracture\n";
    cout << "6.Diabetes Checkup\n";
    cout << "7.Infection\n";
    cout << "8.Viral Fever\n";
    cout << "9.Common Cold/Head ache\n";
}
