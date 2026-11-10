# Challenge10

Problem Statement:
The university wants to understand environmental conditions across its campus and identify areas that may need attention. Develop a menu-driven C program that analyses seven days of temperature, humidity, and Air Quality Index (AQI) readings from five campus zones. Your program must turn the readings into a clear risk report, a Green Index ranking, and practical recommendations.

Algorithm:
1.Start.
2.Declare three 2D arrays for temperature, humidity and AQI for 5 zones and 7 days.
3.Declare arrays for average values, Green Index and risk days.
4.Set dataReady = 0.
5.Display the menu with seven options.
6.Read the user's choice.
7.Perform the selected operation using switch.
Option 1
1. Select the data source.
2. Enter temperature, humidity and AQI for each zone and day.
3. Validate every reading within the permitted range.
4. Re-enter invalid values.
5. Set dataReady = 1.
Option 2
1. Check whether data is entered.
2. Display the temperature, humidity and AQI matrices.
Option 3
1. Check whether data is entered.
2. Calculate the total of each parameter for every zone.
3. Divide each total by 7.
4. Display the average values.
Option 4
1. Check whether data is entered.
2. Check whether AQI > 150 OR temperature > 35 OR humidity > 80.
3. Count each risk day only once.
4. Display risk day numbers and total risk days.
Option 5
1. Calculate the average values.
2. Calculate AQI, temperature and humidity scores.
3. Replace negative component scores with zero.
4. Calculate the Green Index.
5. Rank the zones from highest to lowest Green Index.
6. Display the ranking, including tied ranks.
Option 6
1. Calculate the average values.
2. Detect risk days.
3. Check which environmental parameter needs attention.
4. Display suitable recommendations for each zone.
Option 7
1. Display the thank-you message.
2. Stop.
Step 8: Repeat the menu until the user selects Exit.

Step 9: Stop the program.
