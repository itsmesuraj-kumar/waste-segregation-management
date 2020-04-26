(function() {
  // Set the configuration for your app
  var config = {
      apiKey: "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", //provide api key
      authDomain: "xxxxxxxxxxxxxxxx.firebaseapp.com",   //provide authorised domain
      databaseURL: "https://xxxxxxxxxxxx.firebaseio.com", //provide databaseURL
      projectId: "xxxxxxxxxxxxxxx", //provide projectID
      storageBucket: "xxxxxxxxxxxxxx.appspot.com", //provide storageBucket URL
      messagingSenderId: "xxxxxxxxxxxxxx" //provide messaging sender ID
  };

  firebase.initializeApp(config);

  var database = firebase.database();

  const Distance1 = document.getElementById('data1');
  const Distance2 = document.getElementById('data2');
  const Distance3 = document.getElementById('data3');

  const ref1 = database.ref('Distance').child('Bin1');

  const ref2 = database.ref('Distance').child('Bin2');

  const ref3 = database.ref('Distance').child('Bin3');

  ref1.limitToLast(1).on('value', function(snapshot) {
      snapshot.forEach(function(childSnapshot) {
          var childData = childSnapshot.val();
          console.log("Distance1: " + childData);
          Distance1.append(childData + 'cm');
      });
  });
  ref2.limitToLast(1).on('value', function(snapshot) {
    snapshot.forEach(function(childSnapshot) {
        var childData = childSnapshot.val();
        console.log("Distance2: " + childData);
        Distance2.append(childData + 'cm');
    });
  });
  ref3.limitToLast(1).on('value', function(snapshot) {
    snapshot.forEach(function(childSnapshot) {
        var childData = childSnapshot.val();
        console.log("Distance3: " + childData);
        Distance3.append(childData + 'cm');
    });
  });

}());