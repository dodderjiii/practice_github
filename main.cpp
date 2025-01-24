#include <iostream>
#include <string>
using namespace std;

// Base class: Plaza
class Plaza {
protected:
    string plazaName;
    string location;

public:
    void inputPlazaDetails() {
        cout << "Enter Plaza Name: ";
        getline(cin, plazaName);
        cout << "Enter Plaza Location: ";
        getline(cin, location);
    }

    void displayplazaname()
    {
        cout<<"Plaza Name: "<<plazaName<<endl;
    }
    void displayPlazaDetails() {
        cout << "Plaza Name: " << plazaName << endl;
        cout << "Location: " << location << endl;
    }
};

// Base class: Inventory
class Inventory {
protected:
    int totalItems;

public:
    void inputInventoryDetails() {
        cout << "Enter Total Items in Inventory: ";
        cin >> totalItems;
    }

    void displayInventory() {
        cout << "Total Items in Inventory: " << totalItems << endl;
    }
};

// Derived class: Shop (Multiple Inheritance from Plaza and Inventory)
class Shop : public Plaza, public Inventory {
protected:
    string shopName;
    string ownerName;

public:
    void inputShopDetails() {
        cin.ignore(); // Clear input buffer before getline
        cout << "Enter Shop Name: ";
        getline(cin, shopName);
        cout << "Enter Owner Name: ";
        getline(cin, ownerName);
    }

    void displayShopDetails() {
        displayPlazaDetails();
        cout << "Shop Name: " << shopName << endl;
        cout << "Owner Name: " << ownerName << endl;
    }
};

// Derived class: MobileAccessories (Multilevel Inheritance from Shop)
class MobileAccessories : public Shop {
private:
    int totalMobileAccessories;

public:
    void inputAccessoriesDetails() {
        inputPlazaDetails();
        inputInventoryDetails();
        inputShopDetails();
        cout << "Enter Total Mobile Accessories: ";
        cin >> totalMobileAccessories;
    }

    void displayAccessoriesDetails() {
        displayShopDetails();
        displayInventory();
        cout << "Total Mobile Accessories: " << totalMobileAccessories << endl;
    }
};

// Main function
int main() {
    // Creating an object of MobileAccessories
    MobileAccessories mobileShop;

    // Input details
    cout << "Enter details for the Mobile Accessories Plaza Management System:" << endl;
    mobileShop.inputAccessoriesDetails();

    // Displaying details
    cout << "\nMobile Accessories Plaza Management System" << endl;
    cout << "------------------------------------------" << endl;
    mobileShop.displayAccessoriesDetails();

    return 0;
}
