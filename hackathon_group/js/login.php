<?php  
	define("DB_HOST", "localhost:3306");
	define("DB_USER", "root");
	define("DB_PASSWORD","toor");
	define("DB_DBNAME","test");
	define("DB_CHARSET","set names utf-8");

	$action = $_POST['action'];

    switch($action) {
        case 'login':
            login();
            break;
        case 'register':
            register();
            break;
        case 'search':
            search();
            break;
        case 'card':
            card();
            break;
    }

    function login(){
    	$user=$_POST['username'];
    	alert($user);
    	$connect=mysqli_connect('DB_HOST','DB_USER','DB_PASSWORD','DB_DBNAME');
    	$sql="select * from users where name='".$user."';";
    	mysqli_query($connect,'DB_CHARSET');
    	$result=mysqli_query($connect,$sql);
    	if(mysqli_num_rows($result))
    		echo 'Success';
    	else
    		echo 'Fair';
    }

    function register(){
    	$user=$_POST['username'];
    	$connect=mysqli_connect('DB_HOST','DB_USER','DB_PASSWORD','DB_DBNAME');
    	$sql="insert into users(name) value('".$user."');";
    	mysqli_query($connect,'DB_CHARSET');
    	$result=mysqli_query($connect,$sql);
    	if($result)
    		echo "true";
    	else
    		echo "false";
    }

?> 