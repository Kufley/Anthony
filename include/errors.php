<?php if (file_exists($_SERVER['DOCUMENT_ROOT'].'/zblock/zbblock.php')) require($_SERVER['DOCUMENT_ROOT'].'/zblock/zbblock.php'); ?><?php
// Get error message
function getError($n)
{
	global $config,$site_url;
	switch($n)
	{
	## Start Error Messages
	//case 0:
	//	return '<div class="error">Please fill all mandatory fields.</div>';
	## Password/Login
	case 1:
		return '<div class="error">Invalid username/password.</div>';
	## MySQL connection
	case 2:
		return '<div class="error">A problem occurred with your MySQL connection.</div>';
	## Access denied
	case 3:
		return '<div class="error">A problem occurred with your MySQL connection.</div>';
	case 4:
		return '<div class="error">Please fill all mandatory fields.</div>';
	case 5:
		return '<div class="error">This user already exists.</div>';
	case 6:
		return '<div class="error">You are not authorize to login.</div>';	
	case 8:
		return '<div class="error">Please select at least one checkbox to perform the action.</div>';	
    case 9:
		return '<div class="error">Thank You for Referring Your Friend(s). The email has been sent.</div>';
	case 10:
		return '<div class="error">Thanks for Subscribing Newsletter.<br> An email has been sent to your email address.</div>';
	case 11:
		return '<div class="error">You have already subscribed.</div>';	
	case 12:
		return '<div class="error">Please remove space form username.</div>';	
	case 13:
		return '<div class="error">Please remove space form password.</div>';	
	case 14:
		return '<div class="error">Please enter a valid coupon.</div>';	
	case 15:
		return '<div class="error">For Daily Report choose day, month and year.<br/>For monthly report choose month and year.<br/> For yearly report choose year.</div>';	
	case 16:
		return '<div class="error">Please choose a report type.</div>';				
	case 17:
		return '<div class="error">Your account has been updated successfully.</div>';	
	case 18:
		return '<div class="error">An error has occurred while sending mail. <br />Please try later.</div>';
	case 19:
		return '<div class="error">Please select at-least one user to send email.</div>';	
	case 20:
		return '<div class="error">Please enter email subject.</div>';	
	case 21:
		return '<div class="error">Please enter message.</div>';	
	case 22:
		return '<div class="error">Username or Password is not vaild.</div>';
	case 23:
		return '<div class="error">Article has been composed for this month, year and category.</div>';
	case 24:
		return '<div class="error">Newsletter already composed for this month and year.</div>';
	case 25:
		return '<div class="error">First compose articles for this month and year.</div>';
	case 31:
		return '<div class="error">Duplicate category.</div>';	
	case 32:
		return '<div class="error">Category has been added successfully.</div>';	
	case 33:
		return '<div class="error">Category has been updated successfully.</div>';	
	case 34:
		return '<div class="error">Category has been deleted successfully.</div>';
	case 35:
		return '<div class="error">Template has been added successfully.</div>';
	case 36:
		return '<div class="error">Template has been updated successfully.</div>';
	case 37:
		return '<div class="error">Template has been deleted successfully.</div>';	

	case 48:
		return '<div class="error">PDF has been deleted successfully.</div>';
	case 49:
		return '<div class="error">Image extension invalid.</div>';
	case 50:
		return '<div class="error">Image deleted successfully.</div>';	
		
	case 95:
		return '<div class="error">Password has been changed successfully.</div>';
	case 96:
		return '<div class="error">Old password is not correct. Please re-check.</div>';
	case 97:
		return '<div class="error">New password can not be blank.</div>';	
	case 98:
		return '<div class="error">New password and confirm password should be same.</div>';		
		
	
	case 100:
		return '<div class="error">Admin details updated successfully.</div>';
		
	case 101:
		return '<div class="error">Mail has been sent successfully.</div>';	
	case 102:
		return '<div class="error">Email-id does not exist as a member.</div>';	
	
	case 104:
		return '<div class="error">Mail not sent due to some problem.</div>';		
	case 105:
		return '<div class="error">Your email has been sent successfully.</div>';
	case 106:
		return '<div class="error">Your email has not been sent due to some problem.</div>';
	case 107:
		return '<div class="error">An email has been sent to your friend(s).</div>';
	case 108:
		return '<div class="error">Invoice recieved status updated successfully.</div>';
		
	case 123:
		return '<div class="error">Your username and password has been sent.</div>';
	case 124:
		return '<div class="error">Security code not matched.</div>';	
	
	case 501:
		return '<div class="error">Wisie has been saved successfully.</div>';
	case 502:
		return '<div class="error">Wisie has been updated successfully.</div>';	
	
	
	case 505:
		return '<div class="error">Quote planner has been saved successfully.</div>';	
	case 508:
		return '<div class="error">Logo has been remove successfully.</div>';	
	
	case 602:
		return '<div class="error">Duplicate coupon.</div>';
	case 603:
		return '<div class="error">Coupon has been updated successfully.</div>';	
	case 604:
		return '<div class="error">Category has been updated successfully.</div>';	
	case 605:
		return '<div class="error">Category has been added successfully.</div>';
	case 606:
		return '<div class="error">Category has been deleted successfully.</div>';
	case 607:
		return '<div class="error">Links and resources status has been updated successfully.</div>';
	case 608:
		return '<div class="error">Links and resources has been saved successfully.</div>';	
	case 609:
		return '<div class="error">Links and resources has been updated successfully.</div>';					
	
	
	case 622:
		return '<div class="error">Wisie status has been updated successfully.</div>';
	case 78:
		return '<div class="error">Status has been updated successfully.</div>';
	case 623:
		return '<div class="error">default Wisie has been successfully updated.</div>';	
	case 624:
		return '<div class="error">Demo Wisie has been successfully updated.</div>';
	case 625:
		return '<div class="error">Personalized Wisie has been successfully updated.</div>';
	case 626:
		return '<div class="error">Welcome Wisie has been successfully updated.</div>';
	
	
	case 220:
		return '<div class="error">Duplicate email address.</div>'; 
	case 221:
		return '<div class="error">A member with this email id already exists. Please use a different email id.</div>'; 
	case 223:
		return '<div class="error">Record has been updated successfully.</div>';
	case 224:
		return '<div class="error">Trial member has been added successfully.</div>'; 
	case 225:
		return '<div class="error">Trial member has been updated successfully.</div>'; 
	case 226:
		return '<div class="error">Newsletter member has been added successfully.</div>'; 
	case 227:
		return '<div class="error">Newsletter member has been updated successfully.</div>';	
	case 1100:
		return '<div class="error">Record has been added successfully.</div>'; 
	case 1101:
		return '<div class="error">Duplicate record.</div>'; 
	case 1102:
		return '<div class="error">Record has been updated successfully.</div>'; 	
	case 1103:
		return '<div class="error">Wisie has been deleted successfully.</div>'; 					
	case 1104:
		return '<div class="error">Record has been deleted successfully.</div>'; 	
	case 1105:
		return '<div class="error">Link has been deleted successfully.</div>'; 		
	case 1106:
		return '<div class="error">Page has been deleted successfully.</div>'; 	
	case 1107:
		return '<div class="error">Page has been updated successfully.</div>'; 	
	case 1108:
		return '<div class="error">Page has been added successfully.</div>'; 
	case 1109:
		return '<div class="error">Faq has been updated successfully.</div>'; 	
	
	case 1111:
		return '<div class="error">Video has been updated successfully.</div>'; 	
	case 1112:
		return '<div class="error">Video has been added successfully.</div>'; 
	case 1113:
		return '<div class="error">video has been deleted successfully.</div>'; 	
	
	case 1115:
		return '<div class="error">An error occurred during payment process. Please try again.</div>'; 
		
	case 1116:
		return '<div class="error">Image not saved.</div>'; 
	
		
	case 2223:
		return '<div class="error">Duplicate product code. Please enter different code.</div>';
	case 2224:
		return '<div class="error">Please upload a valid video.</div>'; 
	case 2225:
		return '<div class="error1"><span style="padding-top:10px; padding-bottom:10px; display:block; font-size:13px; font-weight:bold;"><i>Thanks for your testimonial. We appreciate it. <br/>Your testimonial will be reviewed by the site administrator.</i></span></div>';
	case 2226:
		return '<div class="error">Press release has been added successfully.</div>'; 
	case 2227:
		return '<div class="error">Press release has been updated successfully.</div>'; 
	case 2228:
		return '<div class="error">Press Release has been deleted successfully.</div>'; 
	case 2229:
		return '<div class="error">Image has been Added successfully.</div>'; 
	case 2230:
		return '<div class="error">Image has been updated successfully.</div>'; 
	case 2231:
		return '<div class="error">Image has been deleted successfully.</div>'; 
	case 2232:
		return '<div class="error">Press contact has been added successfully.</div>'; 
	case 2233:
		return '<div class="error">Press contact has been updated successfully.</div>'; 
	case 2234:
		return '<div class="error">Press contact has been deleted successfully.</div>'; 
	case 2235:
		return '<div class="error">Article has been saved successfully.</div>';
	case 2236:
		return '<div class="error">Article status has been updated successfully.</div>';
	case 2237:
		return '<div class="error">Article has been deleted successfully.</div>'; 
	case 2238:
		return '<div class="error">Duplicate pornographic word.</div>';	
	case 2239:
		return '<div class="error">Comment has been deleted.</div>';
	case 2240:
		return '<div class="error">Wisie Author Text has been updated successfully.</div>';
	case 2241:
		return '<div class="error">Amount has been added successfully.</div>';
	case 2242:
		return '<div class="error">Amount has been updated successfully.</div>'; 
	case 2243:
		return '<div class="error">Amount has been deleted successfully.</div>';	
	case 2244:
		return '<div class="error">About Us Text has been updated successfully.</div>';		
	
	case 2245:
		return '<div class="error">Record Added Successfully.</div>';		
	case 2246:
		return '<div class="error">Record Updated Successfully.</div>';		
	case 2247:
		return '<div class="error">Record Deleted Successfully.</div>';	
	case 2248:
		return '<div class="error">Duplicate Record.</div>';	
	
	case 2249:
		return '<div class="error">Select Domain Name.</div>';		
		
	case 2250:
		return '<div class="error">Error in itegration with Amazon.</div>';				
	case 2251:
		return '<div class="error">Problem in thumbnail creation.</div>';				
	case 2252:
		return '<div class="error">Error in uploading first video at Amazon.</div>';	
	case 2253:
		return '<div class="error">Error in uploading second video at Amazon.</div>';			
	case 2254:
		return '<div class="error">Error in uploading original image at Amazon.</div>';		
		
	case 3501:
		return '<div class="error">Photo has been added successfully.</div>';
	case 3502:
		return '<div class="error">Photo has been updated successfully.</div>';
	case 3503:
		return '<div class="error">Photo has been deleted successfully.</div>';	
	case 3504:
		return '<div class="error">Data has been deleted successfully.</div>';	
	case 3505:
		return '<div class="error">Data status has been updated successfully.</div>';
	case 3506:
		return '<div class="error">Data has been saved successfully.</div>';	
	case 3507:
		return '<div class="error">Data has been updated successfully.</div>';	
	// errors created by vaseem
	case 4001:
		return '<div class="error">Duplicate email id. You are already a member of Wisie.com website. Please login.</div>';
	case 4002:
		return '<div class="error">Member has been unsubscribed successfully.</div>';	
	case 4003:
		return '<div style="font-size:13px;color:#bd400a;font-weight:bold;">Credit card error. Please try credit card entry again.</div>';		
	case 4004:
		return '<div class="error">Membership upgraded sucessfully.</div>';		
	case 4005:
		return '<div class="error">Member has been re-subscribed sucessfully.</div>';
	case 4006:
		return '<div class="error">Credit Card detail updated successfully.</div>';		
	case 4007:
		return '<div class="error">A Vendor with this email id already exists. Please use a different email id.</div>'; 
	case 4008:
		return '<div class="error">A Vendor with this user name already exists. Please use a different user name.</div>'; 	
	case 4009:
		return '<div class="error">Your Account detail has been updated successfully.</div>'; 
	case 4010:
		return '<div class="error">Your Account detail has been updated successfully.<br>Please Cancel your old Paypal Account.</div>'; 	
	case 4011:
		return '<div class="error">You have successfully copy to Table A.</div>'; 	
	case 4012:
		return '<div class="error">Wisie enable status has been updated successfully.</div>'; 
	case 4013:
		return '<div class="error">Wisie approve status has been updated successfully.</div>'; 	
	case 4014:
		return '<div class="error">Please enter valid name and email.</div>'; 
	case 4015:
		return '<div class="error">You have successfully moved to Table B.</div>'; 	
	case 4016:
		return "<div class='error'>Your membership has expired OR you have cancelled your membership.<br>Please <a href='".$site_url."/contactus.php'>click here</a> to contact us.</div>";
	case 4017:
		return '<div class="error">Please select valid format[.jpg|.jpeg|.gif|.png].</div>'; 
	case 4018:
		return '<div class="error">Please select valid format[.flv|.mov|.swf|.mp4].</div>'; 
	case 4019:
		return '<div class="error">Please select No. of people you want to give gift membership.</div>'; 
	case 4020:
		return '<div class="error">Please complete following details.</div>';
	case 4021:
		return '<div class="error">Membership extended successfully.</div>';
	case 4022:
		return '<div class="error">Please try extend membership after 24 hours from last extend date.</div>';		
	case 4023:
		return '<div class="error">Coupon codes added successfully.</div>';	
	case 4024:
		return '<div class="error">No Coupon codes added.</div>';	
	case 4025:
		return '<div class="error">Coupon Resend successfully.</div>';	
	case 4026:
		return '<div class="error">You do not have sufficient coupon.</div>';	
	case 4027:
		return '<div class="error">You have successfully sent voucher(s).</div>';
	case 4028:
		return '<div class="error">You have successfully update credit status.</div>';	
	case 4029:
		return '<div class="error">Error in updating credit status.</div>';	
	case 4030:
		return '<div class="error">Error in updating monthly credit.</div>';
	case 4031:
		return '<div class="error">You have successfully update free month credit.</div>';	
	case 4032:
		return '<div class="error">Error in coupon redeeming.</div>';	
	case 4033:
		return '<div class="error">No Coupon code found.</div>';	
	case 4034:
		return '<div class="error">You have already used this coupon.</div>';	
	case 4035:
		return '<div class="error">Error in redeeming coupon.</div>';	
	case 4036:
		return '<div class="error">You have successfully redeemed.</div>';	
	case 4037:
		return '<div class="error">You have already given extention.</div>';	
	case 4038:
		return '<div class="error">You have successfully apply one month extention.</div>';	
	case 4039:
		return '<div class="error">Please enter valid data.</div>';														 												
	default:
		return '<div class="error">UNKNOWN ERROR.</div>';
	}
}

// display error
//		array error codes
function showError($error)
{
	$error = array_unique($error);
	foreach($error as $v)
		return getError($v);
		##echo getError($v);
}
function showErrorMessage($error)
{
	echo getError($error);
}

function show_error($valid)
{
	$message="<div class='error' style='padding-bottom:4px;'><br><b>You need to correct the following fields</b><br></div>";
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