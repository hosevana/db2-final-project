// Created 2026-10-11 by hosevana
// Test code to setup connecting to atlas
// last edited: 2026-10-25 by hosevana
// untested and not working as of 2026-10-25
import com.mongodb.client.MongoClient;
import com.mongodb.client.MongoClients;
import com.mongodb.client.MongoCollection;
import com.mongodb.client.MongoDatabase;
import org.bson.Document;

public class QuickStart {
    public static void main(String[] args) {
        String db_username = System.getenv("SECRET_USERNAME");
        String db_password = System.getenv("SECRET_MONGO_PASS");
        String uri = "mongodb+srv://" + db_username + ":" + db_password 
        + "@project-cluster.2a5curs.mongodb.net/";
        try (MongoClient mongoClient = MongoClients.create(uri)) {
            MongoDatabase database = mongoClient.getDatabase("sample_mflix");
            MongoCollection<Document> collection = database.getCollection("movies");
            Document doc = collection.find(new Document("title", "Back to the Future")).first();
            System.out.println(doc != null ? doc.toJson() : "No matching documents found.");
        }
    }
}