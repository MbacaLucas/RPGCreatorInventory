#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>

void showLoadingBar()
{
    std::string bar = "--------------------"; // 20 guiones
    for (int i = 0; i <= 20; ++i)
    {
        std::cout << "\rCargando datos: [" << std::string(i, '#') << std::string(20 - i, ' ') << "] " << (i * 5) << "%" << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(25));
    }
    std::cout << "\n\n"; // Salt
}

// Definition of the Weapon structure (Smallest data unit)
struct Weapon
{
    std::string name;
    int damage;
    double durability;
};

// Definition of the Hero structure (Composed of a Weapon object)
struct Hero
{
    int categoryID;
    std::string name;
    std::vector<Weapon> inventory;
    int hp;
    double mana;
    int level;
};

void findLoot(Hero &character)
{
    switch (character.categoryID)
    {
    case 1:
        std::cout << "congrat you found a new shield 🛡️";
        character.inventory.push_back({"shield", 0, 200});
        break;
    case 2:
        std::cout << "congrat you found a potion's box 🧪";
        character.inventory.push_back({"potions", 0, 200});

        break;
    case 3:
        std::cout << "congrat you found a bagg of tnt 🧨";
        character.inventory.push_back({"TNT", 120, 20});

        break;
    default:
        break;
    }
}

// Increments character stats using pass-by-reference (&)
void levelUp(Hero &character)
{
    character.level++;
    character.hp += 20;
}

// Navigates into the nested struct to upgrade weapon stats
void weaponUpgrade(Hero &character)
{
    character.inventory[0].damage++;
    character.inventory[0].durability += 10.0;
}

// Displays the hero's info using const reference for performance and safety
void IntroGame(const Hero &character)
{
    std::cout << "\n==========================================================\n";
    std::cout << "📜 ADVENTURE REPORT:\n";
    std::cout << "The legendary " << character.name << " enters the woods...\n";
    std::cout << "Stats: [HP: " << character.hp << " | Mana: " << character.mana << "]\n";
    std::cout << "--INVENTORY'";
    for (const auto &item : character.inventory)
    {
        std::cout << "- " << item.name << " (Damage: " << item.damage << ")\n";
    }
}

int main()
{
    Hero userHero{}; // Initialize an empty hero object
    int categoryNumber{};

    // Loop to ensure the user picks a valid class
    do
    {
        std::cout << "\tIts Time To create your character\n\n";
        std::cout << "Select Kind of warrior(1. knight, 2. Wizard, 3. Elf): ";
        std::cin >> categoryNumber;

        switch (categoryNumber)
        {
        case 1:
            std::cout << "⚔️.You selected a knight \n\n";
            std::cout << "Give him a powerful name like 'the great Aragorn': ";
            // ws clears the buffer so getline doesn't skip the name
            std::getline(std::cin >> std::ws, userHero.name);
            userHero.inventory.push_back({"steel sword", 15, 100.0});
            userHero.hp = 120;
            userHero.mana = 20.0;
            userHero.categoryID = 1;
            break;
        case 2:
            std::cout << "🧙🏼‍♂️.You selected a Wizard \n";
            std::cout << "Give him a powerful name like 'Gandalf': ";
            std::getline(std::cin >> std::ws, userHero.name);
            userHero.inventory.push_back({"wand", 5, 80.0});
            userHero.hp = 90;
            userHero.mana = 100.0;
            userHero.categoryID = 2;
            break;
        case 3:
            std::cout << "🧝🏻.You selected a Elf \n";
            std::cout << "Give him a powerful name like 'Legolas': ";
            std::getline(std::cin >> std::ws, userHero.name);
            userHero.inventory.push_back({"bow and arrows", 6, 90.0});
            userHero.hp = 110;
            userHero.mana = 80.0;
            userHero.categoryID = 3;
            break;

        default:
            std::cout << "Select a valid option...\n\n";
        }

    } while (categoryNumber < 1 || categoryNumber > 3);

    // Call the function to display the final character profile
    IntroGame(userHero);
    showLoadingBar();
    findLoot(userHero);
    IntroGame(userHero);

    return 0;
}
