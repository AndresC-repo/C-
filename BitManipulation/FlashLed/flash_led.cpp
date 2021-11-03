 #include <stdio.h>
 #include <stdint.h>
 #include <unistd.h>
 #include <iostream>
 
 using namespace std;
 
 void msleep(uint16_t milliseconds)
 {
     // delay
     usleep(milliseconds * 1000);
 }
 
 // print 1 or 0 
 void FlashLed(int& a)
 {
     int out = (a%2) ? 1 : 0;
     cout<<out<<endl;
     a++;
 }
 
 int main()
 {
     static int a = 0;
     cout<<"Start cycle"<< endl;
     while(true){
         FlashLed(a);
         msleep(1000);
     }
     return 0;
 }
