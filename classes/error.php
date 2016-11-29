<?php if (file_exists($_SERVER['DOCUMENT_ROOT'].'/zblock/zbblock.php')) require($_SERVER['DOCUMENT_ROOT'].'/zblock/zbblock.php'); ?><?php
	class error{
		/**
			* error()				: Constructor of the class
			* @return 
		**/
		function error(){	}
		/**
			* errorMessage()		: Get error message
			* @param $id			: Error id
			* @return 				: Error message
		**/
		function errorMessage($id){
			$error;
			switch($id){
				
				case '1':
					$error = "Invalid username or password.";
					break; 
				case '2':
					$error = "Please enter username.";	
					break; 
				case '3':
					$error = "Please enter password.";	
					break; 
				case '4':
					$error = "Please enter old password.";	
					break; 
				case '5':
					$error = "Please enter new password.";	
					break; 
				case '6':
					$error = "Please enter confirm password.";	
					break; 
				case '7':
					$error = "New password and confirm password should not matched.";	
					break; 
				case '8':
					$error = "You have entered wrong old password.";	
					break;
				case '9':
					$error = "Please enter Password of at least six characters.";	
					break;
				case '10':
					$error = "Please enter old password of at least six characters.";	
					break;
				case '11':
					$error = "Please enter new password of at least six characters.";	
					break;	
					
				
					
				case '41':
					$error = "Record has been added.";	
					break;
				case '42':
					$error = "Record already exist.";	
					break;
				case '43':
					$error = "Record has been updated.";	
					break;
				case '44':
					$error = "Record has been deleted.";	
					break;
				case '46':
					$error = "Record has been deactivated.";	
					break;
				case '47':
					$error = "Record has been activated.";	
					break;
			
				
				case '31':
					$error = "Record has been added.";	
					break;	
				case '32':
					$error = "Record already exist.";	
					break;
				case '33':
					$error = "Record has been updated.";	
					break;
				case '34':
					$error = "Record has been deleted.";	
					break;
				case '36':
					$error = "Record status has been deactivated.";	
					break;
				case '37':
					$error = "Record status has been activated.";	
					break;
				case '38':
					$error = "Sorry, you cannot deactivate this author as it has books(s) listed under it.
<br>If you want to still deactivate this author, please deactivate or delete all the book(s) listed under it first.";	
					break;
				case '39':
					$error = "Sorry, you cannot delete this author as it has book(s) listed under it.
<br>If you want to still delete this author, please delete all the books listed(s) under it first.";	
					break;
					
					
					
				case '71':
					$error = "Record has been added.";	
					break;	
				case '72':
					$error = "Record already exist.";	
					break;
				case '73':
					$error = "Record has been updated.";	
					break;
				case '74':
					$error = "Record has been deleted.";	
					break;
				case '76':
					$error = "Record status has been deactivated.";	
					break;
				case '77':
					$error = "Record status has been activated.";	
					break;
				case '78':
					$error = "Sorry, you cannot deactivate this category as it has service(s) listed under it.
<br>If you want to still deactivate this category, please deactivate or delete all service(s) listed under it first.";	
					break;	
				case '79':
					$error = "Sorry, you cannot delete this category as it has service(s) listed under it.
<br>If you want to still delete this category, please delete all service(s) under it first.";	
					break;	
					
					
				case '81':
					$error = "Record has been added.";	
					break;	
				case '82':
					$error = "Record already exist.";	
					break;
				case '83':
					$error = "Record has been updated.";	
					break;
				case '84':
					$error = "Record has been deleted.";	
					break;
				case '86':
					$error = "Record status has been deactivated.";	
					break;
				case '87':
					$error = "Record status has been activated.";	
					break;
				case '88':
					$error = "Sorry, you cannot deactivate this category as it has city guide(s) listed under it.
<br>If you want to still deactivate this category, please deactivate or delete all the city guide(s) listed under it first.";	
					break;	
				case '89':
					$error = "Sorry, you cannot delete this category as it has city guide(s) listed under it.
<br>If you want to still delete this category, please delete all the city guide listed(s) under it first";	
					break;
					
					
				case '91':
					$error = "Record has been added.";	
					break;	
				case '92':
					$error = "Record title already exist.";	
					break;
				case '93':
					$error = "Record has been updated.";	
					break;
				case '94':
					$error = "Record has been deleted.";	
					break;
				case '96':
					$error = "Record status has been deactivated.";	
					break;
				case '97':
					$error = "Record status has been activated.";	
					break;
				case '98':
					$error = "Sorry, you cannot deactivate this book as it has review(s) listed under it.
<br>If you want to still deactivate this book, please deactivate or delete all the review(s) listed under it first.";	
					break;	
				case '99':
					$error = "Sorry, you cannot delete this book as it has review(s) listed under it.
<br>If you want to still delete this book, please delete all the review listed(s) under it first";	
					break;
						
					
				case '101':
					$error = "Record has been added.";	
					break;	
				case '102':
					$error = "Record already exist.";	
					break;
				case '103':
					$error = "Record has been updated.";	
					break;
				case '104':
					$error = "Record has been deleted.";	
					break;
				case '106':
					$error = "Record status has been deactivated.";	
					break;
				case '107':
					$error = "Record status has been activated.";	
					break;
				
					
				default :
					$error = "Unknown error.";	
					break; 					
			}
			return $error;
		}
	}
// This function is used to show server side validation errors on the page.
function show_error($valid)
{
	$message="<div class='error' style='padding-bottom:4px;'><b>You need to correct the following fields!</b></div>";
	foreach ($valid as $k => $v) {
		## if ($v[0][1] == false) {
			if ($v[1] === false) {
			// Checking for empty label field.
			## if (empty($v[0][2])) {
			if (empty($v[2])) {
				// then echo the form name of a field.
				$message .= $k."<br> ";
			}
			else {
				## $message .= "<span class='error'>".$v[0][2].", </span>";
				$message .=$v[2]."<br> ";
			}
		}
	}
	return ("<span class='error'>".rtrim(trim($message), ",")."</span>"); ## Removing comma from the last.
}
?>