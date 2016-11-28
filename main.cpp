#include <iostream>
#include <fstream>

#include <ctime>

#include <string>

using namespace std;

class Logger {
    public:
    Logger (string Log){
    myfile.open (Log.c_str(), ios::app); //opens file
}
        void writeTomyFile (string Log){
            time_t t = time (0);
            struct tm *  now = localtime ( & t );
            time_t rawtime;
            struct tm * timeinfo;
            char buffer[80];
            time (&rawtime);
            timeinfo = localtime (&rawtime);
            strftime(buffer, 80, "%d-%m-%Y %I:%M:%S", timeinfo);
            std::string str (buffer); //gets current time
            myfile << str << "," << Log <<endl; //new row with commas separating columns
}
~Logger(){
    myfile.close();//Closes file after ending Logger class
}
private:
    ofstream myfile;

};
int main( int argc, char* argv[] ){
    Logger Log ("exampleLogger.csv");
    Log.writeTomyFile ("I hate this");//Log to CSV file
    return 0;
}
