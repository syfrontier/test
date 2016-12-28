var events = require("events");

var eventEmitter = new events.EventEmitter();

eventEmitter.newListener("receive", function () {
    console.log(">>>>>");
});

eventEmitter.on("connection", function() {
    console.log("Someone connected.");
    eventEmitter.emit("receive");
});

eventEmitter.on("receive", function(err, data) {
    console.log(err, data);
});

eventEmitter.emit("connection");

console.log("Running finish!");
