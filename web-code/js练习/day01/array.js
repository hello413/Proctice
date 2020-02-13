/*在新生欢迎会上，你已经拿到了新同学的名单，
请排序后显示：欢迎XXX，XXX，XXX和XXX同学！*/
'use strict';
var arr = ['小明', '小红', '大军', '阿黄'];

//start
arr.sort();
let str = '';
for(let i = 0; i < arr.length; i++){
    if(i === arr.length - 1){
        str += `和${arr[i]}同学！`;
    }else if(i === 0){
        str += `欢迎${arr[i]}`;
    }else{
        str += `,${arr[i]}`;
    }
}
console.log(str);