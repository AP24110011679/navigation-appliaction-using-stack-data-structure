# navigation-appliaction-using-stack-data-structure
This project implements a menu-driven navigation application using the Stack data structure in C++.
It simulates how browser or app navigation works, allowing users to:

Visit new locations

Move backward and forward through previously visited locations

View current location

Display complete navigation history

Two stacks are used:

Back Stack – stores previously visited locations

Forward Stack – stores locations available for forward navigation

🛠 Technologies Used

Language: C++

Data Structure: Stack (STL)

Libraries:

<iostream>

<stack>

<string>

⚙ How the Application Works

When a new location is visited, the current location is pushed into the back stack.

Forward navigation history is cleared when a new location is visited.

Going back moves the current location to the forward stack.

Going forward moves the location back to the back stack.

All navigation is handled using LIFO (Last In, First Out) behavior of stacks.
