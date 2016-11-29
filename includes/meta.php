<?php if (file_exists($_SERVER['DOCUMENT_ROOT'].'/zblock/zbblock.php')) require($_SERVER['DOCUMENT_ROOT'].'/zblock/zbblock.php'); ?><?php
	## Meta Part Starts Here ##
if($_SERVER['HTTP_HOST']=='server')
	$page	=	 str_replace("/Anthony-wilson-rd/","",$_SERVER['PHP_SELF']);
elseif($_SERVER['HTTP_HOST']=="weightlosshappens.com"  || $_SERVER['HTTP_HOST']=="www.weightlosshappens.com")
	$page	=	 str_replace("/","",$_SERVER['PHP_SELF']);
else
	$page	=	 str_replace("/projects/weightlosshappens/","",$_SERVER['PHP_SELF']);

$page	=	 str_replace(".php","",$page);


$seoTable = $config['tbl_prefix']."seo";
$seoRecord = $mainClass->get_detail_byID($seoTable,'meta_title,meta_description','page_title LIKE "%'.$page.'%"','','');

if(count($seoRecord)>0)
{
	$metaTitle			=	$mainClass->outputData($seoRecord[0]['meta_title']);
	$metaDescription	=	$mainClass->outputData($seoRecord[0]['meta_description']);
	
	if($metaTitle=='')
	{
		$metaTitle			=	'Anthony Wilson RD Weight Loss';
	}
	else if($metaDescription=='')
	{
		$metaDescription	=	'Anthony Wilson RD';
	}	
}
else
{
	$metaTitle			=	'Anthony Wilson RD';
	$metaDescription	=	'Anthony Wilson RD';
}

## Meta Part Ends Here ##
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xmlns:fb="http://www.facebook.com/2008/fbml">
<head>
<meta http-equiv="X-UA-Compatible" content="IE=edge" />
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title><?php echo $metaTitle;?></title>
<meta name="description" content="<?php echo $metaDescription;?>" />
<!--<link rel="stylesheet" type="text/css" href="<?php echo $config['site_url'];?>css/stylesheet.css" />-->