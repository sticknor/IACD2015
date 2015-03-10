var Twit = require('twit');
var fs = require ('fs');
var client = require('google-images');
var http = require('http');
var https = require('https');
var child_process = require('child_process');
var mkdirp = require('mkdirp');
var domain = require('domain')

d = domain.create();

d.on('error', function(err) {
    if (err){
		clearInterval(bot);
		bot = setInterval(function(){
	 		makeNewQuery();
	 	}, 100000);
	}
});

var options = {
  mode: 'text',
  pythonPath: 'C:/Users/Sam/Documents/GitHub/bot',
  pythonOptions: ['-u'],
  scriptPath: 'path/to/my/scripts',
  args: ['value1', 'value2', 'value3']
};

var T = new Twit({
	consumer_key: 'GetYourOwn',
	consumer_secret: 'GetYourOwn',
	access_token: 'GetYourOwn',
	access_token_secret: 'GetYourOwn'
});

query = ""

colors = ["pink", "red", "green",
"purple", "blue", "yellow", "orange"]

function uploadDaPhoto(){
 var b64content = fs.readFileSync(query+'/collage.png', { encoding: 'base64' })

	// first we must post the media to Twitter
	T.post('media/upload', { media: b64content }, function (err, data, response) {

	  // now we can reference the media and post a tweet (media will attach to the tweet)
	  var mediaIdStr = data.media_id_string
	  var params = { status: query, media_ids: [mediaIdStr] }

	  T.post('statuses/update', params, function (err, data, response) {
	    console.log(data)
	  })
	})
}

function load1(){
	var color = colors[0];
	client.search(color+query, function (err, images) { 
  		try{
  		    download(images[0].url, query+"/1.png", function(){
  		 		load2()
  		 	});
  		 }
  		 catch(err){ 
  		 	download(images[1].url, query+"/1.png", function(){
  		 		load2()
  		 	});
		}
});
}

function shuffle(array) {
  var currentIndex = array.length, temporaryValue, randomIndex ;

  // While there remain elements to shuffle...
  while (0 !== currentIndex) {

    // Pick a remaining element...
    randomIndex = Math.floor(Math.random() * currentIndex);
    currentIndex -= 1;

    // And swap it with the current element.
    temporaryValue = array[currentIndex];
    array[currentIndex] = array[randomIndex];
    array[randomIndex] = temporaryValue;
  }

  return array;
}

function load2(){
	var color = colors[1];
	client.search(color+query+' white background', function (err, images) { 
  		try{
  		    download(images[0].url, query+"/2.png", function(){
  		 		load3()
  		 	});
  		 }
  		 catch(err){ 
  		 	download(images[1].url, query+"/2.png", function(){
  		 		load3()
  		 	});
		}
});
}

function load3(){
	var color = colors[2];
	client.search(color+query+' white background', function (err, images) { 
  		try{
  		    download(images[0].url, query+"/3.png", function(){
  		 		load4()
  		 	});
  		 }
  		 catch(err){ 
  		 	download(images[1].url, query+"/3.png", function(){
  		 		load4()
  		 	});
		}
});
}

function load4(){
	var color = colors[3];
	client.search(color+query+' white background', function (err, images) { 
  		try{
  		    download(images[0].url, query+"/4.png", function(){
  		 		load5()
  		 	});
  		 }
  		 catch(err){ 
  		 	download(images[1].url, query+"/4.png", function(){
  		 		load5()
  		 	});
		}
});
}

function load5(){
	var color = colors[4];
	client.search(color+query+' white background', function (err, images) { 
  		try{
  		    download(images[0].url, query+"/5.png", function(){
  		 		load6()
  		 	});
  		 }
  		 catch(err){ 
  		 	download(images[1].url, query+"/5.png", function(){
  		 		load6()
  		 	});
		}
});
}

function load6(){
	var color = colors[5];
	client.search(color+query+' white background', function (err, images) { 
  		try{
  		    download(images[0].url, query+"/6.png", function(){
				child_process.exec('python work_it.py '+query,function(error,stdout,stderr){
										  		    	if (error) throw error
										  		    		else console.log(stdout)
										  		    		uploadDaPhoto();

										  		    });
  		 	});
  		 }
  		 catch(err){ 
  		 	download(images[1].url, query+"/6.png", function(){
				child_process.exec('python botScript.py '+query,function(error,stdout,stderr){
										  		    	if (error) throw error
										  		    		else {
										  		    			console.log(stdout)
																uploadDaPhoto();
										  		    		}
										  		    });
  		 	});
		}
});
}


var download = function(url, dest, cb) {
    var file = fs.createWriteStream(dest);
    try{
      var request = http.get(url, function(response) {
          response.pipe(file);
          file.on('finish', function() {
              file.close(cb);
          });
      });
    }
    catch(err){
      var request = https.get(url, function(response) {
          response.pipe(file);
          file.on('finish', function() {
              file.close(cb);
          });
      });      
    }
}


function makeNewQuery(){
	try{
		var index = Math.floor(Math.random()*(nounList.length));
		    query = (nounList[index]).substring(0, nounList[index].length-1)
      mkdirp(query, function(err) { 
				shuffle(colors);
				load1();
			});
	}catch(err){
		console.log(err);
	}
}

    var nounList = fs.readFileSync('nouns.txt').toString().split("\n");


var bot;

var run = function(){
 	makeNewQuery();    

 	bot = setInterval(function(){
 		makeNewQuery();
 	}, 60000);
}

run();