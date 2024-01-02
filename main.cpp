#include <iostream>
#include <fstream>

using namespace std;

class Point {
private:
    double x;
    double y;
    double z;

public:
    // Constructors
    Point() : x(0.0), y(0.0), z(0.0) {}
    Point(double xCoord, double yCoord, double zCoord) : x(xCoord), y(yCoord), z(zCoord) {}

    // Member functions for data input
    void inputPointData() {
       cout << "Enter x-coordinate: ";
       cin >> x;

        cout << "Enter y-coordinate: ";
        cin >> y;

        cout << "Enter z-coordinate: ";
        cin >> z;
    }

    // Member function for data display
    void displayPointData() const {
        cout << "Point coordinates: (" << x << ", " << y << ", " << z << ")\n";
    }

    // Accessors for member variables
    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    double getZ() const {
        return z;
    }

    // Save data to a file
    void saveToFile(const std::string& filename) const {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            outFile << x << " " << y << " " << z << endl;
            outFile.close();
           cout << "Data saved to file: " << filename << endl;
        }
        else {
            cerr << "Unable to open file for writing." <<endl;
        }
    }

    // Load data from a file
    void loadFromFile(const std::string& filename) {
      ifstream inFile(filename);
        if (inFile.is_open()) {
            inFile >> x >> y >> z;
            inFile.close();
           cout << "Data loaded from file: " << filename << endl;
        }
        else {
            cerr << "Unable to open file for reading." << endl;
        }
    }
};

int main() {
    Point point;

    // Input point data
    point.inputPointData();

    // Display point data
    cout << "\nPoint Information:\n";
    point.displayPointData();

    // Save data to a file
    point.saveToFile("point_data.txt");

    // Load data from a file
    Point loadedPoint;
    loadedPoint.loadFromFile("point_data.txt");

    // Display loaded point data
    cout << "\nLoaded Point Information:\n";
    loadedPoint.displayPointData();

    return 0;
}