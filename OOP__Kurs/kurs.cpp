#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Класс, представляющий размер напитка
class BeverageSize {
public:
    enum Size { SMALL, MEDIUM, LARGE };

    // Конструктор с установкой размера
    BeverageSize(Size size) : size(size) {}

    // Получение размера
    Size getSize() const {
        return size;
    }

private:
    Size size;
};

// Базовый класс для элементов меню
class MenuItem {
public:
    MenuItem(const string& name) : name(name) {}

    virtual void display() const {
        cout << "Элемент меню: " << name << endl;
    }

    virtual void action() const = 0;

    virtual ~MenuItem() = default;

protected:
    string name;
};

// Класс для блюд
class Dish : public MenuItem {
public:
    Dish(const string& name, float price, const string& composition)
        : MenuItem(name), price(price), composition(composition) {}

    void display() const override {
        cout << "Блюдо: " << name << " - Цена: " << price << " руб." << endl;
    }

    void action() const override {
        int choice;
        cout << "Выберите опцию для блюда '" << name << "': " << endl;
        cout << "1. Узнать цену" << endl;
        cout << "2. Узнать состав" << endl;
        cout << "9. Вернуться в главное меню" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Цена блюда '" << name << "': " << price << " руб." << endl;
                break;
            case 2:
                cout << "Состав блюда '" << name << "': " << composition << endl;
                break;
            case 9:
                break;
            default:
                cout << "Некорректный выбор." << endl;
        }
    }

private:
    float price;
    string composition;
};

// Класс для кофе
class Coffee : public MenuItem {
public:
    Coffee(const string& name, float price) : MenuItem(name), price(price) {}

    void display() const override {
        cout << "Кофе: " << name << " - Цена: " << price << " руб." << endl;
    }

    void action() const override {
        int choice;
        cout << "Выберите вид кофе '" << name << "': " << endl;
        cout << "1. Латте" << endl;
        cout << "2. Капучино" << endl;
        cout << "3. Американо" << endl;
        cout << "4. Эспрессо" << endl;
        cout << "9. Вернуться в главное меню" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                showCoffeeDetails("Латте", "Молоко, кофе", 150.0);
                break;
            case 2:
                showCoffeeDetails("Капучино", "Молоко, кофе", 120.0);
                break;
            case 3:
                showCoffeeDetails("Американо", "Кофе, вода", 100.0);
                break;
            case 4:
                showCoffeeDetails("Эспрессо", "Кофе", 80.0);
                break;
            case 9:
                break;
            default:
                cout << "Некорректный выбор." << endl;
        }
    }

private:
    float price;
    string coffeeType;
    string composition;

    void showCoffeeDetails(const string& coffeeType, const string& composition, float coffeePrice) const {
        cout << "Вы выбрали " << coffeeType << ": " << endl;
        cout << "Цена: " << coffeePrice << " руб." << endl;
        cout << "Состав: " << composition << endl;
    }
};

// Класс для напитков
class Drink : public MenuItem {
public:
    Drink(const string& name, float price, const string& composition)
        : MenuItem(name), price(price), composition(composition) {}

    void display() const override {
        cout << "Напиток: " << name << " - Цена: " << price << " руб." << endl;
    }

    void action() const override {
        int choice;
        cout << "Выберите опцию для напитка '" << name << "': " << endl;
        cout << "1. Узнать цену" << endl;
        cout << "2. Узнать состав" << endl;
        cout << "3. Добавить лёд" << endl;
        cout << "9. Вернуться в главное меню" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Цена напитка '" << name << "': " << price << " руб." << endl;
                break;
            case 2:
                cout << "Состав напитка '" << name << "': " << composition << endl;
                break;
            case 3:
                addIce();
                break;
            case 9:
                break;
            default:
                cout << "Некорректный выбор." << endl;
        }
    }

    // Перегруженный метод с учетом размера напитка
    void action(const BeverageSize& size) const {
        action();
        displaySize(size);
    }

    void addIce() const {
        char answer;
        cout << "Хотите добавить лёд? (y/n): ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y') {
            cout << "Лёд добавлен." << endl;
        } else {
            cout << "Без льда." << endl;
        }
    }

    void displaySize(const BeverageSize& size) const {
        cout << "Выбран размер: ";
        switch (size.getSize()) {
            case BeverageSize::SMALL:
                cout << "Маленький" << endl;
                break;
            case BeverageSize::MEDIUM:
                cout << "Средний" << endl;
                break;
            case BeverageSize::LARGE:
                cout << "Большой" << endl;
                break;
        }
    }

private:
    float price;
    string composition;
};

// Класс для подменю
class SubMenu : public MenuItem {
public:
    SubMenu(const string& name) : MenuItem(name) {}

    void display() const override {
        cout << "Подменю: " << name << endl;
    }

    void addMenuItem(MenuItem* item) {
        items.push_back(item);
    }

    void action() const override {
        int choice;
        do {
            display();
            cout << "Выберите блюдо" << endl;
            cout << "---------------------------------------"<< endl;
            cout << "1. Стейк" << endl;
            cout << "2. Салат Цезарь"<< endl;
            cout << "3. Пицца Маргарита"<< endl;
            cout << "4. Паста"<< endl;
            cout << "5. Рыбное блюдо"<< endl;
            cout << "6. Суп"<< endl;
            cout << "7. Бургер"<< endl;
            cout << "8. Картошка фри"<< endl;
            cout << "9. Кофе"<< endl;
            cout << "10. Кола"<< endl;
            cout << "11. Чай"<< endl;
            cout << "---------------------------------------"<< endl;
            cout << "Для выхода из программы нажмите 0"<< endl;
            cout << "---------------------------------------"<< endl;
            cin >> choice;

            if (choice >= 1 && choice <= items.size()) {
                // Условие для Drink с размером
                if (auto* drink = dynamic_cast<Drink*>(items[choice - 1])) {
                    BeverageSize::Size sizeChoice = chooseSize();
                    drink->action(BeverageSize(sizeChoice));
                } else {
                    items[choice - 1]->action();
                }
            }
        } while (choice != 0);
    }

    ~SubMenu() override {
        for (const auto& item : items) {
            delete item;
        }
    }

private:
    vector<MenuItem*> items;

    BeverageSize::Size chooseSize() const {
        int sizeChoice;
        cout << "Выберите размер: " << endl;
        cout << "1. Маленький" << endl;
        cout << "2. Средний" << endl;
        cout << "3. Большой" << endl;
        cin >> sizeChoice;

        switch (sizeChoice) {
            case 1:
                return BeverageSize::SMALL;
            case 2:
                return BeverageSize::MEDIUM;
            case 3:
                return BeverageSize::LARGE;
            default:
                cout << "Некорректный выбор. Размер установлен как Средний." << endl;
                return BeverageSize::MEDIUM;
        }
    }
};

int main() {
    SubMenu mainMenu("Главное меню");

    Dish* dish1 = new Dish("Стейк", 1000.0, "Говядина, специи");
    Dish* dish2 = new Dish("Салат Цезарь", 500.0, "Курица, салат");
    Dish* dish3 = new Dish("Пицца Маргарита", 800.0, "Тесто, помидоры, сыр");
    Dish* pasta = new Dish("Паста", 700.0, "Макароны, соус болоньезе");
    Dish* fishDish = new Dish("Рыбное блюдо", 900.0, "Рыба, приправы");
    Dish* soup = new Dish("Суп", 300.0, "Бульон, овощи, мясо");
    Dish* burger = new Dish("Бургер", 600.0, "Булочка, котлета, овощи");
    Dish* frenchFries = new Dish("Картошка фри", 250.0, "Картошка, масло, специи");

    Coffee* coffee = new Coffee("Кофе", 120.0);
    Drink* drink1 = new Drink("Кола", 150.0, "Газированная вода, сахар, карамель");
    Drink* drink2 = new Drink("Чай", 100.0, "Чайные листья, вода");

    mainMenu.addMenuItem(dish1);
    mainMenu.addMenuItem(dish2);
    mainMenu.addMenuItem(dish3);
    mainMenu.addMenuItem(pasta);
    mainMenu.addMenuItem(fishDish);
    mainMenu.addMenuItem(soup);
    mainMenu.addMenuItem(burger);
    mainMenu.addMenuItem(frenchFries);
    mainMenu.addMenuItem(coffee);
    mainMenu.addMenuItem(drink1);
    mainMenu.addMenuItem(drink2);

    mainMenu.action();

    return 0;
}
