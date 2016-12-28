var fs = require("fs");

fs.readFile("README", function(err, data) {
    if (err) return console.error(err);
    console.log(data.toString());
});

console.log("Running finish!");

