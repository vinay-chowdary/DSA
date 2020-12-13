#include "iostream"
#include "chrono"
using namespace std;
using namespace chrono;
class Timer
{
    time_point<system_clock> start, end;
    duration<float> dur;

public:
    Timer()
    {
        start = high_resolution_clock::now();
    }
    ~Timer()
    {
        end = high_resolution_clock::now();
        dur = end - start;
        cout << dur.count() * 1000 << "ms\n";
    }
};