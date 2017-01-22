import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.SQLException;


public class JDBCConnection {

    public static void main(String[] argv) {

        String url = "jdbc:postgresql://newparking-db-instance.cvonhbbn1ayt.ca-central-1.rds.amazonaws.com:5432/";
        String userName = "stevenjia";
        String password = "UofTHacks4";
        String dbName = "newparkingDB";
        String driver = "org.postgresql.Driver";

        try {

            Class.forName(driver);

        } catch (ClassNotFoundException e) {

            System.out.println("Where is your PostgreSQL JDBC Driver? "
                    + "Include in your library path!");
            e.printStackTrace();
            return;

        }

        System.out.println("PostgreSQL JDBC Driver Registered!");

        Connection connection = null;

        try {

            connection = DriverManager.getConnection(url + dbName, userName, password);

        } catch (SQLException e) {

            System.out.println("Connection Failed! Check output console");
            e.printStackTrace();
            return;

        }

        if (connection != null) {
            System.out.println("You made it, take control your database now!");
        } else {
            System.out.println("Failed to make connection!");
        }
    }

}