<html>
<head>
<title>ZB Block Setup Completion</title>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1">
</head>
<body>
<?php
//Uncomment next 2 lines to turn on all error and notice notices.
//ini_set('display_errors',1);
//error_reporting(E_ALL|E_STRICT);

// *Poll system variables

$case1=$_SERVER['SCRIPT_NAME'];
$length=strlen($case1);
$length=$length - 10;
$case1=substr($case1,0,$length);
$case1=".........".$case1;
$case2=$_SERVER['SCRIPT_FILENAME'];
$length=strlen($case2);
$length=$length - 10;
$case2=substr($case2,0,$length);
$case3=$_SERVER['PATH_TRANSLATED'];
$length=strlen($case3);
$length=$length - 10;
$case3=substr($case3,0,$length);
$case4=$_SERVER['PHP_SELF'];
$length=strlen($case4);
$length=$length - 10;
$case4=substr($case4,0,$length);
$case4=".........".$case4;
$case5=$_SERVER['DOCUMENT_ROOT'];
$case5=$case5."/zbblock/";
$case6=$_SERVER['HOME'];
$case6=$case6."/zbblock/";
$case7=getcwd();
$case7=$case7."/";

// *Get case used.

$caseused=@$_GET['case'];

// *Apply case to directory name.

if ($caseused == "1") {$directory=$case1;}
if ($caseused == "2") {$directory=$case2;}
if ($caseused == "3") {$directory=$case3;}
if ($caseused == "4") {$directory=$case4;}
if ($caseused == "5") {$directory=$case5;}
if ($caseused == "6") {$directory=$case6;}
if ($caseused == "7") {$directory=$case7;}

// *Begin to emplace files

// place .htaccess and lock dir
if (!file_exists($directory."vault/.htaccess")){
mkdir($directory."vault", 0777);
chmod($directory."vault", 0777);
copy($directory."install.htaccess",$directory."vault/.htaccess");
}

// place zbblock.ini
if (file_exists($directory."vault/zbblock.ini")){
rename($directory."vault/zbblock.ini",$directory."vault/backup_zbblock-" . date("ymd-His") .".ini");
}
copy($directory."zbblock_install.ini",$directory."vault/zbblock.ini");

// place compatibility.inc
if (file_exists($directory."vault/compatibility.inc")){
rename($directory."vault/compatibility.inc",$directory."vault/backup_compatibility-" . date("ymd-His") .".inc");
}
copy($directory."default_compatibility.inc",$directory."vault/compatibility.inc");

// place bannedips.csv
if (file_exists($directory."vault/bannedips.csv")){
rename($directory."vault/bannedips.csv",$directory."vault/backup_bannedips-" . date("ymd-His") .".csv");
}
copy($directory."bannedips.csv",$directory."vault/bannedips.csv");

// place signatures.inc
if (file_exists($directory."vault/signatures.inc")){
rename($directory."vault/signatures.inc",$directory."vault/backup_signatures-" . date("ymd-His") .".inc");
}
copy($directory."signatures_install.inc",$directory."vault/signatures.inc");

// place customsig.inc
if (!file_exists($directory."vault/customsig.inc")){
copy($directory."customsig_install.inc",$directory."vault/customsig.inc");
}

// place counter.dat
if (!file_exists($directory."vault/counter.dat")){
$filex = fopen($directory . 'vault/counter.dat',"a");
$outputstring="0";
fwrite($filex,$outputstring);
fclose($filex);
}

// place directory.dat
if (!file_exists($directory."vault/directory.inc")){
$filex = fopen($directory . 'vault/directory.inc',"a");
$length = 1;
if (substr($directory,-$length) == "\\") {$outputstring='<?php global $path_to_zbblock; $path_to_zbblock="'.$directory.'\"; ?>';}
if (substr($directory,-$length) != "\\") {$outputstring='<?php global $path_to_zbblock; $path_to_zbblock="'.$directory.'"; ?>';}
fwrite($filex,$outputstring);
fclose($filex);
}

// *Move files to repository / safe them.

// place .htaccess and lock dir
if (!file_exists($directory."install/.htaccess")){
mkdir($directory."install", 0766);
chmod($directory."install", 0766);
copy($directory."install.htaccess",$directory."install/.htaccess");
}
if (file_exists($directory."install/customsig_install.inc")){unlink($directory."install/customsig_install.inc");}
rename($directory."customsig_install.inc",$directory."install/customsig_install.inc");

if (file_exists($directory."install/signatures_install.inc")){unlink($directory."install/signatures_install.inc");}
rename($directory."signatures_install.inc",$directory."install/signatures_install.inc");

if (file_exists($directory."install/zbblock_install.ini")){unlink($directory."install/zbblock_install.ini");}
rename($directory."zbblock_install.ini",$directory."install/zbblock_install.ini");

if (file_exists($directory."install/default_compatibility.inc")){unlink($directory."install/default_compatibility.inc");}
rename($directory."default_compatibility.inc",$directory."install/default_compatibility.inc");

if (file_exists($directory."install/bannedips.csv")){unlink($directory."install/bannedips.csv");}
rename($directory."bannedips.csv",$directory."install/bannedips.csv");

if (file_exists($directory."install/install.htaccess")){unlink($directory."install/install.htaccess");}
rename($directory."install.htaccess",$directory."install/install.htaccess");

if (file_exists($directory."install/setup.xphp")){unlink($directory."install/setup.xphp");}
rename($directory."setup.php",$directory."install/setup.xphp");

if (file_exists($directory."install/setup2.xphp")){unlink($directory."install/setup2.xphp");}
rename($directory."setup2.php",$directory."install/setup2.xphp");

if (file_exists($directory."install/yes.xphp")){unlink($directory."install/yes.xphp");}
rename($directory."yes.php",$directory."install/yes.xphp");

if (file_exists($directory."install/yes.gif")){unlink($directory."install/yes.gif");}
rename($directory."yes.gif",$directory."install/yes.gif");

if (file_exists($directory."install/no.gif")){unlink($directory."install/no.gif");}
rename($directory."no.gif",$directory."install/no.gif");

// place hook.php

if (!file_exists($directory."hook.php")){
$filex = fopen($directory . 'hook.php',"a");
$outputstring="<?php require('" . $directory . "zbblock.php'); ?>";
fwrite($filex,$outputstring);
fclose($filex);
}

// *Output End Message
?>

<div align="center">
  <p><font size="+5" face="Verdana, Arial, Helvetica, sans-serif"><strong><em>DONE!</em></strong></font></p>
  <p align="left">Now you must add:</p>
  <p align="left"><font size="+1">&lt;?php require('<?php echo($directory); ?>zbblock.php'); ?&gt; </font></font></p>
  <p align="left">to all the pages you wish to protect, as near as you can to the top as you can, and deffinitely before any MySQL access occurs. 
    Make sure you do not add any spaces, or new lines between the hook's "<font color="#FF0000">?&gt;</font>" and the original script's "<font color="#FF0000">&lt;?php</font>"</p>
  <p align="left"><strong>A COPY OF THAT LINE HAS BEEN SAVED AS hook.php IN YOUR ZB BLOCK DIRECTORY.</strong></p>
  <p align="left">Example (using a file from word press)::</p>
  <p align="left">wp_load.php (for example) starts with<br>
    <font color="#FF0000">&lt;?php</font><br>
    <font color="#FFCC00">/**<br>
    * Bootstrap file for setting the ABSPATH constant<br>
    * and loading the wp-config.php file. The wp-config.php<br>
    * file will then load the wp-settings.php file, which<br>
    * will then set up the WordPress environment.</font><br>
    etc...<br>
  </p>
  <p align="left"> should now start with:<br>
    <font color="#FF0000">&lt;?php</font> <font color="#0000FF">require</font>('<?php echo($directory); ?>zbblock.php'); <font color="#FF0000">?&gt;&lt;?php</font><br>
    <font color="#FFCC00">/**<br>
    * Bootstrap file for setting the ABSPATH constant<br>
    * and loading the wp-config.php file. The wp-config.php<br>
    * file will then load the wp-settings.php file, which<br>
    * will then set up the WordPress environment.</font><br>
    etc...</p>
  <p align="left">If you feel you need to re-install, move all the files out of the install directory, <em>except for &quot;.htaccess&quot;</em>, 
    back to ZB Block's main directory, and load setup.php again.</p>
  <p align="left">&nbsp;</p>
</div>

</body>
</html>