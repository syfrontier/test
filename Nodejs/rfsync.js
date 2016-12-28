var fs = require("fs");

try
{
    var data = fs.readFileSync("README");
    console.log(data, data.toString());
}
catch(ex)
{
    console.log(ex.toString());
}
