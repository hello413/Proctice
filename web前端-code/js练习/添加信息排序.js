function add(L){
    return '<li><span>'+ L + '</span></li>'
}
$('div#test-div>ul').append(['Pascal','Lua','Ruby'].map(add));
var arr = $('div#test-div>ul>li').map(function(){
    return this.innerHTML;
}).get().sort();
console.log(arr)
$('div#test-div>ul>li').remove();
$('div#test-div>ul').append(arr.map(add))

/*
<!-- HTML结构 -->
<div id="test-div">
    <ul>
        <li><span>JavaScript</span></li>
        <li><span>Python</span></li>
        <li><span>Swift</span></li>
    </ul>
</div>
*/