#include <iostream>
#include <conio.h>
#include <vector>

using namespace std;

class MenuItem {
protected:
    string name;

public:
    MenuItem(const string& itemName) : name(itemName) {}

    const string& getName() const {
        return name;
    }

    virtual void displayDetails() const = 0;

    virtual ~MenuItem() {}
};

class Dish : public MenuItem {
public:
    Dish(const string& dishName) : MenuItem(dishName) {}

    virtual void displayDetails() const = 0;

    virtual ~Dish() {}
};

class Pizza : public Dish {
public:
    Pizza() : Dish("Pizza") {}

    void displayDetails() const override {
        system("cls");
        cout << "Pizza Details:" << endl;
        cout << "1. View Price" << endl;
        cout << "2. View Composition" << endl;
        cout << "3. Back to Main Menu" << endl;
    }
};

class Burger : public Dish {
public:
    Burger() : Dish("Burger") {}

    void displayDetails() const override {
        system("cls");
        cout << "Burger Details:" << endl;
        cout << "1. View Price" << endl;
        cout << "2. View Composition" << endl;
        cout << "3. Back to Main Menu" << endl;
    }
};

class Pasta : public Dish {
public:
    Pasta() : Dish("Pasta") {}

    void displayDetails() const override {
        system("cls");
        cout << "Pasta Details:" << endl;
        cout << "1. View Price" << endl;
        cout << "2. View Composition" << endl;
        cout << "3. Back to Main Menu" << endl;
    }
};

void showMenu(const vector<MenuItem*>& menu, int selectedOption);

void showSubMenu(MenuItem* item);

int main() {
    vector<MenuItem*> menu;
    menu.push_back(new Pizza());
    menu.push_back(new Burger());
    menu.push_back(new Pasta());

    int selectedOption = 0;
    char key;

    do {
        showMenu(menu, selectedOption);

        key = _getch(); // wait for a key press without displaying it

        switch (key) {
            case 72: // up arrow key
                selectedOption = (selectedOption > 0) ? selectedOption - 1 : menu.size() - 1;
                break;
            case 80: // down arrow key
                selectedOption = (selectedOption < menu.size() - 1) ? selectedOption + 1 : 0;
                break;
            case 13: // Enter key
                showSubMenu(menu[selectedOption]);
                break;
        }

    } while (key != 27); // continue loop until Esc is pressed

// Clean up memory
for (size_t i = 0; i < menu.size(); ++i) {
    delete menu[i];
}

return 0;

}

void showMenu(const vector<MenuItem*>& menu, int selectedOption) {
    system("cls"); // clear the screen

    cout << "Main Menu:" << endl;
    for (size_t i = 0; i < menu.size(); ++i) {
        cout << (i == selectedOption ? "> " : "  ") << menu[i]->getName() << endl;
    }
    cout << "Exit" << endl;
}

void showSubMenu(MenuItem* item, int subMenuOption) {
    char key;

    do {
        system("cls"); // clear the screen

        item->displayDetails();

        cout << "\nSub Menu:" << endl;
        for (int i = 1; i <= 3; ++i) {
            cout << (i == subMenuOption ? "> " : "  ") << "Option " << i << endl;
        }
        cout << "Back to Main Menu" << endl;

        key = _getch(); // wait for a key press without displaying it

        switch (key) {
            case 72: // up arrow key
                subMenuOption = (subMenuOption > 1) ? subMenuOption - 1 : 3;
                break;
            case 80: // down arrow key
                subMenuOption = (subMenuOption < 3) ? subMenuOption + 1 : 1;
                break;
            case 13: // Enter key
                switch (subMenuOption) {
                    case 1:
                        // View Price
                        system("cls");
                        cout << "Price: $10" << endl;
                        cout << "\nPress any key to go back...";
                        _getch();
                        break;
                    case 2:
                        // View Composition
                        system("cls");
                        cout << "Composition: Dough, Tomato Sauce, Cheese, Toppings" << endl;
                        cout << "\nPress any key to go back...";
                        _getch();
                        break;
                    case 3:
                        // Back to Main Menu
                        break;
                }
                break;
        }

    } while (key != 27 && subMenuOption != 3); // continue loop until Esc is pressed or Back to Main Menu is selected
}
