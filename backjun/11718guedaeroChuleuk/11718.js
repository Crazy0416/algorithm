var fs= require('fs');
var input= fs.readFileSync('/dev/stdin').toString().split('\n');
var a= parseInt(input.shift());

for(var i = 1; i <= a; i++ ){
	console.log(i);
}