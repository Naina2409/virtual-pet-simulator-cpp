#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;
class Pet;

void petTrivia(Pet* myPet);
void petMemoryMatch(Pet* myPet);
void luckySpin(Pet* myPet);
void guessMyFavorite(Pet* myPet);

class Pet
{
protected:
    string name;
    string color;
    int hunger;
    int happiness;
    int energy;
    int cleanliness;

public:
    Pet(string &n, string &clr, int h, int hp, int e, int c)
    {
        name = n;
        color = clr;
        hunger = h;
        happiness = hp;
        energy = e;
        cleanliness = c;
    }

    virtual void feedPet()
    {

        hunger = max(0, hunger - 15); // Reduce hunger when fed
        happiness = min(100, happiness + 10);
        energy = min(100, energy + 10);
        cout << name << " eats food and feels better!\n";
    }

    virtual void playWithPet()
    {
        if (energy < 10)
        {
            cout << name << " is too tired to play.\n";
            return;
        }
        happiness += 10;
        energy -= 10;
        cleanliness -= 10;
        cout << name << " plays happily!\n";
    }

    virtual void PutToSleep()
    {
        energy += 30;
        if (energy > 100)
            energy = 100;
        cout << name << " takes a nap.\n";
    }

    virtual void cleanPet()
    {
        cleanliness = 100;
        cout << name << " is now clean!\n";
    }

    virtual string getType() const
    {
        return "Pet";
    }

    string getMood() const
    {
        if (happiness < 20 || energy < 20 || hunger > 80)
            return "Sad :(";
        if (happiness > 70 && energy > 50 && hunger < 30)
            return "Happy :) ";
        return "Okay ^_^";
    }
    virtual void talkWithPet() const = 0;

    string checkHungryStatus() const
    {
        if (hunger > 80)
            return "Starving";
        if (hunger > 50)
            return "Hungry";
        if (hunger > 20)
            return "Satisfied";
        return "Full";
    }

    virtual void showStatus() const
    {
        cout << "\n----- " << name << " the " << getType() << " -----\n";
        if(getType() == "Cat"){
        cout<< R"(
       \`*-.
        )  _`-.
       .  : `. .
       : _   '  \
       ; ` _.   `-._
       `-.-'          `-.
         ;       `       `.
         :.       .        \
         . \  .   :   .-'   .
         '  `+.;  ;  '      :
         :  '  |    ;       ;-.
         ; '   : :-:     _.* ;
      .' /  .' ; .`- +'  `'
      `*-*   `*-*  `*-*'
            )"<< "\n";
        }

        if(getType() == "Dog")
        {
            cout<< R"(
         .--.             .---.
        /:.  '.         .' ..  '._.---.
       /:::-.  \.-"""-;` .-:::.     .::\
      /::'|  `\/  _ _  \'   `\:'   ::::|
  __.'    |   /  (o|o)  \     `'.   ':/
 /    .:. /   |   ___   |        '---'
|    ::::'   /:  (._.) .:\
\    .='    |:'        :::|
 `""`       \     .-.   ':/
             '---`|I|`---'
                  '-'
                  )"<< "\n";
        }

        if(getType() == "Rabbit")
        {
            cout<< R"(
                     /\    .-""/
                    /  ; .'  .'
                   :   :/  .'
                    \  ;-.'|
       .--""""--../     `. \
     .'           .'    `o  \
    /                    `   ;
   :                  \      :
 .-;        -.         `..-'
:  ;          \     ,   ;
'._:           ;   :   (
    \/  .__    ;    \   `-.
     ;     "-,/..--"`-.._)
     '""--.._:
            )"<< "\n";

        }

        if(getType() == "Parrot")
        {
            cout<< R"(
        .------.
       /  ~ ~   \,------.      ______
     ,'  ~ ~ ~  /  (@)   \   ,'      \
   ,'          /`.    ~ ~ \ /         \
 ,'           | ,'\  ~ ~ ~ X     \  \  \
'  ,'          V--<       (       \  \  \
 ,'               (vv      \/\  \  \  |  |
'  ,'   /         (vv   ""    \  \  | |  |
_,'    /   /       vv   """    \ |  / / /
  \,'   /  |     vv          / / / / /
      \/   / |  | \         / /,',','
         \/\_^  |  \       /,'',','\
                `-^.>./  ' ,'   \
                        // //---'      |
      ===============(((((((=================
                                 | \ \  \
                                 / |  |  \
                                / /  / \  \
                                `.     |   \
            )"<< "\n";
        }

        cout << "Hunger: " << hunger << " (" << checkHungryStatus() << ")\n";
        cout << "Happiness: " << happiness << "\n";
        cout << "Energy: " << energy << "\n";
        cout << "Cleanliness: " << cleanliness << "\n";
        cout << "Mood: " << getMood() << "\n";
    }

    void updateStats()
    {
        hunger = min(100, hunger + 5);         // Hunger increases over time
        happiness = max(0, happiness - 2);     // Happiness decreases slightly each cycle
        energy = max(0, energy - 3);           // Energy decreases over time
        cleanliness = max(0, cleanliness - 1); // Cleanliness decreases over time
    }
    virtual void triggerRandomEvent() {
    // Default has no events, or could be overridden
}


};
class Dog : public Pet
{
public:
    Dog(string &n, string &clr, int h, int hp, int e, int c)
        : Pet(n, clr, h, hp, e, c) {}

    void playWithPet() override
    {
        if (energy < 15)
        {
            std::cout << name << " (the dog) is too tired to fetch.\n";
            return;
        }
        happiness += 15;
        energy -= 15;
        cleanliness -= 10;
        cout << name << " happily plays fetch!\n";
    }
    void talkWithPet() const
    {
        vector<string> dogTalks = {
            "Woof! Let's go outside!",
            "I missed you!",
            "Can I chase the ball?",
            "You smell like treats!",
            "You're my favorite human!"};
        cout << name << " the dog says: \"" << dogTalks[rand() % dogTalks.size()] << "\"\n";
    }

    string getType() const override
    {
        return "Dog";
    }
    void triggerRandomEvent() override {
    int chance = rand() % 100;
    if (chance < 25) {
        vector<string> events = {
            "\n\nYour dog found an old bone! Happiness +10.",
            "\n\nA loud vacuum scared your dog. Happiness -10.",
            "\n\nYour dog rolled in mud. Cleanliness -20.",
            "\n\nYour dog barked at a squirrel for 10 minutes! Energy -10, Happiness +5.",
            "\n\nYour dog took a surprise nap. Energy +15."
        };
        int i = rand() % events.size();
        cout << "\n[Random Dog Event] " << events[i] << "\n";

        switch (i) {
        case 0: happiness = min(100, happiness + 10); break;
        case 1: happiness = max(0, happiness - 10); break;
        case 2: cleanliness = max(0, cleanliness - 20); break;
        case 3: energy = max(0, energy - 10); happiness = min(100, happiness + 5); break;
        case 4: energy = min(100, energy + 15); break;
        }
    }
}

};
class Cat : public Pet
{
public:
    Cat(string &n, string &clr, int h, int hp, int e, int c)
        : Pet(n, clr, h, hp, e, c) {}

    void playWithPet() override
    {
        if (energy < 15)
        {
            cout << name << " (cat) ignores you, Too tired.\n";
            return;
        }
        happiness += 15;
        energy -= 15;
        cleanliness -= 5;
        cout << name << " happily plays with a toy mouse!\n";
    }
    void talkWithPet() const override
    {
        vector<string> catTalks = {
            "Meow. Feed me.",
            "I'll sit on your keyboard.",
            "Pet me. Now stop.",
            "I knocked something off the shelf. On purpose.",
            "You're lucky I like you."};
        cout << name << " the cat says: \"" << catTalks[rand() % catTalks.size()] << "\"\n";
    }

    string getType() const override
    {
        return "Cat";
    }
    void triggerRandomEvent() override {
    int chance = rand() % 100;
    if (chance < 25) {
        vector<string> events = {
            "\n\nYour cat knocked over a plant. Cleanliness -15.",
            "\n\nYour cat purred on your lap. Happiness +10.",
            "\n\nYour cat scratched the couch. Happiness -5.",
            "\n\nYour cat took a cozy nap in a sunbeam. Energy +10.",
            "\n\nYour cat ignored you completely. Mood unchanged."
        };
        int i = rand() % events.size();
        cout << "\n[Random Cat Event] " << events[i] << "\n";

        switch (i) {
        case 0: cleanliness = max(0, cleanliness - 15); break;
        case 1: happiness = min(100, happiness + 10); break;
        case 2: happiness = max(0, happiness - 5); break;
        case 3: energy = min(100, energy + 10); break;
        case 4: break;
        }
    }
}

};
class Rabbit : public Pet
{
public:
    Rabbit(string &n, string &clr, int h, int hp, int e, int c)
        : Pet(n, clr, h, hp, e, c) {}

    void playWithPet() override
    {
        if (energy < 10)
        {
            cout << name << " is too tired to hop around.\n";
            return;
        }
        happiness += 12;
        energy -= 10;
        cleanliness -= 8;
        cout << name << " hops around happily!\n";
    }

    void talkWithPet() const override
    {
        vector<string> rabbitTalks = {
            "\n\nThump thump! I'm excited!",
            "\n\nGot any carrots? ",
            "\n\nI'll dig a little hole now.",
            "\n\nSoft and fluffy. Like me!",
            "\n\nI'm alert! What was that noise?"};
        cout << name << " the rabbit says: \"" << rabbitTalks[rand() % rabbitTalks.size()] << "\"\n";
    }

    string getType() const override
    {
        return "Rabbit";
    }
    void triggerRandomEvent() override {
    int chance = rand() % 100;
    if (chance < 25) {
        vector<string> events = {
            "\n\nYour rabbit found a carrot in the yard! Hunger -10.",
            "\n\nYour rabbit dug a small hole in the carpet. Cleanliness -10.",
            "\n\nYour rabbit did a happy jump! Happiness +10.",
            "\n\nYour rabbit hid in a corner. Happiness -5.",
            "\n\nYour rabbit nibbled a wire. Energy -5."
        };
        int i = rand() % events.size();
        cout << "\n[Random Rabbit Event] " << events[i] << "\n";

        switch (i) {
        case 0: hunger = max(0, hunger - 10); break;
        case 1: cleanliness = max(0, cleanliness - 10); break;
        case 2: happiness = min(100, happiness + 10); break;
        case 3: happiness = max(0, happiness - 5); break;
        case 4: energy = max(0, energy - 5); break;
        }
    }
}

};
class Parrot : public Pet
{
public:
    Parrot(string &n, string &clr, int h, int hp, int e, int c)
        : Pet(n, clr, h, hp, e, c) {}

    void playWithPet() override
    {
        if (energy < 15)
        {
            cout << name << " (parrot) is too tired to fly.\n";
            return;
        }
        happiness += 15;
        energy -= 15;
        cleanliness -= 5;
        cout << name << " happily flies around!\n";
    }

    void talkWithPet() const override
    {
        vector<string> parrotTalks = {
            "Polly wants a cracker! ",
            "Squawk! I'm the smartest bird!",
            "Tweet-tweet! I'm a parrot! ",
            "Hello! How are you today? ",
            "Did you hear that? I'm a talking parrot!"};
        cout << name << " the parrot says: \"" << parrotTalks[rand() % parrotTalks.size()] << "\"\n";
    }

    string getType() const override
    {
        return "Parrot";
    }
    void triggerRandomEvent() override {
    int chance = rand() % 100;
    if (chance < 25) {
        vector<string> events = {
            "\n\nYour parrot repeated your name! Happiness +10.",
            "\n\nYour parrot made a mess of seeds. Cleanliness -10.",
            "\n\nYour parrot flew in circles joyfully. Energy -10, Happiness +5.",
            "\n\nYour parrot squawked loudly. Happiness -5.",
            "\n\nYour parrot danced to music. Happiness +15."
        };
        int i = rand() % events.size();
        cout << "\n[Random Parrot Event] " << events[i] << "\n";

        switch (i) {
        case 0: happiness = min(100, happiness + 10); break;
        case 1: cleanliness = max(0, cleanliness - 10); break;
        case 2: energy = max(0, energy - 10); happiness = min(100, happiness + 5); break;
        case 3: happiness = max(0, happiness - 5); break;
        case 4: happiness = min(100, happiness + 15); break;
        }
    }
}

};
void playMiniGame(Pet* myPet)
{
    int gameChoice;
    cout << "\nChoose a Mini-Game:\n";
    cout << "1. Pet Memory Match \n";
    cout << "2. Pet Trivia \n";
    cout << "3. Lucky Spin \n";
    cout << "4. Guess My Favorite \n";
    cout << "Choice: ";
    cin >> gameChoice;

    switch (gameChoice)
    {
    case 1:
        petMemoryMatch(myPet);
        break;
    case 2:
        petTrivia(myPet);
        break;
    case 3:
        luckySpin(myPet);
        break;
    case 4:
        guessMyFavorite(myPet);
        break;
    default:
        cout << "Invalid mini-game choice.\n";
    }
}
void runGame()
{
    string type, name, color;
    int hunger, happiness, energy, cleanliness;

    cout<< "         _________________________________________\n";
    cout<< "\n           WELCOME TO VIRTUAL PET SIMULATOR\n";
    cout<< "\n       _________________________________________\n";


    cout << "\nChoose pet type (dog/cat/rabbit/parrot): ";
    cin >> type;
    cin.ignore();

    cout << "Enter your pet's name: ";
    getline(cin, name);

    cout << "Enter the color of your pet: ";
    getline(cin, color);

    cout << "Enter initial stats (0-100):\n";
    cout << "Hunger: ";
    cin >> hunger;
    cout << "Happiness: ";
    cin >> happiness;
    cout << "Energy: ";
    cin >> energy;
    cout << "Cleanliness: ";
    cin >> cleanliness;

    Pet *myPet = nullptr;

    if (type == "dog")
        myPet = new Dog(name, color, hunger, happiness, energy, cleanliness);
    else if (type == "cat")
        myPet = new Cat(name, color, hunger, happiness, energy, cleanliness);
    else if(type == "rabbit")
    myPet = new Rabbit(name, color, hunger, happiness, energy, cleanliness);
    else if (type == "parrot")
    myPet = new Parrot(name, color, hunger, happiness, energy, cleanliness);

    else
    {
        cout << "Invalid pet type. Defaulting to Dog.\n";
        myPet = new Dog(name, color, hunger, happiness, energy, cleanliness);
    }

    int choice;
    while (true)
    {
        myPet->showStatus();
        cout << "\n1. Feed\n2. Play\n3. Sleep\n4. Clean\n5. Talk\n6. Mini-Games\n0. Exit\nChoice: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            myPet->feedPet();
            break;
        case 2:
            myPet->playWithPet();
            break;
        case 3:
            myPet->PutToSleep();
            break;
        case 4:
            myPet->cleanPet();
            break;
        case 5:
            myPet->talkWithPet();
            break;
            case 6:
            playMiniGame(myPet);
            break;

        case 0:
            delete myPet;
            return;
        default:
            cout << "Invalid choice!\n";
        }

        myPet->updateStats();
        myPet->triggerRandomEvent();

        cout << "\n*\n";

    }
}

void petMemoryMatch(Pet* myPet) {
    vector<string> symbols = {"Dog", "Cat", "Rabbit", "Parrot", "Dog", "Cat", "Rabbit", "Parrot"};
    random_shuffle(symbols.begin(), symbols.end());

    vector<bool> matched(8, false);
    int attempts = 5;
    int score = 0;

    while (attempts > 0 && score < 4) {
        while (attempts > 0 && score < 4) {
            char choice;
            cout << "\nDo you want to continue playing the Memory Match Challenge? (y/n): ";
            cin >> choice;

            if (choice == 'n' || choice == 'N') {
                cout << "\nYou exited the Memory Match Challenge early.\n";
                return;
            }
        cout << "\nMemory Grid:\n";
        for (int i = 0; i < 8; ++i) {
            if (matched[i])
                cout << "[" << symbols[i] << "] ";
            else
                cout << "[" << i + 1 << "] ";
        }

        cout << "\nPick two positions to reveal (1-8): ";
        int a, b;
        cin >> a >> b;
        a--; b--;

        if (a == b || a < 0 || a >= 8 || b < 0 || b >= 8 || matched[a] || matched[b]) {
            cout << "Invalid selection. Try again.\n";
            continue;
        }

        cout << "You flipped: " << symbols[a] << " and " << symbols[b] << "\n";

        if (symbols[a] == symbols[b]) {
            cout << "Matched!\n";
            matched[a] = matched[b] = true;
            score++;
        } else {
            cout << "Not a match.\n";
            attempts--;
        }
    }
}

    if (score == 4) {
        cout << "\nYou won the Memory Match Challenge!\n";
        cout << myPet->getType() << " is proud of your brainpower!\n";
        myPet->playWithPet();
    } else {
        cout << "\nChallenge failed. Better luck next time!\n";
    }
}

void petTrivia(Pet* myPet){
    cout << "\nMini-Game: Pet Trivia \n";
    cout << "Answer the following question about your pet species!\n";
    string answer;
    cout << "What do cats like to scratch? (a) Furniture (b) Shoes (c) Walls: ";
    cin >> answer;

    // Simple answer check
    if (answer == "a" || answer == "A")
    {
        cout << "Correct! +10 Happiness!\n";
        myPet->playWithPet();  // Happiness +10
    }
    else
    {
        cout << "Oops, wrong answer! The correct answer was (a) Furniture.\n";
        myPet->updateStats();  // Small penalty
    }
}

void luckySpin(Pet* myPet)
{
    cout << "\nMini-Game: Lucky Spin \n";
    cout << "Spinning the wheel...\n";

    int spin = rand() % 6; // Spin the wheel, 6 outcomes

    if (spin == 0)
    {
        cout << "Wheel landed on +10 Energy! \n";
        myPet->PutToSleep();
    }
    else if (spin == 1)
    {
        cout << "Wheel landed on -5 Cleanliness! \n";
        myPet->updateStats(); // Slight penalty
    }
    else if (spin == 2)
    {
        cout << "Wheel landed on +15 Happiness! \n";
        myPet->playWithPet();
    }
    else if (spin == 3)
    {
        cout << "Wheel landed on -10 Hunger! \n";
        myPet->feedPet();
    }
    else if (spin == 4)
    {
        cout << "Wheel landed on +5 Bonding! \n";
        myPet->talkWithPet();
    }
    else
    {
        cout << "Wheel landed on Nothing. Better luck next time! \n";
    }
}
void guessMyFavorite(Pet* myPet)
{
    cout << "\nMini-Game: Guess My Favorite \n";
    cout << "I have a favorite toy. What is it? (1) Ball (2) Toy Mouse (3) Scratcher: ";
    int guess;
    cin >> guess;

    // Randomly select a correct answer for the pet's favorite toy
    int correct = rand() % 3 + 1;

    if (guess == correct)
    {
        cout << "Correct! I love that toy! +15 Happiness!\n";
        myPet->playWithPet();  // Happiness +15
    }
    else
    {
        cout << "Nope, that's not my favorite. I like the ";
        if (correct == 1) cout << "Ball!";
        else if (correct == 2) cout << "Toy Mouse!";
        else cout << "Scratcher!";
        cout << "\nBetter luck next time! -5 Cleanliness.\n";
        myPet->updateStats();  // Penalty
    }
}



int main()
{
    srand(time(0));
    runGame();
    return 0;
}