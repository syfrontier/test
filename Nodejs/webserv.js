const http = require("http");
const fs = require("fs");
const url = require("url");

http.createServer(function(req, res)
{
    var pathname = url.parse(req.url).pathname;
    pathname = (pathname == "/" ? pathname.concat("index.html") : pathname);
    console.log("Request for " + pathname + " received.");

    try
    {
        res.writeHead(200, {"Content-Type":"text/html; charset=utf-8"});
        var htmlc = fs.readFileSync(pathname.substr(1));
	res.write(htmlc.toString());
	res.end();
    }
    catch(ex)
    {
        console.log(ex.toString());
        res.writeHead(404, {"Content-Type:t":"text/plain; charset=utf-8"});
        res.end("<H1 style='font-size: 64px'>404</H1>" + "<H3>" + ex.toString() + "</H3>\n");
    }
}).listen(8080);

console.log("Server running at http://127.0.0.1:8080/\n");
