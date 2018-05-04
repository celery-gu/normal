function login(){
  var $name=$('#username');
  $("#login-btn .btn").click(
      $.ajax({
          type:"post";
          url:"login.php",
          data:{action:"login",username:$("#username"),val()},
          dataType:"json",
          beforeSend:function(){("正在登录中...");},
          success:function(){
            if(data==Fail){
              alert("登陆失败！请重新输入")
            }
            else{
              alert("登陆成功！")
            }
          }
        })
    )
}

function register(){
    var $name=$('#username');
    $("#register-btn .btn").click(
        $.ajax({
            type:"post";
            url:"login.php",
            data:{action:"register",username:$("#username"),val()},
            dataType:"jason",
            success:function(){
              if(data==Fail){
                alert("zhuce失败！请重新输入")
              }
              else{
                alert("zhuce成功！")
              }
            }
          })
      )
}