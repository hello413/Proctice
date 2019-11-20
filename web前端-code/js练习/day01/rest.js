/*请用rest参数编写一个sum()函数，接收任意个参数并返回它们的和：*/
'use strict';

//---(1)未用rest
function sum(...rest) {
    let sum=0;   
    for(let i=0;i<arguments.length;i++)
    sum+=arguments[i]
    return sum;
}
//---使用rest
function sum(...rest) {
    var result = 0;
    for(var value of rest){
        result += value;
    };
    return result;
    }
// 测试:
var i, args = [];
for (i=1; i<=100; i++) {
    args.push(i);
}
if (sum() !== 0) {
    console.log('测试失败: sum() = ' + sum());
} else if (sum(1) !== 1) {
    console.log('测试失败: sum(1) = ' + sum(1));
} else if (sum(2, 3) !== 5) {
    console.log('测试失败: sum(2, 3) = ' + sum(2, 3));
} else if (sum.apply(null, args) !== 5050) {
    console.log('测试失败: sum(1, 2, 3, ..., 100) = ' + sum.apply(null, args));
} else {
    console.log('测试通过!');
}