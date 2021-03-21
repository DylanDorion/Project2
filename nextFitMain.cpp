// Dylan Dorion

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void NextFit (int* base, int* displacement, int* procSize, char* labels, int baseLength, int procLength)
{
        int j = 0;
        int completion = 0;

        for (int i = 0; i < procLength; i++)
        {
                int iterationNum = 0;
                cout << "Taking up Process " << labels[i] << endl;
                while (true)
                {
                        iterationNum++;
                        if (procSize[i] <= displacement[j])
                        {
                                cout << "Slot assignment successful. " << labels[i] << " - Base location " << base[j] << endl;
                                displacement[j] -= procSize[i];
                                base[j] += procSize[i];

                                cout << "Current slot map:" << endl;

                                for (int i = 0; i < baseLength; i++)
                                {
                                        if (displacement[i] == 0)
                                                continue;
                                        cout << base[i] << '\t';
                                }
                                cout << endl;

                                for (int i = 0; i < baseLength; i++)
                                {
                                        if (displacement[i] == 0)
                                                continue;
                                        cout << displacement[i] << '\t';
                                }
                                cout << endl << endl;
                                completion++;
                                break;
                        }
                        else
                        {
                                j++;
                        }
                        //if (j == baseLength)
                        //      j = 0;

                        if (iterationNum == baseLength)
                        {
                                cout << "Slot assignment could not succeed. The next fit algorithm will now stop." << endl;
                                for (int i = 0; i < baseLength; i++)
                                {
                                        if (displacement[i] == 0)
                                                continue;
                                        cout << base[i] << '\t';
                                }
                                cout << endl;

                                for (int i = 0; i < baseLength; i++)
                                {
                                        if (displacement[i] == 0)
                                                continue;
                                        cout << displacement[i] << '\t';
                                }
                                cout << endl;
                                break;
                        }
                }
                if (iterationNum == baseLength)
                {
                        break;
                }
        }
        if (completion == procLength)
        {
                cout << "All processes in the list were successfully allocated memory slots." << endl;
        }
        else
        {
                cout << "Not all processes in the list could be allocated memory slots." << endl;
        }
}

int main ()
{
        int locNum;
        int procNum;

        int* baseLoc;
        int* displacement;
        int* procSize;
        char* labels;

        cout << "This memory manager program allocates slots to processes using the Next Fit Dynamic Relocation.\n" << endl;

        cout << "Please enter the number of base locations you will be using: ";
        cin >> locNum;

        baseLoc = new int[locNum];
        displacement = new int[locNum];

        cout << "\nPlease enter the base locations of the slots: ";
        for (int i = 0; i < locNum; i++)
        {
                cin >> baseLoc[i];
        }

        cout << "\nPlease enter the displacements for the base locations that you entered: ";
        for (int i = 0; i < locNum; i++)
        {
                cin >> displacement[i];
        }

        cout << "\nCurrent slot map:" << endl;
        for (int i = 0; i < locNum; i++)
        {
                cout << baseLoc[i] << '\t';
                }

        cout << endl;

        for (int i = 0; i < locNum; i++)
        {
                cout << displacement[i] << '\t';
        }

        cout << "\n\nPlease enter the number of process sizes you will be using: ";
        cin >> procNum;

        procSize = new int[procNum];
        labels = new char[procNum];

        cout << "\nPlease enter the list of process sizes: ";
        for (int i = 0; i < procNum; i++)
        {
                cin >> procSize[i];
                labels[i] = 'A' + i;
        }

        cout << "\nProcesses:" << endl;
        for (int i = 0; i < procNum; i++)
        {
                cout << labels[i] << '\t';
        }

        cout << endl;

        for (int i = 0; i < procNum; i++)
        {
                cout << procSize[i] << '\t';
        }

        cout << "\n" << endl;

        NextFit (baseLoc, displacement, procSize, labels, locNum, procNum);

        return 0;
}
