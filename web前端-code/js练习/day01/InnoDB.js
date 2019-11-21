/*要生成一个自增的ID，可以编写一个next_id()函数*/
var current_id = 0;

function next_id() {
    current_id ++;
    return current_id;
}

function* next_id() {
    var n=0;
    while(n<x)
        yield ++n;
    return;
}

// 测试:
var
    x,
    pass = true,
    g = next_id();
for (x = 1; x < 100; x ++) {
    if (g.next().value !== x) {
        pass = false;
        console.log('测试失败!');
        break;
    }
}
if (pass) {
    console.log('测试通过!');
}    