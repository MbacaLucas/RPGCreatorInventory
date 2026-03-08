# ⚔️ C++ Hero Creator & Inventory System

Un simulador de creación de personajes RPG desarrollado en **C++** que implementa conceptos  de **estructuras compuestas**, **vectores dinámicos** y **paso por referencia**.

## 🚀 Características

- **Sistema de Clases:** Elige entre Caballero, Mago o Elfo, cada uno con estadísticas únicas (HP, Mana, ID).
- **Composición de Datos:** Uso de estructuras anidadas (`Hero` contiene una `Weapon`).
- **Inventario Dinámico:** Implementación de `std::vector` para gestionar múltiples ítems.
- **Lógica de Recompensas:** Sistema de *Loot* basado en el ID de clase del personaje.
- **Experiencia de Usuario:** Incluye una barra de carga estética y reportes detallados en consola.

## 🛠️ Conceptos Técnicos Aplicados

*   **Structs:** Organización de datos relacionados.
*   **std::vector:** Manejo de colecciones de objetos que crecen en tiempo de ejecución.
*   **Paso por Referencia (`&`):** Optimización de memoria y modificación de datos originales en funciones.
*   **Const Accuracy:** Uso de `const` para proteger datos en funciones de solo lectura.
*   **Control de Flujo:** Validación de entradas con `do-while` y toma de decisiones con `switch-case`.

## 📦 Estructura de Datos

```cpp
struct Weapon {
    string name;
    int damage;
    double durability;
};

struct Hero {
    int categoryID;
    string name;
    vector<Weapon> inventory;
    int hp;
    double mana;
    int level;
};
