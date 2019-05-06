<?php session_start(); ?>
<?php
header("Content-Type:text/html; charset=utf-8");
?>
<html>

<head>

<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<META HTTP-EQUIV="refresh" CONTENT="0;URL=login.php"> 

<title>logout</title>



<style fprolloverstyle>A:hover {color: #FF00FF}
</style>


<STYLE> 
<!-- A{text-decoration:none} --> 
</STYLE>
</head>

<body align=center>
<hr>


<?php
session_start();
$_SESSION['final']="";
echo "登出中";

?>


<hr>

</body>

</html>