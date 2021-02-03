#include <iostream>
#include <vector>
#include <string>
#include "lib.h"
#include <map>
using namespace std;


class Elevator {
private:
        map<int, unsigned int> m_passengers;
        vector<unsigned int> m_status;
        load m_load;
        floor m_floor;
        direction m_dir;
public:
        Elevator(const map<int, unsigned int> &passengers, const vector<unsigned int> status,
                                                        const load &load, const floor &floor):
                m_passengers(passengers), m_status(status), m_load(load), m_floor(floor),
                m_dir(_NONE_) {};
        
        void set_loadcur(const int &loadcur)
        {
                m_load.cur = loadcur;
        }

        int get_loadcur(void) const 
        {
                return m_load.cur;
        }

        void set_floorcur(const int &floorcur)
        {
                m_floor.cur = floorcur;
        }

        int get_floorcur(void) const 
        {
                return m_floor.cur;
        }

        void set_dir(const enum direction &dir)
        {
                m_dir = dir;
        }

        enum direction get_dir(void) const 
        {
                return m_dir;
        }

        
};       


int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}