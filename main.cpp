#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct credit_card {
        string number, date;
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

bool validate_input(const string &input)
        {
                for (const auto i: input) 
                        if ((i > 57) && (i < 48))
                                return false;
                        else
                                continue;
                
                return true;
        }


class CCV {
private:
        struct credit_card m_card;
public:
        CCV(const string &num = "0000000000000000", const string &date = "0000"): 
                                                        m_card{num, date} {} 
        
        void set_card_number(const string &num)
        {       
                if ((num.size() == 16) && (validate_input(num)))
                        m_card.number = num; 
                else
                        cout << "Invalid input!" << endl;
        }

        string get_card_number(void) const 
        {
                return m_card.number;
        }

        void set_card_date(const string &date) 
        {
                if ((date.size() == 4) && (validate_input(date)))
                        m_card.date = date;
                else
                        cout << "Invalid input!" << endl;
        }

        string get_card_date(void) const
        {
                return m_card.date;
        }
//private:
        vector<short> stov(const string &str)
        {
                vector<short> vec;
                for (const auto i: str)
                        vec.push_back(i - '0');
                
                return vec;
        }

        unsigned short vec_sum(const vector<short> &vec)
        {
                unsigned short sum = 0;
                for (const auto i: vec)
                        sum += vec[i];
                
                return sum;
        }

        bool algo_lohn(void)
        {
                vector<short> digits = stov(get_card_number());

                bool is_odd = true;
                for (const auto i: digits)
                        if ((is_odd) && (digits[i] > 4)) {
                                digits[i] *= 2;
                                digits[i] = 1 + digits[i] % 10;
                                is_odd = false;
                        } else if ((is_odd) && (digits[i] < 5)) {
                                digits[i] *= 2;
                                is_odd = false;
                        } else if (!is_odd) {
                                is_odd = true;
                        }
                
                unsigned short sum = vec_sum(digits);
                if (sum % 10)
                        return false;
                else 
                        return true;
        }
};

void menu(void)
{
        cout << "Menu" << endl << "What would you like to do? Type in appropriate number." << 
        endl << "1. Validate credit card" << endl << "2. Check for how long your credit card" 
                " will be valid" << endl << "4. About" << endl << "5. Exit" << endl;
}

int main(void)
{
        class CCV user_card;
        string str;

        cout << "Credit card validator" << endl << "Made by Jan Kuliga (3 EiT PL)" <<
        endl << "Tutor: dr inż. Rafał Frączek" << endl;  

        menu();


        
        cin >> str;
        user_card.set_card_number(str);
        
        cout << "Menu" << endl << "Enter your credit card's number here: " << endl;
        cin >> str;
        user_card.set_card_number(str);

        class CCV my_card("4874742066698715", "0922");
        //class CCV example("6111111111111116", "0922");
        bool check = my_card.algo_lohn();
        //bool check = example.algo_lohn();

        //example.panel();
        if (check)
                cout << "sztos" << endl;
        else 
                cout << "not sztos" << endl;
        //return 0;



}