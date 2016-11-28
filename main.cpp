#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

using namespace std;

class Logger {
    public:
    Logger (string Blargh){
    theFile.open (Blargh.c_str(), ios::app); //opens file that logger logs to
}
        void writeTotheFile (string Blargh){
            time_t t = time (0);
            struct tm *  now = localtime ( & t );
            time_t rawtime;
            struct tm * timeinfo;
            char buffer[50];
            time (&rawtime);
            timeinfo = localtime (&rawtime);
            strftime(buffer, 80, "%d-%m-%Y %I:%M:%S", timeinfo);
            std::string str (buffer); //gets current time
            theFile << str << "," << Blargh <<endl; //makes new row in file with commas separating columns
}
~Logger(){
    theFile.close();//Closes file after ending Logger class
}
private:
    ofstream theFile;

};
int main( int argc, char* argv[] ){
    Logger Blargh ("ItsmyLogger.csv");
    Blargh.writeTotheFile ("I made my own");//Log to CSV file
    return 0;
}
