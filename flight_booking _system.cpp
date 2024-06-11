#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structure to hold flight information
struct Flight {
    int flightNumber;
    string destination;
    int availableSeats;
};

// Structure to hold booking information
struct Booking {
    string passengerName;
    int flightNumber;
};

vector<Flight> flights;
vector<Booking> bookings;

// Function to add flights to the system
void addFlights() {
    flights.push_back({101, "New York", 5});
    flights.push_back({102, "London", 3});
    flights.push_back({103, "Paris", 7});
}

// Function to display available flights
void displayFlights() {
    cout << "Available Flights:\n";
    for (const auto& flight : flights) {
        cout << "Flight Number: " << flight.flightNumber
             << ", Destination: " << flight.destination
             << ", Available Seats: " << flight.availableSeats << endl;
    }
}

// Function to book a flight
void bookFlight() {
    string passengerName;
    int flightNumber;

    cout << "Enter passenger name: ";
    cin >> passengerName;
    cout << "Enter flight number to book: ";
    cin >> flightNumber;

    for (auto& flight : flights) {
        if (flight.flightNumber == flightNumber && flight.availableSeats > 0) {
            flight.availableSeats--;
            bookings.push_back({passengerName, flightNumber});
            cout << "Booking successful for " << passengerName << " on flight " << flightNumber << endl;
            return;
        }
    }

    cout << "Booking failed. Flight not found or no available seats.\n";
}

// Function to display bookings
void displayBookings() {
    cout << "Current Bookings:\n";
    for (const auto& booking : bookings) {
        cout << "Passenger Name: " << booking.passengerName
             << ", Flight Number: " << booking.flightNumber << endl;
    }
}

int main() {
    addFlights();
    int choice;

    while (true) {
        cout << "\nFlight Booking System\n";
        cout << "1. View Available Flights\n";
        cout << "2. Book a Flight\n";
        cout << "3. View Bookings\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayFlights();
                break;
            case 2:
                bookFlight();
                break;
            case 3:
                displayBookings();
                break;
            case 4:
                cout << "Exiting system...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
