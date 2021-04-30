#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//

// SearchType is the enumeration of the options for a search.
//Searches can be a ROUTE (origin to destination),ORIGIN only, DESTINATION only, AIRLINE company, or a QUIT command.
typedef enum SearchType
{
    ROUTE = 1,
    ORIGIN,
    DESTINATION,
    AIRLINE,
    QUIT,
} SearchType;

// RouteRecord is the combination of a flight's origin, destination, id, and number of passengers
typedef struct RouteRecord_struct
{
    char origin[4];
    char destination[4];
    char airline[4];
    int passengers[7];
} RouteRecord;

// checkFileOpening returns -1 if inputFile opened improperly, and 0 otherwise
int checkFileOpening(FILE *inputFile)
{
    int output = 0;

    if (inputFile == NULL)
    {
        printf("Error\n");
        output = -1;
    }
    return output;
}

// getFileLength returns an int of the length of fileName
int getFileLength(FILE *inputFile)
{
    //creates file pointer
    int output;
    //counts the number of lines
    char buffer[1000];
    while (!feof(inputFile) && output != -1)
    {
        fgets(buffer, 1000, inputFile);
        output++;
    }
    rewind(inputFile);
    return output;
}

// createRecords returns a pointer to the start of a RouteRecords array from the File pointer, it accounts for headers
RouteRecord *createRecords(FILE *inputFile)
{
    RouteRecord *flights;
    int fileLength = getFileLength(inputFile);
    fileLength -= checkCSVHeader(inputFile);
    flights = (RouteRecord *)malloc(sizeof(RouteRecord) * fileLength);
    return flights;
}
// stringUpper takes a string and uppercases all of it
void stringUpper(char *lowered)
{
    int i;
    for (i = 0; i < strlen(lowered); i++)
    {
        lowered[i] = toupper(lowered[i]);
    }
}

// checkCSVHeader returns 1 if there is a file header, and 0 if there is none, from a parameter of an input file
// a CSV file header must start with "Month"
int checkCSVHeader(FILE *inputFile)
{

    char buffer[1000];
    fgets(buffer, 1000, inputFile);
    char tester[5];
    sscanf(buffer, "%5[^,]", tester);
    stringUpper(tester);
    if (strcmp(tester, "MONTH") == 0)
    {
        rewind(inputFile);
        return 1;
    }
    rewind(inputFile);
    return 0;
}

// fillRecords returns the usable length of an array flights, and fills flights with data from an inputFile
// fillRecords assumes file is sorted by months
int fillRecords(RouteRecord *flights, FILE *inputFile)
{
    int month;
    char origin[4];
    char destination[4];
    char airline[4];
    char flightType[20];
    int passengers;

    char buffer[1000];
    int flightsLength = 0;
    int flightIndex;
    int passengersIndex;

    int fileLength = getFileLength(inputFile);
    int i = checkCSVHeader(inputFile);
    if (i == 1)
    {
        fgets(buffer, 1000, inputFile);
    }

    while (i < fileLength && !feof(inputFile))
    {
        fgets(buffer, 1000, inputFile);
        sscanf(buffer, "%d,%3[^,],%3[^,],%3[^,],%20[^,],%d", &month, origin, destination, airline, flightType, &passengers);
        //printf("%d|%s|%s|%s|%s|%d\n", month, origin, destination, airline, flightType, passengers);
        if (strlen(airline) != 3)
        {
            flightIndex = findAirlineRoute(flights, flightsLength, origin, destination, airline);
            if (flightIndex == -1)
            {
                strcpy((*(flights + flightsLength)).origin, origin);
                strcpy((*(flights + flightsLength)).destination, destination);
                strcpy((*(flights + flightsLength)).airline, airline);
                for (passengersIndex = 0; passengersIndex < 6; passengersIndex++)
                {
                    (*(flights + flightsLength)).passengers[passengersIndex] = 0;
                }
                (*(flights + flightsLength)).passengers[month - 1] = passengers;
                flightsLength++;
            }
            else
            {
                (*(flights + flightIndex)).passengers[month - 1] = passengers;
            }
        }
        i++;
    }

    printf("Unique routes operated by airlines: %d\n", flightsLength);
    return flightsLength;
}

// findAirlineRoute returns -1 if the inputted RouteRecord data is new to an inputted array, in the case of a duplicate it returns the index in flights the dupe is.
int findAirlineRoute(RouteRecord *flights, int flightsLength, char *origin, char *destination, char *airline)
{
    int test = -1;
    int i = 0;
    while (i < flightsLength && test == -1)
    {
        RouteRecord compare = (*(flights + i));
        if (strcmp(compare.origin, origin) == 0)
        {
            if (strcmp(compare.destination, destination) == 0)
            {
                if (strcmp(compare.airline, airline) == 0)
                {

                    test = i;
                }
            }
        }
        i++;
    }
    return test;
}

// printMenu prints the script to direct the user for input
void printMenu()
{
    printf("\n\n######### Airline Route Records Database MENU #########\n");
    printf("1. Search by Route\n");
    printf("2. Search by Origin Airport\n");
    printf("3. Search by Destination Airport\n");
    printf("4. Search by Airline\n");
    printf("5. Quit\n");
    printf("Enter your selection: ");
}

// getMenuOption returns the enum of  choice of the user, and fills the search keys key1 and key2
SearchType getMenuOption(char *key1, char *key2)
{
    printMenu();
    int searchKind;
    int checker;
    char buf[100];

    do
    {
        checker = scanf("%d", &searchKind);
        while (checker == 0)
        {
            printf("Error: invalid option\n");
            printf("Please enter an INTEGER option:");
            fgets(buf, 100, stdin);
            checker = scanf("%d", &searchKind);
        }

        switch (searchKind)
        {
        case ROUTE:
            printf("Enter the origin: ");
            scanf("%s", key1);
            printf("Enter the destination: ");
            scanf("%s", key2);
            break;

        case ORIGIN:
            printf("Enter the origin: ");
            scanf("%s", key1);
            break;

        case DESTINATION:
            printf("Enter the destination: ");
            scanf("%s", key1);
            break;

        case AIRLINE:
            printf("Enter the airline: ");
            scanf("%s", key1);
            break;

        case QUIT:
            break;

        default:
            printf("Error: invalid option\n");
            printf("Please choose an option 1-5: ");
            break;
        }
    } while (searchKind != ROUTE && searchKind != ORIGIN && searchKind != DESTINATION && searchKind != AIRLINE && searchKind != QUIT);
    return searchKind;
}

// searchRecords prints search results from an list of flights, its length, search keys, and search type
void searchRecords(RouteRecord *flights, int flightsLength, char *key1, char *key2, SearchType searchKind)
{
    int i;
    int j;
    int matches = 0;
    RouteRecord *compare;

    int totalPassengers[6] = {0, 0, 0, 0, 0, 0};
    printf("\n");
    switch (searchKind)
    {
    case ROUTE:
        printf("Searching by route...\n");
        for (i = 0; i < flightsLength; i++)
        {
            if (strcmp(flights[i].origin, key1) == 0 && strcmp(flights[i].destination, key2) == 0)
            {
                matches++;
                printf("%s (%s-%s)  ", flights[i].airline, flights[i].origin, flights[i].destination);
                for (j = 0; j < 6; j++)
                {
                    (totalPassengers[j]) += flights[i].passengers[j];
                }
                if (i == 10)
                {
                    printf("\n");
                }
            }
        }
        break;

    case ORIGIN:
        printf("Searching by origin...\n");
        for (i = 0; i < flightsLength; i++)
        {
            if (strcmp(flights[i].origin, key1) == 0)
            {
                matches++;
                printf("%s (%s-%s)  ", flights[i].airline, flights[i].origin, flights[i].destination);
                for (j = 0; j < 6; j++)
                {
                    (totalPassengers[j]) += flights[i].passengers[j];
                }
                if (i == 10)
                {
                    printf("\n");
                }
            }
        }
        break;

    case DESTINATION:
        printf("Searching by destination...\n");
        for (i = 0; i < flightsLength; i++)
        {
            if (strcmp(flights[i].destination, key1) == 0)
            {
                matches++;
                printf("%s (%s-%s)", flights[i].airline, flights[i].origin, flights[i].destination);
                for (j = 0; j < 6; j++)
                {
                    totalPassengers[j] += flights[i].passengers[j];
                }
                if (i == 10)
                {
                    printf("\n");
                }
            }
        }

    case AIRLINE:

        printf("Searching by airline...\n");
        for (i = 0; i < flightsLength; i++)
        {
            if (strcmp(flights[i].airline, key1) == 0)
            {
                printf("%s (%s-%s)", flights[i].airline, flights[i].origin, flights[i].destination);
                for (j = 0; j < 6; j++)
                {
                    totalPassengers[j] += flights[i].passengers[j];
                }
                if (i == 10)
                {
                    printf("\n");
                }
            }
        }

        break;

    default:
        break;
    }
    printf("\n%d matches were found.\n", matches);
    printf("\n");
    printf("Statistics:\n");
    int totaltotal = totalPassengers[0] + totalPassengers[1] + totalPassengers[2] + totalPassengers[3] + totalPassengers[4] + totalPassengers[5];
    printf("Total Passengers: %d\n", totaltotal);
    for (i = 0; i < 6; i++)
    {
        printf("Total Passengers in Month %d: %d\n", i + 1,
               totalPassengers[i]);
    }
    printf("\n");
    printf("Average Passengers per month: %d\n", totaltotal / 6);
    printf("\n");
}
