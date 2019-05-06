<?php
session_start();
header("Content-Type:text/html; charset=utf-8");

?>

<html>

<head>

<meta http-equiv="Content-Type" content="text/html; charset=utf-8">

<?php
if (!$_SESSION['final'])
{header("Refresh: 0; url=login.php");
exit(1);
}


?>


<title>project</title>

<script type="text/javascript" src="jquery.js"></script>
<!--[if lte IE 8]><script language="javascript" type="text/javascript" src="/js/flot/excanvas.min.js"></script><![endif]-->
<script type="text/javascript" src="/js/flot/jquery.flot.min.js"></script>
<script type="text/javascript" src="/js/flot/jquery.flot.time.js"></script>    
<script type="text/javascript" src="/js/flot/jshashtable-2.1.js"></script>    
<script type="text/javascript" src="/js/flot/jquery.numberformatter-1.2.3.min.js"></script>
<script type="text/javascript" src="/js/flot/jquery.flot.symbol.js"></script>
<script type="text/javascript" src="/js/flot/jquery.flot.axislabels.js"></script>
<script>
var dat = [];
var dataset;
var totalPoints = 2000;
var now=2000;
var options = {
    series: {
        lines: {
            lineWidth: 1.2
        },
        bars: {
            align: "center",
            fillColor: { colors: [{ opacity: 1 }, { opacity: 1}] },
            barWidth: 1000,
            lineWidth: 1
        }
    },
    xaxis: {
         min: 0,
            max: 2000,
            tickSize: 250,
     
        axisLabel: "Time",
        axisLabelUseCanvas: true,
        axisLabelFontSizePixels: 12,
        axisLabelFontFamily: 'Verdana, Arial',
        axisLabelPadding: 10
    },
    yaxes: [
        {
            min: 0,
            max: 4200,
            tickSize: 500,
          
            axisLabel: "DATA",
            axisLabelUseCanvas: true,
            axisLabelFontSizePixels: 12,
            axisLabelFontFamily: 'Verdana, Arial',
            axisLabelPadding: 6
        }
    ],
    legend: {
        noColumns: 0,
        position:"nw"
    },
    grid: {      
        backgroundColor: { colors: ["#ffffff", "#EDF5FF"] }
    }
};

function initData() {
    for (var i = 0; i < totalPoints; i++) {
      //  var temp = [now -=1,0];

        dat.push(temp);
    }
}

var temp;


function update(_data) {
    
	var NumOfData = _data.length; //取出物件長度   

   for(var i = 0; i < NumOfData; i++){
	dat.shift();
	temp = [_data[i]["asix"], _data[i]["data"]];
    dat.push(temp);

	
   }
    dataset = [
        { label: "DATA" , data:dat , lines: { fill: false, lineWidth: 1.2 }, color: "#00FF00" }          
    ];

    $.plot($("#flot-placeholder1"), dataset, options);
    setTimeout(GetData, 500);
}


function GetData() {
    //set no cache
    $.ajaxSetup({ cache: false });
 
    $.ajax({
        url: "Noname1.php",
        dataType: 'json',
        success: update,  //if success, call update()
        error: function () {
            //if fail, prepare next update
            setTimeout(GetData, 500);
        }
    });
}




$(document).ready(function () {
    initData();

    dataset = [        
        { label: "data", data:dat, lines:{fill:true, lineWidth:1.2}, color: "#00FF00" }
   
    ];

    $.plot($("#flot-placeholder1"), dataset, options);
    setTimeout(GetData, 1000);
});



</script>
<!-- HTML -->




</head>

<body>

<div id="flot-placeholder1" style="width:800px;height:300px;margin:0 auto"></div>

<?php


	//naccess_sql($id);
	

	echo "<INPUT id=\"b1\" TYPE=\"button\" VALUE=\"登出\" onclick=\"window.open('logout.php','_self');\"><br>";
		$host = "db_host";
		$account = "db_id";
		$password = "pass";

		$database = mysql_connect($host,$account,$password);

		
		mysql_query("SET NAMES 'UTF8'");
		mysql_select_db("db",$database);
        $result =  mysql_query("SELECT * FROM `data1"."` ORDER BY `id` DESC LIMIT 1");
	while ($row=mysql_fetch_array($result)){
		$tie = strtotime($row['date_d']);
		$n = mktime();
		if ((($n-$tie)/60)>0.5){
		echo "***************node 1 offline***************<br>";}else{echo "***************node1 online***************<br>";
		}
	}
	


?>

</body>

</html>
