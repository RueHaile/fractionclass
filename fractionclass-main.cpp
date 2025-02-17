/** L2: virtual pets
Rue Haile
username: hailer
Purpose: To learn about the implementation of OOP principles in C++.

Acknowledgements:
Modified from original stub code written by Dr. Jan Pearce.
Fun fact source: Nationwide Pet Insurance. (n.d.). Fun facts about pets. Retrieved February 13, 2025,
from https://www.petinsurance.com/healthzone/ownership-adoption/pet-ownership/pet-owner-topics/fun-facts-about-pets/
Further reference: geeksforgeeks.org

*/


#include <iostream>
#include <string>
#include <random>
using namespace std;

// This class is used to generate a random number in a given range
class GetRandom {
    /** Uses <random> from C++11 to return a random integer in range [0..size-1] */
public:
    GetRandom(int size) : gen(rd()), intdist(0, size - 1) {} // Fix range to be 0-based
    int get_random() { return intdist(gen); } // Generate a new random number each call

private:
    random_device rd;
    mt19937 gen;
    uniform_int_distribution<int> intdist;
}; // end of GetRandom

class FunFact {    // This class is used to generate a random fun fact about pets
private:
    string fun[28] = { //The following are fun facts about pets from Nationwide Pet Insurance.
        "Dogs only sweat from the bottoms of their feet, the only way they can discharge heat is by panting.", // Retrieved February 13, 2025, from https://www.petinsurance.com/healthzone/ownership-adoption/pet-ownership/pet-owner-topics/fun-facts-about-pets/
        "Dogs have about 100 different facial expressions, most of them made with the ears.",
        "Dogs have about 10 vocal sounds.",
        "Dogs do not have an appendix.",
        "There are more than 350 different breeds of dogs worldwide.",
        "Dalmatians are born spotless: at first pure white, their spots develop as they age.",
        "Contrary to popular belief, dogs aren’t color blind; they can see shades of blue, yellow, green, and gray.",
        "Most domestic dogs are capable of reaching speeds up to about nineteen miles per hour when running at full speed.",
        "Using their swiveling ears like radar dishes, experiments have shown that dogs can locate the source of a sound in 6/100ths of a second.",
        "Domesticated for more than 10,000 years, the dog was one of the first animals domesticated by humans.",
        "Cats do not have sweat glands.",
        "A cat can jump as much as seven times its height.",
        "Cats have five toes on each front paw, but only four toes on each back paw.",
        "Cats have over one hundred vocal sounds, while dogs only have about ten.",
        "A pack of kittens is called a kindle, while a pack of adult cats is called a clowder.",
        "An adult cat can run about 12 miles per hour, and can sprint at nearly thirty miles per hour.",
        "A cat's tongue is scratchy because it's lined with papillae—tiny elevated backwards hooks that help to hold prey in place.",
        "The nose pad of each cat has ridges in a unique pattern not unlike a person's fingerprints.",
        "Cats' bodies are extremely flexible; the cat skeleton contains more than 230 bones (a human has about 206), and the pelvis and shoulders loosely attach to the spine.",
        "Cats have better memories than dogs. Tests conducted by the University of Michigan concluded that while a dog's memory lasts no more than 5 minutes, a cat's can last as long as 16 hours—exceeding even that of monkeys and orangutans.",
        "To survive, every bird must eat at least half its own weight in food each day.",
        "A bird's heart beats 400 times per minute while they are resting.",
        "Americans own more than 60 million pet birds.",
        "Larger parrots such as the macaws and cockatoos live more than 75 years.",
        "Many hamsters only blink one eye at a time.",
        "Iguanas are able to hold their breath for up to 30 minutes.",
        "A garter snake can give birth to 85 babies.",
        "Ferrets are currently the third most popular pet in the US."
    };
public:
    // Sets a fun fact based on the provided index
    string set_fun_fact(int index) {
        return fun[index];
    }

    // Gets a random fun fact
    string get_random_fun_fact() {
        GetRandom random(28); // Create a GetRandom object with size 28
        int index = random.get_random(); // Get a random index
        return set_fun_fact(index); // Return the fun fact at the random index
    }
};

// Define the Pet class
class Pet {
private:
    string name;
    string species;
    string favorite_toy;
    int hunger_level; // Hunger level of the pet

public:
    // Constructor to initialize the hunger level
    Pet() : hunger_level(5) {}

    // Prompts user to enter the pet's name
    void set_name() {
        cout << "What is your pet's name? ";
        cin >> name;
    }
    // Returns the pet's name
    string get_name() { return name; }

    // Prompts user to enter the pet's species
    void set_species() {
        cout << "What species is your pet? ";
        cin >> species;
    }
    // Returns the pet's species
    string get_species() { return species; }

    // Prompts user to enter the pet's favorite toy
    void set_toy() {
        cout << "What's your pet's favorite toy (ball, slime, tweety)? ";
        cin >> favorite_toy;
    }
    // Returns the pet's favorite toy
    string get_toy() { return favorite_toy; }

    // Sets the pet's hunger level
    void set_hunger_level() {
        cout << "Set how hungry your pet is (from 1-10, where 1 is starving and 7 and above is full): ";
        cin >> hunger_level;
    }
    // Returns the pet's hunger level
    int get_hunger_level() { return hunger_level; }

    // Feeds the pet and increases its hunger level
    void feed() {
        if (hunger_level < 7) {
            cout << "Feeding" << name << endl;
            cout << name << " is now less hungry." << endl;
        }
        else {
            cout << name << " is already full!" << endl;
        }
    }

    // Displays the pet's information
    void display_info() {
        cout << "Pet's name: " << get_name() << endl;
        cout << "Pet's species: " << get_species() << endl;
        cout << get_name() << "'s favorite toy: " << get_toy() << endl;
    }

    // Gets a random fun fact related to the pet
    void get_fun_fact(FunFact& funFact) {
        cout << "Did you know? " << funFact.get_random_fun_fact() << endl;
    }
};

class Owner {   // Define the Owner class
private:
    string time_of_day;
    string colour;
    string name;
    int age;

public:
    // Prompts user to enter their name
    void set_name() {
        cout << "Hey there! What's your name? ";
        cin >> name;
    }
    // Returns the owner's name
    string get_name() { return name; }

    // Prompts user to enter their age
    void set_age() {
        cout << "Nice to meet you, " << name << "! How young are you? ";
        cin >> age;
    }
    // Returns the owner's age
    int get_age() { return age; }

    // Prompts user to enter the time of day
    void set_time_of_day() {
        cout << "What time of day is it (M for Morning, N for Noon, N for Night)? ";
        cin >> time_of_day;
    }
    // Returns the time of day
    string get_time_of_day() { return time_of_day; }

    // Prompts user to enter their favorite color
    void set_color() {
        cout << "What's your favorite color? ";
        cin >> colour;
    }
    // Returns the owner's favorite color
    string get_color() { return colour; }

    // Feeds the pet by calling the pet's feed method
    void feed_pet(Pet& pet) {
        pet.feed();
    }

    // Displays the owner's information
    void display_info() {
        cout << "Owner's name: " << get_name() << endl;
        cout << "Owner's age: " << get_age() << endl;
        cout << "Current time of day: " << get_time_of_day() << endl;
        cout << "Favorite color: " << get_color() << " (which is also your pet's color!)" << endl;
    }
};

int main() {
    Owner owner1;
    Pet pet1;
    FunFact fun_facter;

    // Ensure all setters are called
    owner1.set_name();
    owner1.set_age();
    owner1.set_time_of_day();
    owner1.set_color();

    pet1.set_name();
    pet1.set_species();
    pet1.set_toy();

    owner1.display_info();
    pet1.display_info();
    pet1.set_hunger_level();
    owner1.feed_pet(pet1);  // Owner feeds the pet

    // Pet gets a random fun fact
    pet1.get_fun_fact(fun_facter);

    return 0;
} // end of main