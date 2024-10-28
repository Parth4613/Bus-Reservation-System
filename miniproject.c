#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Struct definition
typedef struct BinarySearchTree BST;
struct BinarySearchTree {
    int PassnNo;
    char name[10];
    struct BinarySearchTree *left;
    struct BinarySearchTree *right;
};

// Function declarations
BST* reservationInfo(BST* r, int s, int* custIDmatched);
BST* insert(BST** r, int custID);
int cost(BST* r);
void DisplaySeat(int bus[33]);
void cancelBooking(int reservationNo);
void login();
void viewBusList();
void bookTickets();
void displayStatus();
void resetColor();
void redColor();

int busSeat[32][9] = {0};
BST *root = NULL;

void login() {
    const char userName[20] = "lalpari";
    const char passWord[10] = "redbus";
    char matchUser[20];
    char matchPass[10];
    int attempt = 3;

    redColor();
    printf("\n\n=========================================================================================\n");
    printf("\n\t\t\tWELCOME TO ONLINE BUS RESERVATION");
    printf("\n\n=========================================================================================\n\n");
    resetColor();

    while (attempt > 0) {
        printf("\nUserName: ");
        fgets(matchUser, sizeof(matchUser), stdin);
        matchUser[strcspn(matchUser, "\n")] = '\0'; // Remove newline

        printf("\nPassword: ");
        fgets(matchPass, sizeof(matchPass), stdin);
        matchPass[strcspn(matchPass, "\n")] = '\0';

        if (strcmp(userName, matchUser) == 0 && strcmp(passWord, matchPass) == 0) {
            printf("\nLOGGED IN SUCCESSFULLY...\n");
            return;
        } else {
            redColor();
            printf("\nINVALID DETAILS. TRY AGAIN. Attempts left: %d\n", --attempt);
            resetColor();
        }
    }
    printf("\nExiting system due to failed login attempts.\n");
    exit(0);
}

void DisplaySeat(int bus[33]) {
    printf("\n----------------- Seat Status -----------------\n");
    for(int i = 1; i <= 32; i++) {
        redColor();
        printf("%02d . ", i);
        resetColor();
        printf(bus[i] == 0 ? "EMPTY  " : "BOOKED ");
        if (i % 4 == 0) printf("\n");
    }
}

BST* insert(BST **r, int custId) {
    if (*r == NULL) {
        *r = (BST *)malloc(sizeof(BST));
        (*r)->PassnNo = custId;
        if (*r == NULL) {
            printf("No memory available\n");
            return NULL;
        }
        (*r)->left = (*r)->right = NULL;
        printf("\nEnter the person's name: ");
        scanf("%9s", (*r)->name);
    } else if ((*r)->PassnNo > custId) {
        (*r)->left = insert(&((*r)->left), custId);
    } else if ((*r)->PassnNo < custId) {
        (*r)->right = insert(&((*r)->right), custId);
    }
    return *r;
}

void cancelBooking(int reservationNo) {
    int reservationID, busNum, seatNum, seatsToCancel;
    char confirm;

    printf("\nEnter your reservation number: ");
    scanf("%d", &reservationID);

    if (reservationID == reservationNo) {
        printf("Is this correct? Reservation No. %d (Y/N): ", reservationID);
        getchar();
        confirm = getchar();
        if (confirm == 'y' || confirm == 'Y') {
            printf("\nEnter Bus Number: ");
            scanf("%d", &busNum);

            printf("\nEnter Number of Seats to Cancel: ");
            scanf("%d", &seatsToCancel);

            for (int i = 0; i < seatsToCancel; i++) {
                printf("\nEnter Seat Number to Cancel: ");
                scanf("%d", &seatNum);
                busSeat[busNum][seatNum] = 0;
            }
            printf("\nYour reservation has been canceled.\n");
        } else {
            printf("Cancellation request denied.\n");
        }
    } else {
        printf("Reservation number not found. Please try again.\n");
    }
}

int main() {
    srand(time(0));
    int choice, reservationNo = rand();
    login();

    do {
        printf("\n\n=================== Main Menu ===================\n\n");
        printf("   [1] VIEW BUS LIST\n");
        printf("   [2] BOOK TICKETS\n");
        printf("   [3] CANCEL BOOKING\n");
        printf("   [4] VIEW SEAT STATUS\n");
        printf("   [5] EXIT\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                viewBusList();
                break;
            case 2:
                bookTickets();
                break;
            case 3:
                cancelBooking(reservationNo);
                break;
            case 4:
                displayStatus();
                break;
            case 5:
                printf("\nThank you for using the Bus Reservation System.\n");
                break;
            default:
                redColor();
                printf("Invalid choice. Please try again.\n");
                resetColor();
                break;
        }
    } while (choice != 5);

    return 0;
}

