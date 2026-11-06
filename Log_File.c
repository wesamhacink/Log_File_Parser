
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *file;
    char filename[256];
    char line[512];
    char keyword[] = "FAILED";

    int lineNumber = 0;
    int alertCount = 0;

    // Ask user to enter log file name
    printf("Enter log file name: ");
    scanf("%255s", filename);

    // Open the user-specified file
    file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Error: Cannot open file!\n");
        return 1;
    }

    // Read file line by line
    while (fgets(line, sizeof(line), file) != NULL)
    {
        lineNumber++;

        // Search for suspicious keyword
        if (strstr(line, keyword) != NULL)
        {
            alertCount++;

            printf("[ALERT] Line %d: %s",
                   lineNumber, line);
        }
    }

    // Display final report
    printf("\n========== Security Report ==========\n");
    printf("File: %s\n", filename);
    printf("Keyword: %s\n", keyword);
    printf("Total Alerts Found: %d\n", alertCount);

    fclose(file);

    return 0;
}
