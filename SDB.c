#include "SDB.h"

int numPatients = 0;
int numReservations = 0;

uint32 isAdminMode()
{
    uint32 mode;
    printf("Choose mode:\n");
    printf("1. Admin mode\n");
    printf("2. User mode\n");
    printf("Enter mode number: ");
    scanf("%d", &mode);
    return mode == 1;
}

uint32 validatePassword()
{
    uint32 attempts = 0;
    uint32 password;

    while (attempts < PASSWORD_ATTEMPTS)
    {
        printf("Enter password: ");
        scanf("%d", &password);

        if (password == 1234)
        {
            return 1;
        }
        else
        {
            attempts++;
            printf("Incorrect password. Attempts left: %d\n", PASSWORD_ATTEMPTS - attempts);
        }
    }

    return 0;
}

void addPatient()
{
    Patient patient;
    printf("Enter patient name: ");
    scanf("%s", patient.name);
    printf("Enter patient age: ");
    scanf("%d", &patient.age);
    printf("Enter patient gender (M/F): ");
    scanf(" %c", &patient.gender);
    printf("Enter patient ID: ");
    scanf("%d", &patient.id);

    // Check if ID already exists
    for (uint32 i = 0; i < numPatients; i++)
    {
        if (patients[i].id == patient.id)
        {
            printf("ID already exists. Patient record not added.\n");
            return;
        }
    }

    patients[numPatients++] = patient;
    printf("Patient record added successfully.\n");
}

void editPatient()
{
    uint32 id;
    printf("Enter patient ID to edit: ");
    scanf("%d", &id);

    // Find patient by ID
    uint32 index = -1;
    for (uint32 i = 0; i < numPatients; i++)
    {
        if (patients[i].id == id)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        printf("Enter new patient name: ");
        scanf("%s", patients[index].name);
        printf("Enter new patient age: ");
        scanf("%d", &patients[index].age);
        printf("Enter new patient gender (M/F): ");
        scanf(" %c", &patients[index].gender);
        printf("Patient record updated successfully.\n");
    }
    else
    {
        printf("Incorrect ID. Patient record not found.\n");
    }
}

void displayAvailableSlots()
{
    printf("Available slots:\n");
    for (uint32 i = 0; i < MAX_SLOTS; i++)
    {
        if (reservations[i].patientId == -1)
        {
            printf("%d. ", i + 1);
            switch (i)
            {
            case 0:
                printf("2pm to 2:30pm\n");
                break;
            case 1:
                printf("2:30pm to 3pm\n");
                break;
            case 2:
                printf("3pm to 3:30pm\n");
                break;
            case 3:
                printf("4pm to 4:30pm\n");
                break;
            case 4:
                printf("4:30pm to 5pm\n");
                break;
            }
        }
    }
}

void reserveSlot()
{
    uint32 id, slot;
    printf("Enter patient ID: ");
    scanf("%d", &id);
    printf("Enter desired slot number: ");
    scanf("%d", &slot);

    if (slot < 1 || slot > MAX_SLOTS)
    {
        printf("Invalid slot number.\n");
        return;
    }

    // Check if slot is already reserved
    if (reservations[slot - 1].patientId != -1)
    {
        printf("Slot is already reserved.\n");
        return;
    }

    reservations[slot - 1].patientId = id;
    printf("Reservation successful.\n");
}

void cancelReservation()
{
    uint32 id;
    printf("Enter patient ID to cancel reservation: ");
    scanf("%d", &id);

    // Find reservation by patient ID
    uint32 index = -1;
    for (uint32 i = 0; i < MAX_SLOTS; i++)
    {
        if (reservations[i].patientId == id)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        reservations[index].patientId = -1;
        printf("Reservation canceled successfully.\n");
    }
    else
    {
        printf("Reservation not found.\n");
    }
}

void viewPatientRecord()
{
    uint32 id;
    printf("Enter patient ID: ");
    scanf("%d", &id);

    // Find patient by ID
    uint32 index = -1;
    for (uint32 i = 0; i < numPatients; i++)
    {
        if (patients[i].id == id)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        printf("Patient Name: %s\n", patients[index].name);
        printf("Patient Age: %d\n", patients[index].age);
        printf("Patient Gender: %c\n", patients[index].gender);
    }
    else
    {
        printf("Patient record not found.\n");
    }
}

void viewReservations()
{
    printf("Today's reservations:\n");
    for (int i = 0; i < MAX_SLOTS; i++)
    {
        if (reservations[i].patientId != -1)
        {
            printf("Slot %d: Patient ID - %d\n", i + 1, reservations[i].patientId);
        }
    }
}

