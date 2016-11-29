jQuery(document).ready(function(){
   //global vars
  
   var form = jQuery("#frmConsultation");
   //alert('hi');
   var name = jQuery("#name");
   var nameInfo = jQuery("#nameInfo");
   
  // var secure = jQuery("#secure");
  // var secureInfo = jQuery("#secureInfo");
   
   var email_id = jQuery("#email");
   var emailInfo = jQuery("#emailInfo");
   
   var phone1 = jQuery("#phone1");
   var phone2 = jQuery("#phone2");
   var phone3 = jQuery("#phone3");
   var phoneInfo = jQuery("#phoneInfo");
   
 // var company = jQuery("#company");
  //var companyInfo = jQuery("#companyInfo");
  
   
   var comments = jQuery("#comments");
   var commentInfo = jQuery("#commentInfo");
   
      //On key press
   name.blur(validateName);
  //company.blur(validateCompany);
   email_id.blur(validateEmail);
  phone1.blur(validatePhone);
   phone2.blur(validatePhone);
   phone3.blur(validatePhone);
   comments.blur(validateComments);
   //secure.blur(validateSecure);
      //On Submitting
   form.submit(function(){ 
       if(validateComments() &validateEmail() &validateName()  &validatePhone() ){
        
		 return true;
       }
       else{ //alert('hi else');
		  // alert('hello');
           return false;
       }
   });
      //validation functions
   function validateEmail(){
              //testing regular expression
       var a = jQuery("#email").val();
	   if(a=='')
	   {
	    if(email_id.val()==''){
           email_id.addClass("error");
           emailInfo.text("Please enter your email address.");
           emailInfo.addClass("error");
		// fname.focus();
           return false;
       }
       //if it's valid
       else{
           email.removeClass("error");
           emailInfo.text("");
           emailInfo.removeClass("error");
           return true;
       }
	   }
	   else
	   {
        // var filter = /^[a-zA-Z0-9]+[a-zA-Z0-9_.-]+[a-zA-Z0-9_-]+@[a-zA-Z0-9]+[a-zA-Z0-9.-]+[a-zA-Z0-9]+.[a-z]{2,4}$/;
       //if it's valid email 
	   var filter = /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,8})+/;
       if(filter.test(a)){ 
           email_id.removeClass("error");
           emailInfo.text("");
           emailInfo.removeClass("error");
           return true;
       }
       //if it's NOT valid
       else{
           email_id.addClass("error");
		   //alert(email_id);
		   emailInfo.text("Invalid email address. Please re-enter your valid email address.");   
	       emailInfo.addClass("error");
		 //  $("#email").focus();
           return false;
       }
	   }
   }
     
      function validateName(){ //alert('hi name');
       //if it's NOT valid
	   var filterName = /^[a-zA-Z .',-]+$/;
          if(name.val()==''){
           name.addClass("error");
           nameInfo.text("Please enter your name.");
           nameInfo.addClass("error");
		// fname.focus();
           return false;
       }
	   else if(!(filterName.test(name.val()))){ 
           name.addClass("error");
           nameInfo.text("Please enter your valid name.");
           nameInfo.addClass("error");
		// fname.focus();
           return false;
       }
       //if it's valid
       else{
           name.removeClass("error");
           nameInfo.text("");
           nameInfo.removeClass("error");
           return true;
       }
   }
   
   function validateCompany(){ //alert('hi name');
       //if it's NOT valid
	   var filterName = /^[a-zA-Z .',-]+$/;
          if(company.val()!=''){
			  if(!(filterName.test(company.val()))){ 
				   company.addClass("error");
				   companyInfo.text("Please enter your valid company name.");
				   companyInfo.addClass("error");
				   return false;
			   }
	    //if it's valid
       else{
				   company.removeClass("error");
				   companyInfo.text("");
				   companyInfo.removeClass("error");
				   return true;
			   }
       }
	   
      
   }
   
 function validatePhone(){
		
		 //testing regular expression
		if(phone1.val()=='' || phone2.val()=='' || phone3.val()=='')
		{
				if(phone1.val().length<3 || phone2.val().length<3 || phone3.val().length<4)
				{ 
					   phone1.addClass("error");
					   phoneInfo.text("Please enter valid phone number.");
					   phoneInfo.addClass("error");
					// fname.focus();
					   return false;
				   }
				   //if it's valid
				   else{
					   phone1.removeClass("error");
					   phoneInfo.text("");
					   phoneInfo.removeClass("error");
					   return true;
				  
				}
		}
		else 
		{
		   phone1.removeClass("error");
		   phoneInfo.text("");
		   phoneInfo.removeClass("error");
		   return true;	
		}
   }
   
  
	
	 
	  function validateComments(){ //alert('Hi ');
       //if it's NOT valid
              if(comments.val()==''){//alert('Hi ');
           comments.addClass("error");
           commentInfo.text("Please enter your comment.");
           commentInfo.addClass("error");
		 //  $("#net_worth").focus();
           return false;
       }
       //if it's valid
       else{
           comments.removeClass("error");
           commentInfo.text("");
           commentInfo.removeClass("error");
           return true;
       }
   }
	
});