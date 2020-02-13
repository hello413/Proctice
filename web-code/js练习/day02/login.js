/*很多登录表单希望用户输入用户名和口令，但是，安全考虑，提交表单时不传输明文口令，
而是口令的MD5。普通JavaScript开发人员会直接修改<input>*/

/*
<!-- HTML -->
<form id="login-form" method="post" onsubmit="return checkForm()">
    <input type="text" id="username" name="username">
    <input type="password" id="input-password">
    //没有name属性的<input>的数据不会被提交
    <input type="hidden" id="md5-password" name="password">
    <button type="submit">Submit</button>
</form>
*/
<script>
function checkForm() {
    var input_pwd = document.getElementById('input-password');
    var md5_pwd = document.getElementById('md5-password');
    // 把用户输入的明文变为MD5:
    md5_pwd.value = toMD5(input_pwd.value);
    // 继续下一步:
    return true;
}
</script>


