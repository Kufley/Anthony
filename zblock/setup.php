<html>
<head>
<title>ZB Block Setup</title>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1">
</head>
<body>
<?php
error_reporting(0);
$case1=$_SERVER['SCRIPT_NAME'];
$length=strlen($case1);
$length=$length - 9;
$case1=substr($case1,0,$length);
$case1=".........".$case1."yes.php";
$case2=$_SERVER['SCRIPT_FILENAME'];
$length=strlen($case2);
$length=$length - 9;
$case2=substr($case2,0,$length);
$case2=$case2."yes.php";
$case3=$_SERVER['PATH_TRANSLATED'];
$length=strlen($case3);
$length=$length - 9;
$case3=substr($case3,0,$length);
$case3=$case3."yes.php";
$case4=$_SERVER['PHP_SELF'];
$length=strlen($case4);
$length=$length - 9;
$case4=substr($case4,0,$length);
$case4=".........".$case4."yes.php";
$case5=$_SERVER['DOCUMENT_ROOT'];
$case5=$case5."/zbblock/yes.php";
$case6=$_SERVER['HOME'];
$case6=$case6."/zbblock/yes.php";
$case7=getcwd();
$case7=$case7."/yes.php";
if ($case1=="yes.php"){$case1=="";}
if ($case2=="yes.php"){$case2=="";}
if ($case3=="yes.php"){$case3=="";}
if ($case4=="yes.php"){$case4=="";}
if ($case5=="yes.php"){$case5=="";}
if ($case6=="yes.php"){$case6=="";}
if ($case7=="yes.php"){$case7=="";}
?>
<div align="center"><font size="+5">Setting Up ZB Block</font></div>
<p>ZB Block needs your help, just a click, to figure out how to set itself up on your webserver. Here is a grid of the methods, what they returned 
  on your system, and how I rate their accuracy on my system. It may help you decide which method below you wish to use. All methods worked 
  on my setup, just some worked better in my opinion.<br>
  <br>
  Those that worked <em><strong><font color="#339900">BEST</font></strong></em> for me, needed the least tampering to hit the target file.<br>
  Those with the <font color="#FF0000"><strong>poor</strong></font>, needed the most.</p>
<p>You should probably pick the one with the most distinct name such as &quot;C:\xAmp\xampp\htdocs\zbblock/yes.php&quot;.</p>
<table width="780" border="1" cellspacing="0" cellpadding="1s">
    <tr> 
      <td>&nbsp;</td>
      <td>Returns this string for finding &quot;yes.php&quot;</td>
      <td>Checks this php variable...</td>
      <td>rated</td>
    </tr>
    <tr> 
      <td width="10%">Method 1</td>
      <td><?php echo($case1); ?></td>
      <td width="35%">$_SERVER['SCRIPT_NAME']</td>
      <td width="5%"><strong><font color="#FF0000">poor</font></strong></td>
    </tr>
    <tr> 
      <td width="10%">Method 2</td>
      <td><?php echo($case2); ?></td>
      <td width="35%">$_SERVER['SCRIPT_FILENAME']</td>
      <td width="5%"><strong><font color="#339900"><em>BEST</em></font></strong></td>
    </tr>
    <tr> 
      <td width="10%">Method 3</td>
      <td><?php echo($case3); ?></td>
      <td width="35%">$_SERVER['PATH_TRANSLATED']</td>
      
    <td width="5%"><strong><font color="#FFCC00"><strong>good</strong></font><font color="#339900"></font></strong></td>
    </tr>
    <tr> 
      <td width="10%">Method 4</td>
      <td><?php echo($case4); ?></td>
      <td width="35%">$_SERVER['PHP_SELF'];</td>
      <td width="5%"><font color="#FF0000"><strong>poor</strong></font></td>
    </tr>
    <tr> 
      <td width="10%">Method 5</td>
      <td><?php echo($case5); ?></td>
      <td width="35%">$_SERVER['DOCUMENT_ROOT']</td>
      <td width="5%"><font color="#FFCC00"><strong>good</strong></font></td>
    </tr>
    <tr> 
      <td width="10%">Method 6</td>
      <td><?php echo($case6); ?></td>
      <td width="35%">$_SERVER['HOME']</td>
      <td width="5%"><font color="#FFCC00"><strong>good</strong></font></td>
    </tr>
    <tr> 
      <td width="10%">Method 7</td>
      <td><?php echo($case7); ?></td>
      <td width="35%">getcwd()</td>
      
    <td width="5%"><font color="#FFCC00"><strong><font color="#339900"><em>BEST</em></font></strong></font></td>
    </tr>
  </table>
  
<p align="center">Chose a method of referencing ZB Block's directory by clicking a <em><strong style="background:#00ff00; color:#FFFFFF;">YES!</strong></em> below.</p>
<div align="center"> 
  <table width="350" height="50" border="0" cellspacing="2" cellpadding="0">
    <tr> 
      <td width="50" height="50"> 
        <a href="setup2.php?case=1" title="Yes, you can use this method!" name="Yes, you can use this method!"><?php error_reporting(0); include($case1); ?></a>
      </td>
      <td width="50" height="50">
        <a href="setup2.php?case=2" title="Yes, you can use this method!" name="Yes, you can use this method!"><?php error_reporting(0); include($case2); ?></a>
      </td>
      <td width="50" height="50">
        <a href="setup2.php?case=3" title="Yes, you can use this method!" name="Yes, you can use this method!"><?php error_reporting(0); include($case3); ?></a>
      </td>
      <td width="50" height="50">
        <a href="setup2.php?case=4" title="Yes, you can use this method!" name="Yes, you can use this method!"><?php error_reporting(0); include($case4); ?></a>
      </td>
      <td width="50" height="50">
        <a href="setup2.php?case=5" title="Yes, you can use this method!" name="Yes, you can use this method!"><?php error_reporting(0); include($case5); ?></a>
      </td>
      <td width="50" height="50">
        <a href="setup2.php?case=6" title="Yes, you can use this method!" name="Yes, you can use this method!"><?php error_reporting(0); include($case6); ?></a>
      </td>
      <td width="50" height="50"> 
        <a href="setup2.php?case=7" title="Yes, you can use this method!" name="Yes, you can use this method!"><?php error_reporting(0); include($case7); ?></a>
      </td>
    </tr>
    <tr> 
      <td><center><font size="-2">Method 1</font></center></td>
      <td><center><font size="-2">Method 2</font></center></td>
      <td><center><font size="-2">Method 3</font></center></td>
      <td><center><font size="-2">Method 4</font></center></td>
      <td><center><font size="-2">Method 5</font></center></td>
      <td><center><font size="-2">Method 6</font></center></td>
      <td><center><font size="-2">Method 7</font></center></td>
    </tr>
	    <tr> 
      <td><center>
          <strong><font color="#FF0000">poor</font></strong>
</center></td>
      <td><center>
          <strong><font color="#339900"><em>BEST</em></font></strong>
</center></td>
      <td><center>
          <strong><font color="#FFCC00"><strong>good</strong></font><font color="#339900"></font></strong> 
        </center></td>
      <td><center>
          <strong><font color="#FF0000">poor</font></strong>
</center></td>
      <td><center>
          <font color="#FFCC00"><strong>good</strong></font>
</center></td>
      <td><center>
          <font color="#FFCC00"><strong>good</strong></font>
</center></td>
      <td><center>
          <font color="#FFCC00"><strong><font color="#339900"><em>BEST</em></font></strong></font> 
        </center></td>
    </tr>
</table>
</div>
</body>
</html>