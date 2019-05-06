<?php

class DB{
	var $database = null;
	
	function __construct(){
		$host = "mysql.2freehosting.com";
		$account = "u493934020_cxzaq";
		$password = "cxzaq412";

		$this->database = mysql_connect($host,$account,$password);

		
		mysql_query("SET NAMES 'UTF8'");
		mysql_select_db("u493934020_cxzaq",$this->database);
		
		
		$this->auto();
		
	}

	function auto(){
		$count=2000;
		$query = "SELECT * FROM `data1` ORDER BY `id` DESC LIMIT 1000";
		$result = mysql_query($query) or die ('Error in query');


		while($row = mysql_fetch_array($result)){
			if($row['data']!=''){
			$data_line[] = array('asix'=>$count=$count-2,'data'=>(int)$row['data']);}	 
		}
		//header('Content-Type: application/json');
		echo json_encode($data_line);
	mysql_close($database);
	
	}
}


$db = new DB();

?>