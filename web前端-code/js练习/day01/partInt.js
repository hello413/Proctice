/*要把[1, 3, 5, 7, 9]变换成整数13579，reduce()也能派上用场：*/
var arr = [1, 3, 5, 7, 9];
arr.reduce(function (x, y) {
    return x * 10 + y;
}); // 13579
/*不要使用JavaScript内置的parseInt()函数，
利用map和reduce操作实现一个string2int()函数：*/
'use strict';

function string2int(s) {
    var arrStr=s.split('');
    var arrInt=arrStr.map(function (x){
    return +x;
    });
    return arrInt.reduce(function (x,y){
    return x*10+y;
    });
}

// 测试:
if (string2int('0') === 0 && string2int('12345') === 12345 && string2int('12300') === 12300) {
    if (string2int.toString().indexOf('parseInt') !== -1) {
        console.log('请勿使用parseInt()!');
    } else if (string2int.toString().indexOf('Number') !== -1) {
        console.log('请勿使用Number()!');
    } else {
        console.log('测试通过!');
    }
}
else {
    console.log('测试失败!');
}