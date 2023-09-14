#include "STD_TYPES.h"


typedef struct
{
    char name[50];
    int age;
    char gender;
    int id;
} Patient;



typedef struct
{
    int slot;
    int patientId;
} Reservation;


Patient patients[MAX_PATIENTS];
Reservation reservations[MAX_SLOTS];


uint32 isAdminMode();
uint32 validatePassword();
void addPatient() ;
void editPatient();
void displayAvailableSlots();
void reserveSlot();
void cancelReservation();
void viewPatientRecord();
void viewReservations();
void SDB_APP (void);
