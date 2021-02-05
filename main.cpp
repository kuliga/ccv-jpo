#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

struct credit_card {
        string number;
        string cvc;
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
        struct credit_card m_card;
public:
        CCV(const string &num = "0", const string &cvc = "00/00"): 
                                                m_card{num, cvc} {} 
        
        void set_card_number(const string &num)
        {
                m_card.number = num; 
        }

        string get_card_number(void) const 
        {
                return m_card.number;
        }

        void set_card_cvc(const string &cvc) 
        {
                m_card.cvc = cvc;
        }

        string get_card_cvc(void) const
        {
                return m_card.cvc;
        }
private:
        vector<short> num_to_vec(void)
        {
                vector<short> num_vec;
                for (const auto i: m_card.number)
                        num_vec.push_back(i - '0');
                
                return num_vec;
        }

        

}


int main(void)
{

}