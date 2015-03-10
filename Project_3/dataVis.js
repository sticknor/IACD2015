var serveStatic = require('serve-static');
var Twit = require('twit');

var express = require('express')
var path = require('path');

var app = express()


var T = new Twit({
	consumer_key: 'GetYourOwn',
	consumer_secret: 'GetYourOwn',
	access_token: 'GetYourOwn',
	access_token_secret: 'GetYourOwn'
});

app.get('/hllo', function(req, res){
	var timeZoneList = [];
	T.get('search/tweets', { q: '#?', count: 100}, function(err, data, response) {
	 for (var i = 0; i < 100; i++){
	 	 if (data.statuses[i].user != undefined){
	 	 if (data.statuses[i].user.time_zone != undefined){
	 	 		timeZoneList.push(Math.floor(data.statuses[i].user.utc_offset/(60*60)));
	 	 }
	 	}
	 }
	 res.send(timeZoneList)
	}); 
});


// routes to serve the static HTML files
app.use(express.static(path.join(__dirname, 'static')));

app.listen(3000);