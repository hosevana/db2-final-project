// Created 2026-10-11 by hosevana
// Test code to setup connecting to atlas
// last edited: 2026-11-15 by hosevana
// CODE IS WORKING AS OF 2026-11-15
import com.mongodb.client.MongoClient;
import com.mongodb.client.MongoClients;
import com.mongodb.client.MongoCollection;
import com.mongodb.client.MongoDatabase;
import org.bson.Document;

public class test_jv {
    public static void main(String[] args) {
        String db_username = System.getenv("MONGO_USER");
        String db_password = System.getenv("MONGO_PASS");
        String uri = "mongodb+srv://" + db_username + ":" + db_password 
        + "@project-cluster.2a5curs.mongodb.net/";
        try (MongoClient mongoClient = MongoClients.create(uri)) {
            MongoDatabase database = mongoClient.getDatabase("sample_guides");
            MongoCollection<Document> collection = database.getCollection("planets");
            Document doc = collection.find(new Document("name", "Neptune")).first();
            System.out.println(doc != null ? doc.toJson() : "No matching documents found.");
        }
    }
}