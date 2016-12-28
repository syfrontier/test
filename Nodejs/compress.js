
var fs = require("fs");
var zlib = require("zlib");

fs.createReadStream("rfsync.js")
.pipe(zlib.createGzip())
.pipe(fs.createWriteStream("t.tar.gz"));
console.log("Compresssion complete.");

///*
fs.createReadStream("t.tar.gz")
.pipe(zlib.createGunzip())
.pipe(fs.createWriteStream("rfsync_t.js"));
console.log("Decompression complete.");
//*/

