#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct credit_card {
        unsigned int number;
        vector<unsigned short> digits;
};

enum service_provider {
        AIRLINE1 = 1,
        AIRLINE2 = 2,
        TnE = 3,
        VISA = 4,
        MASTERCARD = 5,
        OTHER_BANK = 6,
        OIL = 7,
        TELECOMMUNICATIONS = 8,
        OTHER = 9
};

class CCV {
private:
        unsigned int m_number;
public:
        CCV(const unsigned int &num = 0): m_number(num) {} 
        
        void set_card_number(const unsigned int &num)
        {
                m_number = num; 
        }

        unsigned int get_card_number(void) const 
        {
                return m_number;
        }

}


int main(void)
{

}