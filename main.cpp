#include <iostream>
#include <string>

struct Weapon
{
    std::string name;
    int damage;
    double durability;
};

struct Hero
{
    std::string name;
    Weapon weapon;
    int hp;
    double mana;
    int level;
};

void levelUp(Hero &character)
{
    character.level++;
    character.hp += 20;
}

void weaponUpgrade(Hero &character)
{
    character.weapon.damage++;
    character.weapon.durability += 10.0;
}

void IntroGame(const Hero &character)
{
    std::cout << "\n==========================================================\n";
    std::cout << "📜 REPORT DE AVENTURA:\n";
    std::cout << "El legendario " << character.name << " se adentra en el bosque...\n";
    std::cout << "Estadisticas: [HP: " << character.hp << " | Mana: " << character.mana << "]\n";
    std::cout << "Equipo: Empuña un(a) '" << character.weapon.name << "' ";
    std::cout << "(Daño: " << character.weapon.damage << " | Durabilidad: " << character.weapon.durability << ")\n";
    std::cout << "==========================================================\n";
}

int main()
{
    Hero userHero{};
    int categoryNumber{};
    do
    {
        std::cout << "\tIts Time To create your character\n\n";
        std::cout << "Select Kind of warrior(1. knight, 2. Wizard, 3. Elf): ";
        std::cin >> categoryNumber;

        switch (categoryNumber)
        {
        case 1:
            std::cout << "⚔️.You selected a knight \n\n";
            std::cout << "Give him a powefull name like 'the great Aragorn': ";
            std::getline(std::cin >> std::ws, userHero.name);
            userHero.weapon = {"steel sword", 15, 100.0};
            userHero.hp = 120;
            userHero.mana = 20.0;
            break;
        case 2:
            std::cout << "🧙🏼‍♂️.You selected a Wizard \n";
            std::cout << "Give him a powefull name like 'Gandalf': ";
            std::getline(std::cin >> std::ws, userHero.name);
            userHero.weapon = {"wand", 5, 80.0};
            userHero.hp = 90;
            userHero.mana = 100.0;
            break;
        case 3:
            std::cout << "🧝🏻.You selected a Elf \n";
            std::cout << "Give him a powefull name like 'Legolas': ";
            std::getline(std::cin >> std::ws, userHero.name);
            userHero.weapon = {"bow and arrows", 6, 90.0};
            userHero.hp = 110;
            userHero.mana = 80.0;
            break;

        default:
            std::cout << "select a valid option...\n\n";
        }

    } while (categoryNumber < 1 || categoryNumber > 3);

    IntroGame(userHero);
    return 0;
}