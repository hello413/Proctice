//首字母大写，其他小写的规范名字。
function normalize(arr) {
    return arr.map(function(x){
        return x.substring(0,1).toUpperCase()+x.substring(1).toLowerCase();
     })
}
    