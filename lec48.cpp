#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> Designation = {"CEO", "CTO", "MANAGER", "SR_EMPLOYEE", "EMPLOYEE"};
    int empID, start, end, employeeCount, temp = 0;
    string designation;
    vector<int> meetings;
    vector<int> employees;

    cout << "Enter the number of employees: " << endl;
    cin >> employeeCount;

    for (int i = 0; i < employeeCount; i++)
    {
        cout << "Enter the employee IDs: " << endl;
        cin >> temp;
        employees.push_back(temp);
    }

    temp = 4;

    for (int i = 0; i < employeeCount; i++)
    {
        string designationInput;
        int id, inputKey;

        while (true)
        {
            cout << "Enter the designation, empID, and end of employees to fix a meeting with empID = " << employees[i] << ". Press 1 if the inputs are over, else press 0: " << endl;
            cin >> designationInput >> id >> inputKey;

            auto it = find(Designation.begin(), Designation.end(), designationInput);
            int designationIndex = distance(Designation.begin(), it);

            if (designationIndex <= temp)
            {
                meetings.pop_back();
                temp = designationIndex;
                meetings.push_back(id);
            }

            if (inputKey == 1)
                break;
        }

        cout << employees[i] << " " << meetings[i] << endl;
        temp = 4;
    }

    return 0;
}