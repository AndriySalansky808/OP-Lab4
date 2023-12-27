#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct ITINERARY 
{
    string BEG;
    string END;
    int NUM;
    double DISTANCE;
};

void inputItineraries(ITINERARY ROUT[], int N) 
{
    for (int i = 0; i < N; ++i) 
    {
        cout << "Enter details for itinerary #" << i + 1 << ":" << endl;
        cout << "Beginning point: ";
        cin >> ROUT[i].BEG;
        cout << "Ending point: ";
        cin >> ROUT[i].END;
        cout << "Route number: ";
        cin >> ROUT[i].NUM;
        cout << "Distance (in kilometers): ";
        cin >> ROUT[i].DISTANCE;
        cout << endl;
    }
}

void sortItineraries(ITINERARY ROUT[], int N) {
    sort(ROUT, ROUT + N, [](const ITINERARY& a, const ITINERARY& b)
    {
        return a.NUM < b.NUM;
    });
}

void printItineraries(ITINERARY ROUT[], int N, const string& location)
{
    bool found = false;

    cout << "Itineraries starting or ending at " << location << ":" << endl;

    for (int i = 0; i < N; ++i)
    {
        if (ROUT[i].BEG == location || ROUT[i].END == location) 
        {
            cout << "Route #" << ROUT[i].NUM << ": " << ROUT[i].BEG << " to " << ROUT[i].END << " (Distance: " << ROUT[i].DISTANCE << " km)" << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "No itineraries found for " << location << "." << endl;
    }
}

void saveDataToFile(ITINERARY ROUT[], int N) 
{
    ofstream outFile("itinerary_data.txt");

    for (int i = 0; i < N; ++i) 
    {
        outFile << ROUT[i].BEG << " " << ROUT[i].END << " " << ROUT[i].NUM << " " << ROUT[i].DISTANCE << endl;
    }

    outFile.close();
}

void loadDataFromFile(ITINERARY ROUT[], int N) 
{
    ifstream inFile("itinerary_data.txt");

    for (int i = 0; i < N; ++i) 
    {
        inFile >> ROUT[i].BEG >> ROUT[i].END >> ROUT[i].NUM >> ROUT[i].DISTANCE;
    }

    inFile.close();
}

int main() 
{
    int N;

    cout << "Enter the number of itineraries: ";
    cin >> N;

    ITINERARY* ROUT = new ITINERARY[N];

    char choice;
    cout << "Do you want to load previous data? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') 
    {
        loadDataFromFile(ROUT, N);
    }
    else 
    {
        inputItineraries(ROUT, N);
    }

    sortItineraries(ROUT, N);
    
    saveDataToFile(ROUT, N);


    string location;
    cout << "Enter the location: ";
    cin >> location;
    printItineraries(ROUT, N, location);

    delete[] ROUT;

    return 0;
}


