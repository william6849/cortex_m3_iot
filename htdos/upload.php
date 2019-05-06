<?php


		$host = "mysql.2freehosting.com";
		$account = "u493934020_cxzaq";
		$password = "cxzaq412";


		if(!$database = mysql_connect($host,$account,$password))echo "connect err \n";
		

		mysql_query("SET NAMES 'UTF8'");
		mysql_select_db("u493934020_cxzaq",$database);


		$dat=explode('x',$_POST['data']);

$query = "INSERT INTO `data".$_POST['id']."`(`data`) VALUES ('".implode("'),('",$dat)."');";
		mysql_query($query);
	//	saveData($_GET['id'],$_GET['data']);
	
		mysql_close($database);
		


?>