#include <vector>
#include <string>
#include <iostream>
using namespace std;

class CCV {
private:
        struct credit_card { 
                string number, date;
        } m_card;
        enum service_provider {
                AIRLINE1 = 1,
                AIRLINE2 = 2,
                TnE = 3,
                VISA = 4,
                MASTERCARD = 5,
                OTHER_BANK = 6,
                OIL = 7,
                TELCOM = 8,
                OTHER = 9
        };
public:
        CCV(const string &num = "0000000000000000", const string &date = "0000"): 
                                                        m_card {num, date} {} 
        
        
        bool check_input(const string &input)
        {       
                for (const auto i: input) 
                        if ((i > 57) || (i < 48))
                                return false;
                        else
                                continue;
                
                return true;
        }
        
        bool set_card_number(const string &num)
        {       
                if ((num.size() == 16) && (check_input(num))) {
                        m_card.number = num;
                        return true; 
                } else {
                        return false;
                }
        }

        string get_card_number(void) const 
        {
                return m_card.number;
        }

        bool set_card_date(const string &date) 
        {
                if ((date.size() == 4) && (check_input(date))) {
                        m_card.date = date;
                        return true;
                } else {
                        return false;
                }
        }

        string get_card_date(void) const
        {
                return m_card.date;
        }
        
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

        bool algo_lohn(vector<short> &digits)
        {
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

        bool validate_card(void)
        {
                vector<short> digits = stov(get_card_number());

                return algo_lohn(digits);
        }

        void service_provider_info(void)
        {
                cout << "Service provider: ";

                char c = m_card.number.front();
                short d = stoi(&c);
                switch (d) {
                case AIRLINE1:
                        cout << "AIRLINE1" << endl;
                        break;
                case AIRLINE2: 
                        cout << "AIRLINE2" << endl;
                        break;
                case TnE:
                        cout << "Travel and Expense" << endl;
                        break;
                case VISA:
                        cout << "VISA" << endl;
                        break;
                case MASTERCARD:
                        cout << "MASTERCARD" << endl;
                        break;
                case OTHER_BANK:
                        cout << "Bank" << endl;
                        break;
                case OIL:
                        cout << "Oil company" << endl;
                        break;
                case TELCOM:
                        cout << "TELCOM" << endl;
                        break;
                case OTHER:
                        cout << "Custom" << endl;
                        break;
                }
        }

        void card_info(void)
        {
                cout << "Bank's ID number: " << get_card_number().substr(0, 6) << endl;
                cout << "Account's ID number: " << get_card_number().substr(6, 9) << endl;
                cout << "Control digit: " << get_card_number().substr(15, 1) << endl;
        }

        void validation_info(void)
        {
                if (!validate_card()) {
                        cout << "\nValidation failed!" << endl;
                } else {
                        cout << "\nValidation passed!" << endl;
                        service_provider_info();
                        card_info();
                }

        }

        short check_date(short mt, short yr)
        {
                short m = stoi(get_card_date().substr(0, 2));
                short y = stoi(get_card_date().substr(2, 2));

                if (y - yr < 0) 
                        return -1;
                else if ((y - yr) == 0 && (m - mt >= 0)) 
                        return (m - mt);
                else
                        return (y - yr) * 12 + (m - mt);          
        }

        short option(void)
        {
                string option;
                cin >> option;
                if ((option.size() == 1) && (check_input(option)))
                        return stoi(option);
                else   
                        return 0;
        }
};

void about(void)
{
        cout << "\nCredit card validator" << endl << "Made by Jan Kuliga (3 EiT PL)" <<
        endl << "Tutor: dr inż. Rafał Frączek\n" << endl;  
}

void menu_text(void)
{
        cout << "\nMenu" << endl << "What would you like to do? Type in appropriate number.\n" << 
        endl << "1. Validate credit card" << endl << "2. Check for how long your credit card" 
                " will be valid" << endl << "3. About" << endl << "4. Exit\n" << endl;
}

int main(void)
{
        about();

        string str;
        unsigned short option;
        class CCV user_card;

        while (1) {
                menu_text();
                option = user_card.option();
                switch (option) {
                default:
                        cout << "Invalid input!" << endl;
                        break;
                case 1:
                        cout << "Enter credit card's number: ";
                        cin >> str;
                        if (user_card.set_card_number(str))
                                user_card.validation_info();
                        else 
                                cout << "Invalid card number!" << endl;
                        break;
                case 2:
                        cout << "Enter credit card's date (numbers only): ";
                        cin >> str;
                        if (user_card.set_card_date(str))
                                cout << user_card.check_date(1, 21);
                        else 
                                cout << "Invalid card's date!" << endl;
                        break;
                case 3:
                        about();
                        break;
                case 4:
                        return 0;              
                }
        }
}