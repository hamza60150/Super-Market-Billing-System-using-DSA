# Super-Market-Billing-System-using-DSA

Abstract: 

The Supermarket Management System is a C++ program designed to facilitate the management of product information and customer interactions in a supermarket setting. The program utilizes a linked list data structure to store information about various products, including their code, name, price, and quantity. The system supports two user roles: an administrator with privileged access to manage product information and a customer with the ability to view the product list and place orders. 
Product Management: 
The system allows administrators to add, update, and delete product information such as code, name, price, and quantity. 
Products are stored in a linked list, enabling dynamic management and efficient data retrieval. 

File I/O: 

Product information can be saved to and loaded from a file ("product_info.txt"). This feature ensures persistent data storage, allowing the system to retain product information across program executions. Customer Interaction: 
Customers can view the list of available products and place orders by entering the product code and desired quantity. 
The program calculates the total price, considering a discount for regular customers. Administrator Privileges: 
To access administrator features, users must enter a password ("hamza123"). Admin actions include displaying the product list, adding products, changing prices, deleting products, updating quantities, saving to file, and exiting the admin menu. 
 
User-Friendly Menus: 

The program features clear and intuitive menus for both administrators and customers, guiding users through available options. 

Introduction: 

The provided C++ program is an implementation of a Supermarket Management System, designed to efficiently manage product information, facilitate customer interactions, and allow administrative actions. The system incorporates a linked list data structure to store information about various products, such as their code, name, price, and quantity. It provides both an admin menu and a customer menu, catering to the distinct needs of administrators and customers within a supermarket setting. 
The program begins by defining a `Product` structure representing individual products, and a `ProductList` class to manage a linked list of these products. The linked list enables dynamic and flexible product management. The admin functionalities include displaying the product list, adding new products, updating prices, deleting products, saving product information to a file, and updating product quantities.  
For customer interactions, the system prompts the user to enter a product code and quantity, determining the total price considering potential discounts for regular customers. The program efficiently handles various scenarios, such as invalid product codes, insufficient product quantities, and incorrect input from the user. 
The admin menu requires a password for access, and upon successful authentication, administrators can perform various tasks like displaying the product list, adding or updating product information, deleting products, and saving changes to a file. The program includes input validation and informative error messages to enhance user experience. 
The main function serves as the entry point of the program, offering users the choice between accessing the admin menu or the customer menu. The system gracefully handles different user inputs and provides a seamless experience for both administrators and customers. Overall, this Supermarket Management System demonstrates effective organization, modularity, and user-friendly design, making it a valuable tool for managing supermarket operations. 

Problem Statement: 

We developed a Supermarket Management System program that enables both administrators and customers to interact with the supermarket's product inventory. The program incorporates functionalities such as adding, updating, and deleting product information, as well as allowing customers to place orders. The system is menu-driven, offering distinct options for administrators and customers. 

Product Management: 

Administrators can view, add, modify prices, and delete products from the inventory. Products are represented as a linked list, with each node containing information like code, name, price, and quantity. File Handling: 
The program supports loading product information from a file at the start and saving it back to the file after any modifications. 
The default filename for storing product information is "product_info.txt". 

Customer Interaction: 

Customers can view the product list and place orders by entering the product code, quantity, and indicating whether they are regular customers. 
The total price for the order is calculated, considering a discount for regular customers. 

User Authentication: 

Access to the administrator menu is password-protected to ensure security. 
The admin password is hardcoded in the program as "hamza123". Menu-Driven Interface: 
The program provides a clear and structured menu for both administrators and customers, making it user-friendly. Flexibility: 
The system is designed to be flexible, allowing for the addition, modification, and deletion of products based on the supermarket's changing inventory.

Customer and Admin Menus: 

The program distinguishes between customer and admin users, providing separate menus and functionalities for each. Usage: 
Upon execution, the program prompts the user to select either the Admin Menu or the Customer Menu. For administrators, the system requests an authentication password before granting access to features like managing products, updating quantities, and saving to a file. Customers can view the product list and place orders by entering product codes and quantities. 
The program continues running until the user decides to exit, providing an interactive and intuitive supermarket management experience for both administrators and customers. 

Existing Systems (Show Comparison with existing systems to differentiate how your project is different from existing similar projects) 
Database Integration: 

Existing Systems: 

Advanced systems often integrate with databases to store and manage large volumes of product data efficiently. These databases may use SQL or NoSQL technologies. 

This Program: 

The C++ program uses a simple file-based approach to store product information. Each product entry is stored in a text file. This design simplifies the program but may not be as scalable as database-backed solutions. User Authentication and Roles: 

Existing Systems:

In enterprise-level systems, user authentication and role-based access control are common. This ensures that only authorized personnel can perform administrative tasks. 

This Program: The C++ program has a basic admin authentication system with a hardcoded password. It lacks user roles, making it less suitable for complex organizational structures. 

Real-time Sales and Inventory Tracking: 

Existing Systems: Many systems provide real-time tracking of sales and inventory levels. This allows businesses to make data-driven decisions and respond quickly to changes in demand. 

This Program: The C++ program focuses on basic inventory management without realtime tracking. It might not be suitable for businesses with a high transaction volume requiring constant updates. 

Reporting and Analytics: 

Existing Systems: Advanced systems often include reporting and analytics features. These can help businesses gain insights into sales trends, product performance, and customer behavior. 

This Program: The C++ program lacks built-in reporting and analytics. Businesses seeking in-depth analysis may need to export data to external tools for further examination. 

Web-Based Systems:-

Existing Systems: Many modern solutions are web-based, allowing users to access the system from any device with an internet connection. This enhances accessibility and facilitates remote management. 
This Program: The C++ program is not web-based. It needs to be run locally, limiting accessibility compared to web-based alternatives. 
In summary, the C++ program is a simplified supermarket management system that may be suitable for small businesses or educational purposes. It offers a straightforward command-line interface for managing products and basic customer interactions. However, it lacks some advanced features found in more complex, database-backed, and web-based systems. Depending on the requirements, businesses may opt for existing solutions tailored to their specific needs.

Objectives and Goals:  
1.	Implement a supermarket management system with admin and customer functionalities. 
2.	Allow the admin to perform actions such as adding, updating, and deleting products, as well as saving/loading data to/from a file. 
3.	Enable customers to view the product list, place orders, and calculate total prices with possible discounts. 
4.	Provide a user-friendly interface for both admin and customers. 
5.	Ensure data integrity through proper error handling and validation. 
6.	Facilitate easy navigation and interaction within the program. 
7.	Enhance system efficiency by loading product information from a file at the start and saving updates to a file upon admin actions. 
8.	Maintain code modularity and readability through the use of functions and a structured class for product-related operations. 
7. Project Scope 
The Supermarket Management System is a software application designed to automate and streamline the management of a supermarket. The system provides functionalities for both administrators and customers, offering features such as product management, order placement, and file I/O operations.
 
Administrator Features: 

Display Product List: View a list of all products with their details, including code, name, price, and quantity. 
Add Product: Add new products to the system, specifying the code, name, price, and initial quantity. 
Change Price: Modify the price of an existing product. 
Delete Product: Remove a product from the system based on its code. 
Save to File: Save the current product information to a file ("product_info.txt"). 
Update Quantity: Adjust the quantity of a product, considering availability. 
Update Price: Change the price of a product. 
Customer Features: 
Display Products List: View the list of available products with their details. Place Order: Allow customers to select a product, specify the quantity, and calculate the total price with an optional discount for regular customers.

Common Features: 

Password Protection: The administrator actions are protected by a password ("hamza123"). 

File I/O Operations: Load product information from the file on program start-up. 

Save product information to the file during the admin's "Save to File" operation.  Implementation Details: 

Product Structure: Each product is represented by a structure with attributes like code, name, price, quantity, and a pointer to the next product. 

ProductList Class: Manages the linked list of products, providing methods for adding, updating, and deleting products. 

User Interaction: The program interacts with users through a console interface, allowing admins and customers to perform their respective actions. 

Password Protection: Administrator actions are secured with a password to prevent unauthorized access. 

Flow of Operations: 

Program Start: Loads existing product information from the file. 

User Selection: Users can choose between the administrator and customer roles. Administrator Actions: Admins can perform various operations like adding, updating, and deleting products, as well as saving to and loading from a file. 

Customer Interaction: Customers can view product lists and place orders, with a total price calculation considering optional discounts. 

File Operations: Product information is saved to the file during the admin's "Save to File" operation and loaded during program start-up. 
 
The Supermarket Management System aims to enhance the efficiency of supermarket operations, providing a robust platform for product management and customer interactions. With features catering to both administrators and customers, the system streamlines supermarket processes and offers room for future enhancements. 
