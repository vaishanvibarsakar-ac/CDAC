public class Program {

    public static void main(String[] args) {

        Date objDate = new Date();

        System.out.println("Enter the day:");
        int day = ConsoleInput.getInt();

        System.out.println("Enter the month:");
        int month = ConsoleInput.getInt();

        System.out.println("Enter the year:");
        int year = ConsoleInput.getInt();

        objDate.setDate(day, month, year);

        int choice;

        do {
            System.out.println("\n======================================");
            System.out.println("Date Menu");
            System.out.println("1. Set Days");
            System.out.println("2. Add Days");
            System.out.println("3. Add Months");
            System.out.println("4. Add Years");
            System.out.println("5. Display");
            System.out.println("6. Compare dates (not implement)");
            System.out.println("7. Exit");
            System.out.println("--------------------------------------");
            System.out.print("Enter your choice: ");

            choice = ConsoleInput.getInt();

            switch (choice) {

                case 1:
                    System.out.println("Enter the day:");
                    day = ConsoleInput.getInt();

                    System.out.println("Enter the month:");
                    month = ConsoleInput.getInt();

                    System.out.println("Enter the year:");
                    year = ConsoleInput.getInt();

                    objDate.setDate(day, month, year);
                    break;

                case 2:
                    System.out.println("Enter number of days to add:");
                    int days = ConsoleInput.getInt();

                    objDate.addDays(days);
                    break;

                case 3:
                    System.out.println("Enter number of months to add:");
                    int months = ConsoleInput.getInt();

                    objDate.addMonths(months);
                    break;

                case 4:
                    System.out.println("Enter number of years to add:");
                    int years = ConsoleInput.getInt();

                    objDate.addYears(years);
                    break;

                case 5:
                    System.out.println(
                        objDate.getDay() + "/" +
                        objDate.getMonth() + "/" +
                        objDate.getYear()
                    );
                    break;

                case 6:
                    System.out.println("Compare dates is not implemented.");
                    break;

                case 7:
                    System.out.println("Program exited.");
                    break;

                default:
                    System.out.println("Invalid choice.");
            }

        } while (choice != 7);
    }
}