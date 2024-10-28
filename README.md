# Bus-Reservation-System



Bus Reservation System
A simple C-based console application for bus seat reservation, cancellation, and viewing reservation details. This system allows users to book and cancel seats, view available seats, and check reservation information.

Features
User Authentication: Secure login with preset username and password.
Bus List Display: Shows details of available buses, destinations, charges, and timings.
Seat Booking: Allows users to book seats by choosing a bus, entering the seat number, and generating a unique customer ID.
Cancellation: Seats can be canceled using a unique reservation number.
Seat Status: Displays the current status (booked/available) of all seats for a chosen bus.
Reservation Information: Retrieves details about a reservation using the customer ID.
How to Use
Login:

Username: lalpari
Password: redbus
Provides secure access to the main features.
Main Menu Options:

1 - View Bus List: Displays bus options with details.
2 - Book Tickets: Choose a bus and specify seats to reserve.
3 - Cancel Booking: Cancel seat reservations with a reservation number.
4 - Bus Seats Info: View seat availability for a selected bus.
5 - Reservation Info: Enter the reservation and customer IDs to view booking details.
6 - Exit: Exit the application.
Commands:

Navigation: Use the main menu options (1-6) to select an action.
Reservation and Cancellation: Follow the prompts to enter seat numbers and customer IDs.
Code Structure
Binary Search Tree (struct BinarySearchTree): Manages reservations, each identified by a unique customer ID.
Functions:
login(): Verifies user access to the system.
busLists(): Displays the list of buses.
DisplaySeat(): Shows seat status (booked or empty) for a particular bus.
insert(): Inserts a new reservation into the BST based on a customer ID.
reservationInfo(): Fetches reservation details for a specific customer ID.
cancel(): Allows seat cancellation with a reservation number.
status(): Shows the seat status for all buses.
cost(): Calculates ticket cost based on the bus number.
