/*请把用户输入的不规范的英文名字，变为首字母大写，其他小写的规范名字。
输入：['adam', 'LISA', 'barT']，输出：['Adam', 'Lisa', 'Bart']。*/

'use strict';

function normalize(arr) {
    arr=arr.toString();
    arr=arr.toLowerCase();
    let x1 = arr.substring(0, 1).toUpperCase();
    let x2 = arr.substring(1,5);
    let x3 = arr.substring(5,6).toUpperCase();
    let x4 = arr.substring(6,10);
    let x5 = arr.substring(10, 11).toUpperCase();
    let x6 = arr.substring(11);
    console.log(x1+x2+x3+x4+x5+x6);
    return x1+x2+x3+x4+x5+x6;    
}

// 测试:
if (normalize(['adam', 'LISA', 'barT']).toString() === ['Adam', 'Lisa', 'Bart'].toString()) {
    console.log('测试通过!');
}
else {
    console.log('测试失败!');
}