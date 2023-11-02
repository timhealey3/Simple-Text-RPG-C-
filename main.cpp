#include <iostream>
#include <cstdlib>
#include <ctime>

struct Player{
    std::string name;
    int health;
    int xp;
    std::string inventory[10];
    int inventoryCount = 0;
};

struct Librarian{
    std::string name;
    std::string riddles[10];
    std::string answers[10];
    std::string ancientBooks[3];
    bool hasMapToLibrary;
};

struct Monster{
    std::string name;
    int health;
    int damage;
};

int main() {
    std::srand(std::time(0));
    Player player;
    player.health = 100;
    Monster troll;
    troll.health = 100;
    troll.damage = 100;
    Librarian eldric = {
        "Eldric",
        {
            "What has keys but can't open locks?",
            "the more you take, the more you leave behind. What am I?",
            "What comes once in a minute, twice in a moment, but never in a thousand years?",
            "What has a heart that doesn't beat?",
            "What comes down but never goes up?",
            "I speak without a mouth and hear without ears. What am I?",
            "What has many keys but can't open a single lock?",
            "What is full of holes but still holds water?",
            "What is so fragile that saying its name breaks it?",
            "What gets wet while drying?"
        },
        {
            "Piano",
            "Steps",
            "M",
            "Artichoke",
            "Rain",
            "An echo",
            "A piano",
            "A sponge",
            "Silence",
            "A towel"
        },
        {"The Book of Shadows", "Mystical Creatures", "Time's Passage"},
        true
    };
    std::cout << "Hey you, your finally awake\n";
    std::cout << "Please enter your name: ";
    std::cin >> player.name;
    std::cout << "Welcome " << player.name << " to Skyrim" << std::endl;

    int choice;
    int nestedChoice;
    bool exploring = true;

    while (exploring == true && player.health > 0)
    {
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "You are in the town of Riverwood, where do you want to go " << player.name << "?" << std::endl;
    std::cout << "1. Riverwood Trading Post" << std::endl;
    std::cout << "2. Riverwood Library" << std::endl;
    std::cout << "3. Riverwood River" << std::endl;
    std::cout << "4. View Player Stats" << std::endl;
    std::cout << "5. Exit Game" << std::endl;
    std::cout << "Please enter your choice: ";
    std::cin >> choice;

    switch(choice) {
        case 1:
            std::cout << player.name << " approaches the trading post... *rustles* " << player.name << " hears some strange noise coming from the woods" << std::endl;
            std::cout << player.name << " decides to go check it out..as " << player.name << " enters the forest, the ground begins to shake and a Troll appears" << std::endl;
            std::cout << player.name << " draws their sword out and the troll begins to charge." << std::endl;
            std::cout << player.name << " can either 1. dodge the charging troll or 2. attack the troll back" << std::endl;
            int fightChoice;
            std::cin >> fightChoice;
            if (fightChoice == 1)
            {
                std::cout << player.name << " dodges the troll, the troll stumbles on past" << std::endl;
                std::cout << player.name << " can either 1. strike the vulnerable troll 2. try to communicate that you are peaceful" << std::endl;
                int dodgeChoice;
                std::cin >> dodgeChoice;
                if (dodgeChoice == 2)
                {
                    std::cout << "'Hey!, I am " << player.name << " and I am peaceful!'...the troll doesnt understand english and smacks " << player.name << << " down" << std::endl;
                    std::cout << "The light fades to black as the Troll stands over you" << std::endl;
                    player.health -= troll.damage;
                }
                
            }
            break;
        case 2:
        {
            std::cout << player.name << " opens the doors to the small library, an old librarian is dusting the books in the far corner" << std::endl;
            std::cout << player.name << " greats the librarian, the librarian looks up and introduces themselves" << std::endl;
            std::cout << "Hello, I am Eldric, would you like to solve a riddle? They are lots of fun!" << std::endl;
            int riddleIndex = std::rand() % 5;
            std::cout << eldric.name << " asked " << eldric.riddles[riddleIndex] << std::endl;
            std::string playerAnswer; 
            std::cin >> playerAnswer;

            if (playerAnswer == eldric.answers[riddleIndex])
            {
                std::cout << "Correct! Eldric seems pleased. He heals you 10 health and gives you the Book of Shadows" << std::endl;
                player.health += 10;
                player.inventory[player.inventoryCount++] == "Book of Shadows";
            } 
            else 
            {
                std::cout << "Incorrect. Eldric slaps you...you lose 10 health" << std::endl;
                player.health -= 10;
            }
            if (eldric.hasMapToLibrary && rand() % 100 < 35)
            {
                std::cout << eldric.name << " discreetly hands you a map of the Riverwood library" << std::endl;
                player.inventory[player.inventoryCount++] = "Map of the Riverwood Library";
                eldric.hasMapToLibrary = false;
            }
            break;
        }
        case 3:
            std::cout << player.name << " arrives at the the slowly flowing river. A faint melody can be heard in the background. " 
                << player.name << " can either:" << std::endl;
            std::cout << "1. stay quiet and listen" << std::endl;
            std::cout << "2. Sing along with the melody" << std::endl;
            std::cin >> nestedChoice;
            if (nestedChoice == 1)
            {
                std::cout << "Remaining silent, " << player.name << " hears whispers of the merfolk below, but nothing happens." << std::endl;
            }
            else if (nestedChoice == 2)
            {
                std::cout << "Singing along, a merfolk surfaces and gifts " << player.name
                    << " a special blue gem as a token of appreciation for their voice."
                    << std::endl;
                player.inventory[player.inventoryCount] = "Blue Gem";
                player.inventoryCount++;
            }
            break;
        case 4:
            std::cout << player.name << " has " << player.health << " health points remaining" << std::endl;
            std::cout << "Inventory: " << std::endl;
            for (int i = 0; i < player.inventoryCount; i++)
            {
                if (!player.inventory[i].empty())
                {
                    std::cout << "- " << player.inventory[i] << std::endl;
                }
            }
        case 5:
            exploring = false;
            break;
        default:
            std::cout << "You did not enter a valid choice." << std::endl;
            continue;
    }
    }
}
