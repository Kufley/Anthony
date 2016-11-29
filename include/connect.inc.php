<?php require_once($config['absolute_path']."classes/querymaker.class.php");
	if($_SERVER['HTTP_HOST']=="server")
	{
		$dbHost = "localhost";  		
		$dbUser="root";
		$dbPassword="";
		$dbName="anthony_wilson"; 
	}
	elseif($_SERVER['HTTP_HOST']=="weightlosshappens.com"  || $_SERVER['HTTP_HOST']=="www.weightlosshappens.com")
	{
		$dbHost = "mysql55.web15.luxsci.com";  		
		$dbUser="polarbear364";
		$dbPassword="XtB137*?:%#^</[CvA854$&(265";
		$dbName="weightlosshappens"; 
	}
	else
	{	
		$dbHost = "localhost";  		
		$dbUser="showproj_wilson";
		$dbPassword="wis1tEch";
		$dbName="showproj_anthony";
	}

global $db;
//$db = new CLSQueryMaker($dbHost, $dbUser, $dbPassword, $dbName);
?>
