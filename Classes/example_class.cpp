/* Simple code with classes to see Inheritance
 * Protected and Public
 * Operant overload
 * Outside class function declaration
 * Constructors
 * Support: https://www.cplusplus.com/doc/tutorial/classes/ */

#include <stdio.h>

#include <iostream>

using namespace std;

// Main class
class footballer {

    // Cannot be directly accessed but can be inherited
    protected:
        char id[10], name[30];
		int score;

    public:
		// Constructor
        footballer() {
            score = 100;
        }
	// Set up player
    void getid() {
        cout << "input Player's id: ";
        cin >> id;
        cout << "input Player's name: ";
        cin >> name;
    };
	// Get post match score
    void get_score() {
        std::cout << score << std::endl;
    };
    int operator + (const footballer & );

};

// Sum overload
int footballer::operator + (const footballer & param) {
    footballer temp;
    temp.score = score + param.score;
    return temp.score;
}

// Goalkeeper
class goalkeeper: public footballer {
    int save;
    int loss;
    public:
        void performance() {
            getid();
            cout << "\n Saved Goals \n";
            cin >> save;
            save = save * 25;
            cout << "\n Goals Conceided \n";
            cin >> loss;
            loss = loss * 50;
            score = score + save - loss;
            if (score < 0)
                score = 0;
        }
};

// Defender
class defender: public footballer {
    int defend;
    int loss;
    public:
        void performance() {
            getid();
            cout << "\n Successful Clearances \n";
            cin >> defend;
            defend = defend * 25;
            cout << "\n Errors \n;";
            cin >> loss;
            loss = loss * 70;
            score = score + defend - loss;
            if (score < 0)
                score = 0;
        }
};

// Midfield
class midfielder: public footballer {
    int passing;
    int mispass;
    public:
        void performance() {
            getid();
            cout << "\n Key passes \n";
            cin >> passing;
            passing = passing * 50;
            cout << "\n Lost possesion \n;";
            cin >> mispass;
            mispass = mispass * 25;
            score = score + passing - mispass;
            if (score < 0)
                score = 0;
        }

};

// Striker
class striker: public footballer {
    int goal;
    int loss;
    public:
        void performance() {
            getid();
            cout << "\n Goal scored? \n";
            cin >> goal;
            goal = goal * 50;
            cout << "\n Chances missed \n;";
            cin >> loss;
            loss = loss * 25;
            score = score + goal - loss;
            if (score < 0)
                score = 0;
        }
};

int main() {
    goalkeeper Oblak;
    Oblak.performance();
    Oblak.get_score();

    striker Messi;
    Messi.performance();
    Messi.get_score();

    int total_score = Messi + Oblak;
    std::cout << total_score << std::endl;
    return 0;
}
