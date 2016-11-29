<?php
	include("config.inc.php");

	if(!isset($attributes) || !is_array($attributes)){
 		$attributes = array();
   		$attributes = array_merge($_GET, $_POST,$_FILES); // Assign Post,Get and File varibale.
	}

	include_once("connect.inc.php");
