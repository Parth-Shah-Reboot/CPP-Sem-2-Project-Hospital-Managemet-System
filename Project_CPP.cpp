#include <stdio.h>
#include <string.h>

class Patient
{
public:
    int patientID;
    char name[50];
    int age;
    char gender[10];
    char disease[50];
    char doctor[50];
    char admissionDate[20];
    char contact[15];
    int bedNumber;
    int occupied;

    Patient()
    {
        patientID = 0;
        age = 0;
        bedNumber = 0;
        occupied = 0;
        strcpy(name, "");
        strcpy(gender, "");
        strcpy(disease, "");
        strcpy(doctor, "");
        strcpy(admissionDate, "");
        strcpy(contact, "");
    }
};

class Hospital
{
public:
    Patient opd[10];
    Patient icu[10];
    Patient general[20];

    int opdBeds;
    int icuBeds;
    int generalBeds;

    Hospital()
    {
        opdBeds = 10;
        icuBeds = 10;
        generalBeds = 20;

        opd[0].patientID = 101;
        strcpy(opd[0].name, "Rahul Sharma");
        opd[0].age = 25;
        strcpy(opd[0].gender, "Male");
        strcpy(opd[0].disease, "Fever");
        strcpy(opd[0].doctor, "Dr. Mehta");
        strcpy(opd[0].admissionDate, "20-10-2026");
        strcpy(opd[0].contact, "9876543210");
        opd[0].bedNumber = 1;
        opd[0].occupied = 1;

        opd[3].patientID = 102;
        strcpy(opd[3].name, "Priya Patel");
        opd[3].age = 32;
        strcpy(opd[3].gender, "Female");
        strcpy(opd[3].disease, "Migraine");
        strcpy(opd[3].doctor, "Dr. Shah");
        strcpy(opd[3].admissionDate, "21-10-2026");
        strcpy(opd[3].contact, "9876501234");
        opd[3].bedNumber = 4;
        opd[3].occupied = 1;

        icu[1].patientID = 201;
        strcpy(icu[1].name, "Amit Verma");
        icu[1].age = 58;
        strcpy(icu[1].gender, "Male");
        strcpy(icu[1].disease, "Cardiac Observation");
        strcpy(icu[1].doctor, "Dr. Desai");
        strcpy(icu[1].admissionDate, "19-10-2026");
        strcpy(icu[1].contact, "9812345670");
        icu[1].bedNumber = 2;
        icu[1].occupied = 1;

        icu[5].patientID = 202;
        strcpy(icu[5].name, "Neha Joshi");
        icu[5].age = 45;
        strcpy(icu[5].gender, "Female");
        strcpy(icu[5].disease, "Respiratory Observation");
        strcpy(icu[5].doctor, "Dr. Patel");
        strcpy(icu[5].admissionDate, "20-10-2026");
        strcpy(icu[5].contact, "9898765432");
        icu[5].bedNumber = 6;
        icu[5].occupied = 1;

        general[0].patientID = 301;
        strcpy(general[0].name, "Karan Singh");
        general[0].age = 40;
        strcpy(general[0].gender, "Male");
        strcpy(general[0].disease, "Fracture");
        strcpy(general[0].doctor, "Dr. Rao");
        strcpy(general[0].admissionDate, "18-10-2026");
        strcpy(general[0].contact, "9823456780");
        general[0].bedNumber = 1;
        general[0].occupied = 1;

        general[4].patientID = 302;
        strcpy(general[4].name, "Anjali Desai");
        general[4].age = 29;
        strcpy(general[4].gender, "Female");
        strcpy(general[4].disease, "Postoperative Recovery");
        strcpy(general[4].doctor, "Dr. Shah");
        strcpy(general[4].admissionDate, "20-10-2026");
        strcpy(general[4].contact, "9876123450");
        general[4].bedNumber = 5;
        general[4].occupied = 1;

        general[8].patientID = 303;
        strcpy(general[8].name, "Vikram Patel");
        general[8].age = 65;
        strcpy(general[8].gender, "Male");
        strcpy(general[8].disease, "Pneumonia");
        strcpy(general[8].doctor, "Dr. Mehta");
        strcpy(general[8].admissionDate, "21-10-2026");
        strcpy(general[8].contact, "9898123456");
        general[8].bedNumber = 9;
        general[8].occupied = 1;
    }

    void admitPatient(Patient beds[], int totalBeds, const char facility[])
    {
        int bed;

        printf("\nEnter bed number (1-%d): ", totalBeds);
        scanf("%d", &bed);

        if (bed < 1 || bed > totalBeds)
        {
            printf("Invalid bed number.\n");
            return;
        }

        if (beds[bed - 1].occupied == 1)
        {
            printf("This bed is already occupied.\n");
            return;
        }

        printf("Enter patient ID: ");
        scanf("%d", &beds[bed - 1].patientID);

        if (findPatient(beds[bed - 1].patientID))
        {
            printf("This patient ID already exists.\n");
            beds[bed - 1].patientID = 0;
            return;
        }

        printf("Enter patient name: ");
        scanf(" %49[^\n]", beds[bed - 1].name);

        printf("Enter patient age: ");
        scanf("%d", &beds[bed - 1].age);

        printf("Enter gender: ");
        scanf("%9s", beds[bed - 1].gender);

        printf("Enter disease or condition: ");
        scanf(" %49[^\n]", beds[bed - 1].disease);

        printf("Enter doctor's name: ");
        scanf(" %49[^\n]", beds[bed - 1].doctor);

        printf("Enter admission date (DD-MM-YYYY): ");
        scanf("%19s", beds[bed - 1].admissionDate);

        printf("Enter contact number: ");
        scanf("%14s", beds[bed - 1].contact);

        beds[bed - 1].bedNumber = bed;
        beds[bed - 1].occupied = 1;

        printf("\nPatient admitted successfully to %s.\n", facility);
    }

    int findPatient(int id)
    {
        for (int i = 0; i < opdBeds; i++)
            if (opd[i].occupied && opd[i].patientID == id)
                return 1;

        for (int i = 0; i < icuBeds; i++)
            if (icu[i].occupied && icu[i].patientID == id)
                return 1;

        for (int i = 0; i < generalBeds; i++)
            if (general[i].occupied && general[i].patientID == id)
                return 1;

        return 0;
    }

    void patientSummary(Patient beds[], int totalBeds, const char facility[], int id)
    {
        for (int i = 0; i < totalBeds; i++)
        {
            if (beds[i].occupied && beds[i].patientID == id)
            {
                printf("\n========== PATIENT SUMMARY ==========\n");
                printf("Patient ID: %d\n", beds[i].patientID);
                printf("Name: %s\n", beds[i].name);
                printf("Age: %d\n", beds[i].age);
                printf("Gender: %s\n", beds[i].gender);
                printf("Disease/Condition: %s\n", beds[i].disease);
                printf("Doctor: %s\n", beds[i].doctor);
                printf("Admission Date: %s\n", beds[i].admissionDate);
                printf("Contact: %s\n", beds[i].contact);
                printf("Facility: %s\n", facility);
                printf("Bed Number: %d\n", beds[i].bedNumber);
                printf("Bed Status: OCCUPIED\n");
                printf("=====================================\n");
                return;
            }
        }
    }

    void searchPatient()
    {
        int id;

        printf("\nEnter Patient ID: ");
        scanf("%d", &id);

        for (int i = 0; i < opdBeds; i++)
        {
            if (opd[i].occupied && opd[i].patientID == id)
            {
                patientSummary(opd, opdBeds, "OPD", id);
                return;
            }
        }

        for (int i = 0; i < icuBeds; i++)
        {
            if (icu[i].occupied && icu[i].patientID == id)
            {
                patientSummary(icu, icuBeds, "ICU", id);
                return;
            }
        }

        for (int i = 0; i < generalBeds; i++)
        {
            if (general[i].occupied && general[i].patientID == id)
            {
                patientSummary(general, generalBeds, "General Ward", id);
                return;
            }
        }

        printf("Patient not found.\n");
    }

    void dischargePatient(Patient beds[], int totalBeds)
    {
        int bed;

        printf("\nEnter bed number to discharge patient: ");
        scanf("%d", &bed);

        if (bed < 1 || bed > totalBeds)
        {
            printf("Invalid bed number.\n");
            return;
        }

        if (beds[bed - 1].occupied == 0)
        {
            printf("This bed is already free.\n");
            return;
        }

        printf("Patient %s discharged successfully.\n", beds[bed - 1].name);
        beds[bed - 1].occupied = 0;
    }

    void displayBeds(Patient beds[], int totalBeds, const char facility[])
    {
        int freeBeds = 0;

        printf("\n========== %s ==========\n", facility);

        for (int i = 0; i < totalBeds; i++)
        {
            if (beds[i].occupied)
            {
                printf("Bed %d: OCCUPIED | Patient ID: %d | Name: %s\n",
                       i + 1, beds[i].patientID, beds[i].name);
            }
            else
            {
                printf("Bed %d: FREE\n", i + 1);
                freeBeds++;
            }
        }

        printf("\nTotal Beds: %d\n", totalBeds);
        printf("Occupied Beds: %d\n", totalBeds - freeBeds);
        printf("Free Beds: %d\n", freeBeds);
    }

    void hospitalSummary()
    {
        int occupiedOPD = 0;
        int occupiedICU = 0;
        int occupiedGeneral = 0;

        for (int i = 0; i < opdBeds; i++)
            occupiedOPD += opd[i].occupied;

        for (int i = 0; i < icuBeds; i++)
            occupiedICU += icu[i].occupied;

        for (int i = 0; i < generalBeds; i++)
            occupiedGeneral += general[i].occupied;

        printf("\n========== HOSPITAL SUMMARY ==========\n");

        printf("\nOPD\n");
        printf("Total Beds: %d\n", opdBeds);
        printf("Occupied: %d\n", occupiedOPD);
        printf("Free: %d\n", opdBeds - occupiedOPD);

        printf("\nICU\n");
        printf("Total Beds: %d\n", icuBeds);
        printf("Occupied: %d\n", occupiedICU);
        printf("Free: %d\n", icuBeds - occupiedICU);

        printf("\nGENERAL WARD\n");
        printf("Total Beds: %d\n", generalBeds);
        printf("Occupied: %d\n", occupiedGeneral);
        printf("Free: %d\n", generalBeds - occupiedGeneral);

        printf("\nTOTAL HOSPITAL\n");
        printf("Total Beds: %d\n", opdBeds + icuBeds + generalBeds);

        printf("Occupied Beds: %d\n",
               occupiedOPD + occupiedICU + occupiedGeneral);

        printf("Free Beds: %d\n",
               opdBeds + icuBeds + generalBeds
               - occupiedOPD - occupiedICU - occupiedGeneral);

        printf("======================================\n");
    }

    void menu()
    {
        int choice;
        int facility;

        do
        {
            printf("\n===== HOSPITAL MANAGEMENT SYSTEM =====\n");
            printf("1. Admit Patient\n");
            printf("2. Discharge Patient\n");
            printf("3. Display OPD Beds\n");
            printf("4. Display ICU Beds\n");
            printf("5. Display General Ward Beds\n");
            printf("6. Hospital Summary\n");
            printf("7. View Patient Summary\n");
            printf("8. Exit\n");

            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
                case 1:
                    printf("\n1. OPD\n2. ICU\n3. General Ward\n");
                    printf("Select facility: ");
                    scanf("%d", &facility);

                    if (facility == 1)
                        admitPatient(opd, opdBeds, "OPD");
                    else if (facility == 2)
                        admitPatient(icu, icuBeds, "ICU");
                    else if (facility == 3)
                        admitPatient(general, generalBeds, "General Ward");
                    else
                        printf("Invalid facility.\n");
                    break;

                case 2:
                    printf("\n1. OPD\n2. ICU\n3. General Ward\n");
                    printf("Select facility: ");
                    scanf("%d", &facility);

                    if (facility == 1)
                        dischargePatient(opd, opdBeds);
                    else if (facility == 2)
                        dischargePatient(icu, icuBeds);
                    else if (facility == 3)
                        dischargePatient(general, generalBeds);
                    else
                        printf("Invalid facility.\n");
                    break;

                case 3:
                    displayBeds(opd, opdBeds, "OPD");
                    break;

                case 4:
                    displayBeds(icu, icuBeds, "ICU");
                    break;

                case 5:
                    displayBeds(general, generalBeds, "General Ward");
                    break;

                case 6:
                    hospitalSummary();
                    break;

                case 7:
                    searchPatient();
                    break;

                case 8:
                    printf("Exiting Hospital Management System.\n");
                    break;

                default:
                    printf("Invalid choice. Try again.\n");
            }

        } while (choice != 8);
    }
};

int main()
{
    Hospital h;
    h.menu();
    return 0;
}