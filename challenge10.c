
#include <stdio.h>

#define ZONES 5
#define DAYS 7

void inputData(float temp[ZONES][DAYS],
               float humidity[ZONES][DAYS],
               int aqi[ZONES][DAYS]);

void displayData(float temp[ZONES][DAYS],
                 float humidity[ZONES][DAYS],
                 int aqi[ZONES][DAYS]);

void calculateAverages(float temp[ZONES][DAYS],
                       float humidity[ZONES][DAYS],
                       int aqi[ZONES][DAYS],
                       float avgTemp[ZONES],
                       float avgHumidity[ZONES],
                       float avgAQI[ZONES]);

void detectRiskZones(float temp[ZONES][DAYS],
                     float humidity[ZONES][DAYS],
                     int aqi[ZONES][DAYS],
                     int riskDays[ZONES]);

void computeGreenIndex(float avgTemp[ZONES],
                       float avgHumidity[ZONES],
                       float avgAQI[ZONES],
                       float greenIndex[ZONES]);

void displayRanking(float greenIndex[ZONES]);

void displayRecommendations(float avgTemp[ZONES],
                            float avgHumidity[ZONES],
                            float avgAQI[ZONES],
                            int riskDays[ZONES]);

void zoneName(int i);

int main()
{
    float temp[ZONES][DAYS];
    float humidity[ZONES][DAYS];
    int aqi[ZONES][DAYS];

    float avgTemp[ZONES];
    float avgHumidity[ZONES];
    float avgAQI[ZONES];

    float greenIndex[ZONES];

    int riskDays[ZONES];

    int choice;
    int dataReady = 0;
    int dataSource = 0;
    int i;

    do
    {
        printf("\n CAMPUS ENVIRONMENT \n");

        printf("\n1. Input / Update Data");
        printf("\n2. Display Data");
        printf("\n3. Zone-wise Averages");
        printf("\n4. Detect Risk Days");
        printf("\n5. Green Index and Ranking");
        printf("\n6. Recommendations");
        printf("\n7. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:

                printf("\n1. Authorised Campus Readings");
                printf("\n2. Simulated / Sample Data");

                printf("\nSelect data source: ");
                scanf("%d", &dataSource);

                while(dataSource < 1 || dataSource > 2)
                {
                    printf("Invalid choice. Enter 1 or 2: ");
                    scanf("%d", &dataSource);
                }

                inputData(temp, humidity, aqi);

                dataReady = 1;

                printf("\nData entered successfully!\n");

                break;

            case 2:

                if(dataReady == 0)
                {
                    printf("\nPlease enter data first!\n");
                }
                else
                {
                    if(dataSource == 2)
                    {
                        printf("\nSIMULATED DATA - NOT REAL CAMPUS MEASUREMENTS\n");
                    }

                    displayData(temp, humidity, aqi);
                }

                break;

            case 3:

                if(dataReady == 0)
                {
                    printf("\nPlease enter data first!\n");
                }
                else
                {
                    calculateAverages(temp, humidity, aqi,
                                      avgTemp, avgHumidity, avgAQI);

                    printf("\n AVERAGES \n");

                    for(i = 0; i < ZONES; i++)
                    {
                        zoneName(i);

                        printf("\nTemperature: %.2f", avgTemp[i]);
                        printf("\nHumidity: %.2f", avgHumidity[i]);
                        printf("\nAQI: %.2f\n", avgAQI[i]);
                    }
                }

                break;

            case 4:

                if(dataReady == 0)
                {
                    printf("\nPlease enter data first!\n");
                }
                else
                {
                    detectRiskZones(temp, humidity, aqi, riskDays);
                }

                break;

            case 5:

                if(dataReady == 0)
                {
                    printf("\nPlease enter data first!\n");
                }
                else
                {
                    calculateAverages(temp, humidity, aqi,
                                      avgTemp, avgHumidity, avgAQI);

                    computeGreenIndex(avgTemp, avgHumidity,
                                      avgAQI, greenIndex);

                    displayRanking(greenIndex);
                }

                break;

            case 6:

                if(dataReady == 0)
                {
                    printf("\nPlease enter data first!\n");
                }
                else
                {
                    calculateAverages(temp, humidity, aqi,
                                      avgTemp, avgHumidity, avgAQI);

                    detectRiskZones(temp, humidity, aqi, riskDays);

                    displayRecommendations(avgTemp, avgHumidity,
                                           avgAQI, riskDays);
                }

                break;

            case 7:

                printf("\nThank you!\n");

                break;

            default:

                printf("\nInvalid choice!\n");
        }

    } while(choice != 7);

    return 0;
}


void zoneName(int i)
{
    switch(i)
    {
        case 0:
            printf("Academic Block");
            break;

        case 1:
            printf("Hostel");
            break;

        case 2:
            printf("Library");
            break;

        case 3:
            printf("Cafeteria");
            break;

        case 4:
            printf("Sports Area");
            break;
    }
}


void inputData(float temp[ZONES][DAYS],
               float humidity[ZONES][DAYS],
               int aqi[ZONES][DAYS])
{
    int i, j;

    for(i = 0; i < ZONES; i++)
    {
        printf("\n\n");
        zoneName(i);

        for(j = 0; j < DAYS; j++)
        {
            printf("\nDay %d\n", j + 1);

            do
            {
                printf("Enter Temperature: ");
                scanf("%f", &temp[i][j]);

                if(temp[i][j] < 10 || temp[i][j] > 50)
                {
                    printf("Invalid! Enter between 10 and 50.\n");
                }

            } while(temp[i][j] < 10 || temp[i][j] > 50);

            do
            {
                printf("Enter Humidity: ");
                scanf("%f", &humidity[i][j]);

                if(humidity[i][j] < 0 || humidity[i][j] > 100)
                {
                    printf("Invalid! Enter between 0 and 100.\n");
                }

            } while(humidity[i][j] < 0 || humidity[i][j] > 100);

            do
            {
                printf("Enter AQI: ");
                scanf("%d", &aqi[i][j]);

                if(aqi[i][j] < 0 || aqi[i][j] > 500)
                {
                    printf("Invalid! Enter between 0 and 500.\n");
                }

            } while(aqi[i][j] < 0 || aqi[i][j] > 500);
        }
    }
}

void displayData(float temp[ZONES][DAYS],
                 float humidity[ZONES][DAYS],
                 int aqi[ZONES][DAYS])
{
    int i, j;

    printf("\n TEMPERATURE \n");

    printf("Zone\t");

    for(j = 0; j < DAYS; j++)
    {
        printf("D%d\t", j + 1);
    }

    printf("\n");

    for(i = 0; i < ZONES; i++)
    {
        zoneName(i);
        printf("\t");

        for(j = 0; j < DAYS; j++)
        {
            printf("%.1f\t", temp[i][j]);
        }

        printf("\n");
    }

    printf("\n HUMIDITY \n");

    printf("Zone\t");

    for(j = 0; j < DAYS; j++)
    {
        printf("D%d\t", j + 1);
    }

    printf("\n");

    for(i = 0; i < ZONES; i++)
    {
        zoneName(i);
        printf("\t");

        for(j = 0; j < DAYS; j++)
        {
            printf("%.1f\t", humidity[i][j]);
        }

        printf("\n");
    }

    printf("\n AQI \n");

    printf("Zone\t");

    for(j = 0; j < DAYS; j++)
    {
        printf("D%d\t", j + 1);
    }

    printf("\n");

    for(i = 0; i < ZONES; i++)
    {
        zoneName(i);
        printf("\t");

        for(j = 0; j < DAYS; j++)
        {
            printf("%d\t", aqi[i][j]);
        }

        printf("\n");
    }
}

void calculateAverages(float temp[ZONES][DAYS],
                       float humidity[ZONES][DAYS],
                       int aqi[ZONES][DAYS],
                       float avgTemp[ZONES],
                       float avgHumidity[ZONES],
                       float avgAQI[ZONES])
{
    int i, j;

    float t, h, a;

    for(i = 0; i < ZONES; i++)
    {
        t = 0;
        h = 0;
        a = 0;

        for(j = 0; j < DAYS; j++)
        {
            t = t + temp[i][j];
            h = h + humidity[i][j];
            a = a + aqi[i][j];
        }

        avgTemp[i] = t / DAYS;
        avgHumidity[i] = h / DAYS;
        avgAQI[i] = a / DAYS;
    }
}


void detectRiskZones(float temp[ZONES][DAYS],
                     float humidity[ZONES][DAYS],
                     int aqi[ZONES][DAYS],
                     int riskDays[ZONES])
{
    int i, j;

    printf("\n RISK REPORT \n");

    for(i = 0; i < ZONES; i++)
    {
        riskDays[i] = 0;

        zoneName(i);

        printf("\nRisk Days: ");

        for(j = 0; j < DAYS; j++)
        {
            if(aqi[i][j] > 150 ||
               temp[i][j] > 35 ||
               humidity[i][j] > 80)
            {
                riskDays[i]++;

                printf("%d ", j + 1);
            }
        }

        if(riskDays[i] == 0)
        {
            printf("None");
        }

        printf("\nTotal Risk Days: %d\n", riskDays[i]);
    }
}


void computeGreenIndex(float avgTemp[ZONES],
                       float avgHumidity[ZONES],
                       float avgAQI[ZONES],
                       float greenIndex[ZONES])
{
    int i;

    float aq, ts, hs;
    float td, hd;

    for(i = 0; i < ZONES; i++)
    {
        aq = 100 - (avgAQI[i] / 5);

        td = avgTemp[i] - 25;

        if(td < 0)
        {
            td = -td;
        }

        ts = 100 - (4 * td);

        hd = avgHumidity[i] - 50;

        if(hd < 0)
        {
            hd = -hd;
        }

        hs = 100 - (2 * hd);

        if(aq < 0)
        {
            aq = 0;
        }

        if(ts < 0)
        {
            ts = 0;
        }

        if(hs < 0)
        {
            hs = 0;
        }

        greenIndex[i] = (0.4 * aq) +
                        (0.3 * ts) +
                        (0.3 * hs);
    }
}


void displayRanking(float greenIndex[ZONES])
{
    int rank[ZONES];

    int i, j, r;

    for(i = 0; i < ZONES; i++)
    {
        rank[i] = 1;

        for(j = 0; j < ZONES; j++)
        {
            if(greenIndex[j] > greenIndex[i])
            {
                rank[i]++;
            }
        }
    }

    printf("\n GREEN INDEX RANKING \n");

    printf("\nRank\tZone\t\tGreen Index\n");

    for(r = 1; r <= ZONES; r++)
    {
        for(i = 0; i < ZONES; i++)
        {
            if(rank[i] == r)
            {
                printf("%d\t", rank[i]);

                zoneName(i);

                printf("\t%.2f\n", greenIndex[i]);
            }
        }
    }
}


void displayRecommendations(float avgTemp[ZONES],
                            float avgHumidity[ZONES],
                            float avgAQI[ZONES],
                            int riskDays[ZONES])
{
    int i;
    int found;

    printf("\n RECOMMENDATIONS \n");

    for(i = 0; i < ZONES; i++)
    {
        found = 0;

        zoneName(i);

        printf("\n");

        if(avgAQI[i] > 150)
        {
            printf("- Reduce vehicle idling or improve ventilation.\n");
            found = 1;
        }

        if(avgTemp[i] > 35)
        {
            printf("- Provide shade and increase green cover.\n");
            found = 1;
        }

        if(avgHumidity[i] > 80)
        {
            printf("- Check ventilation and stagnant water.\n");
            found = 1;
        }

        if(found == 0 && riskDays[i] > 0)
        {
            printf("- Review the individual risk days.\n");
        }

        if(riskDays[i] == 0)
        {
            printf("- No risk detected. Continue monitoring.\n");
        }

        printf("\n");
    }
}
