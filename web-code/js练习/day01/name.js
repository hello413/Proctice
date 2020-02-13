/*请把用户输入的不规范的英文名字，变为首字母大写，其他小写的规范名字。
输入：['adam', 'LISA', 'barT']，输出：['Adam', 'Lisa', 'Bart']。*/

'use strict';

function normalize(arr) {
    function strs(str){
        str=str.toLowerCase();
        let x1 = str.substring(0, 1).toUpperCase();
        let x2 = str.substring(1);
        return x1+x2;
    }
    return arr.map(strs)  
}

// 测试:
if (normalize(['adam', 'LISA', 'barT']).toString() === ['Adam', 'Lisa', 'Bart'].toString()) {
    console.log('测试通过!');
}
else {
    console.log('测试失败!');
}