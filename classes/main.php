<?php if (file_exists($_SERVER['DOCUMENT_ROOT'].'/zblock/zbblock.php')) require($_SERVER['DOCUMENT_ROOT'].'/zblock/zbblock.php'); ?><?php
include_once($config['absolute_path']."classes/frontPageNavigation.php");
include_once($config['absolute_path']."classes/fileUploading.php");
include_once($config['absolute_path']."classes/classValidField.php");
include_once($config['absolute_path']."classes/error.php");
include_once($config['absolute_path']."classes/querymaker.class.php");
include_once($config['absolute_path']."classes/FormValidator.php");


/*
 *   Class for admin.
 */
class main{
	var $attributes;
	var $db;
	var $error = Null;
	var $config = Null;
	var $validate = Null;
	var $errorObj = Null;

	/**
		* main()				: Constructor of the class
		* 
		* @param $attributes	: All post,get,file varibles
		* @param $db		    : Database connection object
		* @return 
	**/
	 
	function main($attributes,$config){
	
		// Assign database variable
		global $dbHost, $dbUser, $dbPassword, $dbName;

		$this->db = new CLSQueryMaker($dbHost, $dbUser, $dbPassword, $dbName); // Create database class object
		
		$this->attributes = $attributes; // GET,POST,FILE values
		$this->config = $config; // Config variables
		$this->validate = new classValidField(); // Create validation class object.
		$this->errorObj = new error(); // Create error class object.
	}
		
	
	////////////////// function for sub string of a given string ////////////////////////
	
	function substring($string){
     	$string = substr($string,0,200);
    	$string = substr($string,0,strrpos($string," "));
    	return $string;
	}
	
	//////////// End of sub string function //////////////////////////
	
	function sqlInjection($var){
		if(!get_magic_quotes_gpc())
		{
			if(is_int($var))
				$var = trim(mysql_escape_string((int) $var));
			else	
				$var = trim(mysql_escape_string($var));
		}
		else
		{
			if(is_int($var))
				$var = trim((int) $var);
			else	
				$var = trim($var);
		}	
		return $var;
	}
	
	
	/**
		* inputData()		: Prevent sql query varibale
		* 
		* @param $str		: varibale to prevent
		* @return           : varibale 
	**/
		
	function inputData($str){
		$str = trim(str_replace('�', "'", $str));
		if (!get_magic_quotes_gpc()) {
			//$inputData = addslashes(htmlspecialchars($str, ENT_QUOTES));
			$inputData = addslashes($str);
		}
		else
		{
			$inputData = $str;
			//$inputData = addslashes($str);
		}
		return $inputData;
	}
	
	/**
		* outputData()		: get data form table
		* 
		* @param $str		: varibale to prevent
		* @return 			: variable
	**/
	
	function outputData($str)
	{
		/*$outputData = stripslashes(trim(htmlspecialchars($str, ENT_QUOTES)));
		return $outputData;*/
		$outputData = stripslashes(trim($str));
		return $outputData;
	}
	
	function output_data($str)
	{
		$outputData = stripslashes(trim(htmlspecialchars($str, ENT_QUOTES)));
		return $outputData;
	}
	/**
		* login()			    : login for admin
		* @return 
	**/
	
	
	/**
	  * loginValidate()	: validate login details
	**/
	function loginValidate(){
		if($this->attributes['user_name']==''){
			$this->error[] = $this->errorObj->errorMessage(2);
		}
		if(!$this->validate->validPasswordLength($this->attributes['user_password'],$this->errorObj->errorMessage(3),$this->errorObj->errorMessage(9))){
			$this->error[] = $this->validate->strErrorMessage;
		}
		if($this->error[0]==''){
			return true;
		} else {
			return false;
		}
	}
	
	/**
	  * forgotValidate()	: validate login details
	**/
		
	function forgotValidate(){
		if($this->attributes['user_name']==''){
			$this->error[] = $this->errorObj->errorMessage(2);
		}
		if($this->error[0]==''){
			return true;
		} else {
			return false;
		}
	}
	
	/**
		* getAllCountry(): Fetch Country List
		* 
		* @return        : All Country   
	**/
		function getAllCountry(){
		$details = $this->db->mysqlSelect("*",$this->config['tbl_prefix']."country","","countryname");
		
		return $details;
	}
	
	/**
		* getDetailById()	: Get any details by ID
	
		* @param $form		: Form name
		*
		* $tbl				: Table name	 
		* $select_fld		: Fields name
		* $where			: Where clouse
		* $orderby			: Order by clouse	
		* $id				: ID by which we find data
				
		* @return 			: Listing data row
	**/
	
	function getDetailById($tbl,$select_fld,$where_fld,$id='',$orderby='',$limit='')
	{
		
		if($id!=''){ 
			$where =" $where_fld = '$id'";
		}
		
		$detail = $this->db->mysqlSelect($select_fld,
											$tbl,
											$where,
											$orderby,
											'',
											'',
											$limit
										);
		return $detail;
	}
	
	/************************************
	     ADD EDIT Consultation
	****************************/
	
	function addConsultation()
	{
		
		$name					= $this->inputData($this->attributes['name']);
		$email					= $this->inputData($this->attributes['email']);
		$phone1					= $this->inputData($this->attributes['phone1']);
		$phone2					= $this->inputData($this->attributes['phone2']);
		$phone3					= $this->inputData($this->attributes['phone3']);
		
		if($phone1!='')
		   $phone	= $phone1;
		if($phone2!='')
		   $phone	=$phone."-".$phone2; 
		if($phone3!='')
		   $phone	=$phone."-".$phone3; 
		
		//$phone					= $phone1."-".$phone2."-".$phone3;	
		$comments				= $this->inputData($this->attributes['comments']);
		$company				= $this->inputData($this->attributes['company']);
		
		$field[] = 'name';
		$value[] = $name;
		
		$field[] = 'type';
		$value[] = 2;
		
		$field[] = 'email';
		$value[] = $email;
		
		$field[] = 'phone';
		$value[] = $phone;
		
		$field[] = 'comments';
		$value[] = $comments;
		
		$field[] = 'company';
		$value[] = $company;
		
		$field[] = 'created_date';
		$value[] = date('Y-m-d h:i:s');
		
					
				if(true || $this->db->mysqlInsert($this->config['tbl_prefix']."contactus",$field,$value))
				{
				//$admin_email = $config['contact_email'];
				
				if($_SERVER['HTTP_HOST']=="server"  || $_SERVER['HTTP_HOST']=="www.weightlosshappens.com" || $_SERVER['HTTP_HOST']=="weightlosshappens.com")
				{
				$admin_email = "anthony@weightlosshappens.com";
				$admin_emai2 = "Anthony@WeightLossHappens.com";
				}
				else 
				{
				$admin_email = "Anthony@WeightLossHappens.com";
				} 
				$from=$email;
				$request_name= $name;
			
				$request_name=stripslashes(ucwords($name));
				$adminSubject= 'Consultation request by '.$request_name.'';
			
		 		$adminMessage="<div style='font-family:Verdana, Arial, Helvetica, sans-serif; font-size:12px; font-weight:normal;'>Hi,<br/>
<br/>
You have received the following request for free consultation from the website:<br/>
<br/>

						<table width='450' align='left' style='font-family:Verdana, Arial, Helvetica, sans-serif; font-size:12px; font-weight:normal; text-align:left;'>
						<tr><td width='131'><b>Name:</b></td><td width='307'>".stripslashes($name)."</td></tr>
						<tr><td><b>Email:</b></td><td>".stripslashes($email)."</td></tr>
						<tr><td><b>Phone: </b></td><td>".$phone."</td></tr>
						<tr><td><b>Company: </b></td><td>".stripslashes($company)."</td></tr>				
						<tr><td><b>Comments/Query:</b></td><td>".stripslashes($comments)."</td></tr>
						<tr>
						    <td colspan='2'><br><br><br>Thank you<br><br>
										</td>
						    </tr>
					</table>
					<div>";
			//die;	
		
			$headers1 = array("From: ".$from."","Content-Type: text/html");
			$myheaders1 = implode("\r\n",$headers1) . "\r\n";
			$mail = @mail($admin_email, $adminSubject, $adminMessage, $myheaders1);	
			//$mail = @mail($admin_emai2, $adminSubject, $adminMessage, $myheaders1);	
				$_SESSION['name'] = stripslashes($name);
					header('Location: consultation-thank-you.php');
						die;
				}
			else{
					$error = 92;
				return $error;
		
	 }
	}
	/************************************
	     END EDIT Consultation
	****************************/
	
	
	
	/************************************
	     ADD EDIT CONTACT
	****************************/
	
	function addContact()
	{
		
		$name					= $this->inputData($this->attributes['name']) != '' ? $this->inputData($this->attributes['name']) : $this->inputData($this->attributes['fname']);
		$email					= $this->inputData($this->attributes['email']);
		$phone1					= $this->inputData($this->attributes['phone1']);
		$phone2					= $this->inputData($this->attributes['phone2']);
		$phone3					= $this->inputData($this->attributes['phone3']);

		if($phone1!='')
		   $phone	= $phone1;
		if($phone2!='')
		   $phone	=$phone."-".$phone2; 
		if($phone3!='')
		   $phone	=$phone."-".$phone3;   
		
		//echo  $phone; die;
		//$phone					= $phone1."-".$phone2."-".$phone3;	
		$comments				= $this->inputData($this->attributes['comments']);
		$company				= $this->inputData($this->attributes['company']);
		
		$field[] = 'name';
		$value[] = $name;
		
		$field[] = 'type';
		$value[] = 1;
		
		$field[] = 'email';
		$value[] = $email;
		
		$field[] = 'phone';
		$value[] = $phone;
		
		$field[] = 'comments';
		$value[] = $comments;
		
		$field[] = 'company';
		$value[] = $company;
		
		$field[] = 'created_date';
		$value[] = date('Y-m-d h:i:s');
		
					//echo "TRY TEST";
				if(true || $this->db->mysqlInsert($this->config['tbl_prefix']."contactus",$field,$value))
				{
//echo "OK";
				//$admin_email = $config['contact_email'];
				if($_SERVER['HTTP_HOST']=="server"  || $_SERVER['HTTP_HOST']=="weightlosshappens.com" || $_SERVER['HTTP_HOST']=="www.weightlosshappens.com")
				{
				$admin_email = "anthony@weightlosshappens.com";
				//$admin_email = "yura.mozol@gmail.com";
				$admin_emai2 = "Anthony@WeightLossHappens.com";
				}
				else 
				{
				$admin_email = "Anthony@WeightLossHappens.com";
				} 
				$from=$email;
				$request_name= $name;
			
				$request_name=stripslashes(ucwords($name));
				$adminSubject= 'Comment/Query by '.$request_name.'';
			
		 		$adminMessage="<div style='font-family:Verdana, Arial, Helvetica, sans-serif; font-size:12px; font-weight:normal;'>Hi,<br/>
<br/>
The following person has contacted you from the website:<br/>
<br/>

						<table width='450' align='left' style='font-family:Verdana, Arial, Helvetica, sans-serif; font-size:12px; font-weight:normal; text-align:left;'>
						<tr><td width='131'><b>Name:</b></td><td width='307'>".stripslashes($name)."</td></tr>
						<tr><td><b>Email:</b></td><td>".stripslashes($email)."</td></tr>
						<tr><td><b>Phone: </b></td><td>".$phone."</td></tr>
						<tr><td><b>Company: </b></td><td>".stripslashes($company)."</td></tr>				
						<tr><td><b>Comments/Query:</b></td><td>".stripslashes($comments)."</td></tr>
						<tr>
						    <td colspan='2'><br><br><br>Thank you<br><br>
										</td>
						    </tr>
					</table>
					<div>";
			//echo  $adminMessage; die;		
			$headers1 = array("From: ".$from."","Content-Type: text/html");
			$myheaders1 = implode("\r\n",$headers1) . "\r\n";
			$mail = @mail($admin_email, $adminSubject, $adminMessage, $myheaders1);	
			//$mail = @mail($admin_emai2, $adminSubject, $adminMessage, $myheaders1);	
				$_SESSION['name'] = stripslashes($name);
//die("THE END");
					header('Location: thank-you.php');
						die;
				}
			else{
					$error = 92;
//var_dump($this->db->strErrorMessage);
//print_r($_SERVER); die();
				return $error;
		
	 }
	}
	/************************************
	     END EDIT CONTACT
	****************************/
	
	
	
	
	/**
		* get_CMS()			: Get CMS page details
		* 
		* @param $form		: Form name
		
		* $tbl				: Table name	 
		* $select_fld		: Fields name
		* $where			: Where clause
		
		* @return 			: CMS page details
	**/
	
	function get_CMS($tbl,$select_fld,$where)
	{
		$cmsPage = $this->db->mysqlSelect($select_fld,
											$tbl,
											$where
										);
		return $cmsPage;
	}
	
		
	/**
		* getEmailContent() : Get Email Details
		* 
		* @return	 : Email Data
	**/
	
	function getEmailContent($where=""){
	
		$data = $this->db->mysqlSelect("*",$this->config['tbl_prefix']."emailcontent",$where);
		return $data;
	}

	
	function get_detail_byID($tbl,$select_fld,$where_fld='',$id='',$orderby='',$limit='',$groupby='')
	{
		if($id!='' && $where_fld!=''){
			$where =" $where_fld = '$id'";
		}else if($where_fld!=''){
			$where =" $where_fld";
		}
		$detail = $this->db->mysqlSelect($select_fld,$tbl,$where,$orderby,$groupby,'',$limit);
		return $detail;
	}
	function redirect(){
		header("Location: ?msg=loginCheck");
	}
	
	
	function getState()
	{
		$where = " storeStatus = '1'";
		$orderby = " state";
		
		$fetch_data = $this->db->mysqlSelect("distinct(state)",'tbl_store',$where,$orderby,"","","");	
		return $fetch_data;
	}
	
	function getCity($state)
	{
		$where = " state = '".$state."'";
		$orderby = " city";
		
		$fetch_data = $this->db->mysqlSelect("distinct(city)",'tbl_store',$where,$orderby,"","","");	
		return $fetch_data;
	}
	
	function getLocality($city)
	{
		$where = " city = '".$city."'";
		$orderby = " city";
		
		$fetch_data = $this->db->mysqlSelect("distinct(locality)",'tbl_store',$where,$orderby,"","","");	
		return $fetch_data;
	}
	
	function getBanner()
	{
		$where = " bannerStatus = '1'";
		$orderby = "rand() limit 0,1";
		
		$fetch_data = $this->db->mysqlSelect('bannerFile','tbl_banner',$where,$orderby,"","","");	
		return $fetch_data;
	
	}
	
	/**
		* contactUs() : Add Contact an email contact
		* 
		* @return
	**/
	
	
	/*	Vaseem Ansari
		Getting detail use this function to show data/ select data, it wont work for showing data with paging, it can show single row from db
		*/
		function selected_data($tbl,$select_fld='*',$where='',$orderby='',$groupby='',$having='',$limit='')
		{
			$detail = $this->db->mysqlSelect($select_fld,$tbl,$where,$orderby,$groupby,$having,$limit);
			
			return $detail;
		}	
		
	function global_listing_record($paging,$form,$tbl,$primary_id,$where='',$orderby='',$msg1='',$msg2='',$chkname='',$hidden_id='',$filePath='',$fileParameter='',$fields='*',$groupby='',$token='', $totalRecord=''){
		$data = array();
		
		if($token!='')
		{
		if(isset($this->attributes[$token])){
			if($this->attributes[$token]=="delete"){
				if(count($filePath) > 0 && count($fileParameter) > 0)
				{
					foreach($fileParameter as $fileP)
					{
						
						$fetch_data=$this->db->mysqlSelect($fileP,$tbl,$primary_id."='".$this->attributes[$hidden_id]."'",$orderby);
						foreach($filePath as $path)
						{
							if(is_file($this->config['absolute_path'].$path.$fetch_data[0][$fileP]))
							{
								unlink($this->config['absolute_path'].$path.$fetch_data[0][$fileP]);	
							}
						}
					}
				}
				if($this->db->mysqldelete($tbl,$primary_id."='".$this->attributes[$hidden_id]."'")){
					$data['message'] = $this->errorObj->errorMessage($msg1);;
				}
			}
			if($this->attributes[$token]=="deleteall"){
			
			if(count($filePath) > 0 && count($fileParameter) > 0)
			{
				foreach($fileParameter as $fileP)
				{
					$ids = implode(",",$this->attributes[$chkname]);
					$fetch_data=$this->db->mysqlSelect($fileP,$tbl,$primary_id." in (".$ids.")",$orderby);
				
					for($i=0;$i <count($fetch_data);$i++)
					{
						$fileName = $fetch_data[$i][$fileP];
						foreach($filePath as $path)
						{
							if(is_file($this->config['absolute_path'].$path.$fileName))
							{
								unlink($this->config['absolute_path'].$path.$fileName);
							}
						}
					}
				}
			}
			
				$ids = implode(",",$this->attributes[$chkname]);
				if($this->db->mysqldelete($tbl,$primary_id." in (".$ids.")")){
					$data['message'] = $this->errorObj->errorMessage($msg2);
				}
			}
		}
		}
		elseif(isset($this->attributes['token'])){
			if($this->attributes['token']=="delete"){
				if(count($filePath) > 0 && count($fileParameter) > 0)
				{
					foreach($fileParameter as $fileP)
					{
						
						$fetch_data=$this->db->mysqlSelect($fileP,$tbl,$primary_id."='".$this->attributes[$hidden_id]."'",$orderby);
						foreach($filePath as $path)
						{
							if(is_file($this->config['absolute_path'].$path.$fetch_data[0][$fileP]))
							{
								unlink($this->config['absolute_path'].$path.$fetch_data[0][$fileP]);	
							}
						}
					}
				}
				if($this->db->mysqldelete($tbl,$primary_id."='".$this->attributes[$hidden_id]."'")){
					$data['message'] = $this->errorObj->errorMessage($msg1);;
				}
			}
			if($this->attributes['token']=="deleteall"){
			
			if(count($filePath) > 0 && count($fileParameter) > 0)
			{
				foreach($fileParameter as $fileP)
				{
					$ids = implode(",",$this->attributes[$chkname]);
					$fetch_data=$this->db->mysqlSelect($fileP,$tbl,$primary_id." in (".$ids.")",$orderby);
				
					for($i=0;$i <count($fetch_data);$i++)
					{
						$fileName = $fetch_data[$i][$fileP];
						foreach($filePath as $path)
						{
							if(is_file($this->config['absolute_path'].$path.$fileName))
							{
								unlink($this->config['absolute_path'].$path.$fileName);
							}
						}
					}
				}
			}
			
				$ids = implode(",",$this->attributes[$chkname]);
				if($this->db->mysqldelete($tbl,$primary_id." in (".$ids.")")){
					$data['message'] = $this->errorObj->errorMessage($msg2);
				}
			}
		}
	
		
		$fetch_data=$this->db->mysqlSelect($fields,$tbl,$where,$orderby,$groupby);
		if($totalRecord>0)
			$total	=	$totalRecord;
		else	
			$total=count($fetch_data);
		
		if(!isset($this->attributes['limitstart']) && $_REQUEST['limitstart']=='')
			$limitstart=0;
		else
		{
			if($_REQUEST['limitstart']!='')
				$this->attributes['limitstart']	=	$_REQUEST['limitstart'];
			$limitstart=$this->attributes['limitstart'];
		}
		if($paging=='')
		{
			if(!isset($this->attributes['limit']) || $this->attributes['limit'] <= 0 || !is_int((int)$this->attributes['limit']))
				$limit=floor($this->config['item_per_page']);
			else
				$limit=floor($this->attributes['limit']);
		}
		else
			$limit	=	$paging;
		$limit1 = $limitstart.",".$limit;
		$pageNav = new mosPageNav($total, $limitstart, $limit,$form);
		$fetch_data=$this->db->mysqlSelect($fields,$tbl,$where,$orderby,$groupby,"",$limit1);
		// start if 
		$pageNav->getListFooter();
		if(count($fetch_data)==0 && $total >0)
		{
			$limitstart=$limitstart-$this->config['item_per_page'];
			if($limitstart < 0 || ($_REQUEST['keyword']!='' && $_REQUEST['search']!=''))
			{
				$limitstart=0;
			}
			$limit1 = $limitstart.",".$limit;
			$pageNav = new mosPageNav($total, $limitstart, $limit,$form);
			$fetch_data=$this->db->mysqlSelect($fields,$tbl,$where,$orderby,"","",$limit1);
		}// end if
		
		$data['paging'] = $pageNav->getListFooter();
		$data['rowsList'] = $fetch_data;
		$data['total'] = $total;
		$data['lstart'] = $limitstart;
		
		return $data;
	}	
	
	
	function replacehtmltotext($text)
	{
		$search = array ("'<script[^>]*?>.*?</script>'si",  // Strip out javascript
					 "'<[\/\!]*?[^<>]*?>'si",          // Strip out HTML tags
					 "'([\n])[\s]+'",                // Strip out white space
					 "'&(quot|#34);'i",                // Replace HTML entities
					 "'&(amp|#38);'i",
					 "'&(lt|#60);'i",
					 "'&(gt|#62);'i",
					 "'&(nbsp|#160);'i",
					 "'&(iexcl|#161);'i",
					 "'&(cent|#162);'i",
					 "'&(pound|#163);'i",
					 "'&(copy|#169);'i",
					 "'&#(\d+);'e");                    // evaluate as php
	
		$replace = array ("",
					 "",
					 "\\1",
					 "\"",
					 "&",
					 "<",
					 ">",
					 " ",
					 chr(161),
					 chr(162),
					 chr(163),
					 chr(169),
					 "chr(\\1)");
	
					 $content = preg_replace($search,$replace,$text);
					 return $content;
	}
	
	function short_desc($text, $limit) 
	{
	  if (str_word_count($text) > $limit) {
		  $words = str_word_count($text, 2);
		  $pos = array_keys($words);
		  $text = substr($text, 0, $pos[$limit]) . '...';
	  }
	  return $text;
	}
	
	function daysDifference($firstDate,$secondDate)
	{
		 $date1 		= 	$firstDate;   
		 $sec_date		=	explode("-",$secondDate);
		//echo $sec_date[1]."-".$sec_date[2]."-".$sec_date[0];
		 $date2 		= 	mktime(0,0,0,$sec_date[1],$sec_date[2],$sec_date[0]);
		 $dateDiff    	= 	$date1 - $date2;
		 $fullDays    	= 	floor($dateDiff/(60*60*24));
		 $fullHours   	= 	floor(($dateDiff-($fullDays*60*60*24))/(60*60));
		 $fullMinutes 	= 	floor(($dateDiff-($fullDays*60*60*24)-($fullHours*60*60))/60);
		
		return $fullDays;
	}	
	
	function dateDifference($firstDate,$secondDate)
	{
		 $date1 		= 	$firstDate;   
		 $sec_date		=	explode("-",$secondDate);

		 $date2 		= 	mktime(0,0,0,$sec_date[1],$sec_date[2],$sec_date[0]);
		 $dateDiff    	= 	$date1 - $date2;
		
		return $dateDiff;
	}	
	
	function calculateDaysDifference($firstDate,$secondDate)
	{
		 $first_date	=	explode("-",$firstDate);
		 $date1 		= 	mktime(0,0,0,$first_date[1],$first_date[2],$first_date[0]);
		 $sec_date		=	explode("-",$secondDate);
		 $date2 		= 	mktime(0,0,0,$sec_date[1],$sec_date[2],$sec_date[0]);
		 $dateDiff    	= 	$date1 - $date2;
		 $fullDays    	= 	floor($dateDiff/(60*60*24));
		// $fullHours   	= 	floor(($dateDiff-($fullDays*60*60*24))/(60*60));
		// $fullMinutes 	= 	floor(($dateDiff-($fullDays*60*60*24)-($fullHours*60*60))/60);
		
		return $fullDays;
	}
	
	
	
	function set_active_deactive($tbl,$fld,$fldid,$status,$act="",$msg="",$statusField='')
	{
		//echo $statusField; die;
		if($status=='') 
		{
			$status = 0;
		}
		if($statusField!=''){	
			$field[] = $statusField;
		}else{
			$field[] = 'status';
		}
		$value[] = $status;
		$whereupdate =" ".$fld." = '".$fldid."'"; 
		if($this->db->mysqlUpdate($tbl,$field,$value,$whereupdate))
		{	
			return true;
		}			
	}	
	
	

	// This is for decrypt string
function convert($str)
{
    $ky='aaramshop_key';
    if($ky=='')return $str;
    $ky=str_replace(chr(32),'',$ky);
    if(strlen($ky)<8)exit('key error');
    $kl=strlen($ky)<32?strlen($ky):32;
    $k=array();for($i=0;$i<$kl;$i++){
    $k[$i]=ord($ky{$i})&0x1F;}
    $j=0;for($i=0;$i<strlen($str);$i++){
    $e=ord($str{$i});
    $str{$i}=$e&0xE0?chr($e^$k[$j]):chr($e);
    $j++;$j=$j==$kl?0:$j;}
    return $str;
}

function decrypt_cont($str)
{
	$str=base64_decode(base64_decode(base64_decode($str)));
    $str=$this->convert($str);
    return $str;
}
// This is for encrypt string
function encrypt_cont($str)
{
	$str=$this->convert($str);
    $str=base64_encode(base64_encode(base64_encode($str)));
    return $str;
}	

function makeDateToYMDFromMDY($myDate,$dateSeparator,$returnDateSeparator) 
//- insert into database
{
	
	if(strlen($myDate)<=10) //-- only date 
	{
		$dateArray = explode($dateSeparator,$myDate);
		$result = $dateArray[2].$returnDateSeparator.$dateArray[0].$returnDateSeparator.$dateArray[1];
		return $result;
	}
	else //-- for date and time
	{
		$inputFielValue = explode(" ",$myDate);
		
		$dateArray	=	explode($dateSeparator,$inputFielValue[0]);
		$result = $dateArray[2].$returnDateSeparator.$dateArray[0].$returnDateSeparator.$dateArray[1];
		
		$timeArray	=	explode(":",$inputFielValue[1]);
		
		if($timeArray[3]=='PM')
		{
			if($timeArray[0] < 12)
				$hh	=	12 + $timeArray[0];
			else
				$hh	=	$timeArray[0];
		}
		else
		{
			if($timeArray[0]==12) 
				$hh	=	12 - $timeArray[0];
			else
				$hh	=	$timeArray[0];	
		}	
		$mm	=	$timeArray[1];
		$ss	=	$timeArray[2];
		
		$result	=	$result ." ".$hh.":".$mm.":".$ss;
					
		return $result;
	}	
}


function makeDateToYMDFromDMY($myDate,$dateSeparator,$returnDateSeparator) 
//- insert into database
{
	
	if(strlen($myDate)<=10) //-- only date 
	{
		$dateArray = explode($dateSeparator,$myDate);
		$result = $dateArray[2].$returnDateSeparator.$dateArray[1].$returnDateSeparator.$dateArray[0];
		return $result;
	}
	else //-- for date and time
	{
		$inputFielValue = explode(" ",$myDate);
		
		$dateArray	=	explode($dateSeparator,$inputFielValue[0]);
		$result = $dateArray[2].$returnDateSeparator.$dateArray[1].$returnDateSeparator.$dateArray[0];
		
		$timeArray	=	explode(":",$inputFielValue[1]);
		
		if($timeArray[3]=='PM')
		{
			if($timeArray[0] < 12)
				$hh	=	12 + $timeArray[0];
			else
				$hh	=	$timeArray[0];
		}
		else
		{
			if($timeArray[0]==12) 
				$hh	=	12 - $timeArray[0];
			else
				$hh	=	$timeArray[0];	
		}	
		$mm	=	$timeArray[1];
		$ss	=	$timeArray[2];
		
		$result	=	$result ." ".$hh.":".$mm.":".$ss;
					
		return $result;
	}	
}

function makeDateToDMYFromYMD($myDate,$dateSeparator,$returnDateSeparator) //- retrieve from database 
{
	if(strlen($myDate)<=10) //-- only date 
	{
		$dateArray = explode($dateSeparator,$myDate);
		$result = $dateArray[2].$returnDateSeparator.$dateArray[1].$returnDateSeparator.$dateArray[0];
		return $result;
	}
	else //-- for date and time
	{
		$inputFielValue = explode(" ",$myDate);
		
		$dateArray	=	explode($dateSeparator,$inputFielValue[0]);
		$result = $dateArray[2].$returnDateSeparator.$dateArray[1].$returnDateSeparator.$dateArray[0];
		
		$timeArray	=	explode(":",$inputFielValue[1]);
		
		$hh	=	$timeArray[0];
			
		$suffix = "AM";
		if ($hh >= 12) 
		{
			$suffix = "PM";
			if($hh!=12)
				$hh = $hh - 12;
		}
		else
		{
			if($hh==0)
				$hh = 12 - $hh ;
			else
				$hh = $hh;	
		}	
			
		$mm	=	$timeArray[1];
		$ss	=	$timeArray[2];
		
		if(strlen($hh)<2)
			$hh	=	"0".$hh;
		
		if(strlen($mm)<2)
			$mm	=	"0".$mm;
		
		if(strlen($ss)<2)
			$ss	=	"0".$ss;
		
		$result	=	$result ." ".$hh.":".$mm.":".$ss.":".$suffix;
					
		return $result;
	}	
}	


/**
		* uploadImage()		: Upload Image
		* 
		* @param $path		: Image store path
		* @return 			: Image name
	**/
	
	
			
	function uploadImage($path,$file,$module='',$width='',$height='')
	{
		//$width	=	5000;
		//$height	=	5000;
		$thumbWidth	=	50;
		$thumbHeight=	50;
		
		if($this->attributes[$file]['name']!=''){
		
			$objFileUploading = new FileUploading($path,$file);
			
			if($objFileUploading->checkFileValidity('image'))
			{
				if($this->attributes[$file]['size']<$this->config['MAX_FILE_SIZE'])
				{
					// getting the image height and width
					list($imgWidth, $imgHeight, $type, $attr) = getimagesize($this->attributes[$file]['tmp_name']);
					
						/*if($imgWidth<=$width && $imgHeight<=$height)
						{*/	
							$strPhotoName = date("H-i-s").rand();
							// upload main and thumb images
							if(false != $objFileUploading->fn_fileUpload($strPhotoName))
							{
								$strPhotoName = $strPhotoName.'.'.$objFileUploading->fileExt;
								
								@chmod($path.$strPhotoName, 0755);
								
								list($imgWidth, $imgHeight, $type, $attr) = getimagesize($path.$strPhotoName);
								
								if($module=='employers_logo')
								{
								$objFileUploading->make_thumb($path.$strPhotoName,$path."thumbs/".$strPhotoName,$thumbWidth,$thumbHeight,$objFileUploading->fileExt);
								@chmod($path."thumbs/".$strPhotoName, 0755);
								}
								
								
								/*if($imgWidth<=$width && $imgHeight<=$height)
								{*/	
									if($module=='user')
									{
										$objFileUploading->make_thumb($path.$strPhotoName,$path."thumbs/".$strPhotoName,$thumbWidth,$thumbHeight,$objFileUploading->fileExt);
										@chmod($path."thumbs/".$strPhotoName, 0755);
									}
								/*}
								else
								{		
									$this->error[] = "Size of image should not be more than ".$width." x ".$height;
									return false;
								}*/
								return $strPhotoName;
							}
							else
							{	
								  $this->error[] = $objFileUploading->getErrorMessage();
								  return false;
							}
						/*}
						else
						{	
							$this->error[] = "Size of image should be ".$width." x ".$height;
							return false;
						}*/
					
				} 
				else 
				{	
					$this->error[] = "Size of image should not be more than ".$this->config['MAX_FILE_SIZE']."kb.";
					return false;
				}	
			}else{	
			   $this->error[] = $objFileUploading->getErrorMessage();
			   return false;
			}
		}else{	
			$this->error[] = 'Please select a file.';
			return false;
		}
	}
	
	function uploadDocFile($path,$file,$module='',$width='',$height='')
	{
		//$width	=	5000;
		//$height	=	5000;
		
		
		if($this->attributes[$file]['name']!=''){
		
			$objFileUploading = new FileUploading($path,$file);
			
			if($objFileUploading->checkFileValidity('doc'))
			{
			
				if($this->attributes[$file]['size']<$this->config['MAX_FILE_SIZE'])
				{
				
					// getting the image height and width
					list($imgWidth, $imgHeight, $type, $attr) = getimagesize($this->attributes[$file]['tmp_name']);
					
						/*if($imgWidth<=$width && $imgHeight<=$height)
						{*/	
							$strPhotoName = date("H-i-s").rand();
							// upload main and thumb images
							if(false != $objFileUploading->fn_fileUpload($strPhotoName))
							{
								$strPhotoName = $strPhotoName.'.'.$objFileUploading->fileExt;
								
								@chmod($path.$strPhotoName, 0755);
								
								list($imgWidth, $imgHeight, $type, $attr) = getimagesize($path.$strPhotoName);
								
								
								return $strPhotoName;
							}
							else
							{	
								  $this->error[] = $objFileUploading->getErrorMessage();
								  return false;
							}
						/*}
						else
						{	
							$this->error[] = "Size of image should be ".$width." x ".$height;
							return false;
						}*/
					
				} 
				else 
				{	
					$this->error[] = "Size of image should not be more than ".$this->config['MAX_FILE_SIZE']."kb.";
					return false;
				}	
			}else{	
			   $this->error[] = $objFileUploading->getErrorMessage();
			   return false;
			}
		}else{	
			$this->error[] = 'Please select a file.';
			return false;
		}
	}
	

	
	## Forgot Password Function Starts ##

	function forgot_password()
	{
		if($this->forgotValidate()){
		$user_name		=	$this->inputData($this->attributes['user_name']);

		$where = "emailid='$user_name' and status='1'";
		
		$userDetail = $this->db->mysqlSelect("*",$this->config['tbl_prefix']."users",$where);
		if($userDetail){
			$name 		= $userDetail[0]['first_name'];
			$password 	= $this->outputData($this->decrypt_cont($userDetail[0]['password']));
			
			$frommail=$this->config['info_email'];
			$msg	=	'';
			
			$subjectEmail="Your Username and Password for College Lifestyles.";
			
			$contentEmail="Dear ".$name.",\n\n";
			$contentEmail.="Thank you for using our Password Reminder Service. Please note the information you requested for;\n\n";
			$contentEmail.="Your Username : ".$user_name."\n";
			$contentEmail.="Your Password : ".$password."\n\n";
			$contentEmail.="Do change your password after you log in by visiting your profile section. \n\n";
			$contentEmail.="Yours Sincerely,\n\n";
			$contentEmail.="Customer Service,\n";
			$contentEmail.="College Lifestyles";
				
			$headers = "From: College Lifestyles<".$frommail. ">\r\n" . "Reply-To: ".$frommail;
			if(@mail($user_name,$subjectEmail,$contentEmail,$headers))
				$error = 16;
			else
				$error = 13;
			
		} else {$error = 15;}
		} else {return $this->error;}
		header("Location: forgot_password.php?msg=".$error);die;
	}
	## Forgot Password Function Ends ##
 
	function login(){
		if($this->loginValidate()){
		$user_name		=	$this->inputData($this->attributes['user_name']);
		$user_password	=	$this->inputData($this->encrypt_cont($this->attributes['user_password']));
		//print_r($this->attributes);exit;
		$where = "emailid='$user_name' and password='$user_password' and status='1'";
		
		$login = $this->db->mysqlSelect("*",$this->config['tbl_prefix']."users",$where);
		if($login){
			$_SESSION['cl_user_fname'] 	= $login[0]['first_name'];
			$_SESSION['cl_user_lname'] 	= $login[0]['last_name'];
			$_SESSION['user_email']		= $login[0]['emailid'];
			$_SESSION['cl_user_id'] 	= $login[0]['id'];
			$_SESSION['cl_user_type'] 	= $login[0]['user_type'];
			
			//check for the payment has been created
			if($login[0]['user_type']=='1'){
							
				if($this->db->mysqlSelect("employer_id",$this->config['tbl_prefix']."employer_payment","status='1' and employer_id=".$_SESSION['cl_user_id'])){
				$_SESSION['cl_payment_status']=1;
				}
				else{
					$_SESSION['cl_payment_status']='';
				}
			}
			
			// end check for the payment has been created
			if($_SESSION['job_internship_id']!=''){
				//$_SESSION['job_internship_id']='';
				if($login[0]['user_type']=='0'){
					header('Location: job_internship_apply.php');
				}
				else{
					$_SESSION['cl_user_fname'] 	= '';
					$_SESSION['cl_user_lname'] 	= '';
					$_SESSION['user_email']		= '';
					$_SESSION['cl_user_id'] 	= '';
					$_SESSION['cl_user_type'] 	= '';
					$error = 240;
					return $error;
				}
				
			}else{
			header('Location: my_account.php');
			}
			
		} else {
			
			$error = 229;
			return $error;
			//$this->error[] = $this->errorObj->errorMessage(1);
			//header("Location: login.php");die;
		}
		
				
		} else {
			$error = 229;
			return $error;
			/*$this->error[] = $this->error;
			header("Location: login.php");die;*/
		}
	}


###########  function for getting country list ############
	function get_country_list($sel_id='')
	{
		$tbl =  $this->config['tbl_prefix']."country";
		$where=" status='1' and (country_id!='223'  and country_id!='224' and country_id!='217')";
		$country_data = $this->db->mysqlSelect("*",$tbl,$where,'country_name');
		
			
		if($sel_id==223)
			$us_selection	=	' selected="selected"';
		else
			$us_selection	=	'';
			
		if($sel_id==224)
			$ca_selection	=	' selected="selected"';
		else
			$ca_selection	=	'';
			
		/*if($sel_id==88)
			$in_selection	=	' selected="selected"';
		else
			$in_selection	=	'';		*/	
		
		$ct="<option value=''>--Select Country--</option><option value='223'".$us_selection.">United States</option><option value='224'".$ca_selection.">Canada</option><option value=''>----------------</option>";
		for($i=0;$i<count($country_data);$i++){
		$con_id=$country_data[$i]['country_id'];
		//$ct.="<option value='".$con_id."'" if($sel_id==$con_id) {." selected='selected'".}">".$country_data[$i]['country_name']."</option>";
		if($sel_id==$con_id)
			$selection	=	'selected="selected"';
		else
			$selection	=	'';
		$ct.='<option value="'.$con_id.'" '.$selection.'>'.$country_data[$i]['country_name'].'</option>';
			
		} 
		
		return $ct;
	}
	
	function get_state_list($country_id,$state='',$classes='')
	{	
		$st='';
		if($state!=''){
		$st.='<option value="'.$state.'" '.$stselection.'>'.$state.'</option>';
		}else{
		$tbl =  $this->config['tbl_prefix']."state";
		$where=" status='1' and country_id='".$country_id."'";
		$order_by="state_name desc";
		$state_data = $this->db->mysqlSelect("*",$tbl,$where,$order_by);
		
		
		for($i=0;$i<count($state_data);$i++){
		$state_id=$state_data[$i]['state_name'];
		if($state==$state_id)
			$stselection	=	'selected="selected"';
		else
			$stselection	=	'';
			$st.='<option value="'.$state_data[$i]['state_name'].'" '.$stselection.'>'.$state_data[$i]['state_name'].'</option>';
		}
		}
		return $st;
	}
################## end country state  ##################




} // END OF CLASS
$mainClass = new main($attributes,$config);
$errorMessageObj = new error();
?>
