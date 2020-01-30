const http = require("http");
const url = require("url");
const querystring = require('querystring');
http.createServer(function(req, res) {
    res.setHeader('access-control-allow-origin', '*');
    var pathname = url.parse(req.url).pathname;
    var query = url.parse(req.url).query;
    if (pathname == '/test') {
        var postData = "";
        req.on("data", function(postDataChunk) {
            postData += postDataChunk;
        });

        req.on("end", function() {
            var params = querystring.parse(postData);
            var s = params.name;
            console.log(s);
            res.write("收到了，他是" + s);
            res.end();
        })
    }
}).listen(8082);