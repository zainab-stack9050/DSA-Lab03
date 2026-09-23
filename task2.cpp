#include <iostream>
#include <string>
using namespace std;

class StringPool {
private:
    string* stringPool;   //dynamic array 
    int currentSize;     //current number of strings
    int maxSize;          //maximum pool size

public:
    //constructor
    StringPool(int size = 5) {
        maxSize = size;
        currentSize = 0;
        stringPool = new string[maxSize];}

    //releases the dynamically allocated array
    ~StringPool() {
        delete[] stringPool;}

    //adding string to pool
    void addString(const string& str) {
        if (currentSize < maxSize) {
            stringPool[currentSize] = str;
            currentSize++;
            cout << "\"" << str << "\" added to the pool.\n";
        } else {
            cout << "Pool is full. Cannot add \"" << str << "\".\n";
        }
    }

    //removing a string without freeing its memory
    void removeString(int index) {
        if (index >= 0 && index < currentSize) {
            cout << "\"" << stringPool[index]
                 << "\" removed from the pool.\n";

            //shifting strings to the left
            for (int i = index; i < currentSize - 1; i++) {
                stringPool[i] = stringPool[i + 1]; }
            currentSize--;

            //this shows the memory leak
        } else {
            cout << "Invalid index.\n"; } }

    //displays the current status of pool 
    void displayPool() const {
        cout << "\n--- Pool Status ---\n";
        if (currentSize == 0) {
            cout << "Pool is empty.\n";
            return;
        }

        for (int i = 0; i < currentSize; i++) {
            cout << "Index " << i << ": "
                 << stringPool[i] << endl;
        }

        cout << "Current size: " << currentSize << endl;
        cout << "Maximum size: " << maxSize << endl;}
};

int main() {
    StringPool pool;

    // Adding strings
    pool.addString("Car");
    pool.addString("Bike");
    pool.addString("Bus");
    pool.addString("room");
    pool.addString("Ali");

    pool.displayPool();

    // Remove strings
    cout << "\nRemoving strings...\n";
    pool.removeString(4);  // Remove Ali
    pool.removeString(3);  // Remove room

    pool.displayPool();
    cout << "\nMemory management:\n";
    cout << "The StringPool destructor uses delete[] to release the dynamically allocated string array.\n";

    return 0;
}