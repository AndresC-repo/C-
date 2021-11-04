/* Time is short int therefore 0xFFFF
*  0x3F = 0011 1111 & with 0x3F
* 
* 
* Struct of time is same size as one int
* despite containing three pieces of information 
*/

#include <iostream>

using namespace std;

struct time {
	// This is the important stuff
    unsigned int seconds: 5;
    unsigned int minutes: 6;
    unsigned int hours: 5;
    // Extra bits to fill 32-int
    unsigned int extra: 16;
	
	// Fucntion to get time
    void set_time(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s / 2;
        extra = 0;
    }
	// Override << operator to print whole struct
    friend ostream & operator << (ostream & os,
        const time & t) {
        os << t.hours << ':' << t.minutes << ':' << t.seconds;
        return os;
    }

};

int main() {
    //declared structure time
    struct time time;
    int integer;
    cout << "Size of normal integer: " << sizeof(integer) << endl;
    cout << "Size of time structure: " << sizeof(time) << endl;

    time.set_time(13, 34, 18);
    cout << "Time is " << time << endl;
    return 0;
}

