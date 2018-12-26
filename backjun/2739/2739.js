var fs = require('fs');
var input = fs.readFileSync('/dev/stdin').toString().split('\n');
var a = parseInt(input[0]);

for(var i = 1; i <= 9; i++){
    console.log(a + " * " +  i + " = " + a*i);
}