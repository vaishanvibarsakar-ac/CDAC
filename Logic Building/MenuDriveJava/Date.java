

public class Date {

    private int day;
    private int month;
    private int year;

    // Setter / Mutator
    public void setDate(int dd, int mm, int yy) {

        year = yy;

        // Check month
        if (mm < 1 || mm > 12) {
            month = 1;
        } else {
            month = mm;
        }

        // Check day according to month
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {

            if (dd < 1 || dd > 31) {
                day = 1;
            } else {
                day = dd;
            }

        } else if (month == 4 || month == 6 || month == 9 || month == 11) {

            if (dd < 1 || dd > 30) {
                day = 1;
            } else {
                day = dd;
            }

        } else {

            // February
            // Check Leap Year

            if (isLeapYear(year)) {

                // February has 29 days
                if (dd < 1 || dd > 29) {
                    day = 1;
                } else {
                    day = dd;
                }

            } else {

                // February has 28 days
                if (dd < 1 || dd > 28) {
                    day = 1;
                } else {
                    day = dd;
                }
            }
        }
    }

    // Add Days
    public void addDays(int days) {

        while (days > 0) {

            day++;
            days--;

            if (day > daysInMonth(month, year)) {
                day = 1;
                month++;

                if (month > 12) {
                    month = 1;
                    year++;
                }
            }
        }
    }

    // Add Months
    public void addMonths(int months) {

        while (months > 0) {

            month++;
            months--;

            if (month > 12) {
                month = 1;
                year++;
            }

            // Adjust day if it is invalid in the new month
            int maxDays = daysInMonth(month, year);

            if (day > maxDays) {
                day = maxDays;
            }
        }
    }

    // Add Years
    public void addYears(int years) {

        year = year + years;

        // Handle February 29 when adding years
        if (month == 2 && day == 29 && !isLeapYear(year)) {
            day = 28;
        }
    }

 // Compare Dates
    public void compareDate() {

      
    }
    
    // Check Leap Year
    private boolean isLeapYear(int yy) {

        if (yy % 400 == 0) {
            return true;
        }

        if (yy % 100 == 0) {
            return false;
        }

        return yy % 4 == 0;
    }

    // Return number of days in a month
    private int daysInMonth(int mm, int yy) {

        if (mm == 1 || mm == 3 || mm == 5 ||
            mm == 7 || mm == 8 || mm == 10 ||
            mm == 12) {

            return 31;
        }

        if (mm == 4 || mm == 6 ||
            mm == 9 || mm == 11) {

            return 30;
        }

        // February
        if (isLeapYear(yy)) {
            return 29;
        }

        return 28;
    }

 
    
    // Getter / Accessor
    public int getDay() {
        return day;
    }

    public int getMonth() {
        return month;
    }

    public int getYear() {
        return year;
    }
}


