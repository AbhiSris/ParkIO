import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
 
public class JDBCconnection{
 
    private final String url = "jdbc:postgresql://newparking-db-instance.cvonhbbn1ayt.ca-central-1.rds.amazonaws.com:5432/newparkingDB";
    private final String user = "stevenjia";
    private final String password = "UofTHacks4";
 
    /**
     * Connect to the PostgreSQL database
     *
     * @return a Connection object
     */
    public Connection connect() {
        Connection conn = null;
        try {
            conn = DriverManager.getConnection(url, user, password);
            System.out.println("Connected to the PostgreSQL server successfully.");
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
 
        return conn;
    }
 
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        App app = new App();
        app.connect();
    }
}