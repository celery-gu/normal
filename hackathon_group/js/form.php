<?php  
	define("DB_HOST", "localhost:3306");
	define("DB_USER", "root");
	define("DB_PASSWORD","toor");
	define("DB_DBNAME","test");
	define("DB_CHARSET","set names utf-8");

	$action = $_POST['action'];

    switch($action) {
        case 'person':
            person();
            break;
        case 'team':
            team();
            break;
    }

    function person(){
    	$dickname=$_POST['dickname'];
        $area=$_POST['area'];
        $qq=$_POST['qq'];
        $keywords=$_POST['keywords'];
        $introduce=$_POST['introduce'];
    	$connect=mysqli_connect('DB_HOST','DB_USER','DB_PASSWORD','DB_DBNAME');
    	$sql="insert into person(dickname,area,qq,keywords,introduce value('".$user.",".$area.",".$qq.",".$keywords.",".$introduce."');";
    	mysqli_query($connect,'DB_CHARSET');
    	$result=mysqli_query($connect,$sql);
    	if(mysqli_num_rows($result))
    		echo 'Success';
    	else
    		echo 'Fair';
    }

    function register(){
        $dickname=$_POST['dickname'];
        $qq=$_POST['qq'];
        $keywords=$_POST['keywords'];
        $introduce=$_POST['introduce'];
    	$connect=mysqli_connect('DB_HOST','DB_USER','DB_PASSWORD','DB_DBNAME');
    	$sql="insert into team(dickname,qq,keywords,introduce value('".$user.",".$qq.",".$keywords.",".$introduce."');";
    	mysqli_query($connect,'DB_CHARSET');
    	$result=mysqli_query($connect,$sql);
        if(mysqli_num_rows($result))
            echo 'Success';
        else
            echo 'Fair';
    }

?> 