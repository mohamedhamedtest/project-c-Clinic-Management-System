#include "SDB.h"
#include"STD_TYPES.h"
void SDB_APP (void){
uint32 mode;
    uint32 loggedIn = 0;

    while (!loggedIn) {
        mode = isAdminMode();

        if (mode == 1) {
            if (validatePassword()) {
                loggedIn = 1;
                printf("Logged in as admin.\n");
            } else {
                printf("Incorrect password. Please try again.\n");
            }
        } else if (mode == 2) {
            loggedIn = 1;
            printf("Logged in as user.\n");
        } else {
            printf("Invalid mode. Please try again.\n");
        }
    }

    if (mode == 1) {
        uint32 choice;
        while (1) {
            printf("\nAdmin Menu:\n");
            printf("1. Add new patient record\n");
            printf("2. Edit patient record\n");
            printf("3. Reserve a slot with the doctor\n");
            printf("4. Cancel reservation\n");
            printf("5. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    addPatient();
                    break;
                case 2:
                    editPatient();
                    break;
                case 3:
                    displayAvailableSlots();
                    reserveSlot();
                    break;
                case 4:
                    cancelReservation();
                    break;
                case 5:
                    printf("Exiting...\n");
                    exit(0);
                default:
                    printf("Invalid choice. Please try again.\n");
            }
        }
    } else if (mode == 2) {
        int choice;
        while (1) {
            printf("\nUser Menu:\n");
            printf("1. View patient record\n");
            printf("2. View today's reservations\n");
            printf("3. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    viewPatientRecord();
                    break;
                case 2:
                    viewReservations();
                    break;
                case 3:
                    printf("Exiting...\n");
                    exit(0);
                default:
                    printf("Invalid choice. Please try again.\n");
            }
        }
    }

}
