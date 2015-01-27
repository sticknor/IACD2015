import com.temboo.core.*;
import com.temboo.Library.NYTimes.MostPopular.*;

// Create a session using your Temboo account application details
TembooSession session = new TembooSession("srticknor", "myFirstApp", "NoneYa");

void setup() {
  // Run the GetMostShared Choreo function
  runGetMostSharedChoreo();  
  println("BREAK");
  // Run the GetMostViewed Choreo function
  runGetMostViewedChoreo();
}

void runGetMostSharedChoreo() {
  // Create the Choreo object using your Temboo session
  GetMostShared getMostSharedChoreo = new GetMostShared(session);

  // Set inputs
  getMostSharedChoreo.setSection("arts");
  getMostSharedChoreo.setAPIKey("NoneYa");
  getMostSharedChoreo.setShareTypes("facebook");
  getMostSharedChoreo.setTimePeriod("1");

  // Run the Choreo and store the results
  GetMostSharedResultSet getMostSharedResults = getMostSharedChoreo.run();
  
  // Print results
  println(getMostSharedResults.getResponse());

}

void runGetMostViewedChoreo() {
  // Create the Choreo object using your Temboo session
  GetMostViewed getMostViewedChoreo = new GetMostViewed(session);

  // Set inputs
  getMostViewedChoreo.setSection("arts");
  getMostViewedChoreo.setAPIKey("NoneYa");
  getMostViewedChoreo.setTimePeriod("1");

  // Run the Choreo and store the results
  GetMostViewedResultSet getMostViewedResults = getMostViewedChoreo.run();
  
  // Print results
  println(getMostViewedResults.getResponse());

}
