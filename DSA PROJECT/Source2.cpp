#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const string ADMIN_PASSWORD = "hamza123"; // Admin password

struct Product {
    int code;
    string name;
    double price;
    int quantity;
    Product* next;
};

class ProductList {
public:
    ProductList() : head(nullptr) {}
    ~ProductList();

    void addProduct(int code, const string& name, double price, int quantity);
    void displayProducts();
    Product* findProduct(int code);
    void updateQuantity(int code, int newQuantity);
    void updatePrice(int code, double newPrice);
    void deleteProduct(int code);
    void saveToFile(const string& filename);
    void loadFromFile(const string& filename);

private:
    Product* head;
    void deleteList(Product* node);
};

ProductList::~ProductList() {
    deleteList(head);
}

void ProductList::deleteList(Product* node) {
    while (node) {
        Product* temp = node;
        node = node->next;
        delete temp;
    }
}

void ProductList::addProduct(int code, const string& name, double price, int quantity) {
    Product* newProduct = new Product{ code, name, price, quantity, nullptr };
    if (!head) {
        head = newProduct;
    }
    else {
        Product* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newProduct;
    }
}

void ProductList::displayProducts() {
    Product* temp = head;
    cout << "Product List:\n";
    cout << setw(10) << "Code" << setw(20) << "Name" << setw(10) << "Price" << setw(10) << "Quantity" << endl;
    while (temp) {
        cout << setw(10) << temp->code << setw(20) << temp->name << setw(10) << temp->price << setw(10) << temp->quantity << endl;
        temp = temp->next;
    }
}

Product* ProductList::findProduct(int code) {
    Product* temp = head;
    while (temp && temp->code != code) {
        temp = temp->next;
    }
    return temp;
}

void ProductList::updateQuantity(int code, int newQuantity) {
    Product* product = findProduct(code);
    if (product) {
        if (newQuantity >= 0 && newQuantity <= product->quantity) {
            product->quantity = newQuantity;
        }
    }
    else {
        cout << "Product not found.\n";
    }
}


void ProductList::updatePrice(int code, double newPrice) {
    Product* product = findProduct(code);
    if (product) {
        product->price = newPrice;
    }
}

void ProductList::deleteProduct(int code) {
    Product* current = head;
    Product* previous = nullptr;

    // Find the product with the given code
    while (current && current->code != code) {
        previous = current;
        current = current->next;
    }

    // If the product is found, delete it
    if (current) {
        if (previous) {
            previous->next = current->next;
        }
        else {
            head = current->next;
        }

        delete current;
    }
}

void ProductList::saveToFile(const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error: Unable to open file for writing.\n";
        return;
    }

    Product* temp = head;
    while (temp) {
        outFile << temp->code << ' ' << temp->name << ' ' << temp->price << ' ' << temp->quantity << '\n';
        temp = temp->next;
    }

    outFile.close();
}

void ProductList::loadFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Unable to open file for reading.\n";
        return;
    }

    int code, quantity;
    double price;
    string name;

    deleteList(head);
    head = nullptr;

    while (inFile >> code >> name >> price >> quantity) {
        addProduct(code, name, price, quantity);
    }

    inFile.close();
}

// Function to calculate the total price considering the discount
double calculateTotalPrice(double price, int quantity, bool isRegularCustomer) {
    const double discountRate = isRegularCustomer ? 0.2 : 0.0; //0.2 because we giving 20% discount
    return price * quantity * (1 - discountRate);
}

// Function to handle customer interaction
void customerInteraction(ProductList& productList) {
    int productCode, quantity;
    char isRegularCustomer;

    cout << "Enter product code: ";
    cin >> productCode;

    Product* product = productList.findProduct(productCode);
    if (!product) {
        cout << "Product not found.\n";
        return;
    }

    cout << "Enter quantity: ";
    cin >> quantity;

    if (quantity <= 0 || quantity > product->quantity) {
        cout << "Product quantity not available. Returning to Customer Menu.\n";
        return;
    }

    cout << "Are you a regular customer? (y/n): ";
    cin >> isRegularCustomer;

    double totalPrice = calculateTotalPrice(product->price, quantity, (isRegularCustomer == 'y'));

    cout << "Product: " << product->name << "\n";
    cout << "Price per unit: " << product->price << "\n";
    cout << "Quantity: " << quantity << "\n";
    cout << "Total Price: " << totalPrice << "\n";
}


// Function to handle admin actions
void adminActions(ProductList& productList) {
    int choice;
    string password;

    cout << "\nPress 1 to enter password: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter admin password: ";
        cin >> password;

        if (password == ADMIN_PASSWORD) {
            do {
                cout << "\nAdmin Menu:\n";
                cout << "1. Display Products List\n";
                cout << "2. Add Product\n";
                cout << "3. Change Price\n";
                cout << "4. Delete Product\n";
                cout << "5. Save to File\n";
                cout << "6. Update Quantity\n";
                cout << "7. Update Price\n";
                cout << "8. Exit\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                case 1:
                    productList.displayProducts();
                    break;
                case 2: {
                    int code, quantity;
                    double price;
                    string name;

                    cout << "Enter product code: ";
                    cin >> code;

                    Product* existingProduct = productList.findProduct(code);
                    if (existingProduct) {
                        cout << "Product with the same code already exists.\n";
                        break;
                    }

                    cout << "Enter product name: ";
                    cin.ignore(); // Clear newline from buffer
                    getline(cin, name);

                    cout << "Enter product price: ";
                    cin >> price;

                    cout << "Enter product quantity: ";
                    cin >> quantity;

                    productList.addProduct(code, name, price, quantity);
                    cout << "Product added successfully.\n";
                    break;
                }
                case 3: {
                    int code;
                    double newPrice;

                    cout << "Enter product code: ";
                    cin >> code;

                    Product* existingProduct = productList.findProduct(code);
                    if (!existingProduct) {
                        cout << "Product not found.\n";
                        break;
                    }

                    cout << "Enter new price: ";
                    cin >> newPrice;

                    productList.updatePrice(code, newPrice);
                    cout << "Price updated successfully.\n";
                    break;
                }
                case 4: {
                    int codeToDelete;
                    cout << "Enter the product code to delete: ";
                    cin >> codeToDelete;

                    productList.deleteProduct(codeToDelete);
                    cout << "Product information deleted.\n";
                    break;
                }
                case 5:
                    productList.saveToFile("product_info.txt");
                    cout << "Product information saved to file.\n";
                    break;
                case 6: {
                    int code, newQuantity;

                    cout << "Enter product code: ";
                    cin >> code;

                    Product* existingProduct = productList.findProduct(code);
                    if (!existingProduct) {
                        cout << "Product not found.\n";
                        break;
                    }

                    cout << "Enter new quantity: ";
                    cin >> newQuantity;

                    if (newQuantity > existingProduct->quantity) {
                        cout << "Not Enough Quantity available, please try again.\n";
                    }
                    else {
                        productList.updateQuantity(code, newQuantity);
                        cout << "Quantity updated successfully.\n";
                    }
                    break;
                }
                case 7: {
                    int code;
                    double newPrice;

                    cout << "Enter product code: ";
                    cin >> code;

                    Product* existingProduct = productList.findProduct(code);
                    if (!existingProduct) {
                        cout << "Product not found.\n";
                        break;
                    }

                    cout << "Enter new price: ";
                    cin >> newPrice;

                    productList.updatePrice(code, newPrice);
                    cout << "Price updated successfully.\n";
                    break;
                }
                case 8:
                    cout << "Exiting admin menu.\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
                }

            } while (choice != 8);
        }
        else {
            cout << "Incorrect admin password. Exiting program.\n";
        }
    }
    else {
        cout << "Invalid choice. Exiting program.\n";
    }
}

int main() {
    ProductList productList;

    // Load product information from file (if available)
    productList.loadFromFile("product_info.txt");

    int userTypeChoice;
    cout << "\n\t\t\t\t\tSUPERMARKET MANAGEMENT SYSTEM:\t\n";
    cout << "Press 1 for Admin Menu \nPress 2 To Place Order: ";
    cin >> userTypeChoice;

    if (userTypeChoice == 1) {
        adminActions(productList);
    }
    else if (userTypeChoice == 2) {
        int customerChoice;
        do {
            cout << "\nCustomer Menu:\n";
            cout << "1. Display Products List\n";
            cout << "2. Place Order\n";
            cout << "3. Exit\n";
            cout << "Enter your choice: ";
            cin >> customerChoice;

            switch (customerChoice) {
            case 1:
                productList.displayProducts();
                break;
            case 2:
                customerInteraction(productList);
                break;
            case 3:
                cout << "Exiting customer menu.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
            }
        } while (customerChoice != 3);
    }
    else {
        cout << "Invalid user type. Exiting program.\n";
    }

    return 0;
}
