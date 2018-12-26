var fs = require('fs');
var input = fs.readFileSync('/dev/stdin').toString().split(' ');
var a = parseInt(input[0]);
for (var i = a; i >= 1; i--) {
    console.log(i);
}